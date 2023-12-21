/* Write a function, char* strdup(const char*), that copies a C-style string 
into memory it allocates on the free store. Do not use any standard library 
functions. */

#include <iostream>

char* strdup(const char* s) {
    // get size of s
    int sz = 0;    
    for(; s[sz]; sz++);

    char* s2 = new char[sz+1]; // last char is '\0'

    // assign value of *s to *s2
    for(int i = 0; i < sz; i++) s2[i] = s[i];
    s2[sz] = '\0';

    return s2;
}

int main() {
    char s[] = "Hello World";
    char* s2 = strdup(s);

    std::cout << s2; 
}