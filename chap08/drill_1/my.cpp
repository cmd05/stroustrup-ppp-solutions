#include <iostream>
#include "my.h"
using namespace std; // this directive is not leaked to use.cpp;
                     // if the directive was added to my.h it would have leaked to use.cpp

void print_foo(){
    cout << foo;
}

void print(int i) {
    cout << i;
}
