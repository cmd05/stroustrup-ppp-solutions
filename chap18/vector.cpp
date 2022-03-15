#include <iostream>
#include <algorithm>

class vector {
	int sz;
	double* elem;
public:
	explicit vector(int s): sz{s}, elem{new double[s]} { for(int i = 0; i < s; i++) elem[i] = 0; }

	vector(std::initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]} {
		std::copy(lst.begin(), lst.end(), elem);
	}

	// copy constructor - deep copy
	vector(const vector& arg): sz{arg.sz}, elem{new double[sz]} {
		for(int i = 0; i < sz; i++) elem[i] = arg.elem[i];
	}

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
};

void fn(const vector& v);

int main() {
	vector v1 = {1, 2, 3, 4};

	/** No copy constructor
	// generic copying copies elements of v1 to v2
	// v1.size == v2.size
	// v1.elem[i] == v2.elem[i]
	v2 = v1;

	// but since the address of object in pointers is same
	// editing elements of v1 affects v2 also
	v1.set(0, 0);
	std::cout << v1.get(0) << " " << v2.get(0) << "\n"; // outputs 0 0 not 0 1

	// worse when v1 gets deleted at end of scope,
	// v2.elem is deleted which causes double-deletion and corrupts free store
	*/

	// With copy constructor
	vector v2 = v1;
	v1.set(0, 0);
	std::cout << v1.get(0) << " " << v2.get(0) << "\n"; // outputs 0 1 not 0 0

	// shallow copy
	int* a = new int{42};
	int* b = b;

	// deep copy
	int* p = new int{42};
	int* q = new int{*p};

	// we prefer move constructor to pointer as poin
	/* 
	The move constructor is called whenever an object is initialized from xvalue of the same type, which includes:

	initialization, T a = std::move(b); or T a(std::move(b));, where b is of type T

	function argument passing: f(std::move(a));, where a is of type T and f is void f(T t)

	function return: return a; inside a function such as T f(), where a is of type T which has a move constructor.
	 */

	/* implicit int to vector */
	// vector v = 10;
	// v = 20;
	// fn(30);
	
	vector v {1, 2, 3, 42};
	v[3] = 4;
	std::cout << v[2];
}
