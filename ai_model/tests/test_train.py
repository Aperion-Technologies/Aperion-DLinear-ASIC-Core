# ai_model/tests/test_train.py
"""Tests for training pipeline."""

import pytest
import torch
import numpy as np
from pathlib import Path
from src.train import train_model, create_dataloader
from src.model import QuantDLinear
from src.config import WINDOW_SIZE


class TestTraining:
    """Test training pipeline components."""

    @pytest.fixture
    def sample_data(self, tmp_path):
        """Create sample price data."""
        prices = np.sin(np.linspace(0, 20*np.pi, 1000)).astype(np.float32) * 100 + 50000
        data_path = tmp_path / "ticks.parquet"
        import pandas as pd
        pd.DataFrame({'price': prices}).to_parquet(data_path)
        return data_path

    def test_dataloader_creation(self, sample_data):
        """DataLoader should yield correct batch shapes."""
        loader = create_dataloader(sample_data, batch_size=4)
        x, y = next(iter(loader))
        assert x.shape == (4, WINDOW_SIZE)
        assert y.shape == (4, 1)

    def test_single_epoch(self, sample_data):
        """One epoch of training should reduce loss."""
        model = QuantDLinear()
        loader = create_dataloader(sample_data, batch_size=8)

        # Get initial loss
        model.eval()
        x, y = next(iter(loader))
        with torch.no_grad():
            initial_loss = torch.nn.functional.mse_loss(model(x), y).item()

        # Train for a few batches
        model.train()
        optimizer = torch.optim.Adam(model.parameters(), lr=1e-2)
        for _ in range(10):
            x, y = next(iter(loader))
            optimizer.zero_grad()
            pred = model(x)
            loss = torch.nn.functional.mse_loss(pred, y)
            loss.backward()
            optimizer.step()

        # Loss should decrease
        model.eval()
        with torch.no_grad():
            final_loss = torch.nn.functional.mse_loss(model(x), y).item()

        assert final_loss < initial_loss * 0.9  # At least 10% improvement
