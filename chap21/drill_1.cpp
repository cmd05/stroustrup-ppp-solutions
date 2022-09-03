#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

struct Item {
	std::string name;
	int iid;
	double value;
};

bool operator==(const Item& a, const Item& b) {
	return a.name == b.name;
}

std::istream& operator>>(std::istream& is, Item& it) {
	is >> it.name;
	is >> it.iid;
	is >> it.value;
	
	return is;
}

std::ostream& operator<<(std::ostream& os, const Item& it) {
	os << it.name << ": " << it.iid << '\t' << it.value << '\n';
	return os;
}

int main() {
	std::ifstream is {"drill_input.txt"};
	std::istream_iterator<Item> ii {is};
	
	std::vector<Item> vi {ii, std::istream_iterator<Item>{}};
	std::sort(vi.begin(), vi.end(), [](Item a, Item b) { return a.name < b.name; });
	std::sort(vi.begin(), vi.end(), [](Item a, Item b) { return a.iid < b.iid; });
	vi.push_back(Item {"horse shoe", 99, 12.34});
	vi.push_back(Item {"Canon S400", 9988, 499.95});
	vi.erase(std::find( vi.begin(), vi.end(), Item{"name8", 8, 8.8} ));
	vi.erase(std::find( vi.begin(), vi.end(), Item{"name6", 6, 6.6} ));


	for(Item x : vi)
		std::cout << x;
}