#include <cufft.h>
#include <proj3.cuh>

__global__
void vsq(int n, float* d_v) {
    const int n_threads = blockDim.x * gridDim.x;
    const int thread_idx = blockIdx.x * blockDim.x + threadIdx.x;
    for (int i = thread_idx; i < n; i += n_threads)
        d_v[i] = d_v[i] * d_v[i];
}
