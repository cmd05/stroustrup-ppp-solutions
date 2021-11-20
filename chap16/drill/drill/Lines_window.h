#include "Gui.h"
#include "Graph.h"
#include <string>

namespace Graph_lib {
	struct Lines_window : Window {
		Lines_window(Point xy, int w, int h, const string& title);
	private:
		// data:
		Open_polyline lines;
		// widgets:
		Button next_button; // add (next_x,next_y) to lines
		Button quit_button; // end program
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button menu_button;

		Menu style_menu;
		Button style_button;

		void change(Color c) { lines.set_color(c); }
		void style(Line_style sty) { lines.set_style(sty); }

		void hide_menu() { color_menu.hide(); menu_button.show(); }
		void s_hide_menu() { style_menu.hide(); style_button.show(); }

		// actions invoked by callbacks:
		void red_pressed() { change(Color::red); hide_menu(); }
		void blue_pressed() { change(Color::blue); hide_menu(); }
		void black_pressed() { change(Color::black); hide_menu(); }
		void menu_pressed() { menu_button.hide(); color_menu.show(); }

		void solid_pressed() { style(Line_style::solid); s_hide_menu(); }
		void dash_pressed() { style(Line_style::dash); s_hide_menu(); }
		void dot_pressed() { style(Line_style::dot); s_hide_menu(); }
		void s_menu_pressed() { style_button.hide(); style_menu.show(); }

		void next();
		void quit();

		// callback functions:
		static void cb_red(Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); };
		static void cb_blue(Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); };
		static void cb_black(Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); };
		static void cb_menu(Address, Address pw) { reference_to<Lines_window>(pw).menu_pressed(); };

		static void cb_solid(Address, Address pw) { reference_to<Lines_window>(pw).solid_pressed(); };
		static void cb_dash(Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed(); };
		static void cb_dot(Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed(); };
		static void cb_style_menu(Address, Address pw) { reference_to<Lines_window>(pw).s_menu_pressed(); };

		static void cb_next(Address, Address pw) { reference_to<Lines_window>(pw).next(); };
		static void cb_quit(Address, Address pw) { reference_to<Lines_window>(pw).quit(); };
	};
}