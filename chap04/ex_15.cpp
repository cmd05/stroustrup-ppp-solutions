/* . Write a program that takes an input value n and then finds the first n
primes. */
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>

int main() {
    int n;
    std::vector<int> v;
    int count = 0;
    std::cin >> n;
    for(int i = 2; count < n; i++) {
        bool is_prime = true;
        for(int j = 2; j < (sqrt(i)+1); j++) {
            if(i % j == 0 && i != j) {
                is_prime = false;
                break;
            }
        }

        if(is_prime) {
            v.push_back(i);
            count++;
        }
    }    
    for(int x : v) std::cout << x << " ";
}