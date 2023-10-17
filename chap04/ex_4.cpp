/* Write a program to play a numbers guessing game. The user thinks of
a number between 0 and 100 and your program asks questions to
figure out what the number is (e.g., "Is the number you are thinking of
less than 50?"). Your program should be able to identify the number
after asking no more than seven questions. Hint: Use the < and <=
operators and the if-else construct. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// let guess = 4
// i = -1
// < 50  l i = 0 
// < 25 l  i = 1
// < 12 l  i = 2
// < 6 l   i = 3
// > 3 h   i = 4 
// < 5 l   i = 5
// == 4    c = 'c' 

int main() {
    vector <int> diffs = {25, 13, 6, 3, 2, 1};
    int start = 50;
    // Lower / correct / Higher
    cout << "** Number Guessing Game **\
    \n Choose a number between 0-100 \
    \n I will try to guess it within 7 tries\
    \n Respond with l for lower, c for correct and h for higher\
    \n\n";
    
    // Allow first element to be accessed
    int i = -1;
    char c;
    
    while(i < 6) {
        cout << "[Respond with l for lower, c for correct and h for higher]\n";
        cout << "Is your less than, equal to or greater than " << start << "\n";
        cin >> c;
        cout << "\n";
        // Allow last input as correct ['c']
        if(i < 5 || (i == 5 && c == 'c')) {
            if(c == 'c') {
                i+=2; // -1 to 1 conversion
                cout << "I guessed in " << i << " trie(s)";
                break;
            } else if(c == 'l') {
                i++;
                start -= diffs[i];
            } else if(c == 'h') {
                i++;
                start += diffs[i];
            }   else {
                cout << "Enter valid response\n";
            }
        }   else {
            cout << "Impossible!";
            break;
        }
    }
}