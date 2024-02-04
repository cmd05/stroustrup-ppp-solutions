#pragma once

#include "Graph.h"
#include <string>
#include <vector>
#include "Weather_Parser.h"

// ---------------- GRAPH-DATA SCALING ---------------- //
/* Scale Data Input to Graphical Points */
class Scale {
	int cbase;
	int vbase;
	double scale;
public:
	Scale(int b, int vb, double s) : cbase{ b }, vbase{ vb }, scale{ s } {}
	int operator()(int v) const { return cbase + (v - vbase) * scale; }
};

// ---------------- PLOT GRAPHS FOR CITY ---------------- //
struct City_Graph {
	City_Graph(Scale xs, Scale ys, Weather_Data::City city, Graph_lib::Color col);
	
	std::vector<double> get_city_avg(std::string type) const;
	void build_graph(std::string type);

	Weather_Data::City city;
	std::vector<double> min_avgs;
	std::vector<double> max_avgs;
	std::vector<double> avg_avgs;

	Scale xs;
	Scale ys;
	Graph_lib::Open_polyline max_graph;
	Graph_lib::Open_polyline min_graph;
	Graph_lib::Open_polyline avg_graph;
};