#include <iostream>

struct Base {
    int x;
    virtual int get() const { return x; }
};

struct Der : Base { 
    int y, z;
    Der(int a, int b): y{a}, z{b} {}
    int get() const override { return y + z; } 
};

struct Der2 : Base { 
    int y;
    Der2(int a): y{a} {}
    int get() const override { return y; } 
};

int main() {
    // This segfaults. sizeof(Base) = 16 and sizeof(Der) = 24

    // std::cout << sizeof(Base) << " " << sizeof(Der) << '\n';
    // Base* p = new Der[5] {{1, 2},{2,3},{3,4},{4,5},{5,6}};
    // for(int i = 0; i < 5; i++) std::cout << p[i].get();

    // This does not segfault. sizeof(Base) = 16 and sizeof(Der) = 16

    std::cout << sizeof(Base) << " " << sizeof(Der2) << '\n';
    Base* p = new Der2[5] {1,2,3,4,5};
    for(int i = 0; i < 5; i++) std::cout << p[i].get();
}