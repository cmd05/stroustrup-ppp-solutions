#include <iostream>
#include <cstdint>

int main() {
    int* pi = new int[2];
    double* pd = new double[5];
    bool* pb = new bool[2];


    // by defn, ptr subtraction gives no. of elements
    // std::cout << &pd[4] - &pd[0]; // out: 4

    std::cout << (reinterpret_cast<uintptr_t>(&pi[1]) - reinterpret_cast<uintptr_t>(&pi[0])) << '\n'; // out: 4
    std::cout << (reinterpret_cast<uintptr_t>(&pd[1]) - reinterpret_cast<uintptr_t>(&pd[0])) << '\n'; // out: 8
    std::cout << (reinterpret_cast<uintptr_t>(&pb[1]) - reinterpret_cast<uintptr_t>(&pb[0])) << '\n'; // out: 1
}