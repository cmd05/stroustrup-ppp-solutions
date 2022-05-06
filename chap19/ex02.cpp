// 2. Write a template function that takes a vector<T> vt and a
// vector<U> vu as arguments and returns the sum of all vt[i]*vu[i]s.

#include <iostream>
#include <vector>

template<typename T, typename U>
auto f(std::vector<T> vt, std::vector<U> vu) {
	auto x = vt[0] * vu[0];
	
	for (int i = 1; i < vt.size(); ++i)	{
		x += vt[i]*vu[i];
	}

	return x;
}

int main() {
	std::vector<int> v1 {1,2,3};
	std::vector<double> v2 {4,5,6};

	std::cout << f(v1,v2);
}