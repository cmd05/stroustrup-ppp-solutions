/*   12. Write a program that generates random floating-point numbers and sort 
them  using  std::sort().  Measure  the  time  used  to  sort  500,000  doubles 
and 5,000,000 doubles. */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

double rand_d(double min, double max) {
    // using time() gives narrowing warning, so just use random_device rn
    // (static variable)
    static std::default_random_engine ran {std::random_device{}()}; // generates 'random' integers for computation

    return std::uniform_real_distribution<>{min,max}(ran);
}

double rand_d(double max) {
    return rand_d(0, max);
}

void print(std::vector<double> v) {
    for(double d : v)
        std::cout << d << '\n';
}

int main() {
    std::vector<double> v;

    int m1 = 500000, m2 = 5000000;

    
    for(int i = 0; i < m2; i++)
        v.push_back(rand_d(10000));

    auto t1 = std::chrono::system_clock::now();

    std::sort(v.begin(), v.end());
    
    auto t2 = std::chrono::system_clock::now();
    
    std::cout << "time taken (sort): " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms\n";
    
    // print(v);

    // m1: time taken (sort): 289ms
    // m2: time taken (sort): 3324ms
}