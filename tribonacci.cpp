template<unsigned n>
struct tribo {
    static inline constexpr unsigned value = tribo<n-1>::value + tribo<n-2>::value + tribo<n-3>::value;
};

template<>
struct tribo<0> {
    static inline constexpr unsigned value = 0u;
};

template<>
struct tribo<1> {
    static inline constexpr unsigned value = 0u;
};

template<>
struct tribo<2> {
    static inline constexpr unsigned value = 1u;
};

int main () {
    static_assert(tribo<10>::value == 81);
}
