#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Marked_polyline m_poly{ "", {{ 30, 10}, {20, 70}, {400, 300} }};
	win.attach(m_poly);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}