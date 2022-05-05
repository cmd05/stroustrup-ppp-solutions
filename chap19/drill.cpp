#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

template<typename T>
struct S {
	S(T v): val{v} {}
	
	T get() const;
	T& get();

	void set(T& v);
	void set(T&& v);
	S& operator=(const T&);
private:
	T val;
};

template<typename T>
T& S<T>::get() { return val; }

template<typename T>
T S<T>::get() const { return val; }

template<typename T>
void S<T>::set(T& v) { val = v; }

template<typename T>
void S<T>::set(T&& v) { val = v; }

template<typename T>
S<T>& S<T>::operator=(const T& v) {
	val = v;
}

template<typename T>
std::istream& operator>>(std::istream& is, S<T>& s) {
	is >> s.get();
	return is;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {

	std::string x;
	std::getline(std::cin, x);

    std::stringstream ss {x};

	char c1;
	ss >> c1;

	if(c1 != '{') return is;

	char c2;

	for(T t; ss >> t >> c2;) {
		if(c2 == ',')
			v.push_back(t);
		else {
			if(c2 == '}') v.push_back(t);
			return is;
		}
	}
		
	return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v) {
	os << "{ ";
	
	for (int i = 0; i < v.size(); i++) {
		os << v[i];
		if(i != v.size()-1) os << ", ";
	}

	os << " }";
	return os;
}

template<typename T>
void read_val(S<T>& v) {
	std::cout << "Enter val: ";
	std::cin >> v;
}

int main() {
	S<int> i{69};
	S<char> c{'c'};
	S<double> d{420.0};
	S<std::string> s{"yoooo"};

	// read_val(i);
	// read_val(c);
	// read_val(d);

	std::vector<int> v {8,9,10};
	S<std::vector<int>> vi{v};

	read_val(vi);
	std::cout << "\n" << vi.get();
/*
	std::cout << i.val << "\t" << c.val << "\t"
			  << d.val << "\t" << s.val << "\n";

	for(int x : vi.val) std::cout << x << "\t";
	std::cout << "\n";
*/
	// std::cout << i.get() << "\t" << c.get() << "\t"
	// 		  << d.get() << "\t" << s.get() << "\n";

	// std::vector<int> v2 = vi.get();
	// for(int x : v2) std::cout << x << "\t";
	// std::cout << "\n";
}