#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Box.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Box r { Point{100, 100}, 100, 50 };
	win.attach(r);
	Circle c1{ {100, 125} , 25 };
	//win.attach(c1);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}