#pragma once

#include <memory>

/**
    template<typename T> class allocator {
    public:
            // . . .
            T* allocate(int n);                // allocate space for n objects of type T
            void deallocate(T* p, int n);      // deallocate n objects of type T starting at p
            void construct(T* p, const T& v);  // construct a T with the value v in p
            void destroy(T* p);                // destroy the T in p
    };

   * alloc.destroy(): turns typed object to raw memory. (memory is still owned by the allocator)
   * alloc.deallocate(): returns the memory to the free store. Remember to destroy the memory before returning it to the free store
   * 
   * vector_base deals with raw memory. it must not use destroy() itself
*/

template<typename T, typename A>
class vector_base {
public:
    // Constructors
    vector_base(const A& a, int n): alloc{a}, sz{n}, space{n}, elem{alloc.allocate(n)} {}
    vector_base(): sz{0}, space{0}, elem{nullptr} {}

    // Destructors
    ~vector_base() { deallocate_elem(); }

    void deallocate_elem() { alloc.deallocate(elem, space); }

public:
    T* elem;
    int sz;
    int space;
    A alloc;
};