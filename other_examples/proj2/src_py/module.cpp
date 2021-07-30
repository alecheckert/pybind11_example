#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <proj2.h>

namespace py = pybind11;

/*
py::array_t<double> dvsq(py::array_t<double> v) {
    py::buffer_info v_buf = v.request();
    if (v_buf.ndim != 1)
        throw std::runtime_error("Must be 1-dimensional");

    int n = (int) v_buf.size;
    auto out = py::array_t<double>(v_buf.size);
    py::buffer_info out_buf = out.request();

    // Get pointers to the relevant buffers
    double* pv = static_cast<double*>(v_buf.ptr);
    double* pout = static_cast<double*>(out_buf.ptr);
    
    // Square each element
    vsq<double>(n, pv, pout);

    return out;
}
*/

template <typename T>
py::array_t<T> vec_sq(py::array_t<T> v) {
    py::buffer_info v_buf = v.request();
    if (v_buf.ndim != 1)
        throw std::runtime_error("Must be 1-dimensional");

    int n = (int) v_buf.size;
    auto out = py::array_t<T>(v_buf.size);
    py::buffer_info out_buf = out.request();

    // Get pointers to the relevant buffers
    T* pv = static_cast<T*>(v_buf.ptr);
    T* pout = static_cast<T*>(out_buf.ptr);
    
    // Square each element
    vsq<T>(n, pv, pout);

    return out;
}
template py::array_t<double> vec_sq<double>(py::array_t<double>);
template py::array_t<float> vec_sq<float>(py::array_t<float>);


PYBIND11_MODULE(_pyproj2, m) {
    m.def("dvsq", &vec_sq<double>, "square each element of a double-valued numpy array");
    m.def("svsq", &vec_sq<float>, "square each element of a float-valued numpy array");
}
