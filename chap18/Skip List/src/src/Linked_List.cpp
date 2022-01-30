#include "Linked_List.h"

// ------------------------------ DEFINE ADD OPERATIONS --------------------------------------

Node* Node::add_h(double v) {
	// set new node
	Node* n = new Node{ v };
	n->prev = this;
	n->succ = this->succ;

	// modify previous successor
	if (this->succ) this->succ->prev = n;
	// modify this
	this->succ = n;

	return n;
}

Node* Node::add_h(Node* n) {
	// set new node
	n->prev = this;
	n->succ = this->succ;

	// modify previous successor
	if (this->succ) this->succ->prev = n;
	// modify this
	this->succ = n;

	return n;
}

Node* Node::add_v(double v) {
	// set new node
	Node* n = new Node{ v };
	n->below = this;
	n->above = this->above;

	// modify previous successor
	if (this->above) this->above->below = n;
	// modify this
	this->above = n;

	return n;
}

Node* Node::add_v(Node* n) {
	// set new node
	n->below = this;
	n->above = this->above;

	// modify previous successor
	if (this->above) this->above->below = n;
	// modify this
	this->above = n;

	return n;
}

// ------------------------------ DEFINE ERASE OPERATIONS --------------------------------------

Node* Node::erase_h() {
	if (this->prev) this->prev->succ = this->succ;
	if (this->succ) this->succ->prev = this->prev;
	return this->prev;
}

Node* Node::erase_v() {
	if (this->below) this->below->above = this->above;
	if (this->above) this->above->below = this->below;
	return this->below;
}