#include <iostream>

// this is how std::array works. no need of defining copy constructors / assignment
// arrays will be deep copied when placed in class/struct
struct A { 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}; 
};

void f(int* arr) {
    for(int i = 0; i < 10; i++) std::cout << arr[i];
}

template<typename T, int N>
struct array {
    T elem[N];
    T* p;

    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    T* data() { return elem; }
    const T* data() const { return elem; }

    int size() const { return N; }
};

int main() {
    // A a1;
    // A a2 = a1; // ok. arrays are deep copied when placed in a struct

    // a2.arr[0] = -1;

    // int* p = a2.arr; // ok
    // // a2.arr = a1.arr; // error

    // // output: 12345678910
    // for(int i = 0; i < 10; i++) std::cout << a1.arr[i];

    // int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    // f(arr1);

    array<int, 3> arr = {1,2,3};
    for(int i = 0; i < arr.size(); i++) std::cout << arr[i];

    // for(int i = 0; i < arr.size(); i++) std::cout << arr[i];
}