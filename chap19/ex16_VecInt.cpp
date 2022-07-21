#include <iostream>
#include <memory>

template<typename T, typename A = std::allocator<T>>
class vector_base {
public:
	int sz;
	int space;
};

template<typename T, typename A = std::allocator<T>>
class vector : public vector_base<T,A> {
public:
	vector(): elem{nullptr} {}
private:
	T* elem;
};

int main() {
	vector<int> v;
	std::cout << sizeof(vector<int>);
}