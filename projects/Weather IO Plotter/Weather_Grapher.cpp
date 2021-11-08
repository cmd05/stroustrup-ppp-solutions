#include "Graph.h"
#include <string>
#include <vector>
#include "Weather_Parser.h"
#include "Weather_Grapher.h"


/* Initialize Graphs and calculate data */
City_Graph::City_Graph(Scale xs, Scale ys, Weather_Data::City city, Graph_lib::Color col) :
	city{ city }, xs{ xs }, ys{ ys } {
	max_graph.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dash, 2));
	min_graph.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
	avg_graph.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 2));

	max_graph.set_color(col);
	min_graph.set_color(col);
	avg_graph.set_color(col);


	max_avgs = get_city_avg("max");
	min_avgs = get_city_avg("min");
	avg_avgs = get_city_avg("avg");

	build_graph("max");
	build_graph("min");
	build_graph("avg");
}

/* Calculate Average Temperature of given type for all months */
std::vector<double> City_Graph::get_city_avg(std::string type) const {
	std::vector<double> monthly_avgs;

	for (Weather_Data::Month month : city.months) {
		double avg = 0;
		int i = 0;
		for (Weather_Data::Day day : month.days) {
			double temp;
			if (type == "min") temp = day.min_temp;
			else if (type == "max") temp = day.max_temp;
			else temp = day.avg_temp;

			avg += temp;
			i++;
		}
		avg /= i;

		monthly_avgs.push_back(avg);
	}

	return monthly_avgs;
}

/* Add data points to graph */
void City_Graph::build_graph(std::string type) {
	std::vector<double>& temp_avgs = (type == "max" ? max_avgs : (type == "min" ? min_avgs : avg_avgs));
	Graph_lib::Open_polyline& graph = (type == "max" ? max_graph : (type == "min" ? min_graph : avg_graph));

	for (int i = 0; i < temp_avgs.size(); i++) {
		double temp = temp_avgs[i];
		graph.add(Graph_lib::Point{ xs(i), ys(temp) });
	}
}