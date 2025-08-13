#include <iostream>

template<int... I>
struct Vector;

template<typename Vec>
struct CheckDescending;

template<int i1, int i2, int... rest>
struct CheckDescending<Vector<i1,i2,rest...>> {
    static inline constexpr bool val = (i1 >= i2) ? CheckDescending<Vector<i2,rest...>>::val : false;
};

template<int... rest>
struct CheckDescending<Vector<rest...>> {
    static inline constexpr bool val = true;
};

int main()
{
    static_assert(CheckDescending<Vector<4,3,2,1>>::val);
    static_assert(CheckDescending<Vector<4,3,2,2,2,1>>::val);
    static_assert(!CheckDescending<Vector<1,2,4,3>>::val);
    static_assert(CheckDescending<Vector<>>::val);
    static_assert(CheckDescending<Vector<6>>::val);
}
