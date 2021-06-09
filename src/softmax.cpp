#include <cmath>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> softmax(py::array_t<double> arr) {
    py::buffer_info data = arr.request();
    if (data.ndim != 1)
        throw std::runtime_error("Number of dimensions must be one");
    auto result = py::array_t<double>(data.size);
    py::buffer_info buf_result = result.request();

    double *ptr_in = static_cast<double*>(data.ptr);
    double *ptr_out = static_cast<double*>(buf_result.ptr);
    
    double norm = 0.0;
    int i;

    for (i=0; i<data.size; i++) {
        ptr_out[i] = std::exp(ptr_in[i]);
        norm += ptr_out[i];
    }
    for (i=0; i<data.size; i++) 
        ptr_out[i] /= norm;

    return result;
}
