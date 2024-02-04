#include "Graph.h"
#include "Gui.h"
#include <cmath>

inline double square(double x) { return x * x; }

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
		
		Function f1{ sin, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) };
		Function f2{ log, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) };
		Function f3{ square, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) };

		void set_fn(std::string f);
		void exec();
	};
}