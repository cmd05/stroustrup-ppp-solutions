/**
In the drill, you wrote a program that, given a series of numbers,
found the max and min of that series. The number that appears the
most times in a sequence is called the mode. Create a program that
finds the mode of a set of positive integers
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <math.h>

int main() {
    // Step 1-5
    std::vector<int> v;

    std::cout << "Enter Numbers: ";
    for(int x; std::cin >> x;) v.push_back(x);

    std::unordered_set<int> modes;
    int occurences = -1;

    // 1 1 2 2 1 3 4 2 
    for(int x : v) {
        int new_occurrences = 0;
        for(int y : v) if(y == x) new_occurrences++;

        if(new_occurrences >= occurences) {
            if(new_occurrences > occurences)
                modes.clear();
            
            modes.insert(x);
            occurences = new_occurrences;
        }
    }

    std::cout << "The mode(s) is/are ( ";
    for(int mode : modes) std::cout << mode << " ";
    std::cout << ") with " << occurences << " occurences";
}