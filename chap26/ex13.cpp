/*   12. Write a program that generates random floating-point numbers and sort 
them  using  std::sort().  Measure  the  time  used  to  sort  500,000  doubles 
and 5,000,000 doubles. */

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

int randint(int min, int max) {
    static std::default_random_engine ran {std::random_device{}()}; // generates 'random' integers for computation
    return std::uniform_int_distribution<>{min,max}(ran); // algorithmically maps random integer data to ints in range [min, max)
}

int randint(int max) {
    return randint(0, max);
}

void print(std::vector<std::string> v) {
    for(int i = 0; i < v.size(); i++)
        std::cout << i << ": " << v[i] << '\n';
}

std::string rand_s(int len) {
    std::string s = "";

    for(int i = 0; i < len; i++)
        // s += (char) randint('!', 'z'); // '!' to '~'
        s += (char) randint('a', 'z'); // 'a' to 'z'
    
    return s;
}

int main() {
    std::vector<std::string> v;

    int m1 = 500000, m2 = 5000000;
    
    for(int i = 0; i < m2; i++)
        v.push_back(rand_s(randint(100)));

    auto t1 = std::chrono::system_clock::now();

    std::sort(v.begin(), v.end());
    
    auto t2 = std::chrono::system_clock::now();
    
    std::cout << "time taken (sort): " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms\n";
    
    // print(v);

    // m1: time taken (sort): 631ms, 545ms, 591ms
    // m2: time taken (sort): 6502ms, 6526ms, 7102ms
}