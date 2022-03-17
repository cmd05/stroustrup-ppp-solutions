#include "Vector.h"
#include <algorithm>

vector::vector(int size): sz{size}, elem{new double[size]} {
    for(int i = 0; i < sz; i++) elem[i] = 0;
}

vector::vector(std::initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]} {
    std::copy(lst.begin(), lst.end(), elem);
}

// Copy Constructor
//vector(const vector& arg):