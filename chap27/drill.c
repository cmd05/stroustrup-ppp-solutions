/* 1.  Write a “Hello, World!” program in C, compile it, and run it. 
  2.  Define two variables holding “Hello” and “World!” respectively; concat-
enate them with a space in between; and output them as Hello World!.
  3.  Define a C function that takes a char* parameter p and an int parameter x 
and print out their values in this format: p is "foo" and x is 7. Call it with 
a few argument pairs */

#include <stdio.h>
#include <string.h>

void fn(char* p, int x) {
    printf("p is %s and x is %i\n", p, x);
}

int main() {
    // printf("Hello World");

    char* s1 = "Hello";
    char* s2 = "World!";
    int s_len = strlen(s1) + strlen(s2) + 2;
    char s[s_len]; // space and terminator

    strcpy(s, s1);
    strcat(s, " ");
    strcat(s, s2); // ends with null-terminator
    
    printf("%s\n", s);

    fn("foo", 7);
    fn("Hello", -1);
}