#ifndef _SOFTMAX_H
#define _SOFTMAX_H

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> softmax(py::array_t<double> arr);

py::array_t<double> double_2d(py::array_t<double> arr);

py::array_t<float> double_2d_float(py::array_t<float> arr);

bool string_says_hello(const std::string &s);

#endif
