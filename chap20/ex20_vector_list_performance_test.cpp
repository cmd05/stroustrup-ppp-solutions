/* 
	Run a small timing experiment to compare the cost of using vector
	and list. You can find an explanation of how to time a program in
	§26.6.1. Generate N random int values in the range [0:N). As each int
	is generated, insert it into a vector<int> (which grows by one element
	each time). Keep the vector sorted; that is, a value is inserted after
	every previous value that is less than or equal to the new value and
	before every previous value that is larger than the new value. Now do
	the same experiment using a list<int> to hold the ints. For which N is
	the list faster than the vector? Try to explain your result. This
	experiment was first suggested by John Bentley. 
*/

#include <vector>
#include <list>
#include <chrono>
#include <iostream>

// push a random integer into a vector in ascending order
void push_v(std::vector<int>& v, int n) {
	int r = rand() % n;

	bool inserted = false;

	for(int i = 0; i < v.size(); i++)
		if(v[i] >= r) {
			inserted = true;
			v.insert(v.begin() + i, r);
			break;
		}

	// for(int x : v) std::cout << x << '\t';
	// std::cout << '\n';

	if(!inserted) v.push_back(r);
}

// push a random integer into a list in ascending order
void push_l(std::list<int>& l, int n) {
	int r = rand() % n;

	bool inserted = false;

	for(auto i = l.begin(); i != l.end(); i++)
		if(*i >= r) {
			inserted = true;
			l.insert(i, r);
			break;
		}

	// for(int x : l) std::cout << x << ' ';
	// std::cout << '\n';

	if(!inserted) l.push_back(r);
}

#define ___PERFORM_TEST 'v'
#define ___TEST_ITERATIONS 10000

int main()
{
	srand(time(NULL));
	int n = ___TEST_ITERATIONS;

	auto t1 = std::chrono::system_clock::now(); // begin time

	// perform test
	if(___PERFORM_TEST == 'v') {
		std::vector<int> v;
		for (int i = 0; i < n; i++) push_v(v, n); 

		std::cout << "test: vector\n";
	} else {
		std::list<int> l;
		for (int i = 0; i < n; i++) push_l(l, n);

		std::cout << "test: list\n";
	}

	auto t2 = std::chrono::system_clock::now(); // end time
	
	std::cout << "iterations: " << n << '\n';
	std::cout << "time taken: " 
			  <<  std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() 
			  << " ms\n\n";
}

/**
 * RESULTS:
 * 
 * std::vector:
 * 
	*----------------------------------------------------------------*
	* n            ms1            ms2           ms3           avg	 *
	*----------------------------------------------------------------*
	* 10            0              0             0            0 	 *
	* 1,000         0              0             0            0  	 *
	* 5,000         37             37            37           40     *
	* 10,000        155            147           154          150    *
	* 100,000       14,428         14,427        14,456       14,400 *
	* 500,000                                                        *
	* 1,000,000                                                      *
	*----------------------------------------------------------------*
 * 
 * 
 * std::list:
 */