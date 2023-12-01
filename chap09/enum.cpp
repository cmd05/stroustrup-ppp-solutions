#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class Month {
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

Month operator++(Month& m) {
    m = (m==Month::Dec) ? Month::Jan : Month(int(m) + 1);
    return m;
}

ostream& operator<<(ostream& os, Month m) {
    const vector<string> month_tbl = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September"
        "October", "November", "December"
    };
    
    return os << month_tbl[int(m) - 1];
}

int main() {
    Month m{Month::Feb};
    ++m;
    std::cout << m;
}