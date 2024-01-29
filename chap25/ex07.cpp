/* Write out the hexadecimal values from 0 to 400; write out the hexadeci-
mal values from –200 to 200. */

#include <iostream>

int main() {
    for(int i = 0; i <= 400; i++)
        std::cout << std::dec << i << "\t0x" << std::hex << i << '\n';

    std::cout << '\n';

    for(int i = -200; i <= 200; i++)
        std::cout << std::dec << i << "\t0x" << std::hex << i << '\n';
}