#include <iostream>
#include <string>
#include <vector>
#include "Chrono.h"

int main()
{
    Chrono::Date dd{};
    std::cin >> dd;
    dd.add_year(5);

    std::cout << dd;
}