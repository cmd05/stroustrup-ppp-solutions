#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Axis s_1{ Axis::x, Point{100, 100}, 100, 0, "" };
	Axis s_2{ Axis::y, Point{100, 200}, 100, 0, "" };
	Axis s_3{ Axis::x, Point{100, 200}, 100, 0, "" };
	Axis s_4{ Axis::y, Point{200, 300}, 100, 0, "" };
	Axis s_5{ Axis::x, Point{100, 300}, 100, 0, "" };

	s_1.set_color(Color::black);
	s_2.set_color(Color::black);
	s_3.set_color(Color::black);
	s_4.set_color(Color::black);
	s_5.set_color(Color::black);

	win.attach(s_1);
	win.attach(s_2);
	win.attach(s_3);
	win.attach(s_4);
	win.attach(s_5);

	Axis m_1{ Axis::y, Point{300, 300}, 200, 0, "" };
	Axis m_2{ Axis::x, Point{300, 100}, 200, 0, "" };
	Axis m_3{ Axis::y, Point{500, 300}, 200, 0, "" };
	Axis m_4{ Axis::y, Point{400, 200}, 100, 0, "" };
	m_1.set_color(Color::black);
	m_2.set_color(Color::black);
	m_3.set_color(Color::black);
	m_4.set_color(Color::black);

	win.attach(m_1);
	win.attach(m_2);
	win.attach(m_3);
	win.attach(m_4);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}