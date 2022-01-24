#include <iostream>
#include <math.h>

int ga[10];

void f(int arr[], int sz) {
    int la[10];
    for(int i = 0; i < 10; i++) la[i] = ga[i];
    for(int i = 0; i < 10; i++) std::cout << la[i] << " ";
    
    std::cout << "\n";
    int* p = new int[sz];
    for(int i = 0; i < sz; i++) p[i] = arr[i];
    for(int i = 0; i < 10; i++) std::cout << p[i] << " ";

    std::cout << "\n";

    delete[] p;
}

int main() {
    for(int i = 0; i < 10; i++) ga[i] = pow(2, i);

    f(ga, 10);
    
    int aa[10];
    int fc = 1;

    for(int i = 0; i < 10; i++) {
        aa[i] = fc*(i+1);
        fc = aa[i];
    }

    f(aa, 10);
}