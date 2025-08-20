
#include <iostream>

template<typename... Args>
constexpr auto binor(Args... args) {
    return (args | ...);
}

int main()
{
    static_assert(binor(1,2,3) ==3);
    std::cout<<binor(1,2,3);
}
