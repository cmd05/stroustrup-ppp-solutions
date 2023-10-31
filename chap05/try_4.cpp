#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("My Error");
    } catch(std::exception& e) {
        std::cout << "caught";
    }
    
    std::cout << "this does not print";
    // Uncaught exception
}