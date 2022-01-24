#include <iostream>

int str_len(const char* s) {
    int sz = 0;
    for(; *s; s++) sz++;
    return sz;
}

char* cat_dot(const char* s1, const char* s2, const char* sep) {
    int len = str_len(s1) + str_len(s2) + str_len(sep);
    char* str = new char[len + 1];

    int index = 0;
    for(; *s1; s1++, index++) str[index] = *s1;
    for(; *sep; sep++, index++) str[index] = *sep;
    for(; *s2; s2++, index++) str[index] = *s2;
    str[len] = '\0';

    return str;
}

int main() {
    char* s = cat_dot("Neils", "Bohr", "----");
    std::cout << s;
    delete[] s;
}