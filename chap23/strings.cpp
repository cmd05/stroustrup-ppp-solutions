#include <iostream>
#include <string>

template<typename T>
std::string _to_string(const T& val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

struct bad_from_string {
    const char* what() const {
        return "bad cast from string";
    }
};

template<typename T>
T _from_string(const std::string& s) {
    std::istringstream iss {s};
    T val;

    if(!(iss >> val)) throw bad_from_string{};

    return val;
}