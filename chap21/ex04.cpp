#include <iostream>
#include <iterator>
#include <vector>

template<class InputIt, class UnaryPredicate>
typename InputIt::difference_type count_if(InputIt first, InputIt last, UnaryPredicate p) {
	typename InputIt::difference_type c = 0;
	for(; first != last; first++)
		if(p(*first)) ++c;
	return c;
}

template<typename InputIt>
class LargerThan {
	using value_type = typename InputIt::value_type;
	value_type num;
public:
	LargerThan(value_type v): num{v} {}
	bool operator()(value_type v) { return v > num; }
};

int main() {
	std::vector<int> v {4, 5, 7, 8, 8, 6, 8, 4, 4, 5};
	std::cout << count_if(v.begin(), v.end(), LargerThan<std::vector<int>::iterator>{5});
}