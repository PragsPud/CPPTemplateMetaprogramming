#include <iostream>

template<int... I>
struct Vector;

template<int pos, typename Vec>
struct Get;

template<int i, int... rem1>
struct Get<0, Vector<i, rem1...>> {
    static inline constexpr int value = i;
};

template<int pos, int... rem1>
struct Get<pos, Vector<rem1...>> {
    static_assert(pos < 0, "Out of bounds");
};

template<int pos, int i, int... rem1>
struct Get<pos, Vector<i, rem1...>> {
    static_assert(pos > 0, "Cannot get from position < 0");
    static inline constexpr int value = Get<pos-1, Vector<rem1...>>::value;
};

int main () {
    static_assert(Get<0, Vector<0,1,2>>::value == 0);
    static_assert(Get<1, Vector<0,1,2>>::value == 1);
    static_assert(Get<2, Vector<0,1,2>>::value == 2);
    //static_assert(Get<-2, Vector<0,1,2>>::value == 2);
    //static_assert(Get<9, Vector<0,1,2>>::value == 2);
}
