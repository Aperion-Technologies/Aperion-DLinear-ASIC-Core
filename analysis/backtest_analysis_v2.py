#!/usr/bin/env python3
"""
analysis/backtest_analysis_v2.py
Corrected backtest analysis that matches TRAINING semantics.

The DLinear model was trained to:
- Input: 64 normalized price LEVELS
- Output: Predicted next normalized price LEVEL

Trading strategy:
- If predicted_price > last_input_price → expect price UP → Long
- If predicted_price < last_input_price → expect price DOWN → Short
- P&L = position * actual_price_change
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).parent.parent))

from ai_model.src.config import WINDOW_SIZE, FRAC_BITS, ACCUMULATOR_BITS
from analysis.risk_management import apply_risk_management, RiskConfig

plt.style.use('seaborn-v0_8-whitegrid')
plt.rcParams['figure.figsize'] = (14, 8)


def load_quant_params(path: Path) -> dict:
    """Load quantization parameters."""
    params = {}
    if path.exists():
        with open(path, 'r') as f:
            for line in f:
                if ':' in line and not line.startswith('#'):
                    key, value = line.split(':', 1)
                    try:
                        params[key.strip()] = float(value.strip())
                    except ValueError:
                        params[key.strip()] = value.strip()
    return params


def dequantize_prediction(prediction: np.ndarray,
                          mean: float, std: float,
                          rescale_factor: float,
                          frac_bits: int = FRAC_BITS) -> np.ndarray:
    """
    Convert ASIC output back to price level.

    The output is:
    1. Sum of MAC products (scaled by 2^(2*frac_bits))
    2. Represents a normalized price level

    To convert back:
    1. Divide by 2^(2*frac_bits) to get normalized value
    2. Divide by rescale_factor to undo pre-quantization scaling
    3. Multiply by std and add mean to get real price
    """
    # Undo fixed-point scaling
    fixed_scale = 2 ** (2 * frac_bits)
    normalized = prediction / fixed_scale

    # Undo rescale factor
    zscore = normalized / rescale_factor

    # Convert z-score back to price
    price = zscore * std + mean

    return price


def detect_overflow(predictions: np.ndarray, acc_bits: int = ACCUMULATOR_BITS) -> np.ndarray:
    """Detect overflow (saturation) events."""
    max_val = 2 ** (acc_bits - 1) - 1
    min_val = -(2 ** (acc_bits - 1))
    return (predictions >= max_val) | (predictions <= min_val)


def load_input_windows_last_value(hex_path: Path, frac_bits: int = FRAC_BITS) -> np.ndarray:
    """
    Load the LAST value of each input window from HEX file.

    This is the "current price" that we compare the prediction against.
    """
    last_values = []
    with open(hex_path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue

            # Parse hex line - each 2 chars is one Int8
            values = []
            for i in range(0, len(line), 2):
                byte = int(line[i:i+2], 16)
                if byte >= 128:
                    byte -= 256  # Convert to signed
                values.append(byte)

            # Get last value in window
            if values:
                last_values.append(values[-1])

    return np.array(last_values, dtype=np.float64)


def simulate_trading_v2(predicted_prices: np.ndarray,
                        last_input_prices: np.ndarray,
                        actual_prices: np.ndarray,
                        overflow_mask: np.ndarray,
                        threshold_pct: float = 0.0) -> pd.DataFrame:
    """
    Trading simulation based on price level prediction.

    Strategy:
    - If predicted > last_input (expect price UP): Long
    - If predicted < last_input (expect price DOWN): Short
    - P&L = position * (actual_next - actual_current)
    """
    n = min(len(predicted_prices), len(actual_prices) - 1)

    # Price direction signal
    expected_change = predicted_prices[:n] - last_input_prices[:n]

    # Apply threshold (as percentage of typical change)
    if threshold_pct > 0:
        threshold = threshold_pct * np.std(expected_change[~overflow_mask[:n]])
    else:
        threshold = 0

    signals = np.zeros(n)
    signals[expected_change > threshold] = 1   # Long
    signals[expected_change < -threshold] = -1  # Short
    signals[overflow_mask[:n]] = 0  # Skip overflow

    # Actual price changes
    actual_changes = np.diff(actual_prices[:n+1])

    # P&L
    pnl = signals * actual_changes

    return pd.DataFrame({
        'predicted_price': predicted_prices[:n],
        'last_input': last_input_prices[:n],
        'expected_change': expected_change,
        'actual_price': actual_prices[:n],
        'actual_change': actual_changes,
        'signal': signals,
        'overflow': overflow_mask[:n],
        'pnl': pnl,
        'cumulative_pnl': np.cumsum(pnl)
    })


def calculate_metrics(df: pd.DataFrame) -> dict:
    """Calculate trading metrics."""
    valid = (df['signal'] != 0) & (~df['overflow'])
    pnl = df['pnl'].values
    valid_pnl = pnl[valid]

    if len(valid_pnl) == 0:
        return {'error': 'No valid trades'}

    total_return = np.sum(pnl)
    win_rate = np.mean(valid_pnl > 0)

    # Sharpe (annualized for tick data)
    if np.std(pnl) > 0:
        sharpe = np.mean(pnl) / np.std(pnl) * np.sqrt(365 * 24 * 60 * 60 * 1000)
    else:
        sharpe = 0

    # Drawdown
    cumulative = np.cumsum(pnl)
    running_max = np.maximum.accumulate(cumulative)
    max_dd = np.max(running_max - cumulative)

    return {
        'total_return': total_return,
        'sharpe_ratio': sharpe,
        'max_drawdown': max_dd,
        'win_rate': win_rate,
        'num_trades': np.sum(valid),
        'num_overflow': np.sum(df['overflow']),
        'avg_pnl': np.mean(valid_pnl) if len(valid_pnl) > 0 else 0
    }


def calculate_prediction_accuracy(df: pd.DataFrame) -> dict:
    """Calculate prediction accuracy."""
    valid = (~df['overflow']) & (df['actual_change'] != 0)

    if np.sum(valid) == 0:
        return {'error': 'No valid samples'}

    expected = df.loc[valid, 'expected_change'].values
    actual = df.loc[valid, 'actual_change'].values

    # Direction accuracy
    direction_acc = np.mean(np.sign(expected) == np.sign(actual))

    # Correlation
    if np.std(expected) > 0 and np.std(actual) > 0:
        corr = np.corrcoef(expected, actual)[0, 1]
    else:
        corr = 0

    return {
        'direction_accuracy': direction_acc,
        'correlation': corr,
        'valid_samples': np.sum(valid)
    }


def run_risk_managed_backtest(
    predicted_prices: np.ndarray,
    last_inputs: np.ndarray,
    actual_prices: np.ndarray,
    overflow_mask: np.ndarray
) -> dict:
    """
    Run backtest with risk management.
    """
    # Ensure all arrays have same length (use length of predictions)
    n = len(predicted_prices)
    last_inputs = last_inputs[:n]
    actual_prices = actual_prices[:n + 1]  # Need n+1 for P&L calc
    overflow_mask = overflow_mask[:n]

    # Filter out overflow predictions
    valid = ~overflow_mask

    config = RiskConfig(
        max_position_pct=0.02,
        stop_loss_pct=0.01,
        take_profit_pct=0.03,
        max_drawdown_pct=0.10,
        confidence_threshold=0.1
    )

    result = apply_risk_management(
        predictions=predicted_prices[valid],
        last_inputs=last_inputs[valid],
        actual_prices=actual_prices[:sum(valid) + 1],
        config=config
    )

    return result


def plot_results(df: pd.DataFrame, metrics: dict, accuracy: dict, save_path: Path = None):
    """Create visualization."""
    fig, axes = plt.subplots(2, 2, figsize=(16, 10))

    # 1. Equity curve
    ax1 = axes[0, 0]
    pnl = df['cumulative_pnl'].values
    ax1.plot(pnl, color='blue', linewidth=1)
    ax1.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax1.fill_between(range(len(pnl)), pnl, 0, where=pnl >= 0, color='green', alpha=0.3)
    ax1.fill_between(range(len(pnl)), pnl, 0, where=pnl < 0, color='red', alpha=0.3)
    ax1.set_title('Equity Curve (Price Level Prediction)', fontsize=12, fontweight='bold')
    ax1.set_xlabel('Tick')
    ax1.set_ylabel('Cumulative P&L')

    # 2. Expected vs Actual change scatter
    ax2 = axes[0, 1]
    valid = (~df['overflow']) & (df['actual_change'] != 0)
    if valid.sum() > 0:
        exp = df.loc[valid, 'expected_change'].values[:500]
        act = df.loc[valid, 'actual_change'].values[:500]
        ax2.scatter(exp, act, alpha=0.3, s=10)
        ax2.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
        ax2.axvline(x=0, color='gray', linestyle='--', alpha=0.5)
        # Quadrant colors
        ax2.axhspan(0, ax2.get_ylim()[1], 0, 0.5, alpha=0.1, color='red')    # Q2: wrong
        ax2.axhspan(0, ax2.get_ylim()[1], 0.5, 1, alpha=0.1, color='green')  # Q1: correct
    ax2.set_title('Expected vs Actual Price Change', fontsize=12)
    ax2.set_xlabel('Predicted Change')
    ax2.set_ylabel('Actual Change')

    # 3. Signal distribution
    ax3 = axes[1, 0]
    signals = df['signal'].values
    ax3.hist(signals[signals != 0], bins=3, color='steelblue', edgecolor='black')
    ax3.set_title('Signal Distribution', fontsize=12)
    ax3.set_xlabel('Signal (-1=Short, 1=Long)')
    ax3.set_ylabel('Count')

    # 4. Metrics
    ax4 = axes[1, 1]
    ax4.axis('off')

    text = [
        "=" * 45,
        "TRADING METRICS (Price Level Strategy)",
        "=" * 45,
        f"Total Return:      {metrics.get('total_return', 0):.8f}",
        f"Sharpe Ratio:      {metrics.get('sharpe_ratio', 0):.2f}",
        f"Max Drawdown:      {metrics.get('max_drawdown', 0):.8f}",
        f"Win Rate:          {metrics.get('win_rate', 0)*100:.1f}%",
        f"Trades:            {metrics.get('num_trades', 0)}",
        f"Overflow:          {metrics.get('num_overflow', 0)}",
        "",
        "=" * 45,
        "PREDICTION ACCURACY",
        "=" * 45,
        f"Direction Acc:     {accuracy.get('direction_accuracy', 0)*100:.1f}%",
        f"Correlation:       {accuracy.get('correlation', 0):.4f}",
        f"Valid Samples:     {accuracy.get('valid_samples', 0)}",
    ]

    ax4.text(0.1, 0.95, '\n'.join(text), transform=ax4.transAxes,
             fontsize=11, verticalalignment='top', fontfamily='monospace',
             bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

    plt.suptitle('DLinear ASIC Backtest v2 - Price Level Prediction\n'
                 'Model predicts next PRICE, not return',
                 fontsize=14, fontweight='bold')
    plt.tight_layout()

    if save_path:
        plt.savefig(save_path, dpi=150, bbox_inches='tight')
        print(f"Saved to {save_path}")

    plt.show()


def main():
    project_root = Path(__file__).parent.parent

    predictions_path = project_root / 'verification' / 'outputs' / 'asic_predictions.csv'
    market_input_path = project_root / 'ai_model' / 'outputs' / 'market_input.hex'
    target_prices_path = project_root / 'ai_model' / 'outputs' / 'target_prices.csv'
    quant_params_path = project_root / 'ai_model' / 'outputs' / 'quant_params.txt'
    output_dir = project_root / 'analysis' / 'figures'
    output_dir.mkdir(parents=True, exist_ok=True)

    print("=" * 60)
    print("DLinear ASIC Backtest v2 - Price Level Prediction")
    print("=" * 60)

    # Load predictions
    if not predictions_path.exists():
        print(f"ERROR: {predictions_path} not found")
        return
    df_pred = pd.read_csv(predictions_path)
    print(f"Loaded {len(df_pred)} predictions")

    # Load params
    params = load_quant_params(quant_params_path)
    print(f"Params: {params}")

    # Check which version of data prep was used
    normalization = params.get('normalization', 'unknown')
    if normalization != 'zscore':
        print("\n" + "!" * 60)
        print("WARNING: Data was prepared with OLD format (price differences)")
        print("The model expects PRICE LEVELS, not differences!")
        print("Run: python -m ai_model.src.prepare_market_data_v2 --csv trades.csv")
        print("!" * 60)

        # Try to continue with what we have
        mean = params.get('mean', 0)
        std = params.get('std', 1)
        rescale = params.get('rescale_factor', 0.25)
        print(f"\nUsing fallback params: mean={mean}, std={std}, rescale={rescale}")
    else:
        mean = params.get('mean', 0)
        std = params.get('std', 1)
        rescale = params.get('rescale_factor', 0.25)

    # Detect overflow
    raw_preds = df_pred['prediction'].values
    overflow = detect_overflow(raw_preds)
    print(f"Overflow: {np.sum(overflow)} ({100*np.sum(overflow)/len(overflow):.1f}%)")

    # Dequantize to price levels
    pred_prices = dequantize_prediction(raw_preds, mean, std, rescale)
    print(f"Predicted prices: [{pred_prices.min():.6f}, {pred_prices.max():.6f}]")

    # Load last input values (current price from model's perspective)
    if market_input_path.exists():
        last_inputs_q = load_input_windows_last_value(market_input_path)
        # Dequantize last inputs
        last_inputs = last_inputs_q / (2**FRAC_BITS) / rescale * std + mean
        print(f"Last inputs: [{last_inputs.min():.6f}, {last_inputs.max():.6f}]")
    else:
        print("WARNING: No market_input.hex, using predicted prices shifted")
        last_inputs = np.roll(pred_prices, 1)
        last_inputs[0] = pred_prices[0]

    # Load actual prices for P&L
    if target_prices_path.exists():
        actual_prices = np.loadtxt(target_prices_path)
        print(f"Actual prices: [{actual_prices.min():.6f}, {actual_prices.max():.6f}]")
    else:
        # Fallback: use predicted prices (won't give meaningful P&L)
        print("WARNING: No target_prices.csv, using predictions (P&L will be zero)")
        actual_prices = pred_prices.copy()

    # Run trading simulation
    df_trading = simulate_trading_v2(
        pred_prices, last_inputs, actual_prices, overflow
    )

    # Calculate metrics
    metrics = calculate_metrics(df_trading)
    accuracy = calculate_prediction_accuracy(df_trading)

    print("\n" + "=" * 40)
    print("RESULTS")
    print("=" * 40)
    for k, v in {**metrics, **accuracy}.items():
        if isinstance(v, float):
            print(f"  {k}: {v:.6f}")
        else:
            print(f"  {k}: {v}")

    # Risk-managed backtest
    print("\n" + "=" * 40)
    print("RISK-MANAGED BACKTEST")
    print("=" * 40)

    rm_result = run_risk_managed_backtest(
        pred_prices, last_inputs, actual_prices, overflow
    )

    for k, v in rm_result['metrics'].items():
        if isinstance(v, float):
            print(f"  {k}: {v:.6f}")
        else:
            print(f"  {k}: {v}")

    # Save and plot
    df_trading.to_csv(output_dir / 'backtest_v2_results.csv', index=False)
    plot_results(df_trading, metrics, accuracy, output_dir / 'equity_curve_v2.png')


if __name__ == '__main__':
    main()
