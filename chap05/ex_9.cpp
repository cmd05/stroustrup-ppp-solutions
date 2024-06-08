/* . Modify the program from exercise 8 to write out an error if the result
cannot be represented as an int. */

#include <iostream>
#include <vector>
#include <algorithm>

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
        if(sum > std::numeric_limits<int>::max()) throw std::runtime_error("Sum cannot be  represented as INT");

        std::cout << "Sum of the " << n << " numbers is " << sum;
    } catch(std::exception& e) {
        std::cerr << e.what();
    }
}