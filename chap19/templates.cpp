template<typename T>
	requires Element<T>()
class vector {

};

template<Element T>
class vector {

};

template<typename Elem>
class vector {

};

template<typename C> void printout(const C& c) {
	for(int i = 0; i < c.size(); i++) cout << c[i] << '\n';
}

// Template argument deduction
template<typename T, int n> 
void fill(array<T, n> arr, T val) {
	for(int i = 0; i < arr.size(); i++) arr[i] = val;
}