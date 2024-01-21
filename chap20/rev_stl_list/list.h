#pragma once

template<typename T>
class list {
public:
    class iterator;

    iterator begin();
    iterator end();

    iterator insert(iterator p, const T& val); // copied by placement new
    iterator erase(iterator p);

    void push_back(const T& val);
    void push_front(const T& val);

    void pop_front();
    void pop_back();

    T& front();
    T& back();
private:
    struct Link;

    Link* first;
    Link* last;
};

template<typename T>
struct list<T>::Link {
    T val;
    T* next;
    T* prev;
};

template<typename T>
class list<T>::iterator {
public:
    iterator(Link* ptr): p{ptr} {}

    iterator& operator++() { p = p->succ; return *this; }
    iterator& operator--() { p = p->prev; return *this; }
    
    iterator operator++(int) { p = p->succ; iterator it {p->prev}; return it; }
    iterator operator--(int) { p = p->prev; iterator it {p->succ}; return it; }

    T& operator*() { return p->val; }
    
    bool operator==(const iterator& b) const { return p == b.p; }
    bool operator!=(const iterator& b) const { return p != b.p; }
private:
    Link* p;
};