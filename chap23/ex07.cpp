/* Write a program that finds dates in a text file. Write out each line contain-
ing at least one date in the format line— number: line. Start with a regular 
expression  for  a  simple  format,  e.g.,  12/24/2000,  and  test  the  program  
with that. Then, add more formats. */

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream ifs {"credit_card_nums.txt"};

    // mm/dd/yyyy
    std::regex exp {R"(4[0-9]{12}(?:[0-9]{3})?)"};
    int line_no = 0;

    for(std::string line; std::getline(ifs, line);) {
        ++line_no;
        
        std::smatch matches;
        auto search_it = line.cbegin();

        while(std::regex_search(search_it, line.cend(), matches, exp)) {
            std::cout << line_no << ": " << line << '\n';
            search_it = matches.suffix().first;
        }
    }
}