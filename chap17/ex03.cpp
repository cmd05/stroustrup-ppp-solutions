#include <iostream>

void to_lower(char* s) {
    for(int i = 0; s[i]; i++) 
        if(s[i] >= 65 && s[i] <= 90) s[i] += 32;
}

int main() {
    char c_str[] = "Hello, World!";
    to_lower(c_str);

    std::cout << c_str;
}