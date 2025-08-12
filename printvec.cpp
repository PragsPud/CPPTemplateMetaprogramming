#include <iostream>

template<int... i>
struct Vector {};

template<int... T>
void print(Vector<T...>) {
    return;
};

template<int i, int... rest>
void print(Vector<i, rest...>) {
    std::cout << i << " ";
    print(Vector<rest...>{});
};

int main () {
    print(Vector<1,2,3,4,5,6>{});
}
