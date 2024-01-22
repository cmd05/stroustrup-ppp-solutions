#include <iostream>
#include <regex>

int main() {

    std::regex r {"."};
    std::string s {"\n"};
    std::smatch m;

    if(std::regex_search(s, m, r))
        std::cout << "yes";
    else
        std::cout << "no";
}