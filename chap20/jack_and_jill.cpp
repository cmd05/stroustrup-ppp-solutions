#include <iostream>
#include <vector>

double* get_from_jack(int& count);
std::vector<double>* get_from_jill();

int main() {
    int jack_count = 0;
    double* jack_data = get_from_jack(jack_count);
    std::vector<double>* jill_data = get_from_jill();

    delete[] jack_data;
    delete jill_data;
}