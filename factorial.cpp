template<int n>
struct factorial {
    static inline constexpr int value = n * factorial<n-1>::value;
};

template<>
struct factorial<0> {
    static inline constexpr int value = 1;
};

int main () {
    static_assert(factorial<6>::value == 720);
}
