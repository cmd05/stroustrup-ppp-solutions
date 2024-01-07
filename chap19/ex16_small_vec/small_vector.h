#pragma once

#include <memory>
#include <initializer_list>

template<typename T, typename A>
class vector_rep {
public:
    T* elem;
    int space;
    int sz;
    A alloc;
public:
    vector_rep(): elem{nullptr}, space{0}, sz{0} {}
    vector_rep(int s): elem{alloc.allocate(s)}, sz{s}, space{s} {}

    ~vector_rep() {
        for(int i = 0; i < sz; i++)
            alloc.destroy(&elem[i]);

        alloc.deallocate(elem, space);
    }
};

// Contains a vector_rep<T,A>* pointing to a vector_rep<T,A> allocated on the heap
template<typename T, typename A = std::allocator<T>>
class small_vector {
    vector_rep<T,A>* vr;
public:
    small_vector(): vr{new vector_rep<T,A>{}} {}

    small_vector(int s, T val) {
        vr = new vector_rep<T,A>{s};
        for(int i = 0; i < s; i++) vr->alloc.construct(&vr->elem[i], val);
    }

    small_vector(std::initializer_list<T> lst) {
        vr = new vector_rep<T,A>{lst.size()};
        std::uninitialized_copy(lst.begin(), lst.end(), vr->elem);
    }
    
    void reserve(int new_alloc) {
        if(new_alloc <= vr->space) return;

        // not using vector_base for RAII 
        T* p = vr->alloc.allocate(new_alloc);
        std::uninitialized_copy(vr->elem, vr->elem + vr->sz, p);

        delete[] vr->elem;
        vr->elem = p;

        vr->space = new_alloc;
    }

    void resize(int new_size, T val = T()) {
        if(new_size < 0) return;
        reserve(new_size);

        for(int i = vr->sz; i < new_size; i++)
            vr->alloc.construct(&vr->elem[i], val);

        vr->sz = new_size;
    }

    void push_back(T val) {
        if(vr->sz == 0)
            reserve(8);
        else if(vr->sz == vr->space)
            reserve(2*vr->sz);

        vr->elem[vr->sz] = val;

        ++(vr->sz);
    }

    T& operator[](int n) { return vr->elem[n]; }
    const T& operator[](int n) const { return vr->elem[n]; }

    int size() const { return vr->sz; }
    int capacity() const { return vr->space; }

    ~small_vector() { delete vr; }
};