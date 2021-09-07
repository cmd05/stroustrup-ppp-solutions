#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Rectangle rect{ Point{100, 100}, 100, 30 };
	rect.set_color(Color::black);
	Text t{ Point{120, 120}, "Howdy" };
	t.set_color(Color::blue);

	win.attach(rect);
	win.attach(t);
	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}