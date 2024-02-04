#include <stdexcept>
#include <string>
#include <fstream>
#include "Simple_window.h"
#include "Graph.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	// start from tl(topleft) corner
	// size 600x400
	// title Canvas
	Simple_window win{ tl, 600, 400, "Canvas" };

	Axis xa{ Axis::x, Point{20, 300}, 280, 10, "x-axis" };
	xa.set_color(Color::black);
	// axis of type shape
	// Axis::x -> horizontal
	// starts @ 20, 300
	// 280 pixels long
	// 10 notches
	// Label as x 
	win.attach(xa);

	Axis ya{ Axis::y, Point{20, 300}, 280, 10, "y-axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	Function sine{ sin, 0, 100, Point{20, 150}, 1000, 50, 50 };
	sine.set_color(Color::blue);
	win.attach(sine);
	// fn type - sine
	// range of sine input = 0-100
	// start at 20, 150
	// use 100 paoints
	// x*50 y*50 scale

	Graph_lib::Polygon poly;
	poly.add(Point{ 300, 200 });
	poly.add(Point{ 350, 100 });
	poly.add(Point{ 400, 200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 4));
	win.attach(poly);

	Graph_lib::Rectangle r{ Point{200, 200}, 100, 50 }; // define top-left corner, width and height [downwards]
	r.set_color(Color::black);
	r.set_fill_color(Color::yellow);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100, 50 });
	poly_rect.add(Point{ 200, 50 });
	poly_rect.add(Point{ 200, 100 });
	poly_rect.add(Point{ 100, 100 });
	poly_rect.add(Point{ 50, 75 });
	poly_rect.set_color(Color::black);
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);

	// Text Object
	Text t{ Point{150, 150}, "Hello [graphics UwU] world!" };
	t.set_color(Color::black);
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	// Image object
	const std::string rover_img = IMG_DIR + "perseverance.jpg";
	Image ii{ Point{100, 50}, rover_img };
	ii.move(100, 200);
	win.attach(ii);

	// More shapes
	Circle c{ Point{100, 200}, 50 }; // center, radius
	c.set_color(Color::black);

	Graph_lib::Ellipse e{ Point{100, 200}, 75, 25 }; // center, radiusx, radiusy
	e.set_color(Color::dark_cyan);
	Mark m{ Point{100, 200}, 'x' };

	std::ostringstream oss;
	oss << "Screen Size: " << x_max() << "x" << y_max()
		<< "\t Window Size: " << win.x_max() << "x" << win.y_max();
	Text sizes{ Point{100, 20}, oss.str() };
	sizes.set_color(Color::black);

	std::string rita_path = IMG_DIR + "rita.jpg";
	Image masked{ Point{225, 225}, rita_path };
	masked.set_mask(Point{ 50, 0 }, 150, 120);

	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.attach(sizes);
	win.attach(masked);

	win.attach(t);
	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}