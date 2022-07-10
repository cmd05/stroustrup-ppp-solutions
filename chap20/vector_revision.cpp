#include <iostream>

class Vector {
public:
    explicit Vector(int s): sz{s}, space{s}, elem{new double[sz]} {
        for(int i = 0; i < sz; i++) elem[i] = 0;
    }

    Vector(): sz{0}, space{0}, elem{nullptr} {}

    Vector(const Vector& arg): sz{arg.sz}, space{arg.space}, elem{new double[sz]} {
        for(int i = 0; i < sz; i++) elem[i] = 0;
    }

    Vector& operator=(const Vector& arg): sz{arg.sz}, space{arg.space} {
        if(this == &arg) return *this;

        delete[] elem;
        elem = new double[sz];
        for (int i = 0; i < sz; ++i) elem[i] = arg.elem[i];
        return *this;
    }


    Vector(Vector&& arg): sz{arg.sz}, space{arg.space} {
        delete[] elem;
        elem = new double[arg.sz];
        arg.elem = nullptr;
        arg.sz = 0;
        arg.space = 0;
    }
private:
    int sz;
    int space;
    double* elem;
};