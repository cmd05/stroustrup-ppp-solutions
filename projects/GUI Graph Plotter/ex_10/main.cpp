#include "Simple_window.h"
#include "Graph.h"
#include "Grapher.h"

int main() {
	using namespace  Graph_lib;
	

	constexpr int x_max = 600, y_max = 400;
	constexpr int x_orig = x_max / 2, y_orig = y_max / 2;
	constexpr Point origin{ x_orig, y_orig };

	constexpr int r_min = -10;
	constexpr int r_max = 11;
	int n_points = 400;

	constexpr int x_scale = 30;
	constexpr int y_scale = 30;

	constexpr int x_length = x_max - 40;
	constexpr int y_length = y_max - 40;

	Axis x{ Axis::x, Point{20, y_orig}, x_length, x_length / x_scale, "" };
	Axis y{ Axis::y, Point{x_orig, y_length + 20}, y_length, y_length / y_scale, "" };

	// r_min, r_max, origin, n_points, x_scale, y_scale
	std::vector<int> properties = { r_min, r_max, n_points, x_scale, y_scale };
	Grapher win{ {100, 100}, 600, 400, "Grapher", origin, properties };
	
	win.attach(x);
	win.attach(y);

	return gui_main();
}