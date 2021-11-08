#pragma once
#include "Graph.h"
#include <string>

namespace Graph_lib {
	class Controller {
	public:
		Controller(Point sw, int board_len);
		std::string point_to_str(Point xy) const;
		Point str_to_point(std::string str) const;
		bool is_valid_pos(std::string str) const;
		bool is_valid_move(std::string old_pos, std::string new_pos) const;
		void add_piece(std::string str);
		bool piece_exists(std::string str) const;
		void update_pos(std::string old_pos, std::string new_pos);
		void print_pieces() const;
	private:
		Point board_sw;
		int board_side;
		int sq_side;
		std::vector<std::string> pieces;
		std::vector<char> valid_x{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
		std::vector<char> valid_y{'1', '2', '3', '4', '5', '6', '7', '8'};
	};
};