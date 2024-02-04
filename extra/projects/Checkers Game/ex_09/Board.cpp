#pragma once
#include <iostream>
#include "Board.h"
#include "Graph.h"
#include "Square.h"

namespace Graph_lib {
	Board::Board(Simple_window& win, Point nw, int board_side, Color piece_color) :
		win{win}, board_nw {nw}, board_side{ board_side }, piece_color{ piece_color },
		sq_side{board_side / 8}, board_sw{nw.x, nw.y + board_side} {
		
	}

	void Board::init() const {
		std::cout << "Board";
		Square board{ board_nw, board_side };
		board.set_color(Color::invisible);
		win.attach(board);
		
		/*
		 * Board 400 x 400
		 * Square 50 x 50
		 * Circle (25,25) , r = 30
		*/

		// Draw Squares of Board 
		int sq_side = board_side / 8;

		Vector_ref<Square> squares;
		for (int row_num = 0; row_num < 8; row_num++) {
			for (int col_num = 0; col_num < 8; col_num++) {
				squares.push_back(new Square{ {board_sw.x + col_num * sq_side, board_sw.y - sq_side - row_num * sq_side}, sq_side });
				Square& last_el = squares[squares.size() - 1];
				Color fill_color = ((col_num + row_num) % 2 == 0) ? Color::black : Color::white;
				last_el.set_fill_color(fill_color);
				Color border = (col_num % 7 == 0 || row_num % 7 == 0) ? Color::black : Color::invisible;
				last_el.set_color(border);

				win.attach(last_el);
			}
		}

		// Draw Position Axis 
		// Horizontal a-z
		// Vertical 1-8

		Vector_ref<Mark> marks_x;
		for (int i = 0; i < 8; i++) {
			char c = 97 + i;
			marks_x.push_back(new Mark{ {board_sw.x + (sq_side / 2) + sq_side * i,  board_sw.y + (sq_side / 2)}, c });
			Mark& m = marks_x[marks_x.size() - 1];
			win.attach(m);
		}

		Vector_ref<Mark> marks_y;
		for (int i = 0; i < 8; i++) {
			char c = 49 + i;
			marks_x.push_back(new Mark{ {board_sw.x - sq_side / 2,  board_sw.y - (sq_side / 2) - sq_side * i}, c });
			Mark& m = marks_x[marks_x.size() - 1];
			win.attach(m);
		}
	}
};