#include <iostream>
using namespace std;

/* unsigned - special; only +ve */

/* # caller callee error */

// int area(int x, int y) {
//     return x*y;
// }

// callee
int area(int x, int y) {
    if(x <= 0 || y <= 0) throw std::runtime_error("side length invalid"); // exits fn.
    cout << "this does not print if error is thrown\n";
    return x*y;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    
    // caller
    // if(x <= 0 || y <= 0) throw std::runtime_error("side length invalid");
    
    cout << area(x, y);
}

/* # check if input operation succ */
int in1, in2;

std::cin >> in1 >> in2;
if(std::cin) std::cout << "valid input";
else std::cout << "invalid input";

cout << "continued"; // program continues even if input is invalid

/* # try-catch c++ */

/* 
    Generally: error - a problem that an application should not try to catch and recover from
    exception - a problem that an application should catch and recover from
 */
try {

} catch(const std::exception& e) {
    // catch exception objects of type std::exception

    // use of const to indicate exception object will not be modified
    // use of reference is to prevent object slicing and polymorphism stuff - see chap05/slicing_example.cpp
} catch(...) {
    // exception of any other type
}

try {
    double discriminant = b*b - 4*a*c;
    if(discriminant < 0) {
        throw std::runtime_error("Imaginary roots");
    } else {
        discriminant = sqrt(discriminant);
    }
    double x1 = (b + discriminant) / (2*a);
    double x2 = (b - discriminant) / (2*a);
    std::cout << "The solutions are: " << x1 << ", " << x2;
    return 0;
} catch(std::exception& e) {
    std::cerr << e.what();
}

precondtion: if(x <= 0 || y <= 0) throw std::runtime_error("invalid side length")
post condition: if(area <= 0) throw std::runtime_error("invalid area")

// multiple conditions for same switch case
case 'c': case 'C':
    std::cout << "cC";
    break;
case 'k': case 'K':
    std::cout << "kK";
    break;

// multiple cases error throwing
    switch(u) {
        case 'C': case 'c':
            if(t < -273.15) throw runtime_error("Temperature below abs zero");
            return t + 273.15;
            break;
        case 'K': case 'k':
            if(t < 0) throw runtime_error("Temperature below abs zero");
            return t - 273.15;
            break;
        default:
            throw runtime_error("Invalid Unit");
            break;
    }

// overflow / underflow safe addition

// programmer must define numeric_limits in std namespace for user-defined types
template<typename T>
int safe_add(T a, T b, T max = std::numeric_limits<T>::max(), T min = std::numeric_limits<T>::min()) {
    if(a > 0 && b > max - a) throw std::runtime_error("overflow");
    if(a < 0 && b < min - a) throw std::runtime_error("underflow");

    return a + b;
}

// Example UDT
namespace std {
    template<> class numeric_limits<Temperature> {
    public:
       static Temperature min() {return Temperature(-273.15f);};
       // One can implement other methods if needed
    };
}

// digit to char
char('0'+1) => '1'
// char to digit
int('1'-'0') => 1

// std::exception -  base class for exceptions thrown by the standard library components

/*  Standard exceptions

    logic_error
        invalid_argument
        domain_error
        length_error
        out_of_range
        future_error (since C++11)
    runtime_error
    range_error
    overflow_error
    etc ...
*/