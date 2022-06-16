/* Write a program that reads and stores a series of integers and then
computes the sum of the first N integers. First ask for N, then read the
values into a vector, then calculate the sum of the first N values. For
example:
"Please enter the number of values you want to sum:"
3
"Please enter some integers (press '|' to stop):"
12 23 13 24 15 |
"The sum of the first 3 numbers ( 12 23 13 ) is 48."
Handle all inputs. For example, make sure to give an error message if
the user asks for a sum of more numbers than there are in the vector. */

#include <iostream>
#include <vector>

int main() {
    try {
        int n;
        std::cout << "Enter the number of values: ";
        std::cin >> n;
        if(!std::cin) throw std::runtime_error("Invalid Input");
        std::vector<int> v;
        std::cout << "Enter values (end with'|')";
        for(int x; std::cin >> x;) v.push_back(x);

        if(v.size() != n) throw std::runtime_error("You entered wrong number of inputs");

        int sum = 0;
        for(int x : v) sum += x;

        std::cout << "Sum of the " << n << " numbers is " << sum;
    } catch(std::exception& e) {
        std::cerr << e.what();
    }
}