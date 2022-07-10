/* Implement square() without using the multiplication operator;
that is, do the x*x by repeated addition (start a variable result at
0 and add x to it x times). Then run some version of "the first
program" using that square(). */
#include <iostream>
using namespace std;

int square(int x) {
    int tmp = x;
    // 5 10 15 20 25
    for(int i = 1; i < tmp; i++) x+=tmp;
    return x;
}
int main() {
    cout << square(25);    
}