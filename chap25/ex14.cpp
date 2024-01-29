/* Implement  a  simple  vector  that  can  hold  at  most  N  elements  allocated  
from a pool. Test it for N==1000 and integer elements */

#include <iostream>
#include <initializer_list>

template<typename T, unsigned int N>
class Pool {
public:
    using size_type = unsigned int;

    Pool() {
        size = N;
        _pool = (T*) malloc(N * sizeof(T)); // implicit conversion of void* to T*

        for(size_type i = 0; i < size; i++)
            used[i] = false;
    }

    T* get() {
        for(size_type i = 0; i < size; i++)
            if(!used[i]) {
                used[i] = true;
                count_used++;
                return _pool + i;
            }
        
        return nullptr;
    }

    void construct(T* p, T val) {
        new(p) T{val};
    }

    void free_p(T* p) {
        size_type index = p - _pool;

        p->~T(); // destroy
                 // dont deallocate, pool still owns that memory

        count_used--;
        used[index] = false;
    }

    size_type available() const { return size - used; }

    ~Pool() {
        for(size_type i = 0; i < size; i++)
            if(used[i])
                (_pool + i)->~T();
        
        std::free(_pool);
    }
    
    T* _pool;
private:
    size_type size;
    size_type count_used = 0;
    bool used[N];
};

// vector owns the pool, hence it does not set Pool::count_used and Pool::used
template<typename T, unsigned int N, typename P = Pool<T,N>>
class vector {
public:
    struct Error { const char* msg; };

    using size_type = unsigned int;
    using iterator_type = T*;
    
    vector(): sz{0}, space{N} {}

    vector(std::initializer_list<T> lst) {
        memcpy(vpool, lst.begin(), lst.size()*sizeof(T));
        sz = lst.size();
    }

    // can use T&& and T& interface to be more efficient
    
    iterator_type insert(iterator_type p, T val) { // pass by reference, as placement-new is used anyway
        if(sz == space) throw Error{"out of space"};

        size_type index = p - vpool;

        for(size_type i = sz; i > index; i--)
            vpool[i] = vpool[i-1];
        
        *p = val;
        sz++;

        return p;
    }

    iterator_type push_back(T val) {
        return insert(vpool + sz, val);
    }

    void erase(iterator_type p) {
        size_type n = p - vpool;
        if(n < 0 || n >= sz) throw Error{"out of range access on erase()"};

        pool_obj.free_p(p);

        for(size_type i = n; i < (sz - 1); i++)
            vpool[i] = vpool[i+1];

        sz--;
    }

    // unchecked subscript
    T& operator[](int n) { return vpool[n]; }
    const T& operator[](int n) const { return vpool[n]; }

    // checked
    const T& at(int n) const {
        if(n < 0 || n >= sz) throw Error{"out of range access on at()"};
        return vpool[n];
    }

    iterator_type end() const { return vpool + sz; }
    iterator_type begin() const { return vpool; }

    size_type size() const { return sz; }
private:
    P pool_obj {};
    T* vpool {pool_obj._pool};
    size_type sz;
    size_type space = N;
};

template<typename V>
void print(V v) {
    for(auto& x : v)
        std::cout << x;
}

int main() {
    vector<int, 10> v {1,2,3,4};
    int x =7;
    v.push_back(x);
    v.erase(v.begin());
    v.insert(v.begin()+1, 5);
    v.push_back(6);
    print(v);
}