#include <iostream>

template<int... I>
struct Vector;

template<int I, typename T>
struct Append;

template<int I, int... rest>
struct Append<I, Vector<rest...>> {
    using type = Vector<rest..., I>;
};

int main () {
    static_assert(std::is_same_v<Append<4, Vector<1,2,3>>::type, Vector<1,2,3,4>>);

}
