#include <iostream>
#include <list>
#include <vector>

int main() {
    int arr[10];

    int* p1 = &arr[10]; // UB, out of range access (dereference happens first)
    int* p2 = arr+10; // ok, dont dereference this (can compare to check for end of array)
    int i1 = arr[10]; // UB, out of range access
}