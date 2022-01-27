#include <string>

#include "Skip_List.h"

class Console {
public:
	Console(Skip_List list) : skip_list{ list } {}
	void run();
	void write_to_file(std::string file) const;
private:
	Skip_List skip_list;
};