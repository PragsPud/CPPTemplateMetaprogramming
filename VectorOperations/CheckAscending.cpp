#include <iostream>

template<int... I>
struct Vector;

template<typename Vec>
struct CheckAscending;

template<int i1, int i2, int... rest>
struct CheckAscending<Vector<i1,i2,rest...>> {
    static inline constexpr bool val = (i1 <= i2) ? CheckAscending<Vector<i2,rest...>>::val : false;
};

template<int... rest>
struct CheckAscending<Vector<rest...>> {
    static inline constexpr bool val = true;
};

int main()
{
    static_assert(CheckAscending<Vector<1,2,3,4>>::val);
    static_assert(CheckAscending<Vector<1,2,4>>::val);
    static_assert(!CheckAscending<Vector<1,2,4,3>>::val);
    static_assert(CheckAscending<Vector<>>::val);
    static_assert(CheckAscending<Vector<6>>::val);
}
