#include "Simple_window.h"
#include "Graph.h"
#include <math.h>
#include <iomanip>

constexpr long double PI = 3.14159265358979323846;

int main() {
	using namespace  Graph_lib;

	Simple_window win{ Point{0, 0}, 1360, 700, "Leibiniz Series" };

	constexpr int xmax = 1360;
	constexpr int ymax = 650;

	Point origin{ 30, ymax / 2 + 50};
	Point end{ 1300, ymax / 2 + 50};
	
	Line axis{ origin, end};
	axis.set_style(Line_style(Line_style::solid, 2));

	int axis_len = end.x - origin.x;

	Text axis_label{ Point{end.x - 100, end.y + 30}, "PI = " + std::to_string(PI) };

	win.attach(axis);
	win.attach(axis_label);

	long double max_deviation = 0;
	long double unit_deviation_distance = 0;

	long double sum = 0;
	long long int denom = 1;
	int terms = 500;

	double xscale = axis_len / terms;

	Open_polyline graph;
	graph.set_color(Color::blue);

	for (int i = 0; i < terms; i++) {
		sum += pow(-1, i) * (1 / double(denom));
		long double estimate_pi = 4 * sum;
		long double deviation = PI - estimate_pi;

		if (i == 0) {
			max_deviation = abs(PI - estimate_pi);
			unit_deviation_distance = (double(ymax) / 2) * (1 / max_deviation); // Displacement from line for disp = PI - estimate = 1
		}

		Point pt{ int(origin.x + xscale * i), int(origin.y + unit_deviation_distance * deviation) };
		Text value{ Point{pt.x, pt.y + (deviation > 0 ? 1 : -1) * 15}, std::to_string(estimate_pi) };

		graph.add(pt);

		//win.attach(graph);
		//win.attach(value);
		//win.wait_for_button();

		denom += 2;
	}

	win.attach(graph);

	gui_main();
}