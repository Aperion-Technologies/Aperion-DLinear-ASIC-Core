# ai_model/src/train.py
"""
Training script for quantized DLinear model.

Features:
- Quantization-Aware Training (QAT) with Brevitas
- L2 regularization to prevent weight explosion
- Weight clipping to ensure accumulator doesn't overflow
- Validation monitoring

Usage:
    python -m src.train --epochs 100 --output outputs/
"""

import argparse
from pathlib import Path
import torch
from torch.utils.data import DataLoader, random_split
import numpy as np

from .model import QuantDLinear
from .dataset import PriceDataset
from .config import (
    WINDOW_SIZE, BATCH_SIZE, LEARNING_RATE, EPOCHS,
    WEIGHT_BITS, ACTIVATION_BITS, ACCUMULATOR_BITS, WEIGHT_DECAY,
    MAX_WEIGHT
)


class DirectionalLoss(torch.nn.Module):
    """
    Custom loss that penalizes wrong direction more than magnitude errors.

    Loss = alpha * MSE + beta * direction_penalty

    Direction penalty: higher when sign(pred - current) != sign(actual - current)
    """

    def __init__(self, alpha: float = 0.7, beta: float = 0.3):
        super().__init__()
        self.alpha = alpha
        self.beta = beta
        self.mse = torch.nn.MSELoss()

    def forward(self, pred: torch.Tensor, target: torch.Tensor,
                current: torch.Tensor) -> torch.Tensor:
        """
        Args:
            pred: Predicted next price (batch, 1)
            target: Actual next price (batch, 1)
            current: Current price (batch,) - last value in input window
        """
        mse_loss = self.mse(pred, target)

        # Direction penalty
        pred_direction = torch.sign(pred.squeeze() - current)
        actual_direction = torch.sign(target.squeeze() - current)

        # 1 when directions match, 0 when they don't
        direction_match = (pred_direction == actual_direction).float()

        # Penalty for wrong direction (higher penalty)
        direction_penalty = 1 - direction_match.mean()

        return self.alpha * mse_loss + self.beta * direction_penalty


def create_dataloaders(
    data_path: Path,
    batch_size: int = BATCH_SIZE,
    val_split: float = 0.1
) -> tuple[DataLoader, DataLoader]:
    """Create train and validation DataLoaders."""
    dataset = PriceDataset(data_path, window_size=WINDOW_SIZE)

    # Split into train/val
    val_size = int(len(dataset) * val_split)
    train_size = len(dataset) - val_size
    train_dataset, val_dataset = random_split(dataset, [train_size, val_size])

    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False)

    return train_loader, val_loader


def clip_weights(model: QuantDLinear, max_weight: float = MAX_WEIGHT):
    """
    Clip weights to prevent accumulator overflow.

    For 64 elements and Int24 accumulator:
    - Max safe weight sum: 8388607 / 127 / 64 ≈ 1030 per weight
    - But we want margin, so clip to smaller values

    With max_weight=0.5 (in Q1.7 that's ~64):
    - Sum of 64 weights at 64 = 4096
    - Worst case: 4096 * 127 = 520,192 (well within Int24)
    """
    with torch.no_grad():
        for name, param in model.named_parameters():
            if 'weight' in name:
                # Clip to [-max_weight, max_weight] in float domain
                # Brevitas will then quantize
                param.clamp_(-max_weight, max_weight)


def get_weight_stats(model: QuantDLinear) -> dict:
    """Get statistics about model weights."""
    weights = model.get_quantized_weights()
    trend_w = weights['trend_w'].flatten()
    seas_w = weights['seas_w'].flatten()

    return {
        'trend_abssum': int(np.sum(np.abs(trend_w))),
        'trend_max': int(np.max(np.abs(trend_w))),
        'seas_abssum': int(np.sum(np.abs(seas_w))),
        'seas_max': int(np.max(np.abs(seas_w))),
        'worst_case': int(np.sum(np.abs(trend_w)) + np.sum(np.abs(seas_w))) * 127,
    }


