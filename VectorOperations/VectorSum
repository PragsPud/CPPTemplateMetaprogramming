#include <iostream>

template<int... I>
struct Vector;

template<typename Vec>
struct VectorSum;

template<int... i1>
struct VectorSum<Vector<i1...>> {
    static inline constexpr int val = (i1 + ...);
};

template<>
struct VectorSum<Vector<>> {
    static inline constexpr int val = 0;
};

int main()
{
    static_assert(VectorSum<Vector<2,3,4>>::val == 9);
    static_assert(VectorSum<Vector<1,2,3,4>>::val == 10);
    static_assert(VectorSum<Vector<>>::val == 0);
}
