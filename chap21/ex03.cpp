#include <iostream>
#include <iterator>
#include <vector>

template<typename InputIt, class T>
typename InputIt::difference_type count(InputIt first, InputIt last, const T& value) {
	typename InputIt::difference_type c = 0;
	for(; first != last; first++)
		if(*first == value) ++c;
	return c;
}

int main() {
	std::vector<int> v {4, 5, 7, 8, 8, 6, 8, 4, 4, 5};
	std::cout << count(v.begin(), v.end(), 8);
}