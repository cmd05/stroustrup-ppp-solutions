#include <iostream>
#include <vector>

/// Array_ref

template<typename T>
class Array_ref {
    T* p;
    int sz;
public:
    Array_ref(): p{nullptr}, sz{0} {}
    Array_ref(T* pp, int s): p{pp}, sz{s} {}

    T& operator[](int n) { return p[n]; }
    const T& operator[](int n) const { return p[n]; }

    bool assign(Array_ref a) {
        if (a.sz != sz) return false;
        for (int i = 0; i < sz; ++i) { p[i] = a.p[i]; }
        return true;
    }

    template<typename Q>
    operator Array_ref<Q>()
    {
        // check implicit conversion of elements
        static_cast<Q>(*static_cast<T*>(nullptr));  // check element conversion
        return Array_ref<Q>{reinterpret_cast<Q*>(p),sz};  // convert Array_ref
    }

    void reset(Array_ref a) { reset(a.p,a.sz); }
    void reset(T* pp, int s) { p=pp; sz=s; }
    int size() const { return sz; }
};

template<typename T, int s>
Array_ref<T> make_ref(T (&pp)[s]) {
	return Array_ref<T>{pp, s};
}

template<typename T>
Array_ref<T> make_ref(std::vector<T> v) {
    return v.size() ? Array_ref(&v[0], v.size()) : Array_ref<T>{};
}

template<typename T> Array_ref<T> make_ref(T* pp, int s)
{
    return (pp) ? Array_ref<T>{pp,s} : Array_ref<T>{};
}

/// GUI Classes
struct Shape { void draw() {} };
struct Circle : public Shape { int x, y; }; // Circle is bigger in size than Shape
struct Polygon : public Shape {};
struct Rectangle : public Shape {};

// we can use Array_ref<Circle*> like an **immutable** Array_ref<Shape*>
void interface_fn(Array_ref<Shape*> a) {
    a[0] = new Rectangle{}; // works when removing making argument mutable and removing `const` inside T-Q cast
                            // causes segfault 
}

int main() {
    Array_ref<Circle*> c;
    interface_fn(c);
}