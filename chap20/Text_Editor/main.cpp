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

void read_replace(Document& doc) {
	while(true) {
		std::string s1, s2;
		std::cout << "search: ";
		if(!(std::cin >> s1)) break;

		std::cout << "replace: ";
		if(!(std::cin >> s2)) break;

		doc.replace(doc.begin(), doc.end(), s1, s2);
		write_doc(doc);
	}
}

int main() {
	Document mydoc;

	std::ifstream ist {"doc.in"};
	ist >> mydoc;

	write_doc(mydoc);

	auto p = mydoc.find(mydoc.begin(), mydoc.end(), "with");

	std::cout << mydoc.char_count();
	mydoc.replace(mydoc.begin(), mydoc.end(), "to", "txxx", 9);

	write_doc(mydoc);
}