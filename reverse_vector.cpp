#include <iostream>
template<int... i>
struct Vector;

template<typename InputVec, typename OutputVec = Vector<>>
struct revvector;

template<int i, int... rest, int... OutVec>
struct revvector<Vector<i, rest...>, Vector<OutVec...>> {
    using type = typename revvector<Vector<rest...>, Vector<i,OutVec...>>::type;
};

template<typename OutputVec>
struct revvector<Vector<>, OutputVec> {
    using type = OutputVec;
};

int main () {
    static_assert(std::is_same_v<typename revvector<Vector<1,2,3,4,5>>::type, Vector<5,4,3,2,1>>);
}
