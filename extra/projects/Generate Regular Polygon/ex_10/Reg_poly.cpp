#include "Graph.h"
#include "Reg_poly.h"
#include <cmath>

const double PI = 3.14159;
double deg_to_rad(double deg) { return deg * (PI / 180.0); }

namespace Graph_lib {
	Reg_poly::Reg_poly(Point center, int n, int distance) {
		for (int i = 0; i < n; i++)
			   add(Point{
				 center.x + int(distance*cos(float(2 * PI * i) / n)),
				 center.y - int(distance*sin(float(2 * PI * i) / n))
			   });
	}
};