#include "Simple_window.h"
#include "Graph.h"
#include "Bar_Graph.h"

int main() {
	using namespace  Graph_lib;
	
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{Point{100, 100}, 600, 400, "Canvas"};
		
	//

	win.wait_for_button(); // display to screen
}