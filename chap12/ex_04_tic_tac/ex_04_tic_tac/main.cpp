#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		int x = (start_x + (100 * j));
	//		int y = (start_y + (100 * i));

	//		Graph_lib::Rectangle r { Point{x, y}, square_len, square_len};
	//		//Color col = Color::red;
	//		r.set_color(Color::black);
	//		r.set_fill_color(Color::red);
	//		win.attach(r);
	//	}	
	//}

	Simple_window win{ Point{100,200},600,400,"Tic-Tac-Toe" };
	//Line 1
	Graph_lib::Rectangle r1_1{ Point{200,100},50,50 };
	r1_1.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r1_2{ Point{250,100},50,50 };
	r1_2.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r1_3{ Point{300,100},50,50 };
	r1_3.set_fill_color(Graph_lib::Color::white);
	win.attach(r1_1);
	win.attach(r1_2);
	win.attach(r1_3);
	//Line 2
	Graph_lib::Rectangle r2_1{ Point{200,150},50,50 };
	r2_1.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r2_2{ Point{250,150},50,50 };
	r2_2.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r2_3{ Point{300,150},50,50 };
	r2_3.set_fill_color(Graph_lib::Color::red);
	win.attach(r2_1);
	win.attach(r2_2);
	win.attach(r2_3);
	//Line 3
	Graph_lib::Rectangle r3_1{ Point{200,200},50,50 };
	r3_1.set_fill_color(Graph_lib::Color::white);
	Graph_lib::Rectangle r3_2{ Point{250,200},50,50 };
	r3_2.set_fill_color(Graph_lib::Color::red);
	Graph_lib::Rectangle r3_3{ Point{300,200},50,50 };
	r3_3.set_fill_color(Graph_lib::Color::white);
	win.attach(r3_1);
	win.attach(r3_2);
	win.attach(r3_3);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}