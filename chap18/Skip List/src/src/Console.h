#include <string>

#include "Skip_List.h"

class Console {
public:
	Console(Skip_List list, std::string f = "") : skip_list{ list }, file{f} {}
	void run();
	bool write_to_file(std::string f) const;
private:
	Skip_List skip_list;
	std::string file = "";
};