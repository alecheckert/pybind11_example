#include <iostream>
#include <string>
#include <softmax.h>

void echo_args(const std::string &json, int Ny, int Nx) {
    // Construct the parameters object
    Params P (json, Ny, Nx);

    // Show all integer-valued parameters
    std::cout << "Integer-valued parameters:\n";
    std::map<std::string,int*>::iterator itri;
    for (itri = P.int_attribs.begin(); itri != P.int_attribs.end(); itri++)
        std::cout << itri->first << ": " << *itri->second << std::endl;

    // Show all floating point-valued parameters
    std::cout << "Float-valued parameters:\n";
    std::map<std::string,float*>::iterator itrf;
    for (itrf = P.float_attribs.begin(); itrf != P.float_attribs.end(); itrf++) 
        std::cout << itrf->first << ": " << *itrf->second << std::endl;

    // Show all string-valued parameters
    std::cout << "String-valued parameters:\n";
    std::map<std::string,std::string>::iterator itrs;
    for (itrs = P.str_attribs.begin(); itrs != P.str_attribs.end(); itrs++) 
        std::cout << itrs->first << ": " << itrs->second << std::endl;

    // Show parameters not in these maps
    std::cout << "Other parameters:\n";
    std::cout << "Ny: " << P.Ny << std::endl;
    std::cout << "Nx: " << P.Nx << std::endl;
    std::cout << "n_pixels: " << P.n_pixels << std::endl;

    return;
}
