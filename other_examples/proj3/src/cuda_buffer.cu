#include <cufft.h>
#include <proj3.cuh>

CudaBuffer::CudaBuffer(int n): n(n) {
    cudaMalloc((void**)&data, sizeof(float)*n);
}

CudaBuffer::~CudaBuffer() {
    cudaFree(data);
}
