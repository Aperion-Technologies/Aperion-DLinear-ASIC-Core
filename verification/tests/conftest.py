# verification/tests/conftest.py
"""Pytest fixtures for Cocotb tests."""

import pytest
from pathlib import Path
import sys

# Add ai_model to path for importing golden reference utilities
AI_MODEL_PATH = Path(__file__).parent.parent.parent / 'ai_model'
sys.path.insert(0, str(AI_MODEL_PATH))


@pytest.fixture
def golden_vectors_dir():
    """Path to golden reference vectors."""
    return AI_MODEL_PATH / 'outputs' / 'golden'


@pytest.fixture
def weights_dir():
    """Path to weight hex files."""
    return AI_MODEL_PATH / 'outputs'
