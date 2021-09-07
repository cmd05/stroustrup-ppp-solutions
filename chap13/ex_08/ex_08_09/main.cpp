#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Reg_hex.h"
#include "Debug.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Reg_hex hex1{ {100, 100}, 98 };
	win.attach(hex1);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}