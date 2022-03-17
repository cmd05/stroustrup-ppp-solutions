#include <iostream>
#include <algorithm>

class vector {
	int sz;
    int space;
	double* elem;
public:
	explicit vector(int s): sz{s}, elem{new double[s]} { for(int i = 0; i < s; i++) elem[i] = 0; }
    vector(): sz{0}, elem{nullptr}, space{0} {}

	vector(std::initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]} {
		std::copy(lst.begin(), lst.end(), elem);
	}

	// copy constructor - deep copy
	vector(const vector& arg): sz{arg.sz}, elem{new double[sz]} {
		for(int i = 0; i < sz; i++) elem[i] = arg.elem[i];
	}

    int size() const { return sz; }
    int capacity() const { return space; }

	//copy assignment 
	vector& operator=(const vector& arg) {
		// we create a copy of a before deleting to account for self-assignment
		double* p = new double[arg.sz];
		for(int i = 0; i < arg.sz; i++) p[i] = arg.elem[i];
		delete[] elem;
		elem = p;
		sz = arg.sz;
		return *this; // for chaining
	}

	// move constructor
	vector(vector&& a): sz{a.sz}, elem{a.elem} {
		a.sz = 0;
		a.elem = nullptr;
	}

	// move assignment
	vector& operator=(vector&& a) {
		delete[] elem;
		elem = a.elem;
		sz = a.sz;
		a.elem = nullptr;
		a.sz = 0;
		return *this;
	}

	void set(int index, double v) { elem[index] = v; }
	double get(int i) const { return elem[i]; }

	double& operator[] (int n) { return elem[n]; }
	double operator[] (int n) const { return elem[n]; }

	~vector() { delete[] elem; }

    void reserve(int new_alloc);
    void resize(int new_size);

};

void vector::reserve(int new_alloc) {
    if(new_alloc <= space) return;
    double* p = new double[new_alloc];
    for(int i = 0; i < sz; i++) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = new_alloc;
}

void vector::resize(int new_size) {
    reserve(new_size);
    for(int i = sz; i < new_size; i++) elem[i] = 0;
    sz = new_size;
}


int main() {
    vector vc;
    vc.resize(-1);
    std::cout << vc.size();
}
