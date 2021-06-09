from unittest import TestCase
import numpy as np
from numpy.testing import assert_allclose
from softmax import softmax, double_2d, double_2d_float, string_says_hello

class TestSoftmax(TestCase):
    def test_softmax(self):
        x = np.array([1., 2, 3, 4])
        result = softmax(x)
        expected = np.exp(x) / np.exp(x).sum()
        assert_allclose(result, expected, 1.0e-8)

    def test_double_2d(self):
        x = np.array([[1., 2, 3], [3, 4, 5]])
        result = double_2d(x)
        assert_allclose(np.abs(2*x - result), 0.0, 1.0e-8)
        
    def test_double_2d_float(self):
        x = np.array([[1., 2, 3], [3, 4, 5]])
        result = double_2d_float(x)
        assert_allclose(np.abs(2*x - result), 0.0, 1.0e-8)

    def test_string_says_hello(self):
        assert string_says_hello("hello")
        assert not string_says_hello("not_hello")
