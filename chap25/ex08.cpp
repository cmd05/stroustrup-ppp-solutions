// Write out the numerical values of each character on your keyboard.

#include <iostream>

int main() {
    std::cout << "\\t" << '\t' << int('\t') << '\n';
    std::cout << "\\n" << '\t' << int('\n') << '\n';

    std::cout << "<space>" << '\t' << int(' ') << '\n';

    for(char c = '!'; c <= '~'; c++)
        std::cout << c << '\t' << int(c) << '\n';
}