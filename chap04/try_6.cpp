/* Write a program that “bleeps” out words that you don't like;
that is, you read in words using cin and print them again on
cout. If a word is among a few you have defined, you write out
BLEEP instead of that word. Start with one “disliked word” such
as
string disliked = “Broccoli”;
When that works, add a few more */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector <string> disliked = {"broccoli", "spinach", "school"};
    cout << "Enter Word: ";
    for(string input; cin >> input;) {
        if(find(disliked.begin(), disliked.end(), input) != disliked.end()) {
            cout << "BLEEP";
        }   else {
            cout << input;
        }
        cout << "\n";
    }
}