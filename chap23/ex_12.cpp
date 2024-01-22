/* Write  a  program,  based  on  the  program  that  finds  lines  containing  
dates  (exercise  6),  that  finds  all  dates  and  reformats  them  to  the  ISO  
yyyy-mm-dd format. The program should take an input file and produce 
an output file that is identical to the input file except for the changed date 
formatting. */

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream ifs {"date_file.txt"};
    std::ofstream ofs {"date_iso_out.txt"};

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
                auto begin = matches[0].first;
                auto end = matches[0].second;
                
                std::string l2 = line;

                std::string::size_type ind = begin - line.cbegin();

                l2.replace(ind, 4, matches[3]); // year
                ind += 4;
                l2[ind] = '-';
                ind += 1;
                l2.replace(ind, 2, matches[1]); // month
                ind += 2;
                l2[ind] = '-';
                ind += 1;
                l2.replace(ind, 2, matches[2]); // day

                line = l2;
            }
            
            search_it = matches.suffix().first;
        }

        ofs << line << '\n';
    }
}