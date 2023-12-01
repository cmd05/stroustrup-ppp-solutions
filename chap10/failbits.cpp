#include <fstream>
#include <iostream>

int main() {
    std::ifstream ist {"points.txt"};
    std::cin.clear(std::ios_base::eofbit); // clear with argument, sets the stream to that flag

    if(ist.bad()) std::cout << "bad\n";
    if(ist.fail()) std::cout << "fail\n";
    if(ist.eof()) std::cout << "eof\n";
    if(ist.good()) std::cout << "good\n";
    if(!ist.good()) std::cout << "not good (!ist.good())\n";
    if(!ist) std::cout << "!ist\n"; // equivalent to if(ist.fail())

    /* 
        fail: fail, not good, !ist
        bad: bad, fail, not good, !ist
        eof: eof, not good
        good: good
     */

    /* from docs:
        std::ios::operator!
        
        Returns true if either failbit or badbit is set, and false otherwise.
        This is equivalent to calling member fail.

        i.e if(!ist) is equivalent to if(ist.fail())
    */
}