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

bool is_gear_sym(char ch) {
    return is_symbol(ch) && ch=='*';
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

struct Point {
    int part_num;

    int line_num;
    int pos;
};

void get_stars(std::ifstream& ifs, const std::string& line, const int line_num, const int num, const int pos, const int valid_lines, const Lines adj_lines, std::vector<Point>& stars) {
    int num_len = std::to_string(num).length();
    int end_pos = pos + num_len; // one after last digit
    char not_symbol = '.';

    // check same line
    if(is_gear_sym(pos == 0 ? not_symbol : line[pos - 1]))
        stars.push_back({num, line_num, pos - 1});

    if(is_gear_sym(line[end_pos]))
        stars.push_back({num, line_num, end_pos});

    // check above and below lines
    for(int i = pos - 1; i < end_pos + 1; i++) {
        // skip checking before 0th position (doesn't exist) 
        if(i == -1)
            continue;
        
        // check above line
        if(line_num != 0 && is_gear_sym(adj_lines.line_above[i]))
            stars.push_back({num, line_num - 1, i});
        
        // check below line
        if(line_num != valid_lines - 1 && is_gear_sym(adj_lines.line_below[i]))
            stars.push_back({num, line_num + 1, i});
    }
}

int main() {
    std::ifstream ifs {"input.txt"};

    std::string line_above;
    int sum_part;
    std::vector<Point> stars;

    // assume file ends with newline character
    int valid_lines = std::count(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), '\n');
    ifs.seekg(0);

    // manually read the first line
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

                get_stars(ifs, line, i, num, num_pos, valid_lines, adj_lines, stars);
            }
        }

        line_above = line;
    }

    std::vector<Point> valid_stars;
    long int sum_ratios = 0;

    for(int i = 0; i < stars.size(); i++) {
        for(int j = i + 1; j < stars.size(); j++) {
            if(stars[j].line_num == stars[i].line_num && stars[j].pos == stars[i].pos) {
                sum_ratios += stars[i].part_num * stars[j].part_num;
            }
        }
    }

    std::cout << "sum=" << sum_ratios;
}