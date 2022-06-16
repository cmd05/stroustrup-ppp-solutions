/* If we define the median of a sequence as "a number so that exactly as
many elements come before it in the sequence as come after it," fix the
program in §4.6.3 so that it always prints out a median. Hint: A median
need not be an element of the sequence. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> temps; // temperatures
    cout << "Enter temps: "; 
    for (double temp; cin>>temp; ) // read into temp
    temps.push_back(temp); // put temp into vector

    // compute median temperature:
    sort(temps.begin(), temps.end()); // sort temperatures
    cout << "Median temperature: ";

    if(temps.size() % 2 == 0) {
        cout << (temps[temps.size()/2 - 1] + temps[temps.size()/2]) / 2;
    }   else {
        cout << temps[temps.size()/2];
    }
}
