/* . Create a program to find all the prime numbers between 1 and 100.
One way to do this is to write a function that will check if a number is
prime (i.e., see if the number can be divided by a prime number
smaller than itself) using a vector of primes in order (so that if the
vector is called primes, primes[0]==2, primes[1]==3,
primes[2]==5, etc.). Then write a loop that goes from 1 to 100,
checks each number to see if it is a prime, and stores each prime found
in a vector. Write another loop that lists the primes you found. You
might check your result by comparing your vector of prime numbers
with primes. Consider 2 the first prime.
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool is_prime(int n) {
    if(n == 1) return false;
    
    bool is_prime = true;
    for(int i = 0; i < primes.size(); i++) {
        if(n % primes[i] == 0 && n != primes[i]) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

int main() {
    vector<int> list;
    for(int i = 0; i < 100; i++) {
        if(is_prime(i)) list.push_back(i);
    }

    for(int x : primes) cout << x << " ";
    std::cout << "\n\n";
    for(int x : list) cout << x << " ";
}