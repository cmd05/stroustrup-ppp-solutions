#include <iostream>

class Shape {    
public:
    void draw() const;    
protected:
    Shape() {}

    // member functions declared inside class are automatically inlined
    // hence there is no performance penalty for these access/modifier functions 
    void Shape::set_point(int i, Point p) { points[i] = p; }
    void Shape::point(int i) const { return points[i]; }
private:
    std::vector<Point> points;
    Color lcolor{fl_color()}; // color for lines and characters (set to default color)
    Line_style ls {0};
    Color fcolor {Color::invisible};
};

int main() {
    // Shape sh;

    /* 
     Analogy: Camera (abstract class) -> Nikon Z5 (concrete class) -> Nikon Z5 camera instance (object i.e has unique serial number)
    */
   
    // protected constructor: does not allow instantation of Base, but allows inheritance
    // private constructor: neither instantiation nor inheritance of base is allowed

    
    // Note:
    Base b; // error
    Der d;
    Base& b1 = d; // ok
}