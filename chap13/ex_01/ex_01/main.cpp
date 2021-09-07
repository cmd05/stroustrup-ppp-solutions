#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Arc arc{ {100, 100}, 50, 200, -10 };
	win.attach(arc);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}