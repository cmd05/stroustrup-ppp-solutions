#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>

struct NoCase {
	bool operator()(const std::string& x, std::string& y) { return true; }
};

// binary search for contiguous memory sequence
// search in [begin, end)
// user should not pass an empty sequence (dereferencing of empty array will occur)
template<typename In, typename T>
std::pair<In, bool> bin(In begin, In end, T val) {
    In middle = begin + (end - begin) / 2;

    if(*middle == val)
        return {middle, true}; // found
    
    if(begin == middle) // test this first to avoid infinite recursion
        return {end, false}; // not found
    
    if(*middle < val)
        return bin(middle, end, val); // search in right half
    
    return bin(begin, middle, val); // search in left half
}

int main() {
	// 1 2 5 12 45 56 67 212 998
	std::vector v {2, 5 ,1, 67, 12, 56, 212, 45};
	std::sort(v.begin(), v.end());

	std::ostream_iterator<int> it {std::cout, " "};
	std::copy(v.begin(), v.end(), it);
	std::cout << '\n';

	auto x = bin(v.begin(), v.end(), 67);

	if(x.second) std::cout << *(x.first);
	else std::cout << "not found";
}