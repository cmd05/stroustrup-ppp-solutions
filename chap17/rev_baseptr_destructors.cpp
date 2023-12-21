#include <iostream>

class Base {
public:
    ~Base() { std::cout << "~Base() "; }
};

class Der : public Base {
    int x;
    std::string s;
public:
    ~Der() { std::cout << " ~Der()"; }
};


class Base1 {
public:
    virtual ~Base1() { std::cout << "~Base1() "; }
};

class Der1 : public Base1 {
    int x;
    std::string s;
public:
    ~Der1() { std::cout << "~Der1() "; }
};


int main() {
    Base* p = new Der;
    delete p; // does not call ~Der(). This will not free x and s owned by Der (memory leak)

    std::cout << '\n';

    Base1* p2 = new Der1;
    delete p2; // ok

    /* Output:
        ~Base()
        ~Der1() ~Base1()
    */
}