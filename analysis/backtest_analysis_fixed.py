#!/usr/bin/env python3
"""
analysis/backtest_analysis_fixed.py
Fixed backtest analysis with proper dequantization and P&L calculation.

Key fixes:
1. Dequantize ASIC predictions to real price scale
2. Use actual price movements for P&L (not prediction deltas)
3. Exclude overflow-saturated predictions
4. Proper signal thresholds based on normalized predictions
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import sys

# Add project paths
sys.path.insert(0, str(Path(__file__).parent.parent))

from ai_model.src.config import WINDOW_SIZE, FRAC_BITS, ACCUMULATOR_BITS

# Set style
plt.style.use('seaborn-v0_8-whitegrid')
plt.rcParams['figure.figsize'] = (14, 8)
plt.rcParams['font.size'] = 11


def load_quant_params(path: Path) -> dict:
    """Load quantization parameters from file."""
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


def load_market_prices(csv_path: Path, max_rows: int = None) -> np.ndarray:
    """Load actual market prices from trades.csv."""
    df = pd.read_csv(csv_path, nrows=max_rows, usecols=['price'])
    return df['price'].values


def dequantize_predictions(predictions: np.ndarray,
                           quant_scale: float,
                           frac_bits: int = FRAC_BITS) -> np.ndarray:
    """
    Dequantize ASIC predictions back to price difference scale.

    The ASIC output is:
    - Sum of 64 products: sum(input[i] * weight[i])
    - Each input is Q1.7 (scaled by 2^7 = 128)
    - Each weight is Q1.7 (scaled by 2^7 = 128)
    - Product scale: 2^14 = 16384
    - After reduceTree sum: still scaled by 2^14

    To convert back to price difference:
    1. Divide by 2^(2*frac_bits) to undo fixed-point scaling
    2. Multiply by quant_scale to get real price units

    Args:
        predictions: Raw Int16 ASIC outputs
        quant_scale: Price normalization scale (3*std of price diffs)
        frac_bits: Fractional bits used in quantization

    Returns:
        Price differences in real units
    """
    # Undo fixed-point scaling: 2^14 for Q1.7 * Q1.7
    fixed_point_scale = 2 ** (2 * frac_bits)

    # Convert to normalized [-1, 1] range, then to real price diff
    normalized = predictions / fixed_point_scale
    price_diffs = normalized * quant_scale

    return price_diffs


def detect_overflow(predictions: np.ndarray,
                    acc_bits: int = ACCUMULATOR_BITS) -> np.ndarray:
    """
    Detect overflow (saturation) events.

    Returns boolean array: True where overflow occurred.
    """
    max_val = 2 ** (acc_bits - 1) - 1   # 32767
    min_val = -(2 ** (acc_bits - 1))    # -32768

    return (predictions >= max_val) | (predictions <= min_val)


def simulate_trading_fixed(predictions_dequant: np.ndarray,
                           actual_prices: np.ndarray,
                           start_idx: int,
                           overflow_mask: np.ndarray,
                           threshold_pct: float = 0.0,
                           position_size: float = 1.0) -> pd.DataFrame:
    """
    Fixed trading simulation using actual price movements.

    Strategy:
    - If prediction > threshold: expect price UP -> Long
    - If prediction < -threshold: expect price DOWN -> Short
    - Skip predictions with overflow (unreliable)

    P&L calculated from ACTUAL price movements, not prediction deltas.

    Args:
        predictions_dequant: Dequantized predictions (price diff units)
        actual_prices: Real market prices
        start_idx: Starting index in actual_prices for predictions
        overflow_mask: Boolean array, True where overflow occurred
        threshold_pct: Threshold as fraction of prediction std
        position_size: Size of position (default 1 unit)

    Returns:
        DataFrame with trading results
    """
    n = len(predictions_dequant)

    # Align predictions with future price changes
    # prediction[i] predicts price change from tick (start_idx + i + WINDOW_SIZE)
    # to tick (start_idx + i + WINDOW_SIZE + 1)

    # Calculate actual future returns
    actual_returns = np.zeros(n)
    for i in range(n - 1):
        price_idx = start_idx + WINDOW_SIZE + i
        if price_idx + 1 < len(actual_prices):
            actual_returns[i] = actual_prices[price_idx + 1] - actual_prices[price_idx]

    # Calculate threshold from prediction distribution (excluding overflow)
    valid_preds = predictions_dequant[~overflow_mask]
    if len(valid_preds) > 0:
        threshold = threshold_pct * np.std(valid_preds)
    else:
        threshold = 0.0

    # Generate signals
    signals = np.zeros(n)
    signals[predictions_dequant > threshold] = 1    # Long
    signals[predictions_dequant < -threshold] = -1  # Short

    # Zero out signals where overflow occurred (unreliable predictions)
    signals[overflow_mask] = 0

    # Calculate P&L: signal * actual_return
    pnl = signals * actual_returns * position_size

    # Cumulative P&L
    cumulative_pnl = np.cumsum(pnl)

    return pd.DataFrame({
        'prediction_raw': predictions_dequant,
        'actual_return': actual_returns,
        'signal': signals,
        'overflow': overflow_mask,
        'pnl': pnl,
        'cumulative_pnl': cumulative_pnl
    })


def calculate_metrics(trading_df: pd.DataFrame) -> dict:
    """Calculate comprehensive trading metrics."""
    pnl = trading_df['pnl'].values
    signals = trading_df['signal'].values
    overflow = trading_df['overflow'].values

    # Filter valid trades (non-zero signal, no overflow)
    valid_trades = (signals != 0) & (~overflow)
    valid_pnl = pnl[valid_trades]

    if len(valid_pnl) == 0:
        return {'error': 'No valid trades'}

    # Basic stats
    total_return = np.sum(pnl)
    win_rate = np.mean(valid_pnl > 0) if len(valid_pnl) > 0 else 0

    # Sharpe ratio (assuming ~1 trade per tick, annualize for HFT)
    # At 1 tick per ms, ~31.5B ticks per year
    ticks_per_year = 365 * 24 * 60 * 60 * 1000
    if np.std(pnl) > 0:
        sharpe = np.mean(pnl) / np.std(pnl) * np.sqrt(ticks_per_year)
    else:
        sharpe = 0

    # Max drawdown
    cumulative = np.cumsum(pnl)
    running_max = np.maximum.accumulate(cumulative)
    drawdown = running_max - cumulative
    max_drawdown = np.max(drawdown) if len(drawdown) > 0 else 0

    # Trade statistics
    num_trades = np.sum(valid_trades)
    num_overflow = np.sum(overflow)

    return {
        'total_return': total_return,
        'sharpe_ratio': sharpe,
        'max_drawdown': max_drawdown,
        'win_rate': win_rate,
        'num_trades': num_trades,
        'num_overflow': num_overflow,
        'overflow_pct': 100 * num_overflow / len(overflow),
        'avg_pnl_per_trade': np.mean(valid_pnl) if len(valid_pnl) > 0 else 0
    }


def calculate_prediction_accuracy(predictions_dequant: np.ndarray,
                                   actual_returns: np.ndarray,
                                   overflow_mask: np.ndarray) -> dict:
    """
    Calculate prediction accuracy metrics.

    Compares predicted direction with actual price movement.
    """
    # Filter out overflow
    valid = ~overflow_mask & (actual_returns != 0)

    if np.sum(valid) == 0:
        return {'error': 'No valid samples'}

    pred_valid = predictions_dequant[valid]
    actual_valid = actual_returns[valid]

    # Direction accuracy: did we predict the right sign?
    pred_sign = np.sign(pred_valid)
    actual_sign = np.sign(actual_valid)
    direction_accuracy = np.mean(pred_sign == actual_sign)

    # Correlation
    if np.std(pred_valid) > 0 and np.std(actual_valid) > 0:
        correlation = np.corrcoef(pred_valid, actual_valid)[0, 1]
    else:
        correlation = 0

    # MSE (in price units)
    mse = np.mean((pred_valid - actual_valid) ** 2)

    return {
        'direction_accuracy': direction_accuracy,
        'correlation': correlation,
        'mse': mse,
        'rmse': np.sqrt(mse),
        'valid_samples': np.sum(valid)
    }


def plot_results(trading_df: pd.DataFrame,
                 metrics: dict,
                 accuracy: dict,
                 save_path: Path = None):
    """Create comprehensive visualization."""
    fig, axes = plt.subplots(3, 2, figsize=(16, 12))

    # 1. Equity Curve
    ax1 = axes[0, 0]
    pnl = trading_df['cumulative_pnl'].values
    ax1.plot(pnl, color='blue', linewidth=1, alpha=0.8)
    ax1.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax1.fill_between(range(len(pnl)), pnl, 0,
                     where=pnl >= 0, color='green', alpha=0.3)
    ax1.fill_between(range(len(pnl)), pnl, 0,
                     where=pnl < 0, color='red', alpha=0.3)
    ax1.set_title('Equity Curve (Fixed Analysis)', fontsize=12, fontweight='bold')
    ax1.set_xlabel('Tick')
    ax1.set_ylabel('Cumulative P&L')

    # 2. Prediction Distribution
    ax2 = axes[0, 1]
    valid_preds = trading_df.loc[~trading_df['overflow'], 'prediction_raw']
    if len(valid_preds) > 0:
        ax2.hist(valid_preds, bins=50, color='steelblue', alpha=0.7, edgecolor='black')
    ax2.axvline(x=0, color='red', linestyle='--', linewidth=2)
    ax2.set_title('Prediction Distribution (excl. overflow)', fontsize=12)
    ax2.set_xlabel('Predicted Price Change')
    ax2.set_ylabel('Frequency')

    # 3. Signals Over Time
    ax3 = axes[1, 0]
    signals = trading_df['signal'].values
    overflow = trading_df['overflow'].values
    ax3.fill_between(range(len(signals)), signals, 0,
                     where=signals > 0, color='green', alpha=0.5, label='Long')
    ax3.fill_between(range(len(signals)), signals, 0,
                     where=signals < 0, color='red', alpha=0.5, label='Short')
    # Mark overflow regions
    ax3.fill_between(range(len(signals)), 1, -1,
                     where=overflow, color='orange', alpha=0.3, label='Overflow')
    ax3.set_ylim(-1.5, 1.5)
    ax3.set_title('Trading Signals', fontsize=12)
    ax3.set_xlabel('Tick')
    ax3.set_ylabel('Signal')
    ax3.legend(loc='upper right')

    # 4. Prediction vs Actual Scatter
    ax4 = axes[1, 1]
    valid = ~trading_df['overflow'] & (trading_df['actual_return'] != 0)
    if valid.sum() > 0:
        pred = trading_df.loc[valid, 'prediction_raw'].values[:1000]  # Limit points
        actual = trading_df.loc[valid, 'actual_return'].values[:1000]
        ax4.scatter(pred, actual, alpha=0.3, s=10, c='steelblue')
        # Add trend line
        if len(pred) > 1:
            z = np.polyfit(pred, actual, 1)
            p = np.poly1d(z)
            x_line = np.linspace(pred.min(), pred.max(), 100)
            ax4.plot(x_line, p(x_line), 'r--', linewidth=2, label=f'Trend')
    ax4.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax4.axvline(x=0, color='gray', linestyle='--', alpha=0.5)
    ax4.set_title('Prediction vs Actual Returns', fontsize=12)
    ax4.set_xlabel('Predicted')
    ax4.set_ylabel('Actual')

    # 5. Rolling P&L
    ax5 = axes[2, 0]
    window = min(100, len(trading_df) // 10)
    if window > 0:
        rolling_pnl = trading_df['pnl'].rolling(window=window).sum()
        ax5.plot(rolling_pnl, color='purple', linewidth=1)
        ax5.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax5.set_title(f'Rolling P&L (window={window})', fontsize=12)
    ax5.set_xlabel('Tick')
    ax5.set_ylabel('P&L')

    # 6. Metrics Summary
    ax6 = axes[2, 1]
    ax6.axis('off')

    metrics_text = [
        "═" * 40,
        "TRADING METRICS",
        "═" * 40,
        f"Total Return:     {metrics.get('total_return', 0):.6f}",
        f"Sharpe Ratio:     {metrics.get('sharpe_ratio', 0):.2f}",
        f"Max Drawdown:     {metrics.get('max_drawdown', 0):.6f}",
        f"Win Rate:         {metrics.get('win_rate', 0)*100:.1f}%",
        f"Num Trades:       {metrics.get('num_trades', 0)}",
        f"Overflow Events:  {metrics.get('num_overflow', 0)} ({metrics.get('overflow_pct', 0):.1f}%)",
        "",
        "═" * 40,
        "PREDICTION ACCURACY",
        "═" * 40,
        f"Direction Acc:    {accuracy.get('direction_accuracy', 0)*100:.1f}%",
        f"Correlation:      {accuracy.get('correlation', 0):.4f}",
        f"RMSE:             {accuracy.get('rmse', 0):.8f}",
        f"Valid Samples:    {accuracy.get('valid_samples', 0)}",
    ]

    ax6.text(0.1, 0.95, '\n'.join(metrics_text), transform=ax6.transAxes,
             fontsize=11, verticalalignment='top', fontfamily='monospace',
             bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

    plt.suptitle('DLinear ASIC Backtest - Fixed Analysis\n'
                 '"Backtested with Cycle-Accurate ASIC Simulator"',
                 fontsize=14, fontweight='bold', y=1.02)

    plt.tight_layout()

    if save_path:
        plt.savefig(save_path, dpi=150, bbox_inches='tight')
        print(f"Saved figure to {save_path}")

    plt.show()


def main():
    """Run fixed backtest analysis."""
    project_root = Path(__file__).parent.parent

    # Paths
    predictions_path = project_root / 'verification' / 'outputs' / 'asic_predictions.csv'
    market_data_path = project_root / 'trades.csv'
    quant_params_path = project_root / 'ai_model' / 'outputs' / 'quant_params.txt'
    output_dir = project_root / 'analysis' / 'figures'
    output_dir.mkdir(parents=True, exist_ok=True)

    print("=" * 60)
    print("DLinear ASIC Backtest - FIXED Analysis")
    print("=" * 60)

    # Load predictions
    if not predictions_path.exists():
        print(f"ERROR: {predictions_path} not found")
        print("Run: cd verification && make market")
        return

    df_pred = pd.read_csv(predictions_path)
    print(f"\nLoaded {len(df_pred)} predictions")

    # Load quant params
    quant_params = load_quant_params(quant_params_path)
    print(f"Quant params: {quant_params}")

    quant_scale = quant_params.get('scale', 1e-6)
    print(f"Using quant_scale: {quant_scale}")

    # Load actual market prices
    if not market_data_path.exists():
        print(f"WARNING: {market_data_path} not found, using synthetic returns")
        actual_prices = None
    else:
        actual_prices = load_market_prices(market_data_path)
        print(f"Loaded {len(actual_prices)} market prices")
        print(f"Price range: {actual_prices.min():.6f} - {actual_prices.max():.6f}")

    # Extract raw predictions
    raw_predictions = df_pred['prediction'].values

    # Detect overflow
    overflow_mask = detect_overflow(raw_predictions)
    num_overflow = np.sum(overflow_mask)
    print(f"\nOverflow events: {num_overflow} ({100*num_overflow/len(raw_predictions):.1f}%)")

    # Dequantize predictions
    predictions_dequant = dequantize_predictions(raw_predictions, quant_scale)
    print(f"Dequantized prediction range: [{predictions_dequant.min():.8f}, {predictions_dequant.max():.8f}]")

    # Run trading simulation
    if actual_prices is not None:
        trading_df = simulate_trading_fixed(
            predictions_dequant,
            actual_prices,
            start_idx=0,
            overflow_mask=overflow_mask,
            threshold_pct=0.0,  # No threshold - trade every signal
            position_size=1.0
        )
    else:
        print("WARNING: No actual prices, using prediction-based returns (not recommended)")
        # Fallback: use predicted returns as actual (for demo only)
        trading_df = pd.DataFrame({
            'prediction_raw': predictions_dequant,
            'actual_return': np.concatenate([[0], np.diff(predictions_dequant)]),
            'signal': np.sign(predictions_dequant),
            'overflow': overflow_mask,
            'pnl': np.sign(predictions_dequant) * np.concatenate([[0], np.diff(predictions_dequant)]),
            'cumulative_pnl': np.zeros(len(predictions_dequant))
        })
        trading_df['cumulative_pnl'] = trading_df['pnl'].cumsum()

    # Calculate metrics
    metrics = calculate_metrics(trading_df)
    print("\n" + "=" * 40)
    print("TRADING METRICS")
    print("=" * 40)
    for k, v in metrics.items():
        if isinstance(v, float):
            print(f"  {k}: {v:.6f}")
        else:
            print(f"  {k}: {v}")

    # Calculate prediction accuracy
    accuracy = calculate_prediction_accuracy(
        predictions_dequant,
        trading_df['actual_return'].values,
        overflow_mask
    )
    print("\n" + "=" * 40)
    print("PREDICTION ACCURACY")
    print("=" * 40)
    for k, v in accuracy.items():
        if isinstance(v, float):
            print(f"  {k}: {v:.6f}")
        else:
            print(f"  {k}: {v}")

    # Save results
    results_path = output_dir / 'backtest_results_fixed.csv'
    trading_df.to_csv(results_path, index=False)
    print(f"\nSaved detailed results to {results_path}")

    # Plot
    plot_results(trading_df, metrics, accuracy,
                 save_path=output_dir / 'equity_curve_fixed.png')

    # Final summary
    print("\n" + "=" * 60)
    print("ANALYSIS COMPLETE")
    print("=" * 60)

    if metrics.get('overflow_pct', 0) > 5:
        print("\n⚠️  HIGH OVERFLOW RATE DETECTED!")
        print("   This indicates accumulator saturation in the ASIC.")
        print("   Possible fixes:")
        print("   1. Reduce weight magnitudes during training")
        print("   2. Increase ACCUMULATOR_BITS in config.py")
        print("   3. Add output scaling/shift in hardware")

    if accuracy.get('direction_accuracy', 0) < 0.52:
        print("\n⚠️  LOW DIRECTION ACCURACY!")
        print("   The model is not predicting price direction well.")
        print("   This could be due to:")
        print("   1. Model undertrained")
        print("   2. Quantization errors")
        print("   3. Market data too noisy")


if __name__ == '__main__':
    main()
