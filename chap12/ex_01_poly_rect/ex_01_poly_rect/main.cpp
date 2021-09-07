#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Rectangle r{ Point{20, 20}, 140, 60 };
	r.set_color(Color::blue);

	Graph_lib::Polygon rect;
	rect.add(Point{ 240, 100 });
	rect.add(Point{ 240, 150 });
	rect.add(Point{ 380, 150 });
	rect.add(Point{ 380, 100 });
	rect.set_color(Color::red);

	win.attach(r);
	win.attach(rect);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}