#pragma once
#include "Graph.h"

namespace Graph_lib {
	class Square : public Rectangle {
	public:
		Square(Point nw, int side);
		int get_side() const { return side; }
	private:
		int side;
	};
};