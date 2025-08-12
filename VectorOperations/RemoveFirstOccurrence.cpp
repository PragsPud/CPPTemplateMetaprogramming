
#include <iostream>

template<int... I>
struct Vector;

template<int x, typename InpVec, typename OutVec = Vector<>>
struct RemoveFirst;

template<int x, int... rem1, int... rem2>
struct RemoveFirst<x, Vector<x, rem1...>, Vector<rem2...>> {
    using type = Vector<rem2..., rem1...>;
};

template<int x, int y, int... rem1, int... rem2>
struct RemoveFirst<x, Vector<y, rem1...>, Vector<rem2...>> {
    using type = typename RemoveFirst<x, Vector<rem1...>, Vector<rem2..., y>>::type;
};

template<int x, int... rem2>
struct RemoveFirst<x, Vector<>, Vector<rem2...>> {
    using type = Vector<rem2...>;
};

int main()
{
    static_assert(std::is_same_v<RemoveFirst<3,Vector<1,2,3>>::type, Vector<1,2>>);
    static_assert(std::is_same_v<RemoveFirst<100,Vector<1,2,3>>::type, Vector<1,2,3>>);
    static_assert(std::is_same_v<RemoveFirst<2,Vector<1,2,3,2,3,2,3>>::type, Vector<1,3,2,3,2,3>>);
    static_assert(std::is_same_v<RemoveFirst<2,Vector<>>::type, Vector<>>);
}
