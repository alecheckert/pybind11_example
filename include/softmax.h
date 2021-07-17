#ifndef _SOFTMAX_H
#define _SOFTMAX_H

#include <string>
#include <map>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

/* NON-PYTHON FUNCTIONS */

/* get_json_item: given a JSON string, parse out the value for a single. 
 * Doesn't look deeper than the first recursion layer. */
template <typename T>
int get_json_item(std::string json, std::string key, T* value);

/* get_json_str: get a JSON string */
int get_json_str(std::string json, std::string key, std::string& value);

/* Params: encapsulates a set of defined possible arguments to a Python
 * function. */
struct Params {
    // Non keyword arguments
    int Ny, Nx, n_pixels;

    // Actual parameters, with default values
    int window_size = 11;
    float sigma = 1.5;
    float damp = 0.3;
    int max_iter = 20;
    std::string method = "None";

    // Pointers to attribute values, keyed by parameter name
    std::map<std::string,int*> int_attribs = {
        {std::string("window_size"), &window_size},
        {std::string("max_iter"), &max_iter}
    };
    std::map<std::string,float*> float_attribs = {
        {std::string("sigma"), &sigma},
        {std::string("damp"), &damp}
    };
    std::map<std::string,std::string> str_attribs = {
        {std::string("method"), method}
    };

    // Constructor from a JSON string
    Params(std::string params_json, int Ny, int Nx);
};

/* PYTHON FUNCTIONS */

/* Regular softmax function for a numpy array */
py::array_t<double> softmax(py::array_t<double> arr);

/* Double each element of a 2D array */
py::array_t<double> double_2d(py::array_t<double> arr);

/* Double each element of a 2D float-valued array, to see how that's different */
py::array_t<float> double_2d_float(py::array_t<float> arr);

/* Determine whether a Python string says "hello". */
bool string_says_hello(const std::string &s);

/* Given a set of Python arguments as a JSON string, parse out
 * recognized arguments and print them along with their values. 
 * For unrecognized arguments, show the defaults in Params. */
void echo_args(const std::string &json, int Ny, int Nx);


#endif
