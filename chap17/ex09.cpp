/** Which way does the stack grow: up (toward higher addresses) or
down (toward lower addresses)? Which way does the free store
initially grow (that is, before you use delete)? Write a program to
determine the answers. */

#include <iostream>

int x = 1;
int y = 2;

int main() {
	std::cout << "static storage grows " <<  ((&y - &x) > 0 ? "up (addresses increase)" : "down (addresses decrease)") << "\n";

	int a = 5;
	int b = 10;

	int arr[2] = {1,2};

	std::cout << "stack grows " <<  ((&b - &a) > 0 ? "up (addresses increase)" : "down (addresses decrease)") << "\n";
	std::cout << "stack array grows " <<  ((&arr[1] - &arr[0]) > 0 ? "up (addresses increase)" : "down (addresses decrease)") << "\n";

	int* x = new int[2];
	std::cout << "free store grows " << ((&x[1] - &x[0]) > 0 ? "forwards (addresses increase)" : "backwards (addresses decrease)");
	std::cin.get();
}