//Fold Expressions - Added in C++17
#include <iostream>

template<typename... Args>
auto add(Args... args) {
    return (args + ...);
}

template<typename... Args>
auto multiply(Args... args) {
    return (args * ...);
}

template<typename... Args>
auto binor(Args... args) {
    return (args | ...);
}

int main()
{
    std::cout<<add(1,2,3,4,5,5,5,5) << " ";
    std::cout<<multiply(3.14,2.56) << " ";
    std::cout << binor(1,2,3) << " ";
}
