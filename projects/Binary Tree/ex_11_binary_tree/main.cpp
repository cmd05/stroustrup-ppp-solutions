#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Binary_Tree.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 1024, 720, "Canvas" };

	B_Tri_Tree btree{ {620, 30}, 6, 1200, 370};
	btree.print();
	win.attach(btree);

	Point pt = btree.node_pos("lrlrl");
	Mark m{ pt, '*' };
	m.set_color(Color::red);
	
	win.attach(m);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}