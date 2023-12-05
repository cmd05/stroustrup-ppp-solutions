#include <iostream>
#include <fstream>
#include <sstream>
#include <initializer_list>
#include <vector>
#include <math.h>
#include <iomanip>

// template<typename T>
// void pt(std::initializer_list<T> il = {}) {
//     for(T t : il)
//         std::cout << t << "\t";
//     std::cout << "\n";
// }

// void log(std::string s) {
//     std::ofstream os {"log.txt", std::ios_base::app}; // append to file
//     if(!os) std::cout << "error opening file"; // always check file stream for errors after opening

//     os << s << '\n';
// }

// void out(std::string s) {
//     std::ofstream os {"log.txt"}; // (truncates file by default) / or starts at index 0 [os dependant]
//     if(!os) std::cout << "error opening file";

//     os << s << '\n';
// }

// template<typename T>
// char* as_bytes(T& i) {
//     return static_cast<char*>((void*) &i);
// }

int main() {
    // std::cout << 1234 << "\tdecimal\n"
    //             << std::hex << 1234 << "\thex\n"
    //             << std::oct << 1234 << "\toct\n";

    // std::cout << std::showbase << std::dec << "\n\n"; // showbase applies to all numerical manipulators
    // // to undo its effect use std::noshowbase
    
    // std::cout << 1234 << "\tdecimal\n"
    //         << std::hex << 1234 << "\thex\n"
    //         << std::oct << 1234 << "\toct\n\n";

    // std::cout << std::dec << 1234 << '\t' << 0x4d2 << '\t' <<  02322 << '\n';


    int a,b,c,d,e;
    // std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
    // pt({a,b,c,d});
    
    // std::cin >> std::dec >> e;
    // pt({e});


    // std::cin.unsetf(std::ios::dec); // unsetf - clears specd flag
    // // std::cin.unsetf(std::ios::hex);
    // std::cin.unsetf(std::ios::oct);

    // std::cin >> a >> b >> c >> d;
    // pt({a,b,c,d});

    // float x = 1234567.89;
    // std::cout << x;
    // fixed, scientific, defaultfloat, setprecision


    // log("this will");
    // log("be overwritten");
    
    // out("--Content--");

    // log("The ancient pond");
    // log("A frog leaps in");
    // log("The sound of the water.");


    // open files and test them to avoid doing work, and then knowing file streams don't work 
    // std::fstream fs {"bin_input.txt", 
    //     std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary};

    // std::ofstream ofs {"bin_output.txt", std::ios_base::binary};

    // try {
    //     if(!fs) throw std::runtime_error("Could not open input file");
    //     if(!ofs) throw std::runtime_error("Could not open output file");
    // } catch(const std::runtime_error& e) {
    //     std::cout << e.what();
    // }

    // // fill input file
    // std::vector<int> dump {12, 4, 7, 2, 7, 8, 2, 6, 32};
    // for(const int& x : dump)
    //     fs.write(as_bytes(x), sizeof(int));

    // fs.seekg(0, std::ios::beg);

    // // // read input
    // std::vector<int> v;
    // for(int x; fs.read(as_bytes(x), sizeof(int));)
    //     v.push_back(x);
    
    // // // square all numbers
    // for(int& x : v)
    //     x = pow(x, 2);
    
    // // write to file
    // for(const int& x : v)
    //     ofs.write(as_bytes(x), sizeof(int));


    // file seeking

    // std::fstream fs {"seek.txt", std::ios_base::in | std::ios_base::out};

    // std::cout << "before";
    // try {
    //     if(!fs) throw std::runtime_error("Could not open input file");
    // } catch(std::exception& e) {
    //     std::cout << e.what();
    // }
    // std::cout << "after";

    // fs.seekg(5); // position file pointer on fs[5]
    // char ch;
    // fs >> ch;
    // std::cout << "fs[5] is: " << ch;

    // std::string s = "1.34e-3";
    // std::istringstream iss {s};
    // double d2;
    // iss >> d2;
    
    // if(!iss) throw std::runtime_error("format err");

    // std::string s2 = "Text ";
    // std::ostringstream oss {s2};
    // oss << '|' << std::setw(10) << "Hello" << '|' << d2;
    
    // std::cout << oss.str(); 
    // c_str() is a member function of std::string
    // Hence, oss.str().c_str() can be used to pass c style string to an interface
    // ostringstream - produce strings by concatenation. Ex: oss << (string) << (double) << (int);
    

    // std::string name;
    // std::cin >> name;
    // std::cout << name << '\n'; 
    // Input: Dennis Ritchie
    // Output: Dennis (String is read until whitespace)

    // std::string name;
    // std::getline(std::cin, name);
    // std::cout << name << '\n';

    /* 
        Note:
            std::cin - ignores whitespaces
            get() - treats whitespace like characters
     */
    for (char ch; std::cin >> ch; ) {
        if (isdigit(ch)) {
            std::cout << ch << " digit\n";
        }
        else if (isalpha(ch)) {
            std::cout << ch << " digit\n";
        }
        else {
            std::cout << ch << " other\n";
        }
    }
}