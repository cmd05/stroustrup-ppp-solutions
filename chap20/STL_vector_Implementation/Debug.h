#pragma once
#include "vector.h"
#include <iostream>

template<typename T>
void print_t(T v) {
	std::cout << v << "\t";
}

template<typename T>
void print(T v) {
	std::cout << v << "\n";
}

template<typename T>
void print_vc(vector<T>& vc) {
	std::cout << "\n";
	for (int i = 0; i < vc.size(); ++i) {
		print_t(vc[i]);
	}
	std::cout << "\n";
}

template<typename T>
void print_vdt(vector<T>& vc) {
    std::cout << vc.size() << "\t" << vc.capacity() << "\n";
}

void br() {
	std::string msg = "*****";
	print<std::string>(msg);
}