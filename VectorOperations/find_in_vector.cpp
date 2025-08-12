#include <iostream>

template<int... I>
struct Vector;

template<int x, typename Vec, int pos>
struct findutil;

template<int x, int i, int... rest, int pos>
struct findutil<x, Vector<i, rest...>, pos> {
    static inline constexpr int res = (x == i) ? pos : findutil<x, Vector<rest...>, pos+1>::res;
};

template<int x, int pos>
struct findutil<x, Vector<>, pos> {
    static inline constexpr int res = -1;
};

template<int x, typename Vec>
struct find;

template<int x, int i, int... rest>
struct find<x, Vector<i, rest...>> {
    static inline constexpr int res = findutil<x, Vector<i, rest...>, 0>::res;
};

int main () {
    static_assert(find<2,Vector<1,2,3,4>>::res == 1);
    static_assert(find<5,Vector<1,2,3,4>>::res == -1);
}
