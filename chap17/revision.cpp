#include <iostream>

int main() {
    int var = 10;
    int var2 = 10;
    int* ptr1 = &var;
    int* ptr2 = &var2;

    *ptr1 = 12;
    // int x = ptr1; // error
    // int* x = var; // error

    std::cout << *ptr1 << *ptr2;
}