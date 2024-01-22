#include <iostream>
#include <regex>
#include <string>
#include <fstream>

int main() {
	// std::regex pat {R"(\w{2}\s*\d{5}(-\s*\d{4})?)"};
	std::regex pat {R"("[[:alnum:]]+")"};

	// raw string literal is given by R"(<stuff>)"

	std::ifstream ifs {"in2.txt"};

	int line_no = 1;
	for(std::string s; std::getline(ifs, s); line_no++) {
		std::smatch matches;
		if(std::regex_search(s, matches, pat)) // returns true if match exists
			std::cout << line_no << ": " << matches[0] <<  '\n';
			if(matches[1].matched) // when matches[i].matched==false, matches[i]=="" (empty string)
				std::cout << "\t: " << matches[1] << '\n';
	}
}