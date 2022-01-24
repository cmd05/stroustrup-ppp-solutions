#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> gv(10);

void f(std::vector<int> v) {
    std::vector<int> lv(v.size());
    lv = gv;

    for(int x : gv) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> lv2 = v;
    for(int x : lv2) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    for(int i = 0; i < 10; i++) gv[i] = pow(2, i);
    f(gv);

    std::vector<int> vv(10);
    int fc = 1;
    
    for(int i = 0; i < 10; i++) {
        vv[i] = fc*(i+1);
        fc = vv[i];
    }

    f(vv);
}