#include <iostream>
#include <cufft.h>
#include <proj3.cuh>

#define THREADS_PER_BLOCK 256

int transvsq(int n, float* v, float* out) {
    int n_thread_blocks = (n + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;
    CudaBuffer B (n);
    cudaError_t exit_code = cudaMemcpy(B.data, v, sizeof(float)*n, cudaMemcpyHostToDevice);
    vsq<<<n_thread_blocks,THREADS_PER_BLOCK>>>(n, B.data);
    exit_code = cudaMemcpy(out, B.data, sizeof(float)*n, cudaMemcpyDeviceToHost);
    return (int) exit_code;
}
