#include <regex>
#include <iostream>
#include <string>
#include <fstream>

struct table_error {
    std::string msg;
    int line_no;

    std::string what() {
        return msg;
    }
};

int main() {
    std::ifstream ifs {"table.txt"};
    if(!ifs) throw std::runtime_error("file not found");

    std::string line;

    std::regex header {R"(^[\w ]+(\t[\w ]+){3}$)"};
    // std::regex row {R"(^([\w ]+)(\t-?\d+\.?\d+){3}$)"};
    std::regex row {R"(^([\w ]+)(\t-?\d+\.?\d+)(\t-?\d+\.?\d+)(\t-?\d+\.?\d+)$)"}; // we want to capture all groups

    double avg_elevation = 0;

    try {
        if(std::getline(ifs, line)) {
            std::smatch matches;
            if(!std::regex_match(line, matches, header))
                throw table_error{"no header", 0};
        }

        int line_no = 1; // header is first line

        while(std::getline(ifs, line)) {
            line_no++; // increment line_no if line exists only

            std::smatch matches;
            std::regex_search(line, matches, row);

            if(matches[0] != line)
                throw table_error{"invalid row format", line_no};
            
            avg_elevation += std::stoi(matches[2]);
        }

        avg_elevation /= (line_no - 1);

        std::cout << "average elevation = " << avg_elevation;
    } catch(table_error& e) {
        std::cerr << e.what() <<  "(line_no=" << e.line_no << ")\n";
    }
}