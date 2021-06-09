# pybind11_example
An example that uses pybind11 to wrap a simple softmax function, mostly for my own future reference

## Build with conda
```
    # Build a suitable conda environment
    conda env create -f example_env.yml
    conda activate example_env

    # Compile and install the softmax module
    python setup.py install

    # Run tests
    nose2
```
