#include "Graph.h"
#include "Gui.h"

namespace Graph_lib {
	struct Currency {
		std::string curr;
		double rate;
	};

	struct Reader {
		Reader(std::string file);
		std::vector<Currency> rates;
		std::vector<Currency> operator()() const { return rates; }
	};

	struct Win : Window {
		Win(Point xy, int w, int h, std::vector<Currency> rates, const std::string& title);
	private:
		std::string in_curr = "usd";
		std::string out_curr = "usd";

		std::vector<Currency> rates;

		Button convert_btn;
		In_box input;
		Out_box output;

		Out_box in_selection;
		Out_box out_selection;

		Menu curr_in;
		Menu curr_out;

		void set_in(std::string in);
		void set_out(std::string out);
		
		double get_rate(std::string curr) const;

		void convert();
	};
}