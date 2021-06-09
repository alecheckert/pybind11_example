#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <softmax.h>

PYBIND11_MODULE(softmax, m) {
    m.def("softmax", &softmax, "softmax function");
}
