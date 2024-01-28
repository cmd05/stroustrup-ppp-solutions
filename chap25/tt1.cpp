#include <iostream>
#include <string>
#include "../includes/std_lib_facilities.h"

struct Message {
	int x;
	int y;
	int z;
};

struct Node {
	int x;
	int y;
};

int main() {
	int i = 0;
	std::cout << sizeof(Message) << '\t' << sizeof(Node) << "\n\n";

	while(i < 10) {
		Message* p = new Message{randint(100), randint(100), randint(100)};
		std::cout << reinterpret_cast<uintptr_t>(p) << '\n';

		Node* n1 = new Node{randint(50), randint(50)};
		std::cout << reinterpret_cast<uintptr_t>(n1) << '\n';

		delete p;

		Node* n2 = new Node{randint(50), randint(50)};
		std::cout << reinterpret_cast<uintptr_t>(n2) << '\n';
		
		std::cout << '\n';

		i++;
	}
}