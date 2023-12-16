#include <iostream>

class B1 {
public:
    virtual void vf() { std::cout << "B1::vf() "; }
    void f() { std::cout << "B1::f() "; }
    virtual void pvf() =0;
};

class D1 : public B1 {
public:
    void vf() override  { std::cout << "D1::vf() "; }
    void f() { std::cout << "D1::f() "; }
    virtual void pvf() override { std::cout << "D1::pvf() "; }
};

class D2: public D1 {
public:
    void pvf() override { std::cout << "D2::pvf() "; }
};

class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
std::string str = "HelloWorld";
public:
    void pvf() override { std::cout << str << " "; }
};

class D22 : public B2 {
int x = 725;
public:
    void pvf() override { std::cout << x << " "; }
};

void f(B2& b2) {
    b2.pvf();
}

void newline() { std::cout << '\n'; }

int main() {
    D1 d1;
    d1.vf();
    d1.f();
    
    newline();

    B1& b1 = d1;
    b1.vf();
    b1.f(); // B1::f() is not virtual, hence it is not overriden
    b1.pvf();

    newline();

    D2 d2;
    D1& d11 = d2;
    d11.vf(); d11.f(); d11.pvf();

    newline();
    
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
}