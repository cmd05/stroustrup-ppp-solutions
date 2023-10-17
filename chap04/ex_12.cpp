/* .  Modify the program described in the previous exercise to take an
input value max and then find all prime numbers from 1 to max.
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
    int max;
    cin >> max;
    if(abs(max) <= 100) {
        for(int i = 0; i < abs(max); i++) {
            if(is_prime(i)) list.push_back(i);
        }
        for(int x : list) cout << x << " ";
    }
}