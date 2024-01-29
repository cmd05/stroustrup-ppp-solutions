/* Without  using  any  standard  headers  (such  as  <limits>)  or  documenta-
tion, compute the number of bits in an int and determine whether char is 
signed or unsigned on your implementation */

#include <iostream>

int main() {
    long long int x = 0;
    int bytes = 1;

    while(true) {
        x ^= 0xff;
        if(x == -1)
            break;
        x <<= 8;
        bytes++;
    }

    std::cout << bytes << '\n';

    char c = -1;
    if(int(c) == -1)
        std::cout << "signed";
    else
        std::cout << "unsigned";
}