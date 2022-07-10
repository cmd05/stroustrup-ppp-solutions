/**
    1. Write a program that consists of a while-loop that (each time around
    the loop) reads in two ints and then prints them. Exit the program
    when a terminating '|' is entered.
    2. Change the program to write out the smaller value is: followed by
    the smaller of the numbers and the larger value is: followed by the
    larger value.
    3. Augment the program so that it writes the line the numbers are
    equal (only) if they are equal.
    4. Change the program so that it uses doubles instead of ints.
    5. Change the program so that it writes out the numbers are almost
    equal after writing out which is the larger and the smaller if the two
    numbers differ by less than 1.0/100.
    6. Now change the body of the loop so that it reads just one double
    each time around. Define two variables to keep track of which is the
    smallest and which is the largest value you have seen so far. Each time
    through the loop write out the value entered. If it's the smallest so far,
    write the smallest so far after the number. If it is the largest so far,
    write the largest so far after the number.
    7. Add a unit to each double entered; that is, enter values such as
    10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft.
    Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft ==
    12in. Read the unit indicator into a string. You may consider 12 m
    (with a space between the number and the unit) equivalent to 12m
    (without a space).
    8. Reject values without units or with "illegal" representations of units,
    such as y, yard, meter, km, and gallons.
    9. Keep track of the sum of values entered (as well as the smallest and
    the largest) and the number of values entered. When the loop ends,
    print the smallest, the largest, the number of values, and the sum of
    values. Note that to keep the sum, you have to decide on a unit to use
    for that sum; use meters.
    10. Keep all the values entered (converted into meters) in a vector. At the
    end, write out those values.
    11. Before writing out the values from the vector, sort them (that'll make
    them come out in increasing order).
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    // Step 1-5
    /* 
    double x, y;
    cout << "Enter Two Integers: ";
    while(cin >> x >> y) {
        if(x > y) {
            cout << "larger number is: " << x << "\n";
            cout << "smaller number is: " << y << "\n";
        } else if(y > x) {
            cout << "larger number is: " << y << "\n";
            cout << "smaller number is: " << x << "\n";
        } else {
            cout << "Numbers are equal";
        }
        if(abs(x - y) < 0.01) {
            cout << "Almost Equal\n";
        }
    } */
    
    // Step 6 onwards
    double min = 2147483647, max = -2147483647, sum = 0;
    vector<double> values;
    string unit;
    cout << "Enter length followed by unit(cm, m. in, ft): ";
    for(double temp; cin >> temp >> unit;) {
        double conv = 0;
        bool illegal = false;
        if(unit == "cm") {
            conv = temp / 100.0;
        } else if(unit == "m") {
            conv = temp;
        } else if(unit == "in") {
            conv = temp * 2.54 / 100.0;
        } else if(unit == "ft") {
            conv = temp * 12.0 * 2.54 / 100.0;
        } else {
            illegal = true;
            cout << "Illegal Input Unit\n";
        }
        
        if(!illegal) {
            cout << "OK\n";
            if(conv > max) {
                cout << "Largest so far\n";
                max = conv;
            }
            if(conv < min) {
                cout << "Smallest so far\n";
                min = conv;
            }
            sum += conv;
            values.push_back(conv);
        }
    }
    sort(values.begin(), values.end());
    for(double x : values) cout << x << " ";
}