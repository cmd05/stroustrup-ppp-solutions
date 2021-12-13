/* Do exercise 7 again, but this time read into a std::string rather than
to memory you put on the free store (string knows how to use the free
store for you). */

#include <iostream>
#include <string>

int main() {
	std::string str;
	for(char c; std::cin >> c;) {
		str += c;
		if(c == '!') break;
	}
	std::cout << str;
}