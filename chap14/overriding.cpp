#include <iostream>

struct B {
    virtual void f() const { std::cout << "B::f() "; }
    virtual void f(int a) const { std::cout << "B::f(int a) "; } // can be distinguished by argument type, but not return type

    void g() const { std::cout << "B::g() "; } // B::g() is always called, for all derived classes as it is non-virtual

    void h() const {
        f(); // calls D::f() for object of `D`
    }
};

struct D : B {
    virtual void f() const override { std::cout << "D::f() "; }
    void f(int a) const override { std::cout << "D::f(int a)"; }
    virtual void g() const { std::cout << "D::g() "; } // does not override B::g() [B::g() is not virtual]
};

struct DD : D {
    // void f() override { std::cout << "DD::f()"; } // error: compiler tells that, 
                                                     // D::f() cannot be overriden as `const` keyword is missing 
                                                     // Hence, `override` keyword acts as a compiler check
    void f() const { std::cout << "DD::f() "; } // overrides D::f() [override keyword is not required.]
    void g() const { std::cout << "DD::g() "; } // does not override D::g() even though D::g() is virtual
};

void call(const B& obj) {
    obj.f();
    obj.g();
    
    std::cout << "\n";
}

/**
 * win has a vector of shapes [circle/rectange/poly]
 * loop on shapes
 * call shape[i].draw()
 * Shape.draw() calls draw_lines() [of type virtual]
 * IF derived class has an override call it
 */

int main() {
    B b;
    D d;
    DD dd;

    // d.h();
    // std::cout << '\n';

    call(b);
    call(d);
    call(dd);

    /* Output:
        When call(const B& obj): (no object copying occurs)
            B::f() B::g() 
            D::f() B::g()
            DD::f() B::g()
        When call(const B obj): (Object slicing occurs)
            B::f() B::g()
            B::f() B::g()
            B::f() B::g()
     */
}