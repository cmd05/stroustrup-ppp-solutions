// Write  a  function  that  takes  an  array  of  ints  as  its  input  and  finds  the  
// smallest and the largest elements. It should also compute the median and 
// mean. Use a struct holding the results as the return value.

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct result {
    int smallest;
    int largest;
    int mean;
    int median;
} result;

int int_cmp(const void* lhs, const void* rhs) {
    const int* a = (const int*) lhs;
    const int* b = (const int*) rhs;

    if(*a == *b)
        return 0;
    
    if(*a > *b)
        return 1;
    
    return -1;
}

int main() {
    // int sz = 10;
    // int arr[] = {552,-927,-61,-905,463,355,525,45,-897,-318};

    int sz = 9;
    int arr[] = {552,-927,-61,-905,463,355,525,45,-897};


    result res;

    res.smallest = arr[0];
    res.largest = arr[0];


    for(int i = 0; i < sz; i++) {
        if(arr[i] > res.largest)
            res.largest = arr[i];
        
        if(arr[i] < res.smallest)
            res.smallest = arr[i];
        
        res.mean += arr[i];
    }

    res.mean /= sz;

    qsort(arr, sz, sizeof(int), int_cmp);

    if(sz % 2 == 0)
        res.median = (arr[sz/2] + arr[sz/2 - 1]) / 2.0;
    else
        res.median = arr[sz/2];

    printf("%i %i %i %i", res.smallest, res.largest, res.mean, res.median);
}