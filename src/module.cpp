#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <softmax.h>

PYBIND11_MODULE(softmax, m) {
    m.def("softmax", &softmax, "softmax function");
    m.def("double_2d", &double_2d, "double a 2D array");
    m.def("double_2d_float", &double_2d_float, "double a 2D array");
    m.def("string_says_hello", &string_says_hello, "determine whether a string says hello");
    m.def("echo_args", &echo_args, "echo a set of recognized Python arguments");
}
