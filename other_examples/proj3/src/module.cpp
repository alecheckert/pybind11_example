#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <proj3.h>

namespace py = pybind11;

// int transvsq(int n, float* v, float* out);

py::array_t<float> vec_sq(py::array_t<float> v) {
    py::buffer_info v_buf = v.request();
    if (v_buf.ndim != 1) 
        throw std::runtime_error("must be 1-dimensional");

    int n = (int) v_buf.size;
    auto out = py::array_t<float>(v_buf.size);
    py::buffer_info out_buf = out.request();

    // Get pointers to relevant buffers
    float* pv = static_cast<float*>(v_buf.ptr);
    float* pout = static_cast<float*>(out_buf.ptr);

    // Square each element
    transvsq(n, pv, pout);

    return out;
}

PYBIND11_MODULE(_pyproj3, m) {
    m.def("vec_sq", &vec_sq, "square each element of a double-valued array");
}
