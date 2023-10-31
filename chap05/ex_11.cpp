/* Write a program that writes out the first so many values of the
Fibonacci series, that is, the series that starts with 1 1 2 3 5 8 13 21
34. The next number of the series is the sum of the two previous ones.
Find the largest Fibonacci number that fits in an int.
 */

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


// programmer must define numeric_limits in std namespace for user-defined types
template<typename T>
int safe_add(T a, T b, T max = std::numeric_limits<T>::max(), T min = std::numeric_limits<T>::min()) {
    if(a > 0 && b > max - a) throw std::runtime_error("overflow");
    if(a < 0 && b < min - a) throw std::runtime_error("underflow");

    return a + b;
}

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 1;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    cout << "1 ";
    for (int i = 1; i <= n; ++i) {
        try {
            nextTerm = safe_add(t1, t2);
        } catch(const std::runtime_error& e) {
            std::cerr << "\n" << e.what() << " after " << i << " terms";
            break;
        }

        t1 = t2;
        t2 = nextTerm;

        cout << nextTerm << " ";
    }
    return 0;
}