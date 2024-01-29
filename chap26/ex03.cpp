#include <iostream>

template<typename In, typename T, typename Compare = std::less<>>
std::pair<In, bool> binary_search(In begin, In end, const T& val, Compare comp = Compare{}) {
    if(begin >= end)
        return {end, false}; // exit empty sequence
    
    In middle = begin + (end - begin) / 2;

    if(*middle == val)
        return {middle, true}; // found
    
    if(begin == middle) // test this first to avoid infinite recursion
        return {end, false}; // not found
    
    if(comp(*middle, val))
        return binary_search(middle, end, val); // search in right half
    
    return binary_search(begin, middle, val); // search in left half
}

int main() {
    int sz = 4;
    int v[sz] = {2,1,0,-1};

    auto p = binary_search(v, v + sz, -1, std::greater<>{});
    
    if(p.second) std::cout << *(p.first);
    else std::cout << "not found";
}