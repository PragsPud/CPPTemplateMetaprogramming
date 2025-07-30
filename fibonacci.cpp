template<unsigned n, unsigned a = 0, unsigned b = 1>
struct fib {
    inline static constexpr unsigned value = fib<n-1, b, a+b>::value;
};

template<unsigned a, unsigned b>
struct fib<0,a,b> {
    inline static constexpr unsigned value = a;
};

int main () {
    static_assert(fib<10>::value == 55);
}
