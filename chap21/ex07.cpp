#include <iostream>
#include <vector>

using vec_it = std::vector<int>::iterator;
using vec_szt = std::vector<int>::size_type;

// ascending vector
template<typename T>
vec_it vc_search(std::vector<T>& vec, vec_it ibegin, vec_it iend, T val, vec_it sentinel) {
	vec_szt sbegin = ibegin - vec.begin();
	vec_szt send = iend - vec.begin() - 1;
	vec_it imid = std::next(vec.begin(), sbegin + int((send - sbegin) / 2));

	if(*imid == val)
		return imid;
	else
		if(imid == (iend - 1))
			return iend;
		else if(*imid < val)
			return vc_search(vec, imid, iend, val, iend);
		else if(*imid > val)
			return vc_search(vec, ibegin, imid, val, iend);
}

template<typename T>
vec_it vbinary_search(std::vector<T>& vec, vec_it ibegin, vec_it iend, T val) {
	return vc_search(vec, vec.begin(), vec.end(), val, vec.end());
}

int main() {
	std::vector<int> v {1,2,3,4,5,6,8,9};
	std::cout << *vbinary_search(v, v.begin(), v.end(), 3);
}