#include <iostream>
#include "Vector_Base.h"
#include "vector.h"
#include "vector_impl.h"

int main() {
	vector<int> vc{1,2,3,4};
	vc[0] = 55;

	for (int i = 0; i < 10; ++i)
	{
		vc.push_back(i*i);
	}

	for (int i = 0; i < vc.size(); ++i)
	{
		std::cout << vc[i] << "\n";
	}

	vector<int> vc2 = vc;
	vc2[0] = -55;

	std::cout << vc[0] << " " << vc2[0];
}