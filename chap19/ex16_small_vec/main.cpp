#include "small_vector.h"

#include <iostream>

int main() {
    small_vector<int> v {1,2,3};
    v.resize(10);
    v.push_back(15);

    std::cout << sizeof(small_vector<int>) << " " << sizeof(int*) << "\n\n"; // yay!

    for(int i = 0; i < v.size(); i++) std::cout << v[i] << '\n';
}