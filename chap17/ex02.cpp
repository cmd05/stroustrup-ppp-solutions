#include <iostream>

int main() {
    // (a_pointer + a_number)
    // = (a_pointer + (a_number * sizeof( (*a_pointer) )))
    // using pointer arithmetic
    
    int* ptr = nullptr;
    ptr += 1;
    std::cout << ptr;
}