#include "Simple_window.h"
#include "Graph.h"
#include "Lines_window.h"

int main() {
	using namespace  Graph_lib;
	
	try {
		Lines_window win{ Point{100, 100}, 600, 400, "lines" };
		return gui_main();
	}
	catch (exception& e) {
		std::cerr << "Error: " << e.what();
	}
	catch (...) {
		std::cerr << "BAD ERROR :/";
	}
}