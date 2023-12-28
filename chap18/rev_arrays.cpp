#include <iostream>

// does not include terminating-zero
// strlen("hello") == 5
// already part of string.h
int strlen(const char* str) {
    int n = 0;
    while(str[n]) n++;
    return n;
}

std::istream& read_word(std::istream& is, char* buffer, int max) {
    is.width(max); // reads `max` no. of characters (including '\0'). Ex: "hello" => "hell"
    is >> buffer;

    return is;
}

int main() {
    char a1[10];
    a1[7] = 'a';
    *a1 = 'b'; // same as a1[0]='b'

    a1[-2] = 'c'; // ub (out of range access)
    a1[12] = 'c'; // ub (out of range access)

    double a2[10];
    double* p = &a2[5];
    *p = 5; // changes a2[5]
    p[1] = 12; // changes a2[6]
    p[-2] = 4; // changes a2[3]
    p += 3;
    *p = 1; // changes p[8]
    p -= 5; // changes p[3]

    double a3[10] = {1,2,3,4,5,6,7,8,9,10};
    // double* a3 = new double[10] {1,2,3,4,5,6,7,8,9,10};

    /* for(double* pt = &a3[0]; pt < &a3[10]; pt++) */
    /// UB. pt < &a3[10] is eqv to: pt < &(*(&a3[0] + 10)). the dereference causes UB
    /// Here out of range memory is `read` by performing *p, which results in UB

    // for(double* pt = &a3[0]; pt <= &a3[9]; pt++) // ok
    //     std::cout << *pt << '\n';
    
    /* for(double* pt = &a3[9]; pt > &a3[-1]; pt--) */
    //. UB. pt > &a3[-1] is eqv to: pt < &(*(&a3[0] - 1)). the dereference causes UB
    /// Here out of range memory is `read` by performing *p (due to subscripting []), which results in UB
    
    // for(double* pt = &a3[9]; pt >= &a3[0]; pt--) // ok
    //     std::cout << *pt << '\n';

    char ch[100];
    char* p2 = ch; // points to ch[0]. eqv to: char* p = &ch[0]

    // std::cout << sizeof(ch) << " " << sizeof(p2) << '\n';

    // f(ch) is same as f(&ch[0])
    // the pointer formed as a result of array to pointer decay, is of rvalue type, it cannot be assigned to.

    // ch = new char[20]; // error: no assignment to array name
    // &ch[0] = new char[20]; // error: &ch[0] is not an lvalue

    int x[100];
    int y[100];

    // x = y; // error: x decays to ptr, which is not an lvalue
    // int z[100] = y; // error

    // std::cout << strlen("str");

    // char ch1[3] = "str"; // error
    char ch1[4] = "str"; // ok

    int ai[] = {1,2,3};
    int ai2[100] = {1,2,3,4}; // next 96 elements are 0 initialized
    double ad[100]; // elements are not 0.0 initialized
    double ad2[100] = {}; // elements are 0.0 initialized
    char ac[] = {'a','b','c'}; // array of size 3. zero-terminator is not added

    // std::cout << ad2[12];

    // int n;
    // std::cin >> n;
    // int arr[n]; // not allowed by C++ standard. g++ allows
    // arr[0] = 15;
    // std::cout << arr[0];
    // array size must be known at compile time according to c++ standard. free store array can have length known at runtime
    // i.e int* p = new int[n]

    // int* pi; // always initialize pointers!

    constexpr int max = 5;
    for(char s[max]; read_word(std::cin, s, max);) {
        std::cout << s << ' ' << strlen(s) << '\n';
    }
}