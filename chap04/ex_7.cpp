/* Modify the "mini calculator" from exercise 5 to accept (just) 
   singledigit numbers written as either digits or spelled out.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> numbers = {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"
};

int get_number()
/*
	An apology: To use cin again after a failed read, you need to use a function call "cin.clear();" to "clear" it.
	That isn't explained in the book until chapter 10. Sorry.

	Solutions that do not use this technique can get very complicated.
*/
{
	const int not_a_symbol = numbers.size();	// not_a_symbol is a value that does not correspond
												// to a string in the numbers vector
	int val = not_a_symbol;
	if (cin>>val) {
        if(abs(val) > 9) throw runtime_error("num must be single digit");
        return val; // try to read an integer composed of digits
    }

	cin.clear();	// clear string after failed attempt to read an integer
	string s;
	cin>>s;
	for (int i=0; i<numbers.size(); ++i)	// see if the string is in numbers
		if (numbers[i]==s) val = i;
	if (val==not_a_symbol) throw runtime_error("unexpected number string: ");
	return val;
}

int main() {

    int size = numbers.size();

    int x , y;
    char op;
    cout << "Enter First Value: ";
    x = get_number();
    cout << "Enter Operation: ";
    cin >> op;
    cout << "Enter Second Value: ";
    y = get_number();

    if(op == '+') {
        cout << "The sum of " << x << " and " << y << " is " << double(x+y); 
    } else if(op == '-') {
        cout << "The difference of " << x << " and " << y << " is " << double(x-y);
    } else if(op == '*') {
        cout << "The product of " << x << " and " << y << " is " << double(x*y);
    } else if(op == '/') {
        cout << "The quotient on dividing " << x << " by " << y << " is " << double(x/y);
    } else {
        cout << "Invalid Operation";
    }
}