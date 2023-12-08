#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

bool is_symbol(char ch) {
    std::string symbols = "!@#$%^&*()-=`~+_/<>,:;\"'{}[]\\|";
    return symbols.find(ch) != std::string::npos;
}

bool contains_symbol(std::vector<char> v) {
    for(char ch : v)
        if(is_symbol(ch)) return true;
    
    return false;
}

struct Lines {
    std::string line_above;
    std::string line_below;
};

bool is_part_num(std::ifstream& ifs, const std::string& line, const int line_num, const int num, const int pos, const int valid_lines, const Lines adj_lines) {
    int num_len = std::to_string(num).length();
    int end_pos = pos + num_len; // one after last digit
    char not_symbol = '.';

    // check same line
    if(contains_symbol({(pos == 0 ? not_symbol : line[pos - 1]), line[end_pos]}))
        return true;

    // check above and below lines
    for(int i = pos - 1; i < end_pos + 1; i++) {
        // skip checking before 0th position (doesn't exist) 
        if(i == -1)
            continue;
        
        // check above line
        if(line_num != 0 && is_symbol(adj_lines.line_above[i]))
            return true;
        
        // check below line
        if(line_num != valid_lines - 1 && is_symbol(adj_lines.line_below[i]))
            return true;
    }
    
    return false;
}

int main() {
    std::ifstream ifs {"input.txt"};

    std::string line_above;
    int sum_part;

    // assume file ends with newline character
    int valid_lines = std::count(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), '\n');
    ifs.seekg(0);

    // // manually read the first line
    std::string line, nline;
    std::getline(ifs, nline);

    for(int i = 0; i < valid_lines; i++) {
        line = nline;

        // Get adjacent lines and fetch next line
        Lines adj_lines;

        if(i != 0) adj_lines.line_above = line_above;
        if(i != valid_lines - 1) { // do not read below last line
            std::getline(ifs, nline); // read next line
            adj_lines.line_below = nline;
        }

        std::istringstream iss {line};
        int pos = 0;
        
        for(int pos = 0; pos < line.length(); pos++) {
            char ch = iss.get();

            if(isdigit(ch)) {
                int num_pos = pos;
                iss.seekg(pos);

                int num;
                iss >> num;

                int num_len = std::to_string(num).length();
                pos += num_len - 1;

                if(is_part_num(ifs, line, i, num, num_pos, valid_lines, adj_lines))
                    sum_part += num;
            }
        }

        line_above = line;
    }

    std::cout << sum_part;
}