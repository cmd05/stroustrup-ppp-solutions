#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Weather_Parser.h"
#include "Weather_Grapher.h"

int main() {
	using namespace  Graph_lib;

	// Initialize Window and Properties
	constexpr int xmax = 1366;
	constexpr int ymax = 720;

	Simple_window win{Point{0, 0}, xmax, ymax, "Weather Graph"};

	Point origin{ 100, ymax / 2 };

	constexpr int xlen = 1000;
	constexpr int ylen = 600;
	constexpr int max_ytemp = 100, min_ytemp = -100;

	constexpr double xscale = xlen / 11;
	constexpr double yscale = ylen / (max_ytemp - min_ytemp);

	Axis x{ Axis::x, origin, xlen, 11, "Month (2020)" };
	Axis y{ Axis::y, Point{origin.x, ymax - 60}, ylen, 20, "Temperature (°C)" };

	win.attach(x);
	win.attach(y);

	// Set scaling factor
	Scale xs{ origin.x, 0, xscale };
	Scale ys{ origin.y, 0, -yscale };

	// Read Weather Data
	Weather_Data::Data weather_data;

	try {
		Weather_Data::Weather_Parser parser{ "data.txt" };
		weather_data = parser();
	} catch (std::runtime_error& err) {
		std::cout << err.what();
	}

	// Attach Graphs
	City_Graph city_1{xs, ys, weather_data.cities[0], Color::dark_blue };
	win.attach(city_1.min_graph);
	win.attach(city_1.max_graph);
	win.attach(city_1.avg_graph);

	City_Graph city_2{ xs, ys, weather_data.cities[1], Color::dark_green };
	win.attach(city_2.min_graph);
	win.attach(city_2.max_graph);
	win.attach(city_2.avg_graph);

	City_Graph city_3{ xs, ys, weather_data.cities[2], Color::dark_red};
	win.attach(city_3.min_graph);
	win.attach(city_3.max_graph);
	win.attach(city_3.avg_graph);

	// Labels
	Point line_start { xmax - 300, 50 };
	int space_btm = 20;
	Point line_end{ xmax - 250, 50};

	Line dashed{ line_start, line_end };
	dashed.set_style(Line_style(Line_style::dash, 2));
	Text ts1{ Point{line_end.x + 10, line_end.y + 5}, "Mean Max" };
	win.attach(dashed);
	win.attach(ts1);

	Line solid{ Point{line_start.x, line_start.y + space_btm}, {line_end.x, line_end.y + space_btm} };
	solid.set_style(Line_style(Line_style::solid, 2));
	Text ts2{ Point{line_end.x + 10, line_end.y + 25}, "Mean Avg" };
	win.attach(solid);
	win.attach(ts2);

	Line dotted{ Point{line_start.x, line_start.y + space_btm*2}, {line_end.x, line_end.y + space_btm*2} };
	dotted.set_style(Line_style(Line_style::dot, 2));
	Text ts3{ Point{line_end.x + 10, line_end.y + 45}, "Mean Min" };
	win.attach(dotted);
	win.attach(ts3);

	Text ts4{ Point{line_start.x, line_end.y + 70}, weather_data.cities[0].city};
	ts4.set_color(Color::dark_blue);
	win.attach(ts4);

	Text ts5{ Point{line_start.x, line_end.y + 95}, weather_data.cities[1].city };
	ts5.set_color(Color::dark_green);
	win.attach(ts5);

	Text ts6{ Point{line_start.x, line_end.y + 115}, weather_data.cities[2].city };
	ts6.set_color(Color::dark_red);
	win.attach(ts6);

	win.wait_for_button(); // display to screen
}