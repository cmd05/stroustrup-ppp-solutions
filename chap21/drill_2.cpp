#include <iostream>
#include <map>
#include <iterator>
#include <numeric>

struct Item {
	std::string s;
	int i;
};

std::istream& operator>>(std::istream& is, Item& it) {
	is >> it.s;
	is >> it.i;
	return is;
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::map<T1, T2> msi) {
	for(auto p : msi)
		os << p.first << ' ' << p.second << '\n';
	return os;
}

void from_input(std::map<std::string, int>& m) {
	std::istream_iterator<Item> ii {std::cin};
	for(auto p = ii; p != std::istream_iterator<Item>{}; p++)
		m[(*p).s] = (*p).i;
}

int main() {
	std::map<std::string, int> msi;
	msi["k5tuu"] = 86;
	msi["l370z"] = 59;
	msi["em7w9"] = 26;
	msi["ygcxb"] = 16;
	msi["c6lmj"] = 30;
	msi["g2x3y"] = 64;
	msi["go3bg"] = 29;
	msi["h1kwx"] = 54;
	msi["8rcfr"] = 36;
	msi["fkt4z"] = 51;
	
	msi.clear();
	from_input(msi);
	std::cout << msi;

	using msi_vtype = std::map<std::string, int>::value_type;
	std::cout << std::accumulate(msi.begin(), msi.end(), 0, 
				 [](int acc, msi_vtype val) { return acc + val.second; });
	
	std::map<int, std::string> mis;
	for(auto p : msi)
		mis[p.second] = p.first;
	std::cout << mis;
}