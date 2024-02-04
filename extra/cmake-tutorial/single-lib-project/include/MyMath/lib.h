#pragma once
#include <vector>

double mysqrt(double x);

struct Prime_Factor {
	int factor;
	int count;
};

void push_uniq(std::vector<Prime_Factor>& primes, int num);
std::vector<Prime_Factor> prime_factors(int x);