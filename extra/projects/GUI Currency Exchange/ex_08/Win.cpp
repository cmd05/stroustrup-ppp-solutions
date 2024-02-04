#include "Graph.h"
#include "Gui.h"
#include "Win.h"

namespace Graph_lib {
	Reader::Reader(std::string file) {
		std::string curr;
		double rate;
		std::ifstream ist{ file };

		while(ist >> curr >> rate) {
			Currency item;
			item.curr = curr;
			item.rate = rate;
			rates.push_back(item);
		}
	}

	Win::Win(Point xy, int w, int h, std::vector<Currency> rates, const std::string& title):
		Window{ xy,w,h,title},
		rates {rates},
		convert_btn{ Point{x_max() - 150,0}, 70, 20, "Convert", [](Address, Address pw) {reference_to<Win>(pw).convert(); } },
		input{ Point{150, 0}, 80, 20, "Enter amount:"},
		output{ Point{ 340,0}, 100, 20, "Output:" },
		in_selection{ Point{ 100, 50}, 70, 20, "" },
		out_selection{ Point{ x_max() - 200, 50}, 70, 20, "" },
		curr_in{ Point {100, 80}, 70, 20, Menu::vertical, "Input" },
		curr_out{ Point{x_max() - 200, 80}, 70, 20, Menu::vertical, "Output" } 
	{

		attach(convert_btn);
		attach(input);
		attach(output);

		attach(in_selection);
		attach(out_selection);

		in_selection.put("usd");
		out_selection.put("usd");

		curr_in.attach(new Button{ Point {0,0}, 0, 0, "usd", [](Address, Address pw) {reference_to<Win>(pw).set_in("usd"); } });
		curr_in.attach(new Button{ Point {0,0}, 0, 0, "inr", [](Address, Address pw) {reference_to<Win>(pw).set_in("inr"); } });
		curr_in.attach(new Button{ Point {0,0}, 0, 0, "yen", [](Address, Address pw) {reference_to<Win>(pw).set_in("yen"); } });

		curr_out.attach(new Button{ Point {0,0}, 0, 0, "usd", [](Address, Address pw) {reference_to<Win>(pw).set_out("usd"); } });
		curr_out.attach(new Button{ Point {0,0}, 0, 0, "inr", [](Address, Address pw) {reference_to<Win>(pw).set_out("inr"); } });
		curr_out.attach(new Button{ Point {0,0}, 0, 0, "yen", [](Address, Address pw) {reference_to<Win>(pw).set_out("yen"); } });

		attach(curr_in);
		attach(curr_out);
	}

	void Win::set_in(std::string in) {
		in_curr = in;
		ostringstream os;
		os << in;
		in_selection.put(os.str());
		redraw();
	}

	void Win::set_out(std::string out) {
		out_curr = out;
		ostringstream os;
		os << out;
		out_selection.put(os.str());
		redraw();
	}

	double Win::get_rate(std::string curr) const {
		for (Currency item : rates)
			if (item.curr == curr) return item.rate;
	}

	void Win::convert() {
		std::string write;

		if (input.get_string() == "" || input.get_int() < 0) write = "bad input";
		else {
			int inp = input.get_int();
			double outp = (inp * get_rate(in_curr)) / get_rate(out_curr);
			write = std::to_string(outp);
		}

		ostringstream os;
		os << write;
		output.put(os.str());
		
		redraw();
	}
}