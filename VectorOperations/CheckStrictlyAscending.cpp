#include <iostream>

template<int... I>
struct Vector;

template<typename Vec>
struct CheckStrictlyAscending;

template<int i1, int i2, int... rest>
struct CheckStrictlyAscending<Vector<i1,i2,rest...>> {
    static inline constexpr bool val = (i1 < i2) ? CheckStrictlyAscending<Vector<i2,rest...>>::val : false;
};

template<int... rest>
struct CheckStrictlyAscending<Vector<rest...>> {
    static inline constexpr bool val = true;
};

int main()
{
    static_assert(CheckStrictlyAscending<Vector<1,2,3,4>>::val);
    static_assert(CheckStrictlyAscending<Vector<1,2,4>>::val);
    static_assert(!CheckStrictlyAscending<Vector<1,2,4,3>>::val);
    static_assert(CheckStrictlyAscending<Vector<>>::val);
    static_assert(CheckStrictlyAscending<Vector<6>>::val);
}
