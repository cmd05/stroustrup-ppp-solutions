// Define a File_handle class with a constructor that takes a string
// argument (the file name), opens the file in the constructor, and closes it
// in the destructor

#include <iostream>
#include <iostream>
#include <fstream>

class File_Handle {
public:
	File_Handle(std::string s) {
		ist.open(s);
	}

	void print_contents() {
		for(std::string t; std::getline(ist, t);) {
			std::cout << t << "\n";
		}
	}

	~File_Handle() {
		ist.close();
	}

private:
	std::ifstream ist;
};

int main() {
	File_Handle f{"review"};
	f.print_contents();
}