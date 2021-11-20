#include "Gui.h"
#include "Graph.h"
#include <string>

namespace Graph_lib {
	struct Lines_window : Window {
		Lines_window(Point xy, int w, int h, const std::string& title);
		Open_polyline lines;
	private:
		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;

		void next();
		void quit();
	};
}