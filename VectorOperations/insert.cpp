//Inserts at the end if pos >= size of input vector
#include <iostream>

template<int... I>
struct Vector;

template<unsigned int pos, int x, typename InpVec, typename OutVec = Vector<>>
struct insert;

template<int x, int i1, int... rest1, int... rest2>
struct insert<0, x, Vector<i1, rest1...>, Vector<rest2...>> {
    using type = Vector<rest2..., x, i1, rest1...>;
};

template<unsigned int pos, int x, int... rest2>
struct insert<pos, x, Vector<>, Vector<rest2...>> {
    using type = Vector<rest2..., x>;
};

template<unsigned int pos, int x, int i1, int... rest1, int... rest2>
struct insert<pos,x,Vector<i1, rest1...>,Vector<rest2...>> {
    using type = typename insert<pos-1, x, Vector<rest1...>, Vector<rest2..., i1>>::type;
};

int main () {
    static_assert(std::is_same_v<typename insert<0,5,Vector<1,2,3>>::type, Vector<5,1,2,3>>);
    static_assert(std::is_same_v<typename insert<4,5,Vector<1,2,3>>::type, Vector<1,2,3,5>>);
    static_assert(std::is_same_v<typename insert<10,5,Vector<1,2,3>>::type, Vector<1,2,3,5>>);
}
