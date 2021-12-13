#include <iostream>

class vector {
    double* elem;
    int sz;
    public:
        vector(int sz): sz{sz}, elem{new double[sz]} {
            for(int i = 0; i < sz; i++) elem[i] = 0;
        }
        ~vector() { delete[] elem; }
        int size() const { return sz; }
        double get(int n) const { return elem[n]; }
        void set(int n, double v) { elem[n] = v; }

};

std::ostream& operator<<(std::ostream& os, vector vc) {
    for(int i = 0; i < vc.size(); i++) os << vc.get(i) << " ";
    return os;
}

void print_array10(std::ostream& os, int* a) {
    for(int i = 0; i < 10; i++) os << a[i] << " ";
}

void print_array(std::ostream& os, int* a, int n) {
    for(int i = 0; i < n; i++) os << a[i] << " ";
}

int main() {
    int sz = 10;
    int* arr = new int[sz];
    
    for(int i = 0; i < sz; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    delete[] arr;

    int* arr2 = new int[10];
    for(int i = 0; i < 10; i++) arr2[i] = 100 + i;
    for(int i = 0; i < 10; i++) std::cout << arr2[i] << " ";
    std::cout << "\n";

    int* arr3 = new int[11];
    for(int i = 0; i < 11; i++) arr3[i] = 100 + i;
    for(int i = 0; i < 11; i++) std::cout << arr3[i] << " ";
    std::cout << "\n";

    int* arr4 = new int[20];
    for(int i = 0; i < 20; i++) arr4[i] = 100 + i;
    for(int i = 0; i < 20; i++) std::cout << arr4[i] << " ";
    std::cout << "\n";

    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    vector v1{10};
    for(int i = 0; i < 10; i++) v1.set(i, 100 + i);

    vector v2{11};
    for(int i = 0; i < 11; i++) v2.set(i, 100 + i);

    vector v3{20};
    for(int i = 0; i < 20; i++) v3.set(i, 100 + i);

    std::cout << v1 << "\n";
    std::cout << v2 << "\n";
    std::cout << v3 << "\n";

}