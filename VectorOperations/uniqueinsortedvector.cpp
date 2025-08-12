#include <iostream>
template<int... i>
struct Vector;

template<typename InpVec, typename OutVec = Vector<>>
struct uniqv;

template<int i, int... tail, int... OutVecElems>
struct uniqv<Vector<i, i, tail...>, Vector<OutVecElems...>> {
    using type = typename uniqv<Vector<i,tail...>,Vector<OutVecElems...>>::type;
};

template<int i, int... tail, int... OutVecElems>
struct uniqv<Vector<i, tail...>, Vector<OutVecElems...>> {
    using type = typename uniqv<Vector<tail...>,Vector<OutVecElems..., i>>::type;
};

template<typename OutVec>
struct uniqv<Vector<>, OutVec> {
    using type = OutVec;
};

int main()
{
    static_assert(std::is_same_v<typename uniqv<Vector<1,1,1,2,2,3,4,5>>::type, Vector<1,2,3,4,5>>);
}
