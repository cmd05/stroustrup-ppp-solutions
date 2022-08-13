#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using str_iterator = std::string*;


str_iterator find_str(str_iterator f, str_iterator l, bool greatest = false) {
    str_iterator res = f;
    for(str_iterator p = f; p != l; p++) {
        if(greatest)
            if(*p > *res) res = p;
        else
            if(*p < *res) res = p;
    }

    return res;
}

int main() {
    std::vector<std::string> v 
        {"lc0ea", "j1rwj", "eq5pn", "wx1nk", "47mnv", "gja64", "i39b5", "pgn5t", "7z1bp", "650lw"};
    
    std::cout << *find_str(&v[0], &v[0] + v.size(), true);
}