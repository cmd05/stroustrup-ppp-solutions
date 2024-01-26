#include <iostream>
#include <iomanip>

int main() {
    // float x = 1.0/333;
    // float sum = 0;
    // for(int i = 0; i < 333; ++i) sum+=x;
    // std::cout << sum << '\n';
    // std::cout << std::setprecision(15) << sum << '\n';

    // float x2 = 1.0/10;
    // std::cout << std::setprecision(15) << x2 << '\n';

    // short int y = 41000; // short is -32768 to 32767
    // int i = 1000000;
    // std::cout << y << ' ' << i*i << '\n'; // i*i gives an int
    // std::cout << (long long) i * i << '\n'; // product is now a long long

    /* 
        2100000009 2.1e+09
        2100000009 2100000000
    */
    // int x3 = 2100000009;
    // float f = x3; // float stores in scientific notation
    // std::cout << x3 << ' ' << f << '\n';
    // std::cout << std::setprecision(15) << x3 << ' ' << f << '\n';

    // float f2 = 2.9;
    // int x4 = f2; // truncation
    // std::cout << std::setprecision(6) << x4 << ' ' << f2 << '\n';

    /* 
        4 4 4
        8 16
        8 8
        2 2
    */
    // std::cout << sizeof(int) << ' ' << sizeof(long) << ' ' << sizeof(long int) << '\n'
    //           << sizeof(double) << ' ' << sizeof(long double) << '\n'
    //           << sizeof(long long) << ' ' << sizeof(long long int) << '\n'
    //           << sizeof(short) << ' ' << sizeof(short int);
 
    // long x5 = 4.5;
    // std::cout << x5; // 4

    // (2^64 - 1) + (2^64 - 1) = 2147483647->-2147483648 then -(2^64) + 2^64-2 = -2
    int x = INT_MAX;
    std::cout << x;

    // number of items (including both start and end) [start, end]: end - start + 1
    // number of items (including start, excluding end) [start, end): end - start
    // number of items in between (excluding both) (start, end): end - start - 1
    
    // distance between items (number of steps taken): end - start
    // value after n steps from start: start + n (ex: 0 + 2 = 2, 1 + 3 = 4
    // valid range of n values (starting from zero) [0, end]: [0, n-1]
    // valid range of n values (starting from one) [1, end]: [1, n]

    // 64 bytes
    // can take 2^64 values
    // unsigned: 0 to (2^64) - 1
    // signed: -2^32 to -1 (2^32 values) and 0 to 2^32 - 1 (2^32 values)
    
    
}