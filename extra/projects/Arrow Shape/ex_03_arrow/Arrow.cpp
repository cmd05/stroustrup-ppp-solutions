#include "Arrow.h"
#include "Graph.h"

const double PI = atan(1) * 4;

double deg_to_rad(double deg) {return deg*(PI/180.0);}

namespace Graph_lib {
	Arrow::Arrow(Point start, Point end, double angle) : start{ start }, end{ end }, Line(start, end), angle{ angle } {
		if (angle >= 90 || angle <= 0) throw std::runtime_error("Invalid Angle");
	}

	void Arrow::draw_lines() const {
		Line::draw_lines();
		const double distance = sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2));
		const double slope_angle = atan2((end.y - start.y) , (end.x - start.x));
		const double incline = deg_to_rad(angle);

		const double s1_x = end.x - (distance / fraction) * cos(slope_angle - incline);
		const double s1_y = end.y - (distance / fraction) * sin(slope_angle - incline);
		
		const double s2_x = end.x + (distance / fraction) * cos(PI - slope_angle - incline);
		const double s2_y = end.y - (distance / fraction) * sin(PI - slope_angle - incline);

		std::cout << s1_x << " " << s1_y << "\n";
		std::cout << s2_x << " " << s2_y << "\n";

		fl_line(end.x, end.y, s1_x, s1_y);
		fl_line(end.x, end.y, s2_x, s2_y);
	}
};