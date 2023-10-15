#include <iostream>
#include <regex>
#include <string>
#include <fstream>


int main() {
	std::regex pt {R"(\w{2}\s*\d{5}(–\d{4})?)"};
	std::ifstream is {"data.txt"};

	int line_no = 0;
	for(std::string line; std::getline(is, line);) {
		++line_no;
		std::smatch matches;
		if(std::regex_search(line, matches, pt))
			std::cout << line_no << ": " << matches[0] << '\n';
		if(matches[1].matched)
			std::cout << "\t:" << matches[1] << '\n';
	}
}