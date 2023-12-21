/* Write a function, char* findx(const char* s, const char* x), that finds the 
first occurrence of the C-style string x in s. */

#include <iostream>

const char* findx(const char* s, const char* x) {
    for(int i = 0; s[i]; i++)
        if(s[i] == x[0]) {
            bool found = true;

            for(int j = 1; x[j] && s[i+j]; j++)
                if(x[j] != s[i+j]) {
                    found = false;
                    break;
                }
            
            if(found)
                return &s[i];
        }
    
    return nullptr;
}

int main() {
    const char* s = "Hello World";
    const char* x = "lo";

    const char* res = findx(s, x);
    std::cout << res;
}