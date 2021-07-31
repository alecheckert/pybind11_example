#!/usr/bin/env python
import numpy as np
from pyproj3 import vec_sq

if __name__ == '__main__':
    n = 256
    x = np.arange(n).astype(np.float32)
    y = vec_sq(x)
    print(y.sum())
