/** Write a program that reads characters from cin into an array that you
allocate on the free store. Read individual characters until an
exclamation mark (!) is entered. Do not use a std::string. Do not
worry about memory exhaustion. */

#include <iostream>

char* append(char* arr, int sz, char c) {
	char* new_arr = new char[sz+1];
	
	for(int i = 0; i < sz; i++) new_arr[i] = arr[i];
	
	new_arr[sz] = c;

	delete[] arr;
	return new_arr;
}

int main() {
	int i = 0;
	char* arr = new char[0];
	
    	std::cout << "Input: ";
	
	for(char c; std::cin >> c; i++) {
		arr = append(arr, i, c);
		if(c == '!') break;
	}

	for(int j = 0; j < i+1; j++) std::cout << arr[j];
}