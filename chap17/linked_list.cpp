#include <iostream>
#include <string>

class Link {
public:
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr):
    value{v}, prev{p}, succ{s} {}

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    Link* advance(int n) const;
   
    Link* next() const { return succ; };
    Link* previous() const { return prev; };

    void set(std::string v) { value = v; }
    std::string get() const { return value; } 
private:
    std::string value;
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) {
    // add elem (n) before ref (p)
    if(n == nullptr) return this; 
    if(this == nullptr) return n; // reference p does not exist - return
    // yep we can access n->succ because c++ allows per class access
    // objects of the same class have access to each other's private data
    n->succ = this;
    if(prev) prev->succ = n; // will not work if p is first item in list
    n->prev = prev; // even if nullptr
    prev = n;
    return n;     
}

Link* Link::add(Link* n) {
    // add elem after ref
    if(n == nullptr) return this;
    if(this == nullptr) return n;

    if(succ) n->succ = succ;
    succ = n;
    n->prev = this;

    return n;
} 

Link* Link::erase() {
    if(this == nullptr) return nullptr;
    if(succ) succ->prev = prev;
    if(prev) prev->succ = succ;

    return succ;
}

Link* Link::find(const std::string& s) {
    // assuming p as start
    Link* p = this;
    while(p) {
        if(p->value == s) return p;
        p = p->succ;
    }

    // return nullptr for no match
    return nullptr;
}

Link* Link::advance(int n) const {
    Link* p = const_cast<Link*>(this);
    // find link at n positions from p
    if(p == nullptr) return nullptr;
    
    if(n > 0) {
        while(n--) {
            if(p->succ == nullptr) return nullptr; // nullptr will not have a succ value
            p = p->succ;
        }
        return p;
    } else if(n < 0) {
        while(n++) {
            if(p->prev == nullptr) return nullptr; // nullptr will not have a prev value
            p = p->prev;
        }
        return p;
    }
    // n == 0
    return p;
}

void print_all(Link* p) {
    std::cout << "{ ";
    while(p) {
        std::cout << p->get();
        if(p = p->next()) std::cout << ", ";
    }
    std::cout << " }";
}

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    // wait zeus is a greek god not norse
    // wait greek god of war is ares not mars

    Link* p = greek_gods->find("Mars");
    if(p) p->set("Ares");

    Link* p2 = norse_gods->find("Zeus");
    if(p2) {
        // let's say norse_gods points to zeus at this point
        // we are erasing zeus 
        // so norse_gods will still point to zeus which would be meaningless
        // as zeus is no longer in the list
        
        // hence we must set it to the next value
        if(p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << "\n";
    print_all(greek_gods);
}