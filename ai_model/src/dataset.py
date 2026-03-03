# ai_model/src/dataset.py
"""
PyTorch Dataset for time series prediction.
"""

import torch
from torch.utils.data import Dataset
import pandas as pd
import numpy as np
from pathlib import Path

from .config import WINDOW_SIZE, PREDICTION_HORIZON


class PriceDataset(Dataset):
    """
    Dataset that creates (input_window, target) pairs from price series.

    Input: Last WINDOW_SIZE prices
    Target: Price at PREDICTION_HORIZON ticks ahead
    """

    def __init__(
        self,
        data_path: Path,
        window_size: int = WINDOW_SIZE,
        horizon: int = PREDICTION_HORIZON,
        normalize: bool = True
    ):
        self.window_size = window_size
        self.horizon = horizon

        # Load data
        df = pd.read_parquet(data_path)
        self.prices = df['price'].values.astype(np.float32)

        # Normalize to zero mean, unit variance for stable training
        if normalize:
            self.mean = self.prices.mean()
            self.std = self.prices.std()
            self.prices = (self.prices - self.mean) / self.std
        else:
            self.mean = 0.0
            self.std = 1.0

        # Number of valid samples
        self.n_samples = len(self.prices) - window_size - horizon

    def __len__(self) -> int:
        return self.n_samples

    def __getitem__(self, idx: int) -> tuple[torch.Tensor, torch.Tensor]:
        # Input window
        x = self.prices[idx : idx + self.window_size]

        # Target: next price after window
        y = self.prices[idx + self.window_size + self.horizon - 1]

        return torch.from_numpy(x), torch.tensor([y], dtype=torch.float32)

    def denormalize(self, value: float) -> float:
        """Convert normalized value back to original scale."""
        return value * self.std + self.mean
