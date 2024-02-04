#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

const double PI = atan(1) * 4;

int sgn(double x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}

int main() {
	try {
		using namespace  Graph_lib;
		Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
		Simple_window win{ tl, 600, 400, "Canvas" };

		int a = 300;
		int b = 200;
		double n = 0.65;
		int N = 10; // no of points

		int start_x = 300;
		int start_y = 200;

		double nRadInterval = 2 * PI / N;
		nRadInterval = floor(nRadInterval * 100) / 100;

		Graph_lib::Open_polyline poly;
		Graph_lib::Open_polyline inner_poly;

		std::cout << "Point Rad Interval: " << nRadInterval << "\n";

		for (double rad = 0; rad <= (PI*2); rad+=0.01) {
			double nA = 2 / double(n);
			int x = pow(abs(cos(rad)), nA) * a*sgn(cos(rad));
			int y = pow(abs(sin(rad)), nA) * b*sgn(sin(rad));

			std::cout << "Polygon: " << x << " " << y << "\n";
			poly.add(Point{ start_x + x, start_y - y });

			double mod_val = floor(fmod(rad, nRadInterval) * 100) / 100;
			if (mod_val == 0) {
				inner_poly.add(Point{ start_x + x, start_y - y });
				std::cout << "Inner: " << x << " " << y << "\n";
			}
		}

		poly.set_color(Color::yellow);
		poly.set_style(Line_style(Line_style::solid, 4));
		
		inner_poly.set_color(Color::blue);
		inner_poly.set_style(Line_style(Line_style::solid, 3));

		win.attach(poly);
		win.attach(inner_poly);

		win.set_label("Canvas");
		win.wait_for_button(); // display to screen
	} catch(std::exception& e) {
		std::cerr << e.what();
	}
}