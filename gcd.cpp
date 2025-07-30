template<int a, int b>
struct gcd {
    static inline constexpr int value = gcd<b, a%b>::value;
};

template<int a>
struct gcd<a,0> {
    static inline constexpr int value = a;
};

int main () {
    static_assert(gcd<12,16>::value == 4);
}
