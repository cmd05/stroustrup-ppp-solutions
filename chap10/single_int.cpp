#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <string>

int get_int();

void skip_to_int() {
    // not of type int
    if(std::cin.fail()) {
        std::cin.clear(); // clear errors so that we can read again

        for(char ch; std::cin >> ch;) { // skip past non digits
            if(isdigit(ch) || ch=='-') { // valid input
                std::cin.unget(); // puts character back into input stream - not empty
                return;
            }
        }
    }

    throw std::runtime_error("No input");
}

int get_int() {
    int n = 0;
    while(true) {
        if(std::cin >> n) return n;
        std::cout << "Wrong input. Retry: ";
        skip_to_int();
    }
}

int get_int(int low, int high) {
    int n = 0;
    while(true) {
        int n = get_int();
        if(low <= n && n <= 10) return n;
        std::cout << "Out of range. Retry: ";
    }
}

int main() {
    std::cin.exceptions(std::cin.exceptions() | std::ios_base::badbit); // throws ios_base::failure

    try {
        std::cout << "Enter a number: ";
        int m = get_int();
        std::cout << "m: " << m << "\n";
    } catch(std::runtime_error& e) {
        std::cerr << "Error: " << e.what();
    }

    // std::cout << "Enter a number 1-10 inclusive: ";
    // int n = get_int(0, 10);
    // std::cout << "n: " << n << "\n";
    // correct input
}