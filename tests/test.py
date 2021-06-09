from unittest import TestCase
import numpy as np
from numpy.testing import assert_allclose
from softmax import softmax

class TestSoftmax(TestCase):
    def test_softmax(self):
        x = np.array([1., 2, 3, 4])
        result = softmax(x)
        expected = np.exp(x) / np.exp(x).sum()
        assert_allclose(result, expected, 1.0e-8)
