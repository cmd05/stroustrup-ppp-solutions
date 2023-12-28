#include <iostream>

char* strdup(const char* str) {
    int sz = 0;
    char* p = const_cast<char*>(str);
    
    for(; *p; p++) sz++;
    sz += 1; // additional null terminator

    char* new_str = new char[sz];

    std::copy(str, str + sz, new_str);

    return new_str;
}

int main() {
    char* new_str = strdup("helloworld");
    std::cout << new_str;
}