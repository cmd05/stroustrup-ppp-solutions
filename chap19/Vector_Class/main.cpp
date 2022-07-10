#include <iostream>
#include "vector.h"

void p(vector& vc) {
    std::cout << "sz, space: " << vc.size() << "\t" << vc.capacity() << "\n";
}


void pvc(vector& vc) {
    for (int i = 0; i < vc.size(); ++i) std::cout << vc[i] << " ";
    std::cout << "\n";
}

int main() {
    vector vc{1,2,3,4,5};
    vc.resize(3);
    p(vc);
    pvc(vc);
    vc.resize(10);
    p(vc);
    pvc(vc);
    vc.push_back(4);
    p(vc);
    pvc(vc);
}