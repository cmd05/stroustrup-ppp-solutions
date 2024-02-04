#include <vector>
#include <iostream>
#include <MyMath/lib.h>

// a hack square root calculation using simple operations
double mysqrt(double x) {
	if (x <= 0) return 0;

	double result = x;

	// do ten iterations
	for (int i = 0; i < 10; ++i) {
		if (result <= 0) result = 0.1;

		double delta = x - (result * result);
		result += 0.5 * delta / result;
	}

	return result;
}

void push_uniq(std::vector<Prime_Factor>& primes, int num) {
	bool contains = false;
	for(Prime_Factor& p : primes)
		if(p.factor == num) {
			p.count++;
			contains = true;
		}
	
	if(!contains) primes.push_back({num, 1});
}

std::vector<Prime_Factor> prime_factors(int x) {	
	std::vector<Prime_Factor> primes = {};
	if(x <= 1) return primes;

	int num = x;

	// Add prime factors
	for(int i = 2; i <= mysqrt(num); i++) {
		if(num % i == 0) {
			push_uniq(primes, i);
			num /= i;
			i = 1; // will be incremented to 2
		}
	}

	// Last number is always prime
	push_uniq(primes, num);

	return primes;
}