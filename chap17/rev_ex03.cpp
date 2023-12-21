/* Write a function, void to_lower(char* s), that replaces all uppercase char-
acters  in  the  C-style  string  s  with  their  lowercase  equivalents.  For  ex-
ample,  Hello,  World!  becomes  hello,  world!.  Do  not  use  any  standard  
library functions. A C-style string is a zero-terminated array of characters, 
so if you find a char with the value 0 you are at the end. */

#include <iostream>

void to_lower(char* s) { // array decays to ptr
    for(int i = 0; s[i]; i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}

int main() {
    // "some string" == const char* always (c-style strings)
    char* s = "Hello World"; // s points to a `string constant`. this declaration gives UB
                             // (correct declaration is const char* s = "Hello World")
    to_lower(s); // invalid. s points to a string constant. hence it cannot be modified. Results in UB

    char s[] = "Hello World"; // ok
    std::cout << s; // ok
}