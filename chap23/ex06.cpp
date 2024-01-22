/* Write a program that finds dates in a text file. Write out each line contain-
ing at least one date in the format line— number: line. Start with a regular 
expression  for  a  simple  format,  e.g.,  12/24/2000,  and  test  the  program  
with that. Then, add more formats. */

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream ifs {"date_file.txt"};

    std::vector<int> days_tbl = {31,28,31,30,31,30,31,31,30,31,30,31};

    int min_year = 1700;
    int max_year = 2100;
    
    // mm/dd/yyyy
    std::regex exp {R"((\d{2})/(\d{2})/(\d{4}))"};
    int line_no = 0;

    for(std::string line; std::getline(ifs, line);) {
        ++line_no;

        std::smatch matches;
        auto search_it = line.cbegin();

        while(std::regex_search(search_it, line.cend(), matches, exp)) {
            int m = std::stoi(matches[1]);
            int d = std::stoi(matches[2]);
            int y = std::stoi(matches[3]);

            if((1 <= m && m <= 12) && (1 <= d && d <= days_tbl[m-1]) && (min_year <= y && y <= max_year)) {
                std::cout << line_no << ": " << line << '\n';
                break;
            }
            
            search_it = matches.suffix().first;
        }
    }
}