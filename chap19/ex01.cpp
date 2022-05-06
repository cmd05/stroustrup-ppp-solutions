/* Write a template function f() that adds the elements of one vector<T>
to the elements of another; for example, f(v1,v2) should do
v1[i]+=v2[i] for each element of v1. */

#include <iostream>
#include <vector>

template<typename T>
void f(std::vector<T>& v1, const std::vector<T>& v2) {
	for (int i = 0; i < v1.size(); ++i)	{
		v1[i] += v2[i];
	}
}

int main() {
	std::vector<int> v1 {1,2,3};
	std::vector<int> v2 {4,5,6};

	f(v1,v2);

	for(int x : v1) {
		std::cout << x << "\t";
	}
}