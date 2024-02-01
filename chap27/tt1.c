#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cat(const char* id, const char* addr)
{
    int len_id = strlen(id);
    int len_addr = strlen(addr); 
    int sz = len_id + len_addr + 2; // '@' and zero-terminator also
    char* res = (char*) malloc(sz); // caller must free the string

    strcpy(res,id);
    res[len_id] = '@';

    strcpy(res+len_id+1,addr);

    res[sz-1] = 0; // terminate string

    return res;
}

int main() {
    const char* id = "cmd05";
    char* email = cat(id, "fluttering-feathers.tech");

    printf(email);

    free(email);
}