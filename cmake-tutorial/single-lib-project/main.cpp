#include <MyMath/lib.h>
#include <iostream>
#include <vector>

int main() {
	std::cout << mysqrt(68) << "\n\n";
	std::vector<Prime_Factor> primes = prime_factors(665280);

	for(Prime_Factor p : primes) 
		std::cout << p.factor << ": " << p.count << "\n";
}