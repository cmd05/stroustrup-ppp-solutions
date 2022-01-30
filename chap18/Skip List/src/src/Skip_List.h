#pragma once
#include <vector>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <float.h>

#include "Linked_List.h"

struct List_Bounds {
	List_Bounds();
	List_Bounds(Node* head, Node* sentinel) : head(head), sentinel(sentinel) {}
	Node* head = nullptr;
	Node* sentinel = nullptr;
};

class Skip_List {
public:
	Skip_List(std::vector<double> v = {});

	Node* insert(double value);
	Node* search(double value) const;
	Node* remove(double value);

	int levels_count() const { return levels.size(); }
	Node* top_head() const { return levels[levels_count() - 1].head; }
	Node* top_sentinel() const { return levels[levels_count() - 1].sentinel; }

	void add_level();
	bool toss() const;

	std::string get_representation(int size = 15) const; // set default number length
	std::string print_levels() const;
private:
	// store pointers to head and sentinel
	std::vector<List_Bounds> levels;

	const double INF = DBL_MAX;
	const double NEG_INF = -INF;
};