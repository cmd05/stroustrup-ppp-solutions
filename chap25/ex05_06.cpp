#include <iostream>

int main() {
    // while(1) {}

    // for(unsigned int i = -1; i >= 0; i++)
    //     std::cout << "yo\n";

    /* terminate called after throwing an instance of 'std::bad_alloc'
    what():  std::bad_alloc */
    while(1) {
            int *pBigDataArray = new int[100000000L];
    }
}