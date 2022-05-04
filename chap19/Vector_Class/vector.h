#include <algorithm>

class vector {
	int sz;
	double* elem;
	int space; // number of elements + free space
public:
	vector();
	explicit vector(int s);
	vector(std::initializer_list<double> lst);
	
	// copy constructor - deep copy
	vector(const vector& arg);

	//copy assignment 
	vector& operator=(const vector& arg);
	// move constructor
	vector(vector&& a);
	// move assignment
	vector& operator=(vector&& a);

	void set(int index, double v);
	double get(int i) const;
	int size() const;
	
	double& operator[] (int n);
	double operator[] (int n) const;

	void reserve(int new_alloc);
	void resize(int new_size);
	int capacity() const;
	void push_back(double d);
	
	~vector();
};

void fn(const vector& v);