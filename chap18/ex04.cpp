#include <iostream>

int str_len(const char* s) {
    int sz = 0;
    for(; *s; s++) sz++;
    return sz;
}

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

const char* findx(const char* s, const char* x) {
    for(; *s; s++) {
        if(*s == *x) { // first letter match
            bool is_match = true;
            const char* begin = s;

            for(const char* x2 = x; *x2; x2++, s++) {
                if(!*s || *x2 != *s) { // if src is over OR letters dont match
                    is_match = false; 
                    break;
                }
            }

            if(is_match) return begin;
        }
    }

    return nullptr;
}

int strcmp(const char* s1, const char* s2) {
    for(; *s1 && (*s1 == *s2); s1++, s2++);
    return *s1 - *s2; 
}

int main() {
    char bad_string1[] = {'H', 'o', 'l', 'a'};
    char bad_string2[] = {'A', 'd', 'i', 'o', 's'};
    // these errors are pretty nasty rip
    std::cout << str_len(bad_string1) << "\n";
    std::cout << strdup(bad_string1) << "\n";
    std::cout << strcmp(bad_string1, bad_string2) << "\n";
    std::cout << findx(bad_string1, bad_string2) << "\n";
}