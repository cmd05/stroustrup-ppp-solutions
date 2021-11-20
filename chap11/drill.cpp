#include <iostream>
#include <iomanip>      // std::setw

int main() {
    int birth_year = 2004;
    std::cout << std::showbase;
    std::cout << "Decimal: " << birth_year << "\t"
              << "Hex: " << std::hex << birth_year << "\t"
              << "Oct: " << std::oct << birth_year << "\n";
    
    int age = 16;
    std::cout << std::dec << "Age: " << age << "\n";

    // int a, b, c, d;
    // std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    // std::cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;
    // std::cin >> std::dec;

    double floating_point = 12345567.89;
    std::cout << std::defaultfloat << floating_point  << "\t"
              << std::fixed << floating_point << "\t"
              << std::scientific << floating_point << "\n";

    std::cout << std::setw(10) << "cmd" << "|"
              << std::setw(10) << "3BOT" << "|"
              << std::setw(10) << "1231231230" << "|"
              << std::setw(30) << "cmd05@mail.in" << "|\n";
              
    std::cout << std::setw(10) << "mohammed" << "|"
            << std::setw(10) << "iftaar" << "|"
            << std::setw(10) << "1231231230" << "|"
            << std::setw(30) << "mmmd@snl.in" << "|\n";
}