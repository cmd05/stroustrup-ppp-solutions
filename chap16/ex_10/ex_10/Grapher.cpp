#include "Graph.h"
#include "Gui.h"
#include "Grapher.h"
#include <math.h>
#include <cmath>

double square(double x) { return x*x; }

namespace Graph_lib {
	Grapher::Grapher(Point xy, int w, int h, const std::string& title, Point origin, std::vector<int> props) :
		Window{ xy,w,h,title },
		plot_btn{ Point{x_max() - 150,0}, 70, 20, "Plot", [](Address, Address pw) {reference_to<Grapher>(pw).exec(); } },
		input{ Point{150, 0}, 80, 20, "Input:" },
		output{ Point{ 340,0}, 100, 20, "Output:" },
		selection{ Point{ x_max()-70,30}, 70, 20, "" },
		graphs{ Point{x_max() - 70,50}, 70, 20, Menu::vertical, "graphs"},
		origin{origin},
		props{props}
	{

		attach(plot_btn);
		attach(input);
		attach(output);


		attach(selection);

		graphs.attach(new Button{ Point {0,0}, 0, 0, "sin", [](Address, Address pw) {reference_to<Grapher>(pw).set_fn("sin"); } });
		graphs.attach(new Button{ Point {0,0}, 0, 0, "log", [](Address, Address pw) {reference_to<Grapher>(pw).set_fn("log"); } });
		graphs.attach(new Button{ Point {0,0}, 0, 0, "x^2", [](Address, Address pw) {reference_to<Grapher>(pw).set_fn("sq"); } });

		attach(graphs);
	}

	void Grapher::set_fn(std::string f) {
		fn = f;
		ostringstream os;
		os << f;
		selection.put(os.str());
		redraw();
	}

	void Grapher::exec() {
		double val;
		double in = input.get_int();

		if (fn == "sin") {
			//attach(new Function{ sin, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) });
			val = sin(in);
		}
		else if(fn == "log") {
			//attach(new Function{ log, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) });
			val = log(in);
		}
		else {
			//attach(new Function{ square, double(props[0]), double(props[1]), origin, props[2], double(props[3]), double(props[4]) });
			val = square(in);
		}


		ostringstream os;
		os << val;
		output.put(os.str());

		redraw();
	}
}