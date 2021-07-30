#!/usr/bin/env python
import numpy as np
from pyproj2 import dvsq

if __name__ == '__main__':
    x = np.arange(256).astype(np.float64)
    y = dvsq(x)
    assert np.abs(y.sum() - (x**2).sum()) < 1.0e-6
