// Write a program that does the equivalent of string s; cin>>s; in C; that 
// is,  define  an  input  operation  that  reads  an  arbitrarily  long  sequence  of  
// whitespace-terminated characters into a zero-terminated array of chars.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reads until '\n' or EOF
const char* read_string(FILE* fs) {
    unsigned int sz = 8; // start with initial 8 bytes
    unsigned int max_len = 16;
    unsigned int i = 0;

    char* string = (char*) malloc(sizeof(char) * sz);

    for(;;) {
        char c = getc(fs);
        
        if(c == '\n' || c == EOF)
            break;
        
        if(i == sz - 1) // last char is '\0'
            if(i == max_len - 1) // last char is '\0'
                break; // ignore any input after max_len
            else {
                sz *= 2; // double allocation size
                char* p = string;

                string = (char*) malloc(sizeof(char) * sz);
                memcpy(string, p, i);

                free(p); // free old allocation
            }

        string[i] = c;
        
        i++;
    }

    // finally copy string to location equal to its length
    unsigned int input_len = i + 1;

    char* p = (char*) malloc(sizeof(char) * input_len);
    memcpy(p, string, input_len);

    free(string); // free old string

    p[i] = 0;

    return p;
}

int main() {
    printf(read_string(stdin));
}