#!/usr/bin/env python
import os
from glob import glob
from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "_pyproj1",
        [os.path.join("src_py", "module.cpp")],
        include_dirs=["include"],
        libraries=["proj1"],
        library_dirs=["build"]
    )
]
print(ext_modules[0].include_dirs)

setup(
    name="pyproj1",
    version="1.0",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules,
    packages=find_packages(),
)
