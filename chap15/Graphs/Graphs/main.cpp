#include "Simple_window.h"
#include "Graph.h"
#include <math.h>

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x*x; }

int main() {
	using namespace  Graph_lib;
	
	constexpr int x_max = 600, y_max = 400;
	constexpr int x_orig = x_max / 2, y_orig = y_max / 2;
	constexpr Point origin{ x_orig, y_orig };

	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;

	constexpr int x_scale = 30;
	constexpr int y_scale = 30;

	Simple_window win{ Point{100, 100} , x_max, y_max, "Graphing Functions" };

	Function s{ one, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s2{ slope, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s3{ square, r_min, r_max, origin, n_points, x_scale, y_scale };

	win.attach(s);
	win.attach(s2);
	win.attach(s3);

	win.wait_for_button(); // display to screen
}