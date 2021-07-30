A simple example project that compiles a static library with cmake,
then links a pybind11-bound library to this library.

The different components have the following names:
    - The static pure C++ library is called proj1 (libproj1.a)
    - The pybind11 module is called \_pyproj1
    - The Python module is called pyproj1 (it imports everything
        from \_pyproj1 into its namespace)

To build:
```
    mkdir build; cd build

    # Build the static library libproj1.a
    cmake ..
    cmake --build .
    
    # Build the _pyproj1, pyproj1 packages
    cd ..
    python setup.py install
```

