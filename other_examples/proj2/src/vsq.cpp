#include <proj2.h>

template <typename T>
void vsq(int n, T* v, T* out) {
    for (int i=0; i<n; i++)
        out[i] = v[i] * v[i];
}
template void vsq<int>(int, int*, int*);
template void vsq<float>(int, float*, float*);
template void vsq<double>(int, double*, double*);
