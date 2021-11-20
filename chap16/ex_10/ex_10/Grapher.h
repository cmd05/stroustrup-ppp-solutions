#include "Graph.h"
#include "Gui.h"

namespace Graph_lib {
	struct Grapher : Window {
		Grapher(Point xy, int w, int h, const std::string& title, Point origin, std::vector<int> props);
	private:
		In_box input;
		Out_box output;
		Out_box selection;
		Menu graphs;
		Point origin;
		std::vector<int> props;

		Button plot_btn;
		std::string fn = "sin";
		
		void set_fn(std::string f);
		void exec();
	};
}