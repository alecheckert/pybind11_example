#!/usr/bin/env python
import os
from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

BUILD_DIR = os.path.abspath("build")
INCLUDE_DIR = os.path.abspath("include")
SRC_DIR = os.path.abspath("src")
CUDA_LIB_DIR = # redacted

ext_modules = [
    Pybind11Extension(
        "_pyproj3",
        [os.path.join(SRC_DIR, "module.cpp")],
        include_dirs=[INCLUDE_DIR, CUDA_LIB_DIR],
        libraries=["proj3", "cuda", "cudart"],
        library_dirs=[BUILD_DIR, CUDA_LIB_DIR],
        runtime_library_dirs=[BUILD_DIR],
    )
]

setup(
    name="pyproj3",
    version="1.0",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules,
    packages=find_packages(),
)
