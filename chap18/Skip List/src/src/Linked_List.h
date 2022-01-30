#pragma once

class Node {
public:
	Node(double value, Node* prev = nullptr, Node* succ = nullptr,
		Node* ceil = nullptr, Node* floor = nullptr) :
		value(value), prev(prev), succ(succ), above(above), below(below) {}

	Node* next() const { return succ; }
	Node* previous() const { return prev; }
	Node* floor() const { return below; }
	Node* ceil() const { return above; }

	Node* erase_h();
	Node* erase_v();

	Node* add_h(double a); // grows right
	Node* add_h(Node* n); // grows right

	Node* add_v(double a); // grows up
	Node* add_v(Node* n); // grows up

	void set(double v) { value = v; }
	double get() const { return value; }
private:
	double value;
	Node* prev;
	Node* succ;
	Node* above;
	Node* below;
};