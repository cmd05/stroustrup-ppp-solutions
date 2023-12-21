#include <iostream>
#include <string>

// Implementation of a doubly linked list
// note: we do not have to check for `this` to be a nullptr
// in the implementation
template<typename T>
class Link {
    T value;
    Link* prev;
    Link* succ;
public:
    Link(T val, Link* p = nullptr, Link* s = nullptr): 
        value{val}, prev{p}, succ{s} {}
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    
    Link* find(T val, bool is_begin = false) const;
    Link* advance(int n) const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

    void set_value(Link* n, T val);
    T get_value() const { return value; }
};

template<typename T>
Link<T>* Link<T>::insert(Link* n) {
    if(!n) return this;

    if(prev) prev->succ = n;
    n->prev = prev;
    n->succ = this;
    prev = n;

    return n;
}

template<typename T>
Link<T>* Link<T>::add(Link* n) {
    if(!n) return this;

    if(succ) succ->prev = n;
    n->prev = this;
    n->succ = succ;
    succ = n;

    return n;
}

template<typename T>
Link<T>* Link<T>::erase() {
    // link n can be ptr to a stack var
    // caller should call delete on ptr after erase()
    if(prev) prev->succ = succ;
    if(succ) succ->prev = prev;

    return prev;
}

template<typename T>
Link<T>* Link<T>::find(T val, bool is_begin) const {
    // if n is not beginning of list, search behind
    if(!is_begin)
        for(Link* p = const_cast<Link*>(this); p;) {
            if(p->value == val)
                return p;
            p = p->prev;
        }

    for(Link* p = const_cast<Link*>(this); p;) {
        if(p->value == val)
            return p;
        p = p->succ;
    }

    return nullptr;
}

template<typename T>
Link<T>* Link<T>::advance(int n) const {
    Link* p = const_cast<Link*>(this);
    
    for(int i = 0; i < n && p; i++)
        p = p->succ;
    
    return p;
}

int main() {
    Link<std::string>* l = new Link<std::string>{"first"};
    l = l->insert(new Link<std::string>{"second"});
    l = l->insert(new Link<std::string>{"third"});
    l = l->insert(new Link<std::string>{"fourth"});

    Link<std::string>* m = new Link<std::string>{"a"};
    m = m->insert(new Link<std::string>{"b"});
    m = m->insert(new Link<std::string>{"c"});
    m = m->insert(new Link<std::string>{"d"});

    /* Subtle error, on erasing item and adding it to other list */
    l = const_cast<Link<std::string>*>(l->advance(2)); // l is on "second"
    
    auto l2 = const_cast<Link<std::string>*>(l->find("second"));
    
    if(l2 == l && l->next()) l = l->next(); // prevent this bug. update l to next link
    l2->erase();

    m->insert(l2); // oops l2 and l point to same object. l was never updated

    for(auto p = l; p;) {
        std::cout << p->get_value() << '\n';

        p = p->next();
    }

    /* 
        Output (without check for l2==l):

        second
        d
        c
        b
        a
     */
}