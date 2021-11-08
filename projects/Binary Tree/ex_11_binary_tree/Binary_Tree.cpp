#define _USE_MATH_DEFINES
#include "Graph.h"
#include "Binary_Tree.h"
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

namespace Graph_lib {
	B_Tree::B_Tree(Point root, int levels, int max_width, int max_height) : root{ root }, levels{ levels },
		max_width{ max_width }, max_height{ max_height },
		tree_sw {
			root.x - (max_width / 2),
			root.y + max_height,
		} { gen_tree(); }

	// Store the Nodes at same level as {Point, Parent_ID} in a vector
	// Store all levels as different vectors in b_tree
	void B_Tree::gen_tree() {
		if (levels == 0) return;
		int level_height = max_height / levels;
		int indent_gap = 0;
		int max_nodes = pow(2, levels - 1);
		int interval = max_width / max_nodes;

		for(int i = levels - 1; i >= 0; i--) {
			int nodes = pow(2, i);
			std::vector<Node> level_nodes;

			for (int j = 0; j < nodes; j++) {
				int node_x = indent_gap + tree_sw.x + j*interval;
				int node_y = tree_sw.y - level_height*(levels - i);
				
				double parent_id = j / 2.0;
				if (j % 2 != 0) parent_id -= 0.5;

				level_nodes.push_back({Point{node_x, node_y}, int(parent_id)});
			}

			b_tree.push_back(level_nodes);

			indent_gap += (interval / 2);
			interval *= 2;
		}
	}

	void B_Tree::draw_lines() const {
		for (int i = 0; i < b_tree.size(); i++) {
			// per level
			for (int j = 0; j < b_tree[i].size(); j++) {
				std::vector<Node> level = b_tree[i];
				
				Node node = level[j];
				Circle c{node.pt, circle_radius };
				c.draw();

				// no parent lines for level 1
				if (i == b_tree.size() - 1) continue;

				Point parent_point = b_tree[i + 1][node.parent_id].pt;
				Line line{ node.pt, parent_point };
				line.draw();
			}
		}
	}

	Point B_Tree::node_pos(std::string pos) const {
		int index = 0;
		int node_id = 0;

		if (pos.length() > b_tree.size()) throw std::runtime_error("Invalid position");

		for (int i = 1; i < pos.length(); i++)
			index = pos[i] == 'l' ? 2 * index : 2 * index + 1;

		return b_tree[b_tree.size() - pos.length()][index].pt;
	}

	void B_Tree::print() const {
		for (int i = 0; i < b_tree.size(); i++) {
			std::cout << "Level " << levels - i << "\n";
			std::vector<Node> level = b_tree[i];
			for (int j = 0; j < level.size(); j++)
				std::cout << "\t[" << j << "] Parent: " << level[j].parent_id << "\tPoint: " << level[j].pt;
		}
	}

	B_Tri_Tree::B_Tri_Tree(Point root, int levels, int max_width, int max_height) : 
		B_Tree(root, levels, max_width, max_height) {}

	void B_Tri_Tree::draw_lines() const {
		std::vector<std::vector<Node>> b_tree = B_Tree::get_tree();

		for (int i = 0; i < b_tree.size(); i++) {
			// per level
			for (int j = 0; j < b_tree[i].size(); j++) {
				std::vector<Node> level = b_tree[i];
				Node node = level[j];
				
				// Points of triangle
				Point top{ node.pt.x, node.pt.y - rad };
				Point right{ node.pt.x + rad * cos(M_PI / 6), node.pt.y + rad*sin(M_PI / 6) };
				Point left{ node.pt.x - rad * cos(M_PI / 6), node.pt.y + rad * sin(M_PI / 6) };

				Graph_lib::Polygon triangle{ {top, right, left} };
				triangle.draw();

				if (i == b_tree.size() - 1) continue;

				Point parent_point = b_tree[i + 1][node.parent_id].pt;
				Line line{ node.pt, parent_point };
				line.draw();
			}
		}
	}
};