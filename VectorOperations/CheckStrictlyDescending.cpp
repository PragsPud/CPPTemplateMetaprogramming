#include <iostream>

template<int... I>
struct Vector;

template<typename Vec>
struct CheckStrictlyDescending;

template<int i1, int i2, int... rest>
struct CheckStrictlyDescending<Vector<i1,i2,rest...>> {
    static inline constexpr bool val = (i1 > i2) ? CheckStrictlyDescending<Vector<i2,rest...>>::val : false;
};

template<int... rest>
struct CheckStrictlyDescending<Vector<rest...>> {
    static inline constexpr bool val = true;
};

int main()
{
    static_assert(CheckStrictlyDescending<Vector<4,3,2,1>>::val);
    static_assert(!CheckStrictlyDescending<Vector<1,2,4,3>>::val);
    static_assert(CheckStrictlyDescending<Vector<>>::val);
    static_assert(CheckStrictlyDescending<Vector<6>>::val);
}
