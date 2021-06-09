#include <cmath>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <softmax.h>

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

py::array_t<double> double_2d(py::array_t<double> arr) {

    // Demonstrate methods to access shape and size of input array
    /*
    std::cout << "arr.shape(0) = " << arr.shape(0) << std::endl;
    std::cout << "arr.shape(1) = " << arr.shape(1) << std::endl;
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.ndim() = " << arr.ndim() << std::endl;
    */

    py::buffer_info buf = arr.request();
    py::array_t<double> result = py::array_t<double>(buf.size);
    py::buffer_info result_buffer = result.request();

    double *ptr_in = (double*) buf.ptr;
    double *ptr_out = (double*) result_buffer.ptr;

    for (int i=0; i<buf.size; i++) {
        ptr_out[i] = ptr_in[i] * 2;
    }
    int X = buf.shape[0];
    int Y = buf.shape[1];

    result.resize({X, Y});
    
    return result;
}

py::array_t<float> double_2d_float(py::array_t<float> arr) {
    py::buffer_info buf = arr.request();
    py::array_t<float> result = py::array_t<float>(buf.size);
    py::buffer_info result_buffer = result.request();

    float *ptr_in = (float*) buf.ptr;
    float *ptr_out = (float*) result_buffer.ptr;

    for (int i=0; i<buf.size; i++) {
        ptr_out[i] = ptr_in[i] * 2;
    }
    int X = buf.shape[0];
    int Y = buf.shape[1];

    result.resize({X, Y});
    return result;
}
