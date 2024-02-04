#include "Graph.h"
#include "Star.h"
#include <cmath>
#include <iostream>

const double PI = atan(1) * 4;

namespace Graph_lib {
	Star::Star(Point center, int n, int w, int len) {
		// outer circle
		std::vector<Point> out;
		std::vector<Point> in;

		for (int i = 0; i < n; i++)
			out.push_back({
			  center.x + int(len * cos(float(2 * PI * i) / n)),
			  center.y - int(len * sin(float(2 * PI * i) / n))
			});
		
		for (int i = 0; i < n; i++) {
			const double angle = float(2 * PI * i) / n;

			in.push_back({
			  center.x + int(w * cos(angle + PI/float(n))),
			  center.y - int(w * sin(angle + PI / float(n)))
			});
		}

		for (int i = 0; i < n; i++) {
			std::cout << out[i] << in[i];
			add(out[i]);
			add(in[i]);
		}
	}
};