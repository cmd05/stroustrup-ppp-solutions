#include "Graph.h"

namespace Graph_lib {
	struct Bar_Graph : Polygon {
	public:
		Bar_Graph(Point origin, int xlen, int ylen, std::vector<double> values);
		
	private:
		Point origin;
		int xlen;
		int ylen;
		std::vector<double> values;
	};
}