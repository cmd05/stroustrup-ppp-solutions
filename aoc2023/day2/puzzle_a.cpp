#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>

std::vector<std::string> split(const std::string& subject, std::string seps) {
    std::regex re(std::string("[\\") + seps + "]");
    std::sregex_token_iterator first{subject.begin(), subject.end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};

    return tokens;
}

int main() {
    int sum_valid = 0;
    int given_r = 12, given_g = 13, given_b = 14;

    std::ifstream ifs {"input_a.txt"};

    int i = 1;

    for(std::string line; std::getline(ifs, line); i++) {
        int sum_r = 0, sum_g = 0, sum_b = 0;

        std::vector<std::string> v1 = split(line, ":");
        std::vector<std::string> v2 = split(v1[1], ";");
        
        bool valid_game = true;

        for(std::string set : v2) {
            std::vector<std::string> pairs = split(set, ",");
            bool valid_set = true;

            for(std::string pair : pairs) {
                std::istringstream iss {pair};
                int n;
                std::string color;
                iss >> n >> color;

                if((color == "red" && n > given_r) || (color == "green" && n > given_g) || (color == "blue" && n > given_b)) {
                    valid_set = false;
                    break;
                }
            }

            if(!valid_set) {
                valid_game = false;
                break;
            }
        }
        
        if(valid_game)
            sum_valid += i;
    }

    std::cout << sum_valid;
}