/* Write a program to solve quadratic equations. A quadratic equation is
of the form
ax2 + bx + c = 0

If you don't know the quadratic formula for solving such an
expression, do some research. Remember, researching how to solve a
problem is often necessary before a programmer can teach the
computer how to solve it. 

Use doubles for the user inputs for a, b,
and c. Since there are two solutions to a quadratic equation, output
both x1 and x2.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main() {
    double a, b, c;
    std::cout << "Quadratic Solver \n";
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;

    double discriminant = b*b - 4*a*c;
    if(discriminant < 0) {
        throw std::invalid_argument("Imaginary roots");
    } else {
        discriminant = sqrt(discriminant);
    }
    double x1 = (-b + discriminant) / (2*a);
    double x2 = (-b - discriminant) / (2*a);
    std::cout << "The solutions are: " << x1 << ", " << x2;
    return 0;
}