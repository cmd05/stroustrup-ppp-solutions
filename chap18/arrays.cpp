#include <iostream>

int str_len(const char* p) { // 0 terminated
    int len = 0;
    // for(;*p; len++, p++);
    while(*p != 0) { len++; p++; }

    return len;
}

int main() {
    double ad[10];
    double* p = &ad[5];
    *p = 7;
    p[2] = 2; // i = 7
    p[-3] = 9; // i = 2

    p += 2; // i = 4

    // Pointer to array
    
    // char arrays are NOT null terminated by default
    // only string literals "lol"
    char ch[100] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam non convallis nisl, ut orci aliquam";
    char* p2 = ch; // p2 = &ch[0]

    std::cout << str_len(p2);
}