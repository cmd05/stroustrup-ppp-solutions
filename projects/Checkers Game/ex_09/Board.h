#pragma once
#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib {
	class Board {
	public:
		Board(Simple_window& win, Point nw, int board_side, Color piece_color);
		void init() const;
	private:
		Simple_window& win;
		Point board_nw;
		Point board_sw;
		int board_side;
		Color piece_color;
		int sq_side;
	};
};