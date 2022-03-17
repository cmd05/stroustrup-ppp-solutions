#include <algorithm>

class vector {
	int sz;
	int space;
	double* elem;
public:
	explicit vector(int s);
	vector();
	vector(std::initializer_list<double> lst);

	// copy constructor - deep copy
	vector(const vector& arg);

	//copy assignment
	vector& operator=(const vector& arg);

	// move constructor
	vector(vector&& a);

	// move assignment
	vector& operator=(vector&& a);

	// Access by index
	double& operator[] (int n);
	double operator[] (int n);

	// Destructor
	~vector() { delete[] elem; }

	void set(int index, double v);
	double get(int i) const;

	int size() const;
	int capacity() const;
	void reserve(int new_alloc); // Copy elements to new pointer and allocate space
	void resize(int new_size); // Copy elements and initialize extra slots
};