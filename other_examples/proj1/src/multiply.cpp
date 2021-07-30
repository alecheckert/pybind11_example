#include <proj1.h>

template <typename T>
T multiply(T x, T y) {
    return x * y;
}
template int multiply<int>(int, int);
template float multiply<float>(float, float);
