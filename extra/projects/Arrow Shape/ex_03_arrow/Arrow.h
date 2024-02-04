#include "Graph.h"
#include <iostream>
#include <cmath>

namespace Graph_lib {
	struct Arrow : Line { // A line with 2 inclined arms
	public:
		Arrow(Point start, Point end, double angle = 45);
		void draw_lines() const;
	private:
		Point start;
		Point end;	
		double angle;
		double fraction = 2;
	};	
};