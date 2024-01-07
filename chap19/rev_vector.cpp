#include <iostream>
#include <algorithm>

class vector {
	int sz;
	int space;

	double* elem;
public:
	explicit vector(int s): sz{s}, elem{new double[s]} { for(int i = 0; i < s; i++) elem[i] = 0; }
	vector(): sz{0}, space{0}, elem{nullptr} {}
	
	vector(std::initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]} {
		std::copy(lst.begin(), lst.end(), elem);
	}

	vector(const vector& arg): sz{arg.sz}, elem{new double[sz]} {
		std::copy(arg.elem, arg.elem + sz, elem);
	}

	vector& operator=(const vector& arg) {
		double* p = new double[arg.sz];
		std::copy(arg.elem, arg.elem + arg.sz, p);
		delete[] elem;
		elem = p;
		sz = arg.sz;

		return *this;
	}

	vector(vector&& a): sz{a.sz}, elem{a.elem} {
		std::cout << "MC";

		a.sz = 0;
		a.elem = nullptr;
	}

	vector& operator=(vector&& a) {
		std::cout << "MA";

		delete[] elem;
		elem = a.elem;
		sz = a.sz;
		a.elem = nullptr;
		a.sz = 0;
		return *this;
	}

	int size() const { return sz; }

	void set(int index, double v) { elem[index] = v; }
	double get(int i) const { return elem[i]; }

	double& operator[] (int n) { return elem[n]; }
	double operator[] (int n) const { return elem[n]; }

	~vector() { delete[] elem; }
};

void fn(const vector& v);

void printv(vector v) {
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << '\n';
}

vector vf() {
    vector v{1,2,3};
    return v;
}

int main() {

}
