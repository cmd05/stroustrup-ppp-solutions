#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    std::ifstream ifs{"input_a.txt"};
    long int sum = 0;
    
    for(std::string s; ifs >> s;) {
        char first, last;

        for(char ch : s)
            if(isdigit(ch)) {
                first = ch;
                break; 
            }


        for(auto it = s.rbegin(); it != s.rend(); it++)
            if(isdigit(*it)) {
                last = *it;
                break;
            }
 
        sum += ((first - '0')*10 + (last - '0'));
    }

    std::cout << sum;
}