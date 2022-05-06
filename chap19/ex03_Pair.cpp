// Write a template class Pair that can hold a pair of values of any type.
#include <iostream>
#include <string>

template<typename T1, typename T2>
class Pair {
public:
	Pair(T1 v1, T2 v2): first{v1}, second{v2} {}

	T1 first;
	T2 second;
};

int main() {
	Pair<std::string, double>{"pi", 3.14};
}