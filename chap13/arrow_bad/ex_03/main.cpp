#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Arrow arr { Point{0, 0}, {3, 4}, 45 };
	win.attach(arr);
	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}