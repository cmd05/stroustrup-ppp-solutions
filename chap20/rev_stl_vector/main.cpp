#include "vector.h"
#include <iostream>
#include <vector>

int main() {
    vector<int> v{};
    // vector v2 {1,2,3,4,5};

    // v = v2;

    // for(int i = 0; i < v.size(); i++) std::cout << v[i] << '\n';

    int x = 5;

    v.insert(v.begin(), x);
    v[0] = 6;

    // for(int i = 0; i < v.size(); i++) std::cout << v[i] << '\n';

    std::cout << x;
}