""" pyfunc.py -- some functions in pure Python """
import json
from _softmax import echo_args

def factor(n):
    result = []
    c = 2
    while n > 1:
        if n % c == 0:
            n //= c
            result.append(c)
        else:
            c += 1
    return result
    
def echo_kwargs(Ny, Nx, **kwargs):
    jstr = json.dumps(kwargs)
    echo_args(jstr, Ny, Nx)
