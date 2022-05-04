#include <iostream>
#include "vector.h"

int main() {
    vector vc{5};
    vc.resize(-10);
    std::cout << vc.size();
}