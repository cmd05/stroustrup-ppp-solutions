#pragma once

#include <iostream>
#include <chrono>
#include <algorithm>
#include <list>
#include "../list/list.h"

/* Debugging Utilities */
class Debug {
public:
	template<class Container>
	static void print_c(Container c, char sep = '\t') {
		for(auto x : c) std::cout << x << sep;
	}

	template<typename T>
	static void print(T val, char end = '\n') {
		std::cout << val;
		std::cout << end;
	}

	class Timer {};
};

/**
	Basic performance test

		Generate N random int values in the range [0:N). As each int
		is generated, insert it into a Container<int> (which grows by one element
		each time). Keep the container sorted
*/

template <template <class...> class Container>
class PerformanceTest {
	// Pushes a random integer into a container in ascending order
	template<typename C>
	static void push_container(C& c, int n) {
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

	static int test(int n) {
		srand(time(NULL));
		auto t1 = std::chrono::system_clock::now(); // begin time


		Container<int> c;
		for (int i = 0; i < n; i++) push_container<Container<int>>(c, n);


		auto t2 = std::chrono::system_clock::now(); // end time
		return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	}
public:
	static int run(int n) { return test(n); }
};

/* Test Functionalities of Container */
template <template <class...> class Container>
class FunctionalityTests {
public:
	static void test1() {
		Container<char> l1 {'x', 'y', 'z'};
		Container<char> l2 {1,2,3,4,5,6,7};
		l2.assign(l1.begin(), l1.end());

		// l2.merge(l1);
		l2.push_back('|');
		// l2.insert(l2.end(), {'q', 'w', 'e'});
		// l2.insert(std::find(l2.begin(), l2.end(), '|'), '.');
		Debug::print_c(l2);
	}
};