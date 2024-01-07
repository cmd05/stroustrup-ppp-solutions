#include "vector.h"
#include "vector_base.h"
#include <iostream>

int main() {

    std::cout << v.capacity() << "\n\n";
    for(int i = 0; i < v.size(); i++) std::cout << v[i] << '\n';
}