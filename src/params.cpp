#include <string>
#include <map>
#include <softmax.h>

/* 
 *  Constructor: Params
 *  -------------------
 *  Parse all recognized parameters out of a JSON string and save
 *  them to attributes of the Params struct.
*/
Params::Params(std::string params_json, int Ny, int Nx) : Ny(Ny), Nx(Nx) {

    // Grab all passed integer-valued parameters
    std::map<std::string,int*>::iterator itri;
    for (itri = int_attribs.begin(); itri != int_attribs.end(); itri++)
        get_json_item<int>(params_json, itri->first, itri->second);

    // Grab all passed float-valued parameters
    std::map<std::string,float*>::iterator itrf;
    for (itrf = float_attribs.begin(); itrf != float_attribs.end(); itrf++)
        get_json_item<float>(params_json, itrf->first, itrf->second);

    // Non user-supplied parameters
    n_pixels = Ny * Nx;
}
