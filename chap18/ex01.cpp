#include <iostream>

char* strdup(const char* str) {
    // get size
    const char* p = str; 
    int sz = 0;
    for(; *p; p++, sz++);

    // allocate string on memory
    char* n = new char[sz+1];
    char* x = n;
    p = str;

    // initialize chars
    while(*p) *(n++) = *(p++); 
    *n = '\0';

    return x;
}

int main() {
    const char* str = "Hello World!";
    std::cout << strdup(str);
}