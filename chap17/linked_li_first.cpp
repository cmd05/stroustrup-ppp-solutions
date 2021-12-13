#include <iostream>
#include <string>
using namespace std;

struct Link {
    std::string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p = nullptr, Link* s = nullptr):
        value{v}, prev{p}, succ{s} {}    
};

Link* insert(Link* p, Link* n) {
    // add elem (n) before ref (p)
    if(n == nullptr) return p; 
    if(p == nullptr) return n; // reference p does not exist - return
    n->succ = p;
    if(p->prev) p->prev->succ = n; // will not work if p is first item in list
    n->prev = p->prev; // even if nullptr
    p->prev = n;
    return n;     
}

Link* add(Link* p, Link* n) {
    // add elem after ref
    if(n == nullptr) return p;
    if(p == nullptr) return n;

    if(p->succ) n->succ = p->succ;
    p->succ = n;
    n->prev = p;

    return n;
} 

Link* erase(Link* p) {
    if(p == nullptr) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    // delete p;
    return p->succ;
}

Link* find(Link* p, const std::string& s) {
    // assuming p as start
    while(p) {
        if(p->value == s) return p;
        p = p->succ;
    }

    // return nullptr for no match
    return nullptr;
}

Link* advance(Link* p, int n) {
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

int main() {
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Zeus"});
    // norse_gods = insert(norse_gods, new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = insert(greek_gods, new Link{"Athena"});
    greek_gods = insert(greek_gods, new Link{"Mars"});
    greek_gods = insert(greek_gods, new Link{"Poseidon"});

    //  wait zeus is a greek god not norse
    // wait greek god of war is ares not mars

    Link* p = find(greek_gods, "Mars");
    if(p) p->value = "Ares";

    Link* pv = find(norse_gods, "Zeus");
    if(pv) {
        // let's say norse_gods points to zeus at this point
        // we are erasing zeus 
        // so norse_gods will still point to zeus which would be meaningless
        // as zeus is no longer in the list
        
        // hence we must set it to the next value
        if(pv == norse_gods) norse_gods = pv->succ;
        erase(pv);
        greek_gods = insert(greek_gods, pv);
    }

    cout << norse_gods->value;
}