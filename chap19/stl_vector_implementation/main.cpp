#include "vector.h"
#include "vector_base.h"
#include <iostream>
#include <vector>

int main() {
    vector v {1,2,3};
    vector v2 {1,2,3,4,5};

    v = v2;

    for(int i = 0; i < v.size(); i++) std::cout << v[i] << '\n';
}