#include <fstream>
#include <iostream>

int main() {
    /*
    std::cin.clear(std::ios_base::failbit);
    std::cin.clear(); // if a stream is in fail state, subsequent read/write operations will not occur
                      // Hence, stream state must cleared. clear() set stream to goodbit

    int x, y;
    std::cin >> x;
    std::cout << x;
    */

    std::ifstream is {"test_file.txt"};

    for(int i; is >> i;) {
        std::cout << i;
    }
    
    if(is.good()) std::cout << "failed";

    is.clear();
    char c; is >> c;
    std::cout << '\n' << c;
}