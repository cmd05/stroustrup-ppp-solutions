#include <iostream>
#include <vector>

class B {
    int x;
protected:
    B() {}
    B(const B&) =delete; // delete copy constructor
    B& operator=(const B&) =delete; // delete copy assignment
    // prevents slicing of data members between derived classes. 
    // Ex: Open_polyline op = marked_poly_obj; (Slices str of Marked_polyline) 
public:
    // B() {}
};

class D: public B {
public:
    D() {};
};

// Example of an 'interface'
class B1 {
protected:
    virtual void f() =0; // pvf
    virtual void g() =0; // pvf
};

class D1 : public B1 {
public:
    void f() override;
    // D1 is still abstract (B1::g() is not overriden)
};

class D2 : public D1 {
public:
    void g() override;
    // D2 is concrete, all pvfs are overriden
};

class D3 : public B1 {
public:
    void f() override;
    void g() override;
    // D3 is concrete
};

class Circle {
    int r;
public:
    Circle(int r): r{r} {}
    int radius() const { return r; }
};

enum Color { Yellow=1, Red, Blue };

class Smiley : public Circle {
    int half_rad = Circle::radius() / 2; // we can use Circle::radius(), as circle has been constructed
    
    struct Features {
        bool tears;
        Color color;
    };
public:
    // Smiley(int r) {} // error. Circle() is invalid. Circle be contructed by valid constructor, like Circle(int)
    Smiley(int r): Circle::Circle(r) {}
    int get_hr() const { return half_rad; }
};

/*
    Order:
    1. data members of Circle
    2. Circle constructor
    3. data members of Smiley
    4. Smiley constructor
*/

class Hat_Smiley : public Smiley {
    int hat_width = 10;
public:
    Hat_Smiley(int r): Smiley::Smiley(r) {}
    Hat_Smiley(int r, int hw): Smiley::Smiley(r), hat_width{hw} {}
};

int main() {
    // std::vector<B> b;
    // b.push_back(D{});
    
    // B1 b1; // error
    // D1 d1; // error
    // D2 d2; // ok
    // D3 d3; // ok

    Smiley s {10};
    std::cout << s.get_hr();
}