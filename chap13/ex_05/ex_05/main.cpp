#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };
	Circle c1{ Point{100, 100}, 50 };
	win.attach(c1);
	std::cout << c1.n().x << " " << c1.n().y;

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}