#include <iostream>
#include <string>

class Link {
public:
	Link(const std::string& v, Link* s = nullptr): value{v}, succ{s} {
		
	};
	Link* insert(Link*& head, Link* n);
	Link* add(Link* n);
	Link* erase(Link*& head);
	Link* advance(int n);
	Link* index(Link* head, int n);
	Link* find(Link* head, std::string value);
	Link* next() const { return succ; }
	
	void set(std::string v) { value = v; }
	std::string get() { return value; }
private:
	std::string value;
	Link* succ;
};

Link* Link::insert(Link*& head, Link* n) {
	if(n == nullptr) return this;
	if(this == nullptr) return n;

	Link* p = head;
	// set succ of elem before this
	while(p) {
		if(p->succ == this) {
			p->succ = n;
			break;
		}
		p = p->succ;
	}
	
	// set succ of n
	n->succ = this;
	if(this == head) head = n;
	
	return n;
}

Link* Link::add(Link* n) {
	if(n == nullptr) return this;
	if(this == nullptr) return n;
	
	n->succ = succ;
	succ = n;
	return n;
}

Link* Link::find(Link* head, std::string value) {
	Link* p = head;
	while(p) {
		if(p->value == value) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::erase(Link*& head) {
	Link* p = head;
	
	if(this == head) {
		head = succ;
		succ = nullptr;
		return head;
	}
	
	while(p) {
		if(p->succ == this) {
			p->succ = succ;
			succ = nullptr;
			return p;
		}
		
		p = p->succ;
	}
	
	return nullptr;
}

Link* Link::advance(int n) {
	if(n < 0) throw std::runtime_error("n cannot be negative");
	
	Link* p = this;
	while(n--) p = p->succ;
	
	return p;
}

Link* Link::index(Link* head, int n) {
	if(0 < n) throw std::runtime_error("Out of range!");
	Link* p = head;
	
	while(n--) p = p->succ;
	
	return p;
}

void print_all(Link* head) {
	Link* p = head;
	while(p) {
		std::cout << p->get() << "\n";
		p = p->next();
	}
}

int main() {
	Link* characters = new Link{"Makato"};
	Link* head = characters;
	
	characters = characters->insert(head, new Link{"Ann"});
	
	characters = characters->insert(head, new Link{"Goro"});
	characters = characters->add(new Link{"Sumire"});
	
	print_all(head);
}
 