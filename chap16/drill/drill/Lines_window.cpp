#include "Lines_window.h"
#include "Gui.h"
#include "Graph.h"
#include <string>

namespace Graph_lib {
	Lines_window::Lines_window(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		next_button{ Point{x_max()-150,0}, 70, 20, "Next point", cb_next },
		quit_button{ Point{x_max()-70,0}, 70, 20, "Quit", cb_quit },
		next_x{ Point{x_max()-310,0}, 50, 20, "next x:" },
		next_y{ Point{x_max()-210,0}, 50, 20, "next y:" },
		xy_out{ Point{100,0}, 100, 20, "current (x,y):" },
		color_menu{ Point{x_max()-70,30},70,20,Menu::vertical,"color" },
		menu_button{ Point{x_max()-80,30}, 80, 20, "color menu", cb_menu },
		style_menu{ Point{70,30},70,20,Menu::vertical,"color" },
		style_button{ Point{80,30}, 80, 20, "style menu", cb_style_menu }
	{
		attach(next_button);
		attach(quit_button);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		xy_out.put("no point");

		color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_red });
		color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_blue });
		color_menu.attach(new Button{ Point{0,0},0,0,"black",cb_black });
		attach(color_menu);
		color_menu.hide();
		attach(menu_button);
		
		style_menu.attach(new Button{ Point{0,0},0,0,"solid",cb_solid});
		style_menu.attach(new Button{ Point{0,0},0,0,"dash",cb_dash });
		style_menu.attach(new Button{ Point{0,0},0,0,"dot",cb_dot });
		attach(style_menu);
		style_menu.hide();
		attach(style_button);

		attach(lines);
	}


	void Lines_window::quit() { hide(); }

	void Lines_window::next() {
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Point{ x, y });

		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());

		redraw();
	}
}