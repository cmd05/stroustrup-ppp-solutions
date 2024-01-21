#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>

struct NoCase {
	bool operator()(const std::string& x, std::string& y) { return true; }
};

template<typename In, typename T>
std::pair<In, bool> bin_s(In first, In last, T val) {
	In p = first + (last - first) / 2;
	if(p == first) return {p, false};
	
	if(*p < val)
		return bin_s(p, last, val);
	else if(*p > val)
		return bin_s(first, p, val);
	
	return {p, true};
}

int main() {
	// 1 2 5 12 45 56 67 212 998
	std::vector v {2, 5 ,1, 67, 12, 56, 212, 45};
	std::sort(v.begin(), v.end());

	std::ostream_iterator<int> it {std::cout, " "};
	std::copy(v.begin(), v.end(), it);
	std::cout << '\n';

	auto x = bin_s(v.begin(), v.end(), 67);

	if(x.second) std::cout << *(x.first);
	else std::cout << "not found";
}