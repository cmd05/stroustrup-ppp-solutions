#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Reg_poly.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };
	Reg_poly p{ {300, 200}, 15, 200 };
	win.attach(p);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}