#include <vector>
#include <list>
#include <chrono>
#include <iostream>

// middle insertion test

template<typename Iterator>
void fill(Iterator begin, Iterator end) {
    int r = rand();

    for(Iterator p = begin; p != end; p++)
        *p = r;
}

#define PERFORM_TEST 'l'
#define TEST_ITERATIONS 10000000

int main()
{
    // set seed
	srand(time(NULL));

    // containers
    std::vector<int> v;
    std::list<int> l;

    // resize them
    v.resize(TEST_ITERATIONS);
    l.resize(TEST_ITERATIONS);
    fill(v.begin(), v.end());
    fill(l.begin(), l.end());

    
    // get iterator to middle of list
    auto l_it = l.begin();
    if(PERFORM_TEST == 'l')
        for (std::size_t i = 0; i <= (TEST_ITERATIONS / 2); i++) l_it++;

    // ****************************************************************

	auto t1 = std::chrono::system_clock::now(); // begin time

	// perform test
	if(PERFORM_TEST == 'v') {
		v.insert(v.begin() + (TEST_ITERATIONS / 2), 100);
	} else {
        l.insert(l_it, 100);
	}

	auto t2 = std::chrono::system_clock::now(); // end time
	
    // ****************************************************************

	std::cout << "iterations: " << TEST_ITERATIONS << '\n';
	std::cout << "time taken: " 
			  <<  std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() 
			  << " ms\n\n";
}