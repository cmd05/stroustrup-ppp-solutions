#include <iostream>
#include <fstream>
#include <sstream>

#include "Editor.h"

void input_doc(Document& doc) {	
	std::cout << "***START OF DOCUMENT***\n";
	std::cin >> doc;
}

void write_doc(Document& doc) {
	std::ofstream ost {"doc.out"};
	ost << doc;
}

int main() {
	Document mydoc;

	std::ifstream ist {"doc.in"};
	ist >> mydoc;

	write_doc(mydoc);

	auto p = mydoc.find_txt(mydoc.begin(), mydoc.end(), "one\nmay");

	if(p == mydoc.end()) std::cout << "string not found";
	else {
		mydoc.erase_line(p);
	}
	
	write_doc(mydoc);	
}