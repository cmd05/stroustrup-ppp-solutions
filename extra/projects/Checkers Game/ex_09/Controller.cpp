#include "Graph.h"
#include "Controller.h"

namespace Graph_lib {
	Controller::Controller(Point sw, int board_len) : board_sw{ sw }, board_side{ board_len }, sq_side{board_len / 8} {}

	std::string Controller::point_to_str(Point pt) const {
		char x = 97 + ((pt.x - sq_side / 2) - board_sw.x) / sq_side;
		char y = 49 + (board_sw.y - (pt.y + sq_side / 2)) / sq_side;
		std::string pos;
		pos += x;
		pos += y;

		return pos;
	}

	Point Controller::str_to_point(std::string pos) const {
		int x = board_sw.x + (sq_side / 2) + (int(pos[0]) - 97)*sq_side;
		int y = board_sw.y - (sq_side / 2) - int(pos[1] - '1') * sq_side;

		return Point{ x, y };
	}

	void Controller::add_piece(std::string str) {pieces.push_back(str);}

	void Controller::print_pieces() const {
		for (std::string piece : pieces) std::cout << "Piece at " << piece << "\n";
	}

	bool Controller::is_valid_pos(std::string input) const {
		return input.length() == 2 &&
			   std::find(valid_x.begin(), valid_x.end(), input[0]) != valid_x.end() &&
			   std::find(valid_y.begin(), valid_y.end(), input[1]) != valid_y.end();
	}

	bool Controller::piece_exists(std::string input) const {
		return std::find(pieces.begin(), pieces.end(), input) != pieces.end();
	}

	bool Controller::is_valid_move(std::string old_pos, std::string new_pos) const {
		int d_x = abs(int(new_pos[0]) - int(old_pos[0]));
		int d_y = abs(int(new_pos[1]) - int(old_pos[1]));

		if (d_x != d_y || piece_exists(new_pos)) return false;

		// check point in b/w
		Point p_old{ str_to_point(old_pos).x - (sq_side / 2),  str_to_point(old_pos).y + (sq_side / 2)};
		Point p_new{ str_to_point(new_pos).x - (sq_side / 2),  str_to_point(new_pos).y + (sq_side / 2) };

		int dir_x = p_new.x > p_old.x ? 1 : -1;
		int dir_y = p_new.y > p_old.y ? -1 : 1;

		for (int i = 1; i < (abs(p_new.x - p_old.x) / sq_side); ++i) {
			Point pt{ p_old.x + (dir_x * i * sq_side) + (sq_side / 2), p_old.y - (dir_y * i * sq_side) - (sq_side / 2)};
			if(piece_exists(point_to_str(pt))) return false;
		}

		return true;
	}

	void Controller::update_pos(std::string old_pos, std::string new_pos) {
		for (std::string& pos : pieces) if (pos == old_pos) pos = new_pos;
	}
};