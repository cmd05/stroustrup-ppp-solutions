#include <iostream>
#include <string>
#include <fstream>

#include "Skip_List.h"
#include "Console.h"

void Console::run() {
    std::cout << "Commands: \n"
        << "\tinsert <value>\n"
        << "\tsearch <value>\n"
        << "\tremove <value>\n\n";
    std::cout << skip_list.get_representation();

    std::cout << "\n" << "> ";

    std::string cmd;
    double arg;
    for (; std::cin >> cmd >> arg;) {
        if (cmd == "insert") {
            if (skip_list.insert(arg)) {
                std::cout << "Successful insertion!\n\n";
                std::cout << skip_list.get_representation();
            }
            else std::cout << "Error inserting value!\n";
        }
        else if (cmd == "search") {
            if (Node* search = skip_list.search(arg)) {
                std::cout << "Element found! (" << &search << ")\n\n";
                std::cout << skip_list.get_representation();
            }
            else std::cout << "Value not found!\n";
        }
        else if (cmd == "remove") {
            if (skip_list.remove(arg)) {
                std::cout << "Successful deletion!\n\n";
                std::cout << skip_list.get_representation();
            }
            else std::cout << "Error deleting value!\n";
        }
        else std::cout << "Command not recognized\n";

        std::cout << "\n" << "> ";
    }
}

void Console::write_to_file(std::string file) const {
    std::ofstream ost{ file };
    std::string content = skip_list.get_representation();
    ost << content;
}