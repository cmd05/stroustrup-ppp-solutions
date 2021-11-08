#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

int main() {
    long double sum = 0;
    int terms = 9 * pow(10, 5);
    long long int denom = 1;

    for(int i = 0; i < terms; i++) {
        sum += pow(-1, i) * ( 1 / double(denom) );
        denom += 2;
        std::cout << std::setprecision(15) << std::fixed << sum << "\n";
        // std::cout << sum << "\n";
    }
}