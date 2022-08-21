#include <iostream>
#include <chrono>

// --------------------------------------------------------------------------------

/// basic performance test

// Generate N random int values in the range [0:N). As each int
// is generated, insert it into a Container<int> (which grows by one element
// each time). Keep the container sorted

// push a random integer into a container in ascending order
template <class Container>
void push_container(Container& c, int n) {
	int r = rand() % n;

	bool inserted = false;

	for(auto i = c.begin(); i != c.end(); i++)
		if(*i >= r) {
			inserted = true;
			c.insert(i, r);
			break;
		}

	if(!inserted) c.push_back(r);
}

template <template <class...> class Container>
int insertion_test(int n) {
	srand(time(NULL));
	auto t1 = std::chrono::system_clock::now(); // begin time


	Container<int> c;
	for (int i = 0; i < n; i++) push_container<Container<int>>(c, n);


	auto t2 = std::chrono::system_clock::now(); // end time
	
	return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

// --------------------------------------------------------------------------------

/// debugging utilities

template<typename T>
void print(std::initializer_list<T> val, char sep = '\t') {
	for(T x : val) std::cout << x << sep;
}

template<typename T>
void pt_list(T& ls) {
	for(auto x : ls) print({x});
	std::cout << '\n';
}

// --------------------------------------------------------------------------------

/// test basic functionalities

template <template <class...> class Container>
void functionality_test() {
	Container<int> l1 {1, 2, 3};
	Container<int> l2 = l1;

	// l1.push_back(10);
	// l1.clear();
	// l1.resize(5);
	// l1.insert(l1.end(), 100);
	// l1.insert(l1.begin(), 101);	

	l1.merge(l2);
	l2.push_back(12);
	l2.resize(10, 5);

	pt_list(l1);
	pt_list(l2);
}

// --------------------------------------------------------------------------------
