#include <pybind11/pybind11.h>
#include <proj1.h>

int pyadd(int x, int y) {
    return add<int>(x, y);
}

int pymultiply(int x, int y) {
    return multiply<int>(x, y);
}

PYBIND11_MODULE(_pyproj1, m) {
    m.doc() = "proj1 example";
    m.def("pyadd", &pyadd, "adds two integers");
    m.def("pymultiply", &pymultiply, "multiplies two integers");
}
