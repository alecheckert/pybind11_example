#include <proj1.h>

template <typename T>
T add(T x, T y) {
    return x + y;
}
template int add<int>(int, int);
template float add<float>(float, float);
