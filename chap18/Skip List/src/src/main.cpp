#include <iostream>

#include "Skip_List.h"
#include "Console.h"

int main()
{
    std::vector<double> vc = {90, 15, -59, 48, -1, -28};
    Skip_List skip_list{vc};

    Console console{skip_list, "output.txt"};
    console.write_to_file("output.txt");
    console.run();
}