#pragma once
#include <memory>

template<typename T, typename A = std::allocator<T>>
class unique_ptr {
public:
	explicit unique_ptr(T* t) { 
		p = alloc.allocate(1);
		alloc.construct(p, *t); 
	}

	T* release() const { return p; }
	
	~unique_ptr() { 
		alloc.destroy(p);
		alloc.deallocate(p, 1);
	}

	T* operator->();
	T& operator*();
private:
	A alloc;
	T* p;
};

template<typename T, typename A>
T* unique_ptr<T,A>::operator->() {
	return p;
}

template<typename T, typename A>
T& unique_ptr<T,A>::operator*() {
	return *p;
}