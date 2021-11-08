#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

const long double PI = atan(1) * 4;
const double euler_c = std::exp(1.0);

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x);  }
double normal_distribution(double x) {
	double a = 0.2;
	double b = 0;

	double exp = -0.01 * pow((x - b) / a, 2);
	double res = pow(euler_c, exp) / (a * sqrt(2 * PI));
	return res;
}

int fact(int n) {
	double res = 1;
	for (int i = 2; i <= n; i++) res *= i;
	return res;
}

double term(double x, int n) { return pow(x, n) / fact(n); }

double expe(double x, int prec) {
	double sum = 0;
	for (int i = 0; i < prec; i++) sum += term(x, i);
	return sum;
}

int main() {
	using namespace  Graph_lib;

	constexpr int x_max = 600, y_max = 400;
	constexpr int x_orig = x_max / 2, y_orig = y_max / 2;
	constexpr Point origin{ x_orig, y_orig };

	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;

	constexpr int x_scale = 30;
	constexpr int y_scale = 30;

	Simple_window win{ Point{100, 100} , x_max, y_max, "Graphing Functions" };

	constexpr int x_length = x_max - 40;
	constexpr int y_length = y_max - 40;

	Axis x{ Axis::x, Point{20, y_orig}, x_length, x_length / x_scale, "one notch == 1" };
	Axis y{ Axis::y, Point{x_orig, y_length + 20}, y_length, y_length / y_scale, "one notch == 1" };

	x.set_color(Color::dark_green);
	y.set_color(Color::dark_green);

	win.attach(x);
	win.attach(y);

	Function s{ one, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s2{ slope, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s3{ square, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s4{ cos, r_min, r_max, origin, n_points, x_scale, y_scale };
	Function s5{ sloping_cos, r_min, r_max, origin, n_points, x_scale, y_scale };
	
	Function s6{ normal_distribution, r_min, r_max, origin, n_points, x_scale, y_scale };

	win.attach(s6);

	Function f1{ log, 0.000001, r_max, origin, n_points, x_scale, y_scale };
	Function f2{ sin, r_min, r_max, origin, n_points, x_scale, y_scale };
	f2.set_color(Color::dark_blue);
	Function f3{ exp, r_min, r_max, origin, n_points, x_scale, y_scale };
	f3.set_color(Color::blue);

	//win.attach(f1);
	//win.attach(f2);
	win.attach(f3);

	s4.set_color(Color::dark_red);
	s5.set_color(Color::dark_red);

	Text ts{ Point{100, y_orig - 40}, "one" };
	Text ts2{ Point{100, y_orig + y_orig / 2 - 20}, "x/2" };
	Text ts3{ Point{x_orig - 100, 20}, "x*x" };

	//win.attach(ts);
	//win.attach(ts2);
	//win.attach(ts3);

	//win.attach(s);
	//win.attach(s2);
	//win.attach(s3);
	//win.attach(s4);
	//win.attach(s5);

	for (int n = 0; n < 50; n++) {
		std::ostringstream ss;
		ss << "exp approximation; n == " << n;
		win.set_label(ss.str());

		Function e{ [n](double x) {return expe(x, n); }, r_min, r_max, origin, 200, x_scale, y_scale };
		e.set_color(Color::red);

		win.attach(e);
		win.wait_for_button(); // display to screen
		win.detach(e);
	}

	//win.wait_for_button(); // display to screen
}