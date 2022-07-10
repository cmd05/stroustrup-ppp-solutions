/* Get this program to run. Check that our input really does
produce that output. Try to "break" the program (i.e., get it to
give wrong results) by giving it other input sets. What is the
least amount of input you can give it to get it to fail? */

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main()
{
    vector<double> temps; // temperatures
    for (double temp; cin>>temp; ) // read and put into temps
    temps.push_back(temp);
    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;
    for (int x : temps)
    {
        if(x > high_temp) high_temp = x; // find high
        if(x < low_temp) low_temp = x; // find low
        sum += x; // compute sum
    }
    cout << "High temperature: " << high_temp<< '\n';
    cout << "Low temperature: " << low_temp << '\n';
    cout << "Average temperature: " << sum/temps.size() << '\n';
}