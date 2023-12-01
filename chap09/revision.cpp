#include <iostream>

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month int_to_month(int x) {
    if(x < int(Month::jan) && x > int(Month::dec)) throw std::runtime_error("Error");
    return Month(x);
}

class A {
public:
    A(int x, int y): x{x}, y{y} {}
    A(const A& a): x{a.x}, y{a.y} { std::cout << "called cp constructor\n"; }
    A& operator=(const A& a) {std::cout << "cp assignment\n"; x = a.x; y = a.y; return *this;} // return for chaining assignments
    
    int unmod_1() { return x; } // will give error if used on const object
    // int unmod_2() const { x++; return x; } // member variables cannot be modified in const member function
    int unmod_3() const { return x; } // correct

private:
    int x, y;
};

void gap() {
    std::cout << "\n\n";
}

void test_const(const A& a) {
    // std::cout << a.unmod_1(); // cannot call member functions on const object, unless member function is qualified with
                              // `const` keyword as in unmod_2()
    // std::cout << a.unmod_2(); // error
    std::cout << a.unmod_3();
}

int& f() {
    // int i = 1;
    // return i; // never return reference to local variable

    static int x = 30;
    return x; // returning reference to local static variable is allowed and works correctly
}

int main() {
    /* Enum object initialization: */
    // Month m2 = 1; // not allowed
    Month m {1}; // allowed as per c++17
    Month m3 {Month::jan}; // allowed
    Month m4 = Month(11); // allowed (does not check if int specified is inside enum range)
    std::cout << int(m4); // prints `11`
    
    // std::cout << bool(true == 1); // example of implicit conversion and then checking
    // std::cout << bool(Month::jan > 1); // enum vs int (error: operands do not match for specified operation). 
                                          // Or define operator overload to compare Enum month and 
                                          // integer without explicit type conversion
    // for comparing `class` object Date to int. Operator overloading is required to be defined
    gap();

    A a{1, 2}; // normal ctor
    A a1 = a; // copy ctor
    a1 = a; // copy assignment

    test_const(a);
    
    std::cout << f(); // 30

    // std::cout << Date{1998, Month::jan, 4}; // A temporary object lives until the end of the statement
    //                                         // i.e the temporary object is destroyed at the end of the std::cout stmt
    // Date{1998, Month::jan, 4}; // destroyed immediately after semicolon

    // int x {5}; // int is a built-in type (not a class), but we can still initializer list syntax to initialize it

}