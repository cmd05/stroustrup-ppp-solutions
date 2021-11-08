#include <iostream>
#include <string>
#include "../includes/std_lib_facilities.h"

struct Person {
    public:
        Person(std::string fn, std::string ln, int a): fname{fn}, lname{ln}, age{a} {
            if(age < 0 || age >= 150) throw std::runtime_error("Age out of range");
            if(!check_name(fn)) throw std::runtime_error("Invalid fname");
            if(!check_name(ln)) throw std::runtime_error("Invalid lname");
        }    

        Person() {}

        bool check_name(std::string name) const;
        std::string get_fname() const { return fname; }
        std::string get_lname() const { return lname; }

        int get_age() const { return age; }
    private:
        std::string invalid = "'[]*&^%$#@!";
        std::string fname = "";
        std::string lname = "";

        int age = 0;
};

bool Person::check_name(std::string name) const {
    for(char c : name) 
        for(char i : invalid) 
            if(c == i) return false;
    
    if(name == "") return false;
    
    return true;
}

std::istream& operator>>(std::istream& is, Person& ps) {
    is.exceptions(is.exceptions() | std::ios_base::badbit);
    std::string fname;
    std::string lname;

    int age;

    if(!(is >> fname >> lname >> age)) return is;

    ps = Person(fname, lname, age);

    return is;
}
std::ostream& operator<<(std::ostream& os, Person& ps) {
    os << ps.get_fname() << " " << ps.get_lname() << "\t" << ps.get_age();
    return os;
}

int main() {
    vector<Person> v;

    std::cout << "Enter fname, lname and age: \n";

    for(Person ps; std::cin >> ps;) {
        v.push_back(ps);
        std::cout << "***Added!***\n";
    }

    for(Person ps : v) std::cout << ps << "\n";
}