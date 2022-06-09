/* Implement a little guessing game called (for some obscure reason)
“Bulls and Cows.” The program has a vector of four different
integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the
user's task to discover those numbers by repeated guesses. Say the
number to be guessed is 1234 and the user guesses 1359; the response
should be “1 bull and 1 cow” because the user got one digit (1) right
and in the right position (a bull) and one digit (3) right but in the
wrong position (a cow). The guessing continues until the user gets
four bulls, that is, has the four digits correct and in the correct order */

#include "../includes/std_lib_facilities.h"

int main() {
    vector<int> v = {1, 2, 3, 4};
    vector<char> vs;

    for(int x : v) vs.push_back(char('0'+ x));
    
    std::cout << "Enter your number: ";
    for(std::string x; std::cin >> x;) {
        int bull_count = 0;
        if(x.size() == 4) {
            for(int i = 0; i < x.size(); i++) {
                if(std::find(vs.begin(), vs.end(), x[i]) != vs.end()) {
                    if(x[i] == vs[i]) {
                        std::cout << "Bull(" << x[i] << ")\n";
                        bull_count++;
                    } else {
                        std::cout << "Cow(" << x[i] << ")\n";
                    }
                }
            }

            if(bull_count == 4) {
                std::cout << "You won!";
                break;
            }
        } else {
            std::cout << "Enter 4 digit number\n";
        }
        std::cout << "Enter your number: ";
    }
}