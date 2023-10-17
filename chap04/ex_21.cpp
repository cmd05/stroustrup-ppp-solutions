/* Modify the program from exercise 19 so that when you enter an
integer, the program will output all the names with that score or score
not found.
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> names;
    std::vector<int> scores;

    std::string name;
    int score;
    std::cout << "Enter name followed by score: ";
    for(; std::cin >> name >> score;) {
        if(name == "NoName" && score == 0) {
            break;
        } else {
            for(std::string x : names) if(name == x) throw std::invalid_argument("Name Repeated");

            names.push_back(name);
            scores.push_back(score);
        }
    }
    for(int i = 0; i < names.size(); i++) std::cout << names[i] << "\t" << scores[i] <<"\n";
    std::cout << "\nSearch a Score: ";
    int search;
    std::cin >> search;

    bool found = false;
    for(int i = 0; i < scores.size(); i++) {
        if(scores[i] == search) {
            if(!found) found = true;
            std::cout << "Name: " << names[i] << "\n";
        }
    }

    if(!found)
        throw std::invalid_argument("Score not found");
}