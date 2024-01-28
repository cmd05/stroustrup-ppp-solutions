#include <iostream>
#include <vector>
using namespace std;

struct Point { int x, y; };

class Shape {
public:
    virtual void draw() {}
protected:
    Shape() {}
};

class Circle : public Shape {
    int x,y,z;
public:
    void draw() override { std::cout << "Circle::draw()\n"; }
};

class Rectangle : public Shape {
public:
    Rectangle(Point, Point) {}
    void draw() override {}
};

class Polygon : public Shape {
public:
    Polygon() {}
};

void poor(Shape* p, int sz)        // poor interface design
{
          for (int i = 0; i<sz; ++i) p[i].draw();
}

void f(Shape* q, vector<Circle>& s0)   // very bad code
{
          poor(&s0[0],s0.size());          // #1 (pass the array from the vector)

        //   Polygon s1[10];
        //   Shape s2[10];
        //   // initialize
        //   Shape* p1 = new Rectangle{Point{0,0},Point{10,20}}; 
        //   poor(&s0[0],s0.size());          // #1 (pass the array from the vector)
        //   poor(s1,10);                            // #2
        //   poor(s2,20);                             // #3
        //   poor(p1,1);                              // #4
        //   delete p1;
        //   p1 = 0;
        //   poor(p1,1);                              // #5
        // //   poor(q,20);                           // #6
}

int main() {
    // Device_driver* p = reinterpret_cast<Device_Driver*>(0xffb8);
    std::cout << sizeof(Shape) << ' ' << sizeof(Circle) << '\n';

    Shape* s = new Circle;
    std::vector<Circle> c {{}, {}, {}};
    f(s,c);
}