/** Which way does the stack grow: up (toward higher addresses) or
down (toward lower addresses)? Which way does the free store
initially grow (that is, before you use delete)? Write a program to
determine the answers. */

#include <iostream>

int main() {
	int a = 5;
	int b = 10;

	std::cout << "stack grows " <<  ((&b - &a) > 0 ? "up" : "down") << "\n";

	int* x = new int[2];
	std::cout << "free store grows " << ((&x[0] - &x[1]) < 0 ? "forwards" : "backwards");
	std::cin.get();
}