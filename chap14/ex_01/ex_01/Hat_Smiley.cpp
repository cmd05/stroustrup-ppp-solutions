#include "Hat_Smiley.h"

namespace Graph_lib {
	Hat_Smiley::Hat_Smiley(Point center, int radius): Smiley(center, radius) {}

	void Hat_Smiley::draw_lines() const {
		Smiley::draw_lines(); // draw smiley first

		// right end
		int x_displace = Circle::radius() * cos(hat_angle);
		int y_displace = Circle::radius() * sin(hat_angle);

		Point right_end{ Circle::center().x + x_displace, Circle::center().y - y_displace};
		Point left_end{ Circle::center().x - x_displace, Circle::center().y - y_displace };
		Point top{ Circle::center().x, Circle::center().y - 2 * Circle::radius() };
		Open_polyline hat{ right_end, top, left_end };
		hat.draw();
	}
};