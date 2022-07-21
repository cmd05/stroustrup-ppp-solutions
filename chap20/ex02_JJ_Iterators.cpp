#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

/// -----------------------------------------------

// get data
double* get_from_jack(int* count) {
	std::ifstream is1{"velocities.data"};

	int sz = std::count(std::istreambuf_iterator<char>(is1),
						std::istreambuf_iterator<char>(), '\n') + 1;
	double* elem = new double[sz];
	*count = sz;

	std::ifstream is2{"velocities.data"};
	int i = 0;
	for (double x = 0; is2 >> x; i++) elem[i] = x;

	return elem;
}

std::vector<double>* get_from_jill() { 
	std::vector<double>* v = new std::vector<double>;
	std::ifstream is{"velocities.data"};

	for (double x = 0; is >> x;) (*v).push_back(x);	

	return v;
}

/// -----------------------------------------------

// // pointer soln
// double* high(double* first, double* last) {
// 	double h = -1;
// 	double* high = nullptr;
	
// 	for(double* p = first; p != last; p++) if(h < *p) h = *p;

// 	return high;
// }

// using iterators
template<typename Iterator>
Iterator high(Iterator first, Iterator last) {
	Iterator high = first;
	for(Iterator p = first; p != last; p++) 
		if(*p > *high) high = p;

	return high;
}

/// -----------------------------------------------

int main() {
	int jack_count;
	double* jack_data = get_from_jack(&jack_count);
	std::vector<double>* jill_data = get_from_jill();
	std::vector<double>& jill_ref = *jill_data;

	/// ...

	double* jack_high = high(jack_data, jack_data + jack_count);
	double* jill_high = high(&jill_ref[0], &jill_ref[0] + jill_ref.size());

	/// ...

	std::cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;
}