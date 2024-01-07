#include <iostream>
#include <concepts>
#include <cstddef>
#include <vector>
#include <memory>

// run with c++20
// g++ revision.cpp -std=c++20

// template<typename T>
// concept Hashable = requires(T a)
// {
//     { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
// };

// class B {};

// template<Hashable T>
// void f(T) {}

// returning pointer to free store - must be deleted by caller after use
std::vector<int>* make_vc1() {
    std::vector<int>* pvc = new std::vector<int>;
    
    // ...

    return pvc;
}

// return a unique_ptr - caller does not need to manually delete unique_ptr
std::unique_ptr<std::vector<int>> make_vc2() {
    std::unique_ptr<std::vector<int>> uptr {new std::vector<int>};

    // supports ptr operations like * -> etc.

    return uptr;
}

// better way - use move operations
std::vector<int> make_vc3() {
    std::vector<int> vc;

    // ...

    return vc; // move semantics on caller are invoked automatically if they are defined
}

int main() {
    // f("abc"); // ok
    // f(B()); // err

    
}