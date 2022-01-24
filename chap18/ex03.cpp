/* 
    Write a function, int strcmp(const char* s1, const char* s2), that
    compares C-style strings. Let it return a negative number if s1 is
    lexicographically before s2, zero if s1 equals s2, and a positive
    number if s1 is lexicographically after s2. Do not use any standard
    library functions. Do not use subscripting; use the dereference
    operator * instead.
*/

#include <iostream>

int strcmp(const char* s1, const char* s2) {
    for(; *s1 && (*s1 == *s2); s1++, s2++);
    return *s1 - *s2; 
}

int main() {
    std::cout << strcmp("boy", "boi");
}