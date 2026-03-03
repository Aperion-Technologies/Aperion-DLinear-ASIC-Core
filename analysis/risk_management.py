#!/usr/bin/env python3
"""
analysis/risk_management.py
Risk management layer for DLinear ASIC trading.

Implements:
- Position sizing based on signal confidence
- Maximum position limits
- Stop-loss and take-profit
- Drawdown limits
"""

import numpy as np
from dataclasses import dataclass
from typing import Optional


@dataclass
class RiskConfig:
    """Risk management configuration."""
    max_position_pct: float = 0.02    # Max 2% of portfolio per trade
    stop_loss_pct: float = 0.01       # 1% stop-loss
    take_profit_pct: float = 0.03     # 3% take-profit
    max_drawdown_pct: float = 0.10    # 10% max drawdown before reducing size
    confidence_threshold: float = 0.1 # Min signal strength to trade
    leverage: float = 1.0             # No leverage by default


class RiskManager:
    """
    Risk management for ASIC trading signals.

    Converts raw predictions to risk-adjusted positions.
    """

    def __init__(self, config: RiskConfig = None, initial_capital: float = 100000):
        self.config = config or RiskConfig()
        self.initial_capital = initial_capital
        self.capital = initial_capital
        self.position = 0.0
        self.entry_price = 0.0
        self.peak_capital = initial_capital
        self.trades = []

    def calculate_signal_confidence(
        self,
        prediction: float,
        last_input: float,
        volatility: float
    ) -> float:
        """
        Calculate signal confidence from prediction.

        Higher confidence = larger expected move relative to volatility.
        """
        expected_change = abs(prediction - last_input)
        if volatility == 0:
            return 0.0

        # Normalize by volatility
        confidence = expected_change / volatility

        # Clip to [0, 1]
        return min(1.0, confidence)

    def calculate_position_size(
        self,
        signal: int,  # 1 = long, -1 = short, 0 = flat
        confidence: float,
        current_price: float
    ) -> float:
        """
        Calculate position size based on signal and risk limits.

        Args:
            signal: Direction (-1, 0, 1)
            confidence: Signal confidence [0, 1]
            current_price: Current asset price

        Returns:
            Position size (negative for short)
        """
        if signal == 0 or confidence < self.config.confidence_threshold:
            return 0.0

        # Check drawdown limit
        current_dd = (self.peak_capital - self.capital) / self.peak_capital
        if current_dd > self.config.max_drawdown_pct:
            # Reduce position size when in drawdown
            size_multiplier = 0.5
        else:
            size_multiplier = 1.0

        # Calculate max position value
        max_position_value = self.capital * self.config.max_position_pct * self.config.leverage

        # Scale by confidence
        position_value = max_position_value * confidence * size_multiplier

        # Convert to units
        position_units = position_value / current_price

        return signal * position_units

    def check_stop_loss(self, current_price: float) -> bool:
        """Check if stop-loss triggered."""
        if self.position == 0:
            return False

        if self.position > 0:  # Long
            loss_pct = (self.entry_price - current_price) / self.entry_price
        else:  # Short
            loss_pct = (current_price - self.entry_price) / self.entry_price

        return loss_pct > self.config.stop_loss_pct

    def check_take_profit(self, current_price: float) -> bool:
        """Check if take-profit triggered."""
        if self.position == 0:
            return False

        if self.position > 0:  # Long
            profit_pct = (current_price - self.entry_price) / self.entry_price
        else:  # Short
            profit_pct = (self.entry_price - current_price) / self.entry_price

        return profit_pct > self.config.take_profit_pct

    def execute_trade(
        self,
        prediction: float,
        last_input: float,
        current_price: float,
        actual_next_price: float,
        volatility: float = 0.01
    ) -> dict:
        """
        Execute one trading step with risk management.

        Returns:
            Dict with trade details and P&L
        """
        # Check existing position for stop/take-profit
        if self.position != 0:
            if self.check_stop_loss(current_price):
                # Close position (stop-loss)
                pnl = self.position * (current_price - self.entry_price)
                self.capital += pnl
                self.trades.append({
                    'type': 'stop_loss',
                    'pnl': pnl,
                    'capital': self.capital
                })
                self.position = 0
                self.entry_price = 0
            elif self.check_take_profit(current_price):
                # Close position (take-profit)
                pnl = self.position * (current_price - self.entry_price)
                self.capital += pnl
                self.trades.append({
                    'type': 'take_profit',
                    'pnl': pnl,
                    'capital': self.capital
                })
                self.position = 0
                self.entry_price = 0

        # Generate new signal
        signal = 1 if prediction > last_input else -1
        confidence = self.calculate_signal_confidence(prediction, last_input, volatility)

        # Calculate position size
        new_position = self.calculate_position_size(signal, confidence, current_price)

        # If position changes, close old and open new
        if (new_position > 0 and self.position <= 0) or (new_position < 0 and self.position >= 0):
            # Close old position
            if self.position != 0:
                pnl = self.position * (current_price - self.entry_price)
                self.capital += pnl

            # Open new position
            self.position = new_position
            self.entry_price = current_price

        # Calculate unrealized P&L
        if self.position != 0:
            unrealized_pnl = self.position * (actual_next_price - self.entry_price)
        else:
            unrealized_pnl = 0

        # Update peak capital
        self.peak_capital = max(self.peak_capital, self.capital)

        return {
            'signal': signal,
            'confidence': confidence,
            'position': self.position,
            'unrealized_pnl': unrealized_pnl,
            'capital': self.capital,
            'drawdown': (self.peak_capital - self.capital) / self.peak_capital
        }

    def get_metrics(self) -> dict:
        """Calculate final trading metrics."""
        if len(self.trades) == 0:
            return {'error': 'No trades'}

        pnls = [t['pnl'] for t in self.trades if 'pnl' in t]

        total_return = (self.capital - self.initial_capital) / self.initial_capital

        if len(pnls) > 0 and np.std(pnls) > 0:
            sharpe = np.mean(pnls) / np.std(pnls) * np.sqrt(252 * 24 * 60)
        else:
            sharpe = 0

        win_rate = np.mean([p > 0 for p in pnls]) if len(pnls) > 0 else 0

        return {
            'total_return': total_return,
            'sharpe_ratio': sharpe,
            'win_rate': win_rate,
            'num_trades': len(pnls),
            'final_capital': self.capital,
            'max_drawdown': (self.peak_capital - min(t['capital'] for t in self.trades)) / self.peak_capital if self.trades else 0
        }


def apply_risk_management(
    predictions: np.ndarray,
    last_inputs: np.ndarray,
    actual_prices: np.ndarray,
    config: RiskConfig = None
) -> dict:
    """
    Apply risk management to prediction array.

    Args:
        predictions: ASIC predictions (dequantized to price levels)
        last_inputs: Last input value for each prediction (current price)
        actual_prices: Actual prices for P&L calculation
        config: Risk configuration

    Returns:
        Dict with P&L series and metrics
    """
    rm = RiskManager(config, initial_capital=100000)

    # Estimate volatility
    price_changes = np.diff(actual_prices)
    volatility = np.std(price_changes) if len(price_changes) > 1 else 0.01

    results = []
    n = min(len(predictions), len(actual_prices) - 1)

    for i in range(n):
        result = rm.execute_trade(
            prediction=predictions[i],
            last_input=last_inputs[i],
            current_price=actual_prices[i],
            actual_next_price=actual_prices[i + 1],
            volatility=volatility
        )
        results.append(result)

    metrics = rm.get_metrics()

    return {
        'results': results,
        'metrics': metrics,
        'capital_history': [r['capital'] for r in results]
    }
