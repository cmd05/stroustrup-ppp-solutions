#include "Simple_window.h"
#include "Graph.h"

class Scale {
	int cbase;
	int vbase;
	double scale;
public:
	Scale(int b, int vb, double s) : cbase{ b }, vbase{ vb }, scale{ s } {}
	int operator()(int v) const { return cbase + (v - vbase) * scale;  }
};

struct Distribution {
	int year, young, middle, old;
};

std::istream& operator>>(std::istream& is, Distribution& d) {
	char ch1, ch2, ch3;
	ch1 = ch2 = ch3 = 0;

	Distribution dd;
	if (is >> ch1 >> dd.year
		>> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) {
		if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
	}
	else return is;

	d = dd;
	return is; // allow chaining
}

int main() {
	using namespace  Graph_lib;

	Simple_window win{ Point{100, 100}, 600, 400, "Aging Japan" };

	constexpr int xmax = 600;
	constexpr int ymax = 400;

	constexpr int xoffset = 100; // y-axis offset from window left hand side
	constexpr int yoffset = 60;  // distance from bottom of window to x-axis

	constexpr int xspace = 40; // space beyond axis
	constexpr int yspace = 40;

	constexpr int xlength = xmax - xoffset - xspace;
	constexpr int ylength = ymax - yoffset - yspace;

	constexpr int base_year = 1960;
	constexpr int end_year = 2040;

	constexpr double xscale = double(xlength) / (end_year - base_year);
	constexpr double yscale = double(ylength) / 100;

	constexpr Point origin{ xoffset, ymax - yoffset };

	Scale xs{ origin.x, base_year, xscale };
	Scale ys{ origin.y, 0, -yscale };

	int notches_x = (end_year - base_year) / 10;

	Axis x{ Axis::x, origin, xlength, notches_x,
		"year     1960     1970     1980     1990      "
		"2000      2010      2020      2030      2040" };

	Axis y{ Axis::y, origin, ylength, 10, "% of population" };

	Line current_year{ Point{xs(2021), ys(0)}, Point{xs(2021), ys(100)} };
	current_year.set_style(Line_style::dash);

	std::string file = "data.txt";
	ifstream ifs{ file };
	if (!ifs) throw std::runtime_error("Cannot open file!");

	Open_polyline children;
	Open_polyline adults;
	Open_polyline aged;

	for(Distribution d; ifs >> d;) {
		if (d.year < base_year || d.year > end_year) throw std::runtime_error("Year out of range");
		if (d.young + d.middle + d.old != 100) throw std::runtime_error("Percentages don't add to 100");
		const int x = xs(d.year);
		children.add(Point{ x, ys(d.young) });
		adults.add(Point{ x, ys(d.middle) });
		aged.add(Point{ x, ys(d.old) });
	}

	Text children_label{ Point{20, children.point(0).y}, "age 0-14"};
	children.set_color(Color::red);
	children_label.set_color(Color::red);

	Text adults_label{ Point{20, adults.point(0).y}, "age 15-64" };
	adults.set_color(Color::blue);
	adults_label.set_color(Color::blue);

	Text aged_label{ Point{20, aged.point(0).y}, "age 65+" };
	aged.set_color(Color::green);
	aged_label.set_color(Color::green);

	win.attach(children);
	win.attach(adults);
	win.attach(aged);

	win.attach(children_label);
	win.attach(adults_label);
	win.attach(aged_label);

	win.attach(x);
	win.attach(y);
	win.attach(current_year);

	gui_main();
	//win.wait_for_button(); // display to screen
}