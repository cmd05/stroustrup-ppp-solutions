#include <iostream>

void print_arr(int* start, int* end) {
	for(int* p = start; p != end; p++) {
		std::cout << *p << "\t";
	}
	std::cout << "\n";
}

void copy(int* f1, int* e1, int* f2) {
	// copies [f1:e1) to [f2:f2+(e1-f1))
	int sz1 = e1 - f1;
	int sz = 2*sz1;

	int arr[sz];
	
	int i = 0;
	for(int* p = f2; p != (f2+(e1-f1)); p++, i++) {
		*(arr+i) = *p;
	}

	int j = 0;
	for(int* p = f1; p != e1; p++, j++, i++) {
		*(arr+i) = *p;
	}

	print_arr(arr, arr+sz);
}


int main() {
	int arr_sz = 20;
	int arr[arr_sz];

	int i = 1;
	for(int* p = arr; p != (arr+arr_sz); p++, i++) *p = i;

	print_arr(arr, arr+arr_sz);

	int* f1 = arr+4;
	int* e1 = arr+9;
	int* f2 = arr+14;
	copy(f1, e1, f2);
}