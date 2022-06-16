/* Write a program that plays the game "Rock, Paper, Scissors." If you
are not familiar with the game do some research (e.g., on the web
using Google). Research is a common task for programmers. Use a
switch-statement to solve this exercise. Also, the machine should give
random answers (i.e., select the next rock, paper, or scissors
randomly). Real randomness is too hard to provide just now, so just
build a vector with a sequence of values to be used as "the next
value." If you build the vector into the program, it will always play
the same game, so maybe you should let the user enter some values.
Try variations to make it less easy for the user to guess which move
the machine will make next. */
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    char x;
    cout << "Rock Paper Scissors \n r - Rock \n p - Paper \n s- Scissors \n Enter Move:";

    while(cin >> x) {
        vector<char> computer = {'r', 'p', 's'};
        vector<string> full = {"rock", "paper", "scissors"};
        int random = 0 + rand() % 3;
        char comp = computer[random];

        if(x == 'r' || x == 'p' || x == 's') {
            string user_move = "";
            int j = 0;
            for(char a : computer) {
                if(a == x) cout << "You chose " << full[j] << endl;
                j++;
            }
            cout << "Computer chose " << full[random] << "\n";
        }

        if(comp == x) {
            cout << "Its a tie";
        } else if(x == 'r') {
            if(comp == 'p') {
                cout << "Computer Win";
            } else {
                cout << "You won";
            }
        } else if(x == 'p') {
            if(comp == 's') {
                cout << "Computer Win";
            } else {
                cout << "You won";
            }
        } else if(x == 's') {
            if(comp == 'r') {
                cout << "Computer Win";
            } else {
                cout << "You won";
            }
        } else {
            cout << "Invalid Input";
        }
        cout << "\n\n";
        cout << "Rock Paper Scissors \n r - Rock \n p - Paper \n s- Scissors \n Enter Move:";
    }
}