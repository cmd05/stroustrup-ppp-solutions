#include <stdexcept>
#include <string>
#include "Simple_window.h"
#include "Graph.h"
#include "Square.h"
#include "Controller.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 1000, 700, "Canvas" };
	win.set_label("Canvas");


	/**
	 * Board 400 x 400
	 * Square 50 x 50
	 * Circle (25,25) , r = 30
	 */
	Point board_nw{ 80, 20};
	int board_side = 560;
	Color piece_color{ Color::red };

	Point board_sw{ board_nw.x, board_nw.x + board_side};
	Controller controller{ board_sw, board_side };

	Square board{board_nw, board_side};
	board.set_color(Color::invisible);
	win.attach(board);

	// Draw Squares of Board 
	int sq_side = board_side / 8;
	
	Vector_ref<Square> squares;
	for (int row_num = 0; row_num < 8; row_num++) {
		for (int col_num = 0; col_num < 8; col_num++) {
			squares.push_back(new Square{ {board_sw.x + col_num*sq_side, board_sw.y - sq_side - row_num*sq_side}, sq_side });
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
		marks_x.push_back(new Mark{ {board_sw.x + (sq_side/2) + sq_side*i,  board_sw.y + (sq_side / 2)}, c });
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

	// Draw Circles on dark squares
	Vector_ref<Circle> pieces;
	int radius = (sq_side / 2) * 0.7;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 8; col++) {
			if ((col + row) % 2 == 0) {
				int x = board_sw.x + (sq_side / 2) + sq_side * col;
				int y = board_sw.y - (sq_side / 2) - sq_side * row;
				pieces.push_back(new Circle{ {x, y}, radius });
				Circle& piece = pieces[pieces.size() - 1];

				piece.set_color(piece_color);
				piece.set_style(Line_style{ Line_style::solid, 3 });
				std::string str_pos = controller.point_to_str(Point{ x, y });
			
				controller.add_piece(str_pos);
				win.attach(piece);
			}
		}
	}

	//controller.print_pieces();
	std::cout << "PRESS NEXT TO START\n\n";
	win.wait_for_button(); // display to screen
	
	// Take Input
	for (int count = 0; count < 100;) {
		std::cout << "CHOOSE PIECE TO MOVE: ";
		std::string to_move;
		std::cin >> to_move;
		std::cout << "ENTER NEW POSITION: ";
		std::string new_move;
		std::cin >> new_move;

		if (!std::cin.good()) break;

		if (controller.is_valid_pos(to_move) && controller.is_valid_pos(new_move)) {
			if (controller.piece_exists(to_move)) {
				if (controller.is_valid_move(to_move, new_move)) {
					// make old piece invisible 
					// draw circle on new pos
					// update vector

					// new move
					Point new_pos = controller.str_to_point(new_move);
					pieces.push_back(new Circle{new_pos, radius});

					Circle& new_piece = pieces[pieces.size() - 1];
					new_piece.set_color(piece_color);
					new_piece.set_style(Line_style{ Line_style::solid, 3 });

					// erase old move
					Point old_pos = controller.str_to_point(to_move);
					pieces.push_back(new Circle{ old_pos, radius });

					Circle& erase_piece = pieces[pieces.size() - 1];
					erase_piece.set_color(Color::black);
					erase_piece.set_style(Line_style{ Line_style::solid, 3 });


					controller.update_pos(to_move, new_move);

					win.attach(erase_piece);
					win.attach(new_piece);

					count++;
				}
				else {
					std::cout << "\nERROR: Illegal move\n";
				}
			}
			else {
				std::cout << "\nERROR: Piece does not exist\n";
			}
		}
		else {
			std::cout << "\nERROR: Enter valid Input\n";
		}
		
		std::cout << "\nPRESS NEXT TO CONTINUE\n\n";
		win.wait_for_button(); // display to screen
	}
}