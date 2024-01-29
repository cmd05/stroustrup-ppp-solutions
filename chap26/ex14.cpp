/*   12. Write a program that generates random floating-point numbers and sort 
them  using  std::sort().  Measure  the  time  used  to  sort  500,000  doubles 
and 5,000,000 doubles. */

#include <iostream>
#include <set>
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

void print(std::set<std::string> v) {
    int i = 0;
    for(auto p = v.begin(); p != v.end(); p++, i++)
        std::cout << i << " " << *p << '\n';
}

std::string rand_s(int len) {
    std::string s = "";

    for(int i = 0; i < len; i++)
        // s += (char) randint('!', 'z'); // '!' to '~'
        s += (char) randint('a', 'z'); // 'a' to 'z'
    
    return s;
}

int main() {
    std::set<std::string> v;

    int m1 = 500000, m2 = 5000000;
    
    auto t1 = std::chrono::system_clock::now();

    for(int i = 0; i < m2; i++)
        v.insert(rand_s(randint(100)));

    auto t2 = std::chrono::system_clock::now();
    
    // assuming time taken to generate string is negligible
    std::cout << "time taken (sort): " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << "ms\n";
    
    // m1: time taken (sort): 0ms, 0ms, 0ms
    // m2: time taken (sort): 22507ms, 20129ms, 22491ms
}