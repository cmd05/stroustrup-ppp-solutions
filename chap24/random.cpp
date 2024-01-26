#include <iostream>
#include <random>
#include <vector>
#include <functional>
#include <fstream>

int randint(int min, int max) {
    static std::default_random_engine ran; // generates 'random' integers for computation
    return std::uniform_int_distribution<>{min,max}(ran); // algorithmically maps random integer data to ints in range [min, max)
}

int randint(int max) {
    return randint(0, max);
}

int main() {
    auto gen = std::bind(std::normal_distribution<double>{15, 4.0}, std::default_random_engine{time(NULL)}); 

    std::ofstream ofs {"hist.txt"};
    std::ostream& os {ofs};

    std::vector<int> hist (2*15);

    for(int i = 0; i < 500; i++)
        ++hist[int(round(gen()))];

    for(int i = 0; i < hist.size(); i++) {
        os << i << '\t';
        for(int j = 0; j < hist[i]; j++)
            os << '*';
        os << '\n';
    }
}