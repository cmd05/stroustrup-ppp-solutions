#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Circle c1{ Point{100, 100}, 50 }; // center, radius
	c1.set_color(Color::blue);
	Circle c2{ Point {200, 100}, 50 };
	c2.set_color(Color::black);
	Circle c3{ Point {300, 100}, 50 };
	c3.set_color(Color::red);

	Circle c4{ Point {150, 170}, 50 };
	c4.set_color(Color::yellow);
	Circle c5{ Point {250, 170}, 50 };
	c5.set_color(Color::green);

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}