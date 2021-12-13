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

void print_array(std::ostream& os, int* a, int n) {
    for(int i = 0; i < n; i++) os << a[i] << " ";
}

int main() {
    int* p1 = new int {7};
    std::cout << p1 << " " << *p1 << "\n";

    int* p2 = new int[7];
    double tmp = 0.5;
    for(int i = 0; i < 7; i++) {
        tmp *= 2;
        p2[i] = tmp;
    }

    std::cout << p2 << "\n";
    for(int i = 0; i < 7; i++) std::cout << p2[i] << " ";
    std::cout << "\n";

    int* p3 = p2;
    int* tmp_pt = p2;
    p2 = p1;
    p3 = p2;
    std::cout << p1 << " " << p2;
    
    delete p1;
    delete[] tmp_pt;

    int* _p1 = new int[10];
    double tmp2 = 0.5;
    for(int i = 0; i < 10; i++) {
        tmp2 *= 2;
        _p1[i] = tmp2;
    }

    int* _p2 = new int[10];
    for(int i = 0; i < 10; i++) _p2[i] = _p1[i];
    
    vector vc1{10};
    
    double tmp3 = 0.5;
    for(int i = 0; i < 10; i++) {
        tmp3 *= 2;
        vc1.set(i, tmp3);
    }

    // or copy constructor
    vector vc2{10};
    for(int i = 0; i < 10; i++) vc2.set(i, vc1.get(i));
    std::cout << "\n" << vc2;
}