#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	const std::string img = IMG_DIR + "rita.jpg";
	Image ii{ Point{0, 0}, img };
	Text tt{ Point {120, 400}, "rita" };
	tt.set_color(Color::white);
	win.attach(ii);
	win.attach(tt);

	win.set_label("rita");
	win.wait_for_button(); // display to screen
}