/// RAII - Resource Acquisition Is Initialization

// The resource (here, free-store memory) is acquired by a constructor 
// and released by the matching destructor.

// Acquire a resource in the constructor for some object that manages it,
// and release it again in the matching destructor

// return-statement will not prevent the invocation of destructors, 
// and neither will throwing an exception.

// when the thread of execution leaves a scope, 
// the destructors for every fully constructed object and sub-object are invoked

struct Exception {
	Exception(int c): code{c} {}
	int code;	
};

struct Int {
	Int(int n): x{&n} {}
	int* x = nullptr;
};

void unsafe(int num, int den) {
	int* n = &num;
	int* d = &den;

	if(den == 0) throw Exception{0};


	delete n; // does not delete if exception thrown
	delete d;

	return (*n / *d);
}

void safe(int num, int den) {
	Int n{num};
	Int n{den};


	if(den == 0) throw Exception{0};

	return (*n / *d);
}

int main() {
	safe(5, 0);
}