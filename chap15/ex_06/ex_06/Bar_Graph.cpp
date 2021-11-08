#include "Graph.h"
#include "Bar_Graph.h"

namespace Graph_lib {
	Bar_Graph::Bar_Graph(Point origin, int xlen, int ylen, std::vector<double> values):
		origin{ origin }, xlen{ xlen }, ylen{ ylen }, values{values} {
		if (xlen <= 0 || ylen <= 0) throw std::runtime_error("Invalid length");
		if (values.size() == 0) throw std::runtime_error("null vector");
	}
}