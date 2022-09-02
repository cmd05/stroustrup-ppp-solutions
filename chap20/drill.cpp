#include <iostream>
#include <vector>
#include <list>

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);

int main() {
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> v {0,1,2,3,4,5,6,7,8,9};
	std::list<int> l {0,1,2,3,4,5,6,7,8,9};
	arr2 = arr;
	v2 = v;
	l2 = l;

	for (int i = 0; i < 10; ++i) {
		arr[i] += 2;
		v[i] += 3;
	}
	
	for(auto p = l.begin(); p != l.end(); p++) *p += 5;

}