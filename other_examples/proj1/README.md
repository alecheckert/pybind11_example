A simple example project that compiles a static library with cmake,
then links a pybind11-bound library to this library.

The different components have the following names:
    - The static pure C++ library is called proj1 (libproj1.a)
    - The pybind11 module is called _glacial
    - The Python module is called glacial (it imports everything
        from _glacial into its namespace)

To build:
    mkdir build; cd build

    # Build the static library "proj1"
    cmake ..
    cmake --build .
    
    # Build the _glacial, glacial packages
    cd ..
    python setup.py install

