#include <iostream>

void ff1(int arr[], int sz) { // ok, parameter `arr` is implicitly converted to ptr
    for(int i = 0; i < sz; i++)
        std::cout << arr[i];
}

// Multidimensional Arrays

// // second dimension cannot be unspecified (and passed as a parameter)
// void f3(int [5][], int dim2);           // error
// void f4(int[][], int dim1, int dim2);    // error

void f5(int* m, int dim1, int dim2)      // odd, but works
{
    for (int i=0; i<dim1; ++i)
        for (int j = 0; j<dim2; ++j) 
            std::cout << m[i*dim2+j] << '\n';
            // std::cout << m[i][j] << '\n'; // cannot use m[i][j] syntax with int*
}

void fn1(int a[3][5]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 5; j++)
            std::cout << a[i][j] << '\n';
}

void f2(int a[][5], int dim1) {
    for(int i = 0; i < dim1; i++)
        for(int j = 0; j < 5; j++)
            std::cout << a[i][j] << '\n';
}

int main() {
    int a[3][5] = {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
    };

    // int a[3][] = { // error
    //     {1,2,3,4,5},
    //     {1,2,3,4,5},
    //     {1,2,3,4,5},
    // };

    // int a[][] = { // error
    //     {1,2,3,4,5},
    //     {1,2,3,4,5},
    //     {1,2,3,4,5},
    // }

    int* p = a[0]; // pointer to first element a[0][0]
    int* p2 = &p[7]; // pointer to a[1][2]
    int* p3 = &a[1][2]; // pointer to a[1][2]

    // fn1(a); // ok
    // f5(p, 3, 5); // ok

    std::cout << *p << ' ' << *p2 << ' ' << *p3;
}