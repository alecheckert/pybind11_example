#include <pybind11/pybind11.h>
#include <proj1.h>

int glacial_add(int x, int y) {
    return add<int>(x, y);
}

int glacial_multiply(int x, int y) {
    return multiply<int>(x, y);
}

PYBIND11_MODULE(_glacial, m) {
    m.doc() = "glacial example";
    m.def("glacial_add", &glacial_add, "adds two integers");
    m.def("glacial_multiply", &glacial_multiply, "multiplies two integers");
}
