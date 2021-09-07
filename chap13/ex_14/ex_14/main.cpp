#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

struct Right_triangle : Graph_lib::Polygon {
	Right_triangle(Point a, int w, int h) {
		const Point c{ a.x + w, a.y };
		const Point b{ a.x, a.y - h};
		add(a);
		add(b);
		add(c);
	}
};

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Right_triangle rt{ {100, 100}, 25, 75 };
	win.attach(rt);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}