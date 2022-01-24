#include <iostream>

int str_len(const char* s) {
    int sz = 0;
    for(; *s; s++) sz++;
    return sz;
}

bool is_palindrome(const char* s) {
    int sz = str_len(s);
    char* rev = new char[sz + 1];
    for(int i = 0; i < sz; i++) rev[i] = s[sz-i-1];
    
    for(int i = 0; i < sz; i++) if(s[i] != rev[i]) return false;
    return true;
}

int main() {
    std::cout << is_palindrome("11055011");
}