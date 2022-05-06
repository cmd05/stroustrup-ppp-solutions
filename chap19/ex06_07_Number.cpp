// Repeat the previous exercise, but with a class Number<T> where T
// can be any numeric type. Try adding % to Number and see what
// happens when you try to use % for Number<double> and
// Number<int>.

#include <iostream>
#include <vector>
#include <fstream>

template<typename T, typename U>
auto sum_of_products(std::vector<T> vt, std::vector<U> vu) {
	auto x = vt[0] * vu[0];
	
	for (int i = 1; i < vt.size(); ++i)	{
		x += vt[i]*vu[i];
	}

	return x;
}

// -------------------------------------------------------------

template<typename T>
class Number {
public:
	Number(): val{T()} {}
	Number(T v): val{v} {}
	T get() const { return val; }

	void set(const T& x) {  val = x; }
	void set(const T&& x) {  val = x; }	
private:
	T val;
};

// -------------------------------------------------------------

template<typename T>
std::ostream& operator<<(std::ostream& os, const Number<T>& n) {
	return os << n.get();
}

template<typename T>
std::istream& operator>>(std::istream& is, Number<T>& n) {
	T v;
	is >> v;
	n.set(v);
	return is;
}

// -------------------------------------------------------------

template<typename T1, typename T2>
auto operator+(const Number<T1>& n1, const Number<T2>& n2) {
	return n1.get() + n2.get();
}

template<typename T1, typename T2>
auto operator-(const Number<T1>& n1, const Number<T2>& n2) {
	return n1.get() - n2.get();
}

template<typename T1, typename T2>
auto operator*(const Number<T1>& n1, const Number<T2>& n2) {
	return n1.get() * n2.get();
}

template<typename T1, typename T2>
auto operator/(const Number<T1>& n1, const Number<T2>& n2) {
	return n1.get() / n2.get();
}

template<typename T1, typename T2>
auto operator%(const Number<T1>& n1, const Number<T2>& n2) {
	return n1.get() % n2.get();
}

int main() {
	std::vector<Number<int>> v1 {1,2,3};
	std::vector<Number<double>> v2 {4,5,6};

	std::cout << sum_of_products(v1, v2);

	Number<int> n1;
	Number<double> n2;

	std::cout << "int: ";
	std::cin >> n1;
	std::cout << "double: ";
	std::cin >> n2;

	std::cout << n1 * n2; // error
	// std::cout << n1 % n2; // error
}