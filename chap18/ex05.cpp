#include <iostream>
#include <string>

std::string cat_dot(const std::string& s1, const std::string& s2) {
    std::string res = s1 + '.' + s2;
    return res;
}

int main() {
    std::cout << cat_dot("Neils", "Bohr");
}