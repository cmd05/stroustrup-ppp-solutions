#include "document.h"

#include <iostream>
#include <fstream>

int main() {
    document d;
    std::ifstream ifs {"doc.in"};
    std::ofstream ofs {"doc.out"};

    ifs >> d;

    d.print_all(ofs);

    std::string s = "hello";
    auto p = d.find(s);

    if(p != d.end()) std::cout << *p;
}