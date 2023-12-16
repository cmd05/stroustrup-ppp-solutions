#pragma once

#define _USE_MATH_DEFINES
#include "Graph.h"
#include <math.h>

namespace Graph_lib {
	class Smiley : public Circle {
	public: 
		Smiley(Point center, int rr);
		void draw_lines() const override;
	private:
		double eye_angle = M_PI / 4;
		double smile_radius = Circle::radius() * 0.75;
		double eye_distance = Circle::radius() / 2;
		double eye_radius = Circle::radius() * 0.25;
	};
};