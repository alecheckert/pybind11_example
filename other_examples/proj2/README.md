Very similar to proj1, except it compiles a numpy function instead
of a regular Python function. The purpose of this function is to 
square each element of a vector.

This also demonstrates the use of metaprogramming with a pybind11/numpy
function.

Component names:
    - proj2: Static pure C++ library, built with cmake
    - \_pyproj2: Python bindings
    - pyproj2: actual Python module

To build:
    mkdir build; cd build

    // Build the proj2 library
    cmake ..
    cmake --build .

    // Build the Python bindings
    cd ..
    python setup.py install
