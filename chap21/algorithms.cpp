#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <map>

// template<typename In, typename Pred>
// In find_if(In first, In last, Pred pred) {
//    while(first != last && !pred(*first)) ++first;
//    return first;
// }

// Function Objects
class LargerThan {
	int v;
public:
	LargerThan(int vv): v(vv) {}
	bool operator()(int x) const { return x > v; }
};

struct Record {
	double unit_price;
	int units;
};

double price(double v, const Record& r) {
	return v + r.unit_price * r.units;
}

int main() {
	// 1. Construct LargerThan with 25 as vv
	// 2. Call operator() on pred object with *first as x
	// find_if(v.begin(), v.end(), LargerThan(25));
	std::vector<Record> v = {{10.5, 7}, {6.67, 6}, {9.8, 12}, {12.5, 7}};
	double a = 0.0;
	a = std::accumulate(v.begin(), v.end(), a, price);
	std::cout << a;

	std::map<std::string, std::string> dow_name = {
		{"M", "s"}
	};
}