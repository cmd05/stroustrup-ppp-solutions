#pragma once

template<typename T>
class Allocator {
public:
	T* allocate(int n) const;
	void construct(T* p, const T& val) const;	
	void destroy(T* p) const;	
	void deallocate(T* p, int n = 0) const;
};