def train_model(
    model: QuantDLinear,
    train_loader: DataLoader,
    val_loader: DataLoader = None,
    epochs: int = EPOCHS,
    lr: float = LEARNING_RATE,
    weight_decay: float = WEIGHT_DECAY,
    max_weight: float = MAX_WEIGHT,
    directional_loss: bool = False,
    device: str = 'cpu'
) -> dict:
    """
    Train the model using QAT (Quantization-Aware Training).

    Args:
        model: QuantDLinear model instance
        train_loader: Training data loader
        val_loader: Validation data loader (optional)
        epochs: Number of training epochs
        lr: Learning rate
        weight_decay: L2 regularization strength
        max_weight: Maximum weight magnitude (for clipping)
        directional_loss: Use direction-aware loss function
        device: Device to train on

    Returns:
        Dict with training history
    """
    model = model.to(device)

    # Adam with L2 regularization
    optimizer = torch.optim.Adam(
        model.parameters(),
        lr=lr,
        weight_decay=weight_decay  # L2 regularization
    )

    # Learning rate scheduler
    scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(
        optimizer, mode='min', factor=0.5, patience=10, verbose=True
    )

    # Use directional loss for better trading performance
    if directional_loss:
        criterion = DirectionalLoss(alpha=0.7, beta=0.3)
        print("Using DirectionalLoss (alpha=0.7, beta=0.3)")
    else:
        criterion = torch.nn.MSELoss()

    history = {
        'train_loss': [],
        'val_loss': [],
        'weight_stats': []
    }

    best_val_loss = float('inf')

    print(f"Training with L2 regularization (weight_decay={weight_decay})")
    print(f"Weight clipping at {max_weight}")
    print(f"Accumulator bits: {ACCUMULATOR_BITS}")
    print("")

    for epoch in range(epochs):
        # Training
        model.train()
        train_loss = 0.0
        n_batches = 0

        for x, y in train_loader:
            x, y = x.to(device), y.to(device)

            optimizer.zero_grad()
            pred = model(x)

            # Compute loss (directional loss needs current price)
            if directional_loss:
                current = x[:, -1]  # Last element of input window is current price
                loss = criterion(pred, y, current)
            else:
                loss = criterion(pred, y)

            loss.backward()
            optimizer.step()

            # Clip weights after each update
            clip_weights(model, max_weight)

            train_loss += loss.item()
            n_batches += 1

        avg_train_loss = train_loss / n_batches
        history['train_loss'].append(avg_train_loss)

        # Validation
        avg_val_loss = None
        if val_loader is not None:
            model.eval()
            val_loss = 0.0
            n_val = 0
            with torch.no_grad():
                for x, y in val_loader:
                    x, y = x.to(device), y.to(device)
                    pred = model(x)
                    if directional_loss:
                        current = x[:, -1]
                        val_loss += criterion(pred, y, current).item()
                    else:
                        val_loss += criterion(pred, y).item()
                    n_val += 1
            avg_val_loss = val_loss / n_val
            history['val_loss'].append(avg_val_loss)
            scheduler.step(avg_val_loss)

            if avg_val_loss < best_val_loss:
                best_val_loss = avg_val_loss

        # Weight statistics
        weight_stats = get_weight_stats(model)
        history['weight_stats'].append(weight_stats)

        # Logging
        if (epoch + 1) % 10 == 0 or epoch == 0:
            msg = f"Epoch {epoch+1:3d}/{epochs} | Train: {avg_train_loss:.6f}"
            if avg_val_loss is not None:
                msg += f" | Val: {avg_val_loss:.6f}"
            msg += f" | Worst-case acc: {weight_stats['worst_case']:,}"
            print(msg)

    print("")
    print(f"Training complete. Best val loss: {best_val_loss:.6f}")

    # Final weight analysis
    final_stats = get_weight_stats(model)
    int24_max = 2**23 - 1
    print(f"\nFinal weight statistics:")
    print(f"  Trend abssum: {final_stats['trend_abssum']} (max per weight: {final_stats['trend_max']})")
    print(f"  Seas abssum:  {final_stats['seas_abssum']} (max per weight: {final_stats['seas_max']})")
    print(f"  Worst-case accumulator: {final_stats['worst_case']:,}")
    print(f"  Int24 max: {int24_max:,}")
    print(f"  Overflow risk: {'HIGH!' if final_stats['worst_case'] > int24_max else 'OK'}")

    return history


def main():
    parser = argparse.ArgumentParser(description='Train quantized DLinear with regularization')
    parser.add_argument('--data', type=Path, default=Path('ai_model/data/ticks.parquet'))
    parser.add_argument('--epochs', type=int, default=EPOCHS)
    parser.add_argument('--output', type=Path, default=Path('ai_model/outputs'))
    parser.add_argument('--lr', type=float, default=LEARNING_RATE)
    parser.add_argument('--weight-decay', type=float, default=WEIGHT_DECAY)
    parser.add_argument('--max-weight', type=float, default=MAX_WEIGHT,
                        help='Maximum weight magnitude for clipping')
    parser.add_argument('--val-split', type=float, default=0.1)
    parser.add_argument('--directional-loss', action='store_true',
                        help='Use direction-aware loss function')
    args = parser.parse_args()

    # Create output directory
    args.output.mkdir(parents=True, exist_ok=True)

    # Initialize model
    model = QuantDLinear(
        window_size=WINDOW_SIZE,
        weight_bits=WEIGHT_BITS,
        act_bits=ACTIVATION_BITS
    )

    # Create dataloaders
    print(f"Loading data from {args.data}...")
    train_loader, val_loader = create_dataloaders(
        args.data, val_split=args.val_split
    )
    print(f"Train samples: {len(train_loader.dataset)}")
    print(f"Val samples: {len(val_loader.dataset)}")
    print("")

    # Train
    history = train_model(
        model, train_loader, val_loader,
        epochs=args.epochs,
        lr=args.lr,
        weight_decay=args.weight_decay,
        max_weight=args.max_weight,
        directional_loss=args.directional_loss
    )

    # Save model
    model_path = args.output / 'dlinear_quantized.pt'
    torch.save(model.state_dict(), model_path)
    print(f"\nModel saved to {model_path}")

    # Export weights
    from .export_weights import export_model_weights
    export_result = export_model_weights(model_path, args.output)
    print(f"Weights exported to {args.output}")


if __name__ == '__main__':
    main()
