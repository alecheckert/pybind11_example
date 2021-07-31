An example of Python bindings for an underlying C++/CUDA application.
A personal experiment; this is almost certainly not the best way to do it.

The basic idea is to compile the C++/CUDA library (libproj3) first, then 
link against it with pybind11. In this context, pybind11 is completely 
unaware of CUDA. These two steps are automated by a makefile.

How to build: `make`

How to reset: `make clean`

Stuff I learned while doing this:
   1. You cannot make *static* C++/CUDA libraries; this results in memory 
     leaks.
   2. In order to compile C++ applications that rely on a C++/CUDA shared
     library, you must link against cuda and cudart, e.g.
```
        g++ -o test_app test_app.cpp -lproj3 -lcuda -lcudart -L./build \
            -I./include -L$(PATH_TO_CUDA_LIBS) -Xlinker -rpath ...
```
   3. The `setuptools` route for installing `pybind11` applications works
    fine for linking against a C++/CUDA shared library, provided you 
    give it the `cuda` and `cudart` libraries (as above). See the 
    `setup.py` script for more details.
   4. Either `python setup.py install` or `python setup.py develop` works.
