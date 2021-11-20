#include "Simple_window.h"
#include "Graph.h"
#include "Win.h"

int main() {
	using namespace  Graph_lib;
	
	Reader rdr{ "rates.txt" };

	Win win{ Point{100, 100}, 600, 400, rdr(), "Currency Converter" };
	return gui_main();
}