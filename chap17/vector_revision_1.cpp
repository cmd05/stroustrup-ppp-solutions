#include <iostream>

class vector {
    int sz;
    double* elem;
public:
    vector(int s): sz{s}, elem{new double[s]} {}
    ~vector() { delete[] elem; }

    double get(int i) const { return elem[i]; }
    void set(int i, double v) { elem[i] = v; }

    int size() const { return sz; }
};

int main() {
    vector* p = new vector{10};
    int x = p->size();
    int y = p->get(2);
    p->set(5, 20);
    // std::cout << p->sz; // if sz was public
}