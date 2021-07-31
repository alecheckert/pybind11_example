#ifndef _PROJ3_CUH
#define _PROJ3_CUH

#include <cufft.h>

class CudaBuffer {
public:
    int n;
    float* data;
    CudaBuffer(int n);
    ~CudaBuffer();
};

__global__
void vsq(int n, float* d_v);

int transvsq(int n, float* v, float* out);

#endif
