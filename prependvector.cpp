#include <iostream>

template<int... i>
struct Vector;

template<int NV, typename V>
struct Prepend;

template<int NV, int... I>
struct Prepend<NV, Vector<I...>> {
    using type = Vector<NV, I...>;
};

int main () {
    static_assert(std::is_same_v<Prepend<1, Vector<2,3>>::type, Vector<1,2,3>>);
}
