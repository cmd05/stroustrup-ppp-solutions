#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Linked_List.h"
#include "Skip_List.h"

Skip_List::Skip_List(std::vector<double> v) {
	// set seed for rng
	srand(time(NULL));

	// Create main list manually
	Node* main_list = new Node(NEG_INF);
	Node* head = main_list;
	Node* sentinel = main_list->add_h(INF);

	levels.push_back({head, sentinel});

	// insert elements
	for (double x : v) insert(x);
};

std::string Skip_List::get_representation() const {
	std::string out = "";
	for (int i = levels_count() - 1; i >= 0; i--) {
		Node* head = levels[i].head;
		Node* sentinel = levels[i].sentinel;

		for (Node* p = head; true; p = p->next()) {
			std::string print = "";

			if (p == head) print = "-INF <--> ";
			else if (p == sentinel) print = "INF";
			else print = std::to_string(p->get()) + " <--> ";

			out += print;
			if (p == sentinel) break;
		}

		out += "\n";
	}

	return out;
}

Node* Skip_List::remove(double value) {
	Node* node = search(value);
	
	if (!node || !node->previous() || !node->next())  // dont erase nullptr, head or sentinel
		return nullptr; 
	
	Node* prev = node->previous();

	for (Node* p = node; p;) {
		Node* q = p->ceil();

		p->erase_h();
		p->erase_v();
		delete p;

		p = q;
	}

	return prev;
}

void Skip_List::add_level() {
	Node* new_head = new Node(NEG_INF);
	top_head()->add_v(new_head);
	
	Node* new_sentinel = new Node(INF);
	top_sentinel()->add_v(new_sentinel);

	// create horizontal link
	new_head->add_h(new_sentinel);

	levels.push_back({ new_head, new_sentinel });
}

// return 0 or 1 i.e coin toss
bool Skip_List::toss() const { return (rand() % 2); }

Node* Skip_List::search(double value) const {
	Node* origin = top_head(); // top left
	Node* iterator = origin;

	for (;;) {
		Node* next = iterator->next();
		
		if (value == next->get()) {
			for (iterator = next; iterator->floor(); iterator = iterator->floor());
			return iterator;
		}
		else if (value > next->get()) iterator = next; // always converges before infinity
		else if (value < next->get()) {
			if (!iterator->floor()) return nullptr;
			iterator = iterator->floor();
		}
	}
}

/**
 * Insert element in skip list
 * Return nullptr if value exceeds range
 */

Node* Skip_List::insert(double value) {
	if (value >= INF || value <= NEG_INF) return nullptr;

	/**
	 * Iterate through list till we find suitable insert position
	 * value >= next -> go right
	 * value < next and floor_exists -> go down
	 * 
	 * Optimize insert by storing visited nodes
	 */
	Node* origin = top_head(); // top left
	Node* iterator = origin;
	
	std::vector<Node*> encountered;

	for (;;) {
		Node* next = iterator->next();
		if (value >= next->get()) iterator = next; // always converges before infinity
		else if (value < next->get() && iterator->floor()) {
			encountered.push_back(iterator);
			iterator = iterator->floor();
		}
		else break;
	}

	// insert after iterator
	Node* main_node = iterator->add_h(value);
	iterator = main_node;

	// build levels based on coin tosses
	// main level starts from 1
	int level = 1;

	while (toss() == 1) {
		Node* prev = nullptr;
		
		if (level >= levels_count()) {
			// add level if toss exceeds top of list
			add_level();
			prev = top_head();
		} else {
			prev = encountered[levels_count() - level - 1];
		}

		// stack node on tower
		Node* stack_node = new Node(value);
		prev->add_h(stack_node);
		iterator->add_v(stack_node);

		iterator = stack_node;
		level++;
	}

	return main_node;
}