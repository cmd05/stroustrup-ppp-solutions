// Implement versions of strlen(), strcmp(), and strcpy()

#include <stdio.h>

int strcmp(const char* s1, const char* s2) {
    for(int i = 0; s1 && s2; i++)
        if(s1[i] != s2[i])
            break;
    
    return *s1 - *s2;
}

int main() {
    printf("%i", strcmp("hello", "hello world"));
}