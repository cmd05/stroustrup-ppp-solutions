/* Look at your solution of exercise 7. Is there any way that input could
get the array to overflow; that is, is there any way you could enter
more characters than you allocated space for (a serious error)? Does
anything reasonable happen if you try to enter more characters than
you allocated? */

// Well i had allocated space according to the size of the input :p

#include <iostream>

int main() {
	int i = 0;
	char* arr = new char[2];
	
    std::cout << "Input: ";
	
	for(char c; std::cin >> c; i++) {
		arr[i] = c;
		if(c == '!') break;
	}

	for(int j = 0; j < i+1; j++) std::cout << arr[j];
}

// Works fine! 