#include <iostream>
#include <iomanip>      // std::setw
#include <vector>
#include <string>

int main() {
    /* 
        oct 
        dec
        hex
        showbase
        noshowbase
     */

    // std::cout << 1234 << "\t" << std::hex << 1234 << "\t" << std::oct << 1234 << "\n";
    // std::cout << std::showbase << std::dec;
    // std::cout << 1234 << "\t" << std::hex << 1234 << "\t" << std::oct << 1234 << "\n";

    // int a, b, c, d;
    // std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
    // std::cout << a << "\t" << b << '\t' << c << "\t" << d;

    // std::cin.unsetf(std::ios::dec); // take 0x as hex
    // std::cin.unsetf(std::ios::hex); // dont assume hex. dec take as dec
    // std::cin.unsetf(std::ios::oct); // dont assume oct. dec take as dec

    /* double x = 1234561231231237.89;
    std::cout << x << "\t\t(default float)\n"
              << std::fixed << x << "\t(fixed)\n"
              << std::scientific << x << "\t(scientific)\n"; */

    /* double x = 12345678;
    std::cout << std::setprecision(5)
              << x << "\t\t(default float)\n"
              << std::fixed << x << "\t(fixed)\n"; */

    /* Set field width */
    /* int x = 123456;
    std::cout << x 
              << '|' << std::setw(4) << x << '|'
              << std::setw(8) << x << '|'
              << x << '|'; */
    std::cout << std::setw(10) << "cmd" << "|"
              << std::setw(10) << "3BOT" << "|"
              << std::setw(10) << "1231231230" << "|"
              << std::setw(30) << "cmd05@mail.in" << "|\n";
              
    std::cout << std::setw(10) << "mohammed" << "|"
            << std::setw(10) << "iftaar" << "|"
            << std::setw(10) << "1231231230" << "|"
            << std::setw(30) << "mmmd@snl.in" << "|\n";
}