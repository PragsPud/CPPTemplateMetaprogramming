template<unsigned n>
struct popcount {
    static inline constexpr unsigned value = (n&1) + popcount<(n>>1)>::value;
};

template<>
struct popcount<0> {
    static inline constexpr unsigned value = 0;
};

int main () {
    static_assert(popcount<10>::value == 2);
}
