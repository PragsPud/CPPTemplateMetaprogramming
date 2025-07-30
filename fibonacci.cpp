
#include <iostream>

template<unsigned n>
struct fib {
    inline static constexpr unsigned value = fib<n-1>::value + fib<n-2>::value;
};

template<>
struct fib<0> {
    inline static constexpr unsigned value = 0u;
};

template<>
struct fib<1> {
    inline static constexpr unsigned value = 1u;
};

int main() {
    static_assert(fib<12>::value == 144);

    return 0;
}
