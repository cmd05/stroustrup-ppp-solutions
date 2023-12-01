#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

void fill_vector(std::ifstream& ist, std::vector<int>& v, char terminator) {
    // throw exception on bad state
    ist.exceptions(ist.exceptions() | std::ios_base::badbit); // throws ios_base::failure

    for(int i; ist >> i;) v.push_back(i);
    if(ist.eof()) {
        // if terminator character is present, the flag will be fail (reading char instead of int)
        // and not eof flag.
        // if file ends with no terminator, i.e file ends with last integer, ist will have eof flag
        std::cout << "eof flag";
        return;
    } 

    if(ist.bad()) 
        std::cout << "bad flag";

    if(ist.fail()) {
        std::cout << "fail flag";

        ist.clear(); //clear error flag on ist (set to goodbit)

        char c;
        ist >> c;

        if(c != terminator) { // unexpected char
            std::cout << "invalid terminator";

            // Makes the most recently extracted value available again.
            ist.unget(); // goes back to position before most recently read value, i.e most recently read value will be read when ist is used again 
            ist.clear(std::ios_base::failbit); // reset to fail state
        }
    }
}

int main() {
    try {
        /* std::cout << "Enter a number: ";
        int i = 0;
        std::cin >> i;
        if(!std::cin) {
            if(std::cin.bad()) {
                throw std::runtime_error("state: bad");
            }

            if(std::cin.eof()) {
                std::cout << "------ End of Input -------";
            }

            if(std::cin.fail()) {
                std::cout << "Failed input";
                std::cin.clear();
                // Recover and take input back
            }
        } */
        std::ifstream ist{"terminating_numbers.txt"};
        std::vector<int> v;
        fill_vector(ist, v, '*');
        for(int x : v) std::cout << x << " ";
    } catch(std::runtime_error& e) {
        std::cout << e.what();
    }
}