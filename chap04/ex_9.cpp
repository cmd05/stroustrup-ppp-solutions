/* Try to calculate the number of rice grains that the inventor asked for in
exercise 8 above. You'll find that the number is so large that it won't
fit in an int or a double. Observe what happens when the number gets
too large to represent exactly as an int and as a double. What is the
largest number of squares for which you can calculate the exact
number of grains (using an int)? What is the largest number of squares
for which you can calculate the approximate number of grains (using a
double)?
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

int main() {
    double sum = 0;
    for(int i = 0; i < 1000; i++) {
        int grain_on_square = pow(2, i + 1);
        sum += grain_on_square;
        cout << sum << endl;
        if(sum >= numeric_limits<double>::max()) {
            cout << "After " << i + 1 << " iterations double value has been overflown";
            break;
        }
    }
}