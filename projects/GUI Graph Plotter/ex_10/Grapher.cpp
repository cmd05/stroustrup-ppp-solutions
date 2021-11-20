#include "Graph.h"
#include "Gui.h"
#include "Grapher.h"

bool is_num(std::string str) {
	if (str == "-" || str == "") return false;

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (i == 0 && c == '-') continue;
		if (!isdigit(c)) return false;
	}

	return true;
}

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
		graphs.attach(new Button{ Point {0,0}, 0, 0, "x^2", [](Address, Address pw) {reference_to<Grapher>(pw).set_fn("square"); } });

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
			attach(f1);
			detach(f2);
			detach(f3);

			val = sin(in);
		}
		else if(fn == "log") {
			attach(f2);
			detach(f1);
			detach(f3);

			val = log(in);
		}
		else {
			attach(f3);
			detach(f2);
			detach(f1);

			val = square(in);
		}

		if (!is_num(input.get_string())) val = 0;
		
		ostringstream os;
		os << val;
		output.put(os.str());

		redraw();
	}
}