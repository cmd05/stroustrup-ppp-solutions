/// RAII - Resource Acquisition Is Initialization

// The resource (here, free-store memory) is acquired by a constructor 
// and released by the matching destructor.

// Acquire a resource in the constructor for some object that manages it,
// and release it again in the matching destructor

// return-statement will not prevent the invocation of destructors, 
// and neither will throwing an exception.

// when the thread of execution leaves a scope, 
// the destructors for every fully constructed object and sub-object are invoked

// Basic Guarantee: Throw exception without leaking resources
// Strong Guarantee: All observable values are same after failure
// No throw Guarantee: Do not throw

// let code==0 indicate invalid fill value
// let code==1 indicate Vec size overflow

#include <memory>

struct Exception {
	Exception(int c): code{c} {}
	int code;	
};

struct Vec {
	Vec(int s): sz{s}, elem{new double[sz]} {}
	
	void add(int x) {
		if(count == sz) throw Exception{1};
		if(x <= 0) throw Exception{0};

		elem[count] = x;
		count++;
	}

	~Vec() { delete[] elem; }

	int sz;
	int count = 0;
	double* elem;
};

// explicity dealing with pointers
// vc will not be deleted automatically if exception is thrown
// user of vc will have to delete it manually using `delete`

Vec* fill_vec_positive_p(double arr[], int sz) { 
	Vec* vc = new Vec{sz};

	for(int i = 0; i < sz; i++) vc->add(arr[i]);

	return vc;

	// ugly solution
	// try {
	// 	for(int i = 0; i < sz; i++) vc->add(arr[i]);
	// 	return vc;
	// } catch(...) {
	// 	delete vc;
	// 	throw;
	// }
}

// A unique_ptr is an object that holds a pointer.
// You can use –> and * on a unique_ptr exactly like a built-in pointer
// unique_ptr owns the object pointed to: when the unique_ptr is destroyed,
// it deletes the object it points to

// A unique_ptr has no overhead compared to an ordinary pointer.
std::unique_ptr<Vec> fill_vec_positive_u(double arr[], int sz) { // uniq_ptr
	std::unique_ptr<Vec> p {new Vec{sz}};

	for(int i = 0; i < sz; i++) p->add(arr[i]);

	// return p.release(); // return pointer to Vec
	return p; // return unique_ptr object
}

Vec fill_vec_positive_r(double arr[], int sz) { // raii
	Vec vc{sz};

	for(int i = 0; i < sz; i++) vc.add(arr[i]);

	return vc;
}

int main() {
	double arr[] = {1,5,5,-1};
	
	Vec* vc = fill_vec_positive_p(arr, sizeof(arr));
	Vec vc2 = fill_vec_positive_r(arr, sizeof(arr));
}