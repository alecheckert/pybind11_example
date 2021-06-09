#ifndef _SOFTMAX_H
#define _SOFTMAX_H

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> softmax(py::array_t<double> arr);

#endif
