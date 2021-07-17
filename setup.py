import os
from glob import glob 
from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "_softmax",
        sorted(glob(os.path.join("src", "*.cpp"))),
        include_dirs=["include"],
    ),
]
print(ext_modules[0].include_dirs)

setup(
    name="softmax",
    version="1.0",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules,
    packages=find_packages(),
)
