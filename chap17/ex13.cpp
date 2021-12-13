#include <iostream>
#include <string>
#include <cctype>

struct God {
	God(std::string n, std::string m, std::string v, std::string w):
		name{n}, mythology{m}, vehicle{v}, weapon{w} {
		if(n == "") throw std::runtime_error("Name cannot be empty"); 
		for(char c : n) if(!isalpha(c)) throw std::runtime_error("Invalid name");
	}
	
	std::string name;
	std::string vehicle;
	std::string mythology;
	std::string weapon;
};

class Link {
public:
    Link(const God& g, Link* p = nullptr, Link* s = nullptr):
    prev{p}, succ{s}, god{g} {}

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    Link* advance(int n) const;
	Link* add_ordered(Link* n);
   
    Link* next() const { return succ; };
    Link* previous() const { return prev; };

    void set(std::string v) { god.name = v; }
    std::string get() const { return god.name; } 
	God get_god() const { return god; }
private:
    God god;
    Link* prev;
    Link* succ;
};

Link* Link::add_ordered(Link* n) {
	// assumes list is already in lexographic order
	if(n == nullptr) return this;
	if(this == nullptr) return n;
	
	Link* p = this;
	
	while(true) {
		if(n->god.name < p->god.name) { // compare lexigraphically
			p->insert(n);
			break;
		}
		
		if(p->succ == nullptr) { // if n > all elements add at the end
			p->add(n);
			break;
		}
		
		p = p->succ;
	}
	
	// goto start of list
	while(true) {
		if(!p->prev) break;
		p = p->prev;
	}
	
	return p;
}

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
        if(p->god.name == s) return p;
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
    std::cout << "{ \n";
	
    while(p) {
        std::cout << p->get() << "\n";
		std::cout << "\t" << p->get_god().mythology << "\n";
		std::cout << "\t" << p->get_god().vehicle << "\n";
		std::cout << "\t" << p->get_god().weapon << "\n";
		p = p->next();
    }
	
    std::cout << "}";
}

int main() {
	Link* list = new Link{God{"Zeus", "Greek", "", "lightning"}};
	list = list->insert(new Link{God{"Artemis", "Greek", "Deer", "Arrows"}});
	list = list->insert(new Link{God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}});
	
	Link* ordered = new Link{God{"dummy", "", "", ""}};
	
	while(list) {
	    God god = list->get_god();
	    ordered = ordered->add_ordered(new Link{ God{
            god.name, 
            god.mythology, 
            god.vehicle, 
            god.weapon
        }});
        
		list = list->next();
	}
	
	Link* dummy = ordered->find("dummy");
	dummy->erase();
	
	print_all(ordered);
}