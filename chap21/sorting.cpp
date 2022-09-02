#include <vector>
#include <iostream>
#include <algorithm>

struct NoCase {
	bool operator()(const std::string& x, std::string& y) { return true; }
};

int main() {
	// std::sort(v.begin(), v.end(), NoCase{});
}