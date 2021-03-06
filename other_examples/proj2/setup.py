#!/usr/bin/env python
import os
from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "_pyproj2",
        [os.path.join("src_py", "module.cpp")],
        include_dirs=["include"],
        libraries=["proj2"],
        library_dirs=["build"]
    )
]

setup(
    name="pyproj2",
    version="1.0",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules,
    packages=find_packages(),
)
