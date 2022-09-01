#include <iostream>


/**
 *	TODO:
 * 		- implement sort()
 * 		- fix merge for empty lists
 * 		- delete pre and sent nodes when invalid
 * 		- validate methods for empty list
 */

/**
 * experimental
 * 
 * SUMMARY:
 * 		- fix merge
 * 		- check methods for empty list
 * 		- delete invalid pre and sent nodes
 * 		- move/copy allocators
 * 		- use std::reverse_iterator
 * 
 * 		- use classes for testing
 */

#include <list>
#include "list/list.h"
#include "tests/tests.h"

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	std::cout << "std::list: " << PerformanceTest<std::list>::run(n) << " ms\n";
	std::cout << "list: " << PerformanceTest<list>::run(n) << " ms\n";
    FunctionalityTests<list>::test1();
}