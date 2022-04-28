template<typename T>
class vector {
	int sz;
	T* elem;
	int space;
public:
	vector(): sz{0}, elem{nullptr}, space{0} {}

	explicit vector(int s): sz{s}, elem{new T[s]}, space{s} {
		for(int i = 0; i < s; i++) elem[i] = 0;
	}
	vector(std::initializer_list<T> lst);
	
	// copy constructor - deep copy
	vector(const vector& arg);

	//copy assignment 
	vector& operator=(const vector& arg);
	// move constructor
	vector(vector&& a);
	// move assignment
	vector& operator=(vector&& a);

	void set(int index, T v);
	const T get(int i) const;
	int size() const;
	
	T& operator[] (int n);
	const T& operator[] (int n) const;

	void reserve(int new_alloc);
	int capacity() const;
	void push_back(const T& d);
	
	~vector();
}