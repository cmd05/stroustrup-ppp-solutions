#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <math.h>

std::vector<std::string> split(const std::string& subject, std::string seps) {
    std::regex re {std::string("[\\") + seps + "]"};
    std::sregex_token_iterator first {subject.begin(), subject.end(), re, -1}, last;
    std::vector<std::string> tokens {first, last};

    return tokens;
}

inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    s.erase(0, s.find_first_not_of(t));

    return s;
}

std::vector<int> get_ints(std::string s) {
    std::vector<int> new_c;
    std::istringstream iss {s};

    for(int x; iss >> x;)
        new_c.push_back(x);
    
    return new_c;
}

int main() {
    std::ifstream ifs {"input.txt"};
    int points = 0, i = 1;

    for(std::string line; std::getline(ifs, line); i++) {
        std::vector<std::string> v2 = split(trim(split(line, ":")[1]), "|");       
        /* Use generic C<T1> to C<T2> for this */
        std::vector<int> winning_cards = get_ints(v2[0]), my_cards = get_ints(v2[1]);

        int n = 0;

        for(int num : my_cards)
            if(std::find(winning_cards.begin(), winning_cards.end(), num) != winning_cards.end())
                n++;

        if(n != 0) 
            points += pow(2, n-1);
    }

    std::cout << points;
}