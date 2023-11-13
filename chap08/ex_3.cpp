/* Create a vector of Fibonacci numbers and print them using the
function from exercise 2. To create the vector, write a function,
fibonacci(x,y,v,n), where integers x and y are ints, v is an empty
vector<int>, and n is the number of elements to put into v; v[0] will
be x and v[1] will be y. A Fibonacci number is one that is part of a
sequence where each element is the sum of the two previous ones. For
example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . . Your
fibonacci() function should make such a sequence starting with its x
and y arguments */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void fibonacci(const int& x, const int& y, vector<int>& v, const int& n) {
    v.push_back(x);
    v.push_back(y);
    
    int a = x;
    int b = y;

    for (int i = 0; i < n-2; i++) {
        if(a > INT_MAX - b) break;

        int sum = a + b;
        a = b;
        b = sum;
        v.push_back(sum);
    }
}

int main() {
    vector<int> v;
    fibonacci(3, 4, v, 50);
    for(int x : v) cout << x << " ";
}