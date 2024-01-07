#pragma once

template<typename T>
class unique_ptr {
public:
    unique_ptr(T* p2) { p = p2; }
    ~unique_ptr() { delete p; }
    
    T* release() { T* p2 = p; p = nullptr; return p2; } // set p to nullptr after release
    
    void reset(T* p2) { 
        delete p;
        p = p2;
    }

    // Disable copy constructor and assignment
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Move semantics
    unique_ptr(unique_ptr&& p2): p{p2} { p2 = nullptr; }
    unique_ptr& operator=(unique_ptr& p2) {
        if(&p2 == this) return *this;

        delete p;
        p = p2;
        p2 = nullptr;
    }

    T& operator*() { return *p; }
    const T& operator*() const { return *p; }

    T* operator->() { return p; }
    const T* operator->() const { return p; }
private:
    T* p;
};