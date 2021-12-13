#include <iostream>
#include <string>

int main() {
    double mb = 0;

    try {
        while(1) {
            char* c = new char[1000];
            mb+=0.001;
        }
    } catch(std::runtime_error& e) {
        std::cout << e.what() << "\n";
        std::cout << mb << " mb allocated.";
    } catch(...) {
        std::cout << mb << " mb allocated.";
        std::cin.get();
    }
}