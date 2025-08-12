
#include <iostream>

template<int... I>
struct Vector;

template<typename Vec = Vector<>>
struct Length;

template<>
struct Length<Vector<>> {
    static inline constexpr unsigned value = 0u;
};

template<int i, int... rest>
struct Length<Vector<i, rest...>> {
    static inline constexpr unsigned value = 1u + Length<Vector<rest...>>::value;
};

int main()
{
    static_assert(Length<Vector<1,2,3>>::value == 3);
    static_assert(Length<Vector<>>::value == 0);
}
