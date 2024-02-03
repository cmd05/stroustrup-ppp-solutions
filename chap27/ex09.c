// Using only C facilities, including the C standard library, read a sequence 
// of  words  from  stdin  and  write  them  to  stdout  in  lexicographical  order.  
// Hint: The C sort function is called qsort(); look it up somewhere. Alter-
// natively, insert the words into an ordered list as you read them. There is 
// no C standard library list.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pstrcmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    unsigned int n = 0;
    unsigned int max_size = 100000; // a reasonable maximum size
    
    printf("Enter number of words to enter: ");
    scanf("%u", &n);

    if(n >  max_size) {
        printf("error: n exceeds max_size");
        return 0;
    }


    char** list = (char**) malloc(n*sizeof(char*));
    
    {
        unsigned int i = 0;
        unsigned int len = 0;

        printf("Enter one word on each line: \n");

        for(char s[1000]; i < n && scanf("%999s%n", s, &len); i++) { // reasonable word length is 1000
            list[i] = (char*) malloc(sizeof(char)*len);
            strcpy(list[i], s);
        }

        if(i < n) {
            printf("error: number of words is less than n");
            return 0;
        }
    }

    qsort(list, n, sizeof(char*), pstrcmp);
    
    for(unsigned int i = 0; i < n; i++)
        printf("%s %s", list[i], "\n");
}