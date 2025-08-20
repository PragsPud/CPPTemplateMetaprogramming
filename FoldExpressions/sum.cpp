#include <iostream>

template<typename... args>
constexpr auto sum(args... Arg) {
    return (Arg + ...);
};

int main()
{
    std::cout<<sum(1,2,3,4,5);
}
