#include <iostream>
#include <vector>

template<typename T>
using vector_iterator = typename std::vector<T>::iterator;

template<typename T>
using vsize_type = typename std::vector<T>::size_type;

// vector arranged in ascending order
// iend is part of vector but not oend
template<typename T>
vector_iterator<T> search_lower(std::vector<T>& vec, vector_iterator<T> ibegin, vector_iterator<T> iend, T val, 
	vector_iterator<T> obegin, vector_iterator<T> oend) {
	if(ibegin > iend) return oend;
	
	vsize_type<T> in_begin = ibegin - vec.begin();
	vsize_type<T> in_end = iend - vec.begin();
	vector_iterator<T> imid = std::next(vec.begin(), (in_begin + in_end) / 2);

	if(*imid >= val)
		if(imid == obegin || *(imid - 1) < val) 
			return imid;
		else
			return search_lower(vec, ibegin, imid-1, val, obegin, oend);
	else if(*imid < val)
		return search_lower(vec, imid+1, iend, val, obegin, oend);
	else
		return search_lower(vec, ibegin, imid-1, val, obegin, oend);
}

template<typename T>
vector_iterator<T> lower_bound(std::vector<T>& vec, vector_iterator<T> ibegin, vector_iterator<T> iend, T val) {
	return search_lower(vec, ibegin, iend - 1, val, ibegin, iend);
}

int main() {
	std::vector<int> v {1,2,3,4,5,6,8,9};
	std::cout << *lower_bound(v, v.begin(), v.end(), 4);
}