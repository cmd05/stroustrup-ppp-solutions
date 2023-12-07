#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> valid(std::vector<std::string>& results, auto it, const int pos, bool& found_symbol) {
    for(auto results_it = results.begin(); results_it != results.end();) {
        const std::string& s = *results_it;

        if(s[pos] == '\0') {
            results = {s};
            found_symbol = true;
            break;
        }

        if(s[pos] != *it) results_it = results.erase(results_it); // erase returns iterator to element after the one erased
        else results_it++;
    }

    return results;
}

auto find_symbol(auto it, auto str_end, const std::vector<string>& needles) {
    std::vector<string> results = needles;
    bool found_symbol = false;

    int i = 0;   
    for(auto it2 = it; true; it2++, i++) {
        results = valid(results, it2, i, found_symbol);
        if(results.size() == 1 && found_symbol) return find(needles.begin(), needles.end(), results[0]);
        if(results.size() == 0) break;

        if(it2 == str_end) break;
    }

    return needles.end();
}

int main() {
    std::vector<string> symbols = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    std::ifstream ifs{"input_a.txt"};
    std::ofstream ofs{"out.txt"};

    long int sum = 0;
    
    for(std::string s; ifs >> s;) {
        std::vector<int> found;

        for(auto it = s.begin(); it != s.end(); it++) {
            char ch = *it;
            
            if(isdigit(ch))
                found.push_back(ch - '0');
            else if(isalpha(ch)) {
                auto symbol_res = find_symbol(it, s.end(), symbols);
                
                if(symbol_res != symbols.end())
                    found.push_back(symbol_res - symbols.begin()); // here digit = index of element
            }
        }

        ofs << *found.begin() << '\t' << *found.rbegin() << '\n';

        sum += (*found.begin())*10 + *found.rbegin();
    }

    std::cout << sum;
}