#pragma once
#include "Graph.h"

namespace Graph_lib {
	class B_Tree : public Shape {
	public:
		struct Node {
			Point pt{};
			int parent_id = 0;
		};

		B_Tree(Point root, int levels, int max_width, int max_height);
		void gen_tree();
		virtual void draw_lines() const override;
		std::vector<std::vector<Node>> get_tree() const { return b_tree; };
		Point node_pos(std::string pos) const;
		void print() const;
	private:
		int levels;
		Point root;
		Point tree_sw;
		int max_width;
		int max_height;
		int circle_radius = 5;

		std::vector<std::vector<Node>> b_tree;
	};

	class B_Tri_Tree : public B_Tree {
	public:
		B_Tri_Tree(Point root, int levels, int max_width, int max_height);
		virtual void draw_lines() const override;
	private:
		int rad = 10;
	};
}