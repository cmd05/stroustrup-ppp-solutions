#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Star.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };


	for (int i = 3; i < 100; i += 2) {
		Graph_lib::Star star{ {300, 200}, i, 100, 200 };
		star.set_fill_color(Color::cyan);
		win.attach(star);
		win.wait_for_button(); // display to screen
	}

	win.set_label("Canvas");
}