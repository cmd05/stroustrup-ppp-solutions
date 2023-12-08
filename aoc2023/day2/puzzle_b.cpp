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
    int sum_powers = 0;
    std::ifstream ifs {"input_a.txt"};

    int i = 1;

    for(std::string line; std::getline(ifs, line); i++) {
        int max_r = 0, max_g = 0, max_b = 0;

        std::vector<std::string> v1 = split(line, ":");
        std::vector<std::string> v2 = split(v1[1], ";");
        
        for(std::string set : v2) {
            std::vector<std::string> pairs = split(set, ",");

            for(std::string pair : pairs) {
                std::istringstream iss {pair};
                int n;
                std::string color;
                iss >> n >> color;

                if(color == "red" && n > max_r) max_r = n;
                else if(color == "green" && n > max_g) max_g = n;
                else if(color == "blue" && n > max_b) max_b = n;
            }
        }

        int power = max_r * max_g * max_b;
        sum_powers += power;
    }

    std::cout << sum_powers;
}