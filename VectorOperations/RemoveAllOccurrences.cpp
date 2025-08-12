
#include <iostream>

template<int... I>
struct Vector;

template<int x, typename InpVec, typename OutVec = Vector<>>
struct RemoveAll;

template<int x, int... rem1, int... rem2>
struct RemoveAll<x, Vector<x, rem1...>, Vector<rem2...>> {
    using type = typename RemoveAll<x, Vector<rem1...>, Vector<rem2...>>::type;
};

template<int x, int y, int... rem1, int... rem2>
struct RemoveAll<x, Vector<y, rem1...>, Vector<rem2...>> {
    using type = typename RemoveAll<x, Vector<rem1...>, Vector<rem2..., y>>::type;
};

template<int x, int... rem2>
struct RemoveAll<x, Vector<>, Vector<rem2...>> {
    using type = Vector<rem2...>;
};

int main()
{
    static_assert(std::is_same_v<RemoveAll<2,Vector<1,2,3>>::type, Vector<1,3>>);
    static_assert(std::is_same_v<RemoveAll<100,Vector<1,2,3>>::type, Vector<1,2,3>>);
    static_assert(std::is_same_v<RemoveAll<2,Vector<1,2,3,2,3,2,3>>::type, Vector<1,3,3,3>>);
    static_assert(std::is_same_v<RemoveAll<2,Vector<>>::type, Vector<>>);
}
