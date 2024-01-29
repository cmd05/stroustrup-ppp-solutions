#include <iostream>
#include <vector>

// using iterators
// search in [begin, end)
/* template<typename In, typename T>
std::pair<In, bool> bin(In begin, In end, T val) {
    // if(begin >= end)
    //     return nullptr; // exit empty sequence
    
    In middle = begin + (end - begin) / 2;

    if(*middle == val)
        return {middle, true}; // found
    
    if(begin == middle) // test this first to avoid infinite recursion
        return {end, false}; // not found
    
    if(*middle < val)
        return bin(middle, end, val); // search in right half
    
    return bin(begin, middle, val); // search in left half
} */

// binary search for contiguous memory sequence
// search in [begin, end)
// user should not pass an empty sequence (dereferencing of empty array will occur)
template<typename T>
T* bin(T* begin, T* end, T val) {
    // if(begin >= end)
    //     return nullptr; // exit empty sequence

    T* middle = begin + (end - begin) / 2;

    if(*middle == val)
        return middle; // found
    
    if(begin == middle) // test this first to avoid infinite recursion
        return nullptr; // not found
    
    if(*middle < val)
        return bin(middle, end, val); // search in right half
    
    return bin(begin, middle, val); // search in left half
}

int main() {
    int v[] = {1,3};
    int sz = 2;
    
    int* p = bin(v, v + sz, 2);

    if(p) std::cout << *p;
    else std::cout << "not found";
}