//Pops last element for non-empty vector
#include <iostream>

template<int... I>
struct Vector;

template<typename InpVec, typename OutVec = Vector<>>
struct PopBack;

template<>
struct PopBack<Vector<>, Vector<>> {
    using type = Vector<>;
};

template<int i1, int... rest2>
struct PopBack<Vector<i1>, Vector<rest2...>> {
    using type = Vector<rest2...>;
};

template<int i1, int... rest1, int... rest2>
struct PopBack<Vector<i1, rest1...>, Vector<rest2...>> {
    using type = typename PopBack<Vector<rest1...>, Vector<rest2..., i1>>::type;
};


int main () {
    static_assert(std::is_same_v<PopBack<Vector<2,3,4,5>>::type, Vector<2,3,4>>);
    static_assert(std::is_same_v<PopBack<Vector<>>::type, Vector<>>);
}
