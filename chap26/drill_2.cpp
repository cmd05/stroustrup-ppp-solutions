#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// using time() gives narrowing warning, so just use random_device rn
static std::default_random_engine ran {std::random_device{}()}; // generates 'random' integers for computation

int randint(int min, int max) {
    return std::uniform_int_distribution<>{min,max}(ran); // algorithmically maps random integer data to ints in range [min, max)
}

int randint(int max) {
    return randint(0, max);
}

int main() {
    // // a very large sequence
    // int N = 100;
    // std::vector<int> v(N);

    // for(int i = 0; i < N; i++)
    //     v[i] = i;
    
    // // ten sequences with random number of elements
    // std::vector<std::vector<int>> v2 (10);

    // for(int i = 0; i < v2.size(); i++)
    //     v2[i] = std::vector<int>(randint(1, 1000), 0);

    // ten sequences with random number of elements
    // containing random sorted elements
    std::vector<std::vector<int>> v3 (10, std::vector<int>{});

    unsigned int elem = 0;
    int spread = 50;
    
    // set v3
    for(int i = 0; i < v3.size(); i++) {
        v3[i] = std::vector<int>(randint(1, 10));

        for(int j = 0; j < v3[i].size(); j++) {
            elem += randint(spread);
            v3[i][j] = elem;
        }
    }

    // print v3
    // for(int i = 0; i < v3.size(); i++) {
    //     for(int j = 0; j < v3[i].size(); j++)
    //         std::cout << v3[i][j] << ' ';
    //     std::cout << '\n';
    // }
}