#include <iostream>

template<int... I>
struct Vector;

template<typename Vec1, typename Vec2>
struct Concat;

template<int... rem1, int... rem2>
struct Concat<Vector<rem1...>, Vector<rem2...>> {
    using type = Vector<rem1..., rem2...>;
};

int main () {
    static_assert(std::is_same_v<Concat<Vector<1,2>, Vector<3,4>>::type, Vector<1,2,3,4>>);
}
