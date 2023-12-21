/* 9.  Which way does the stack grow: up (toward higher addresses) or down (to-
ward lower addresses)? Which way does the free store initially grow (that 
is, before you use delete)? Write a program to determine the answers */

#include <iostream>

int main() {
    int x, y;
    int* p = new int[2];
    std::cout << &y - &x << '\n'; // out: -1 (grows towards lower addresses)
    std::cout << &p[1] - &p[0]; // out: 1 (grows towards higher address)
}