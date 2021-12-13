#include <iostream>

int main() {
    // (a_pointer + a_number)
    // = (a_pointer + (a_number * sizeof( (*a_pointer) )))
    // using pointer arithmetic
    
    bool* ptr = nullptr;
    ptr += 1;
    std::cout << ptr;
}