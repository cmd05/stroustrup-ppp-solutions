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

int main() {
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