#include <iostream>

char* strdup(const char* s) {
    // get size of s
    int sz = 0;
    for(int i = 0; s[i]; i++) sz++;

    // add chars to s2
    char* s2 = new char[sz + 1];
    for(int i = 0; s[i]; i++) s2[i] = s[i];
    
    s2[sz] = '\0'; // terminate string

    return s2;
}

int main() {
    char c_str[] = "Hello, World!";
    char* s2 = strdup(c_str);
    std::cout << s2;
}