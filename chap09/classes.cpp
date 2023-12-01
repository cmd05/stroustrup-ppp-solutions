#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Invalid {
    public: 
        Invalid(string err): msg{err} {} 
        string what() {return msg;}
    private:
        string msg = "Invalid Exception Thrown";
};

enum class Month {
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// Increment op
Month operator++(Month& m) { /// take month arg by ref
    m = m==Month::Dec ? Month::Jan : Month(int(m)+1);
    return m;
}

class Date {
    public:
        Date(int yy, Month mm, int dd);
        Date();

        /* Member function declarations */
        int year() const {return y;}
        Month month() const {return m;}
        int day() const {return d;}

        void add_day(int n);
    private:
        int y;
        int d;
        Month m;
        bool is_valid(); /// private method - concerned with only implementation details
};


Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {
    if(!is_valid()) throw Invalid{"Invalid Date"}; /// throw Invalid exception if date is invalid
}

Date& default_date() {
    /* Epoch Date */
    static constexpr int EPOCH_YEAR = 1970;
    static constexpr Month EPOCH_MONTH = Month::Jan;
    static constexpr int EPOCH_DAY = 1;

    static Date dd {1990, Month::Mar, 1}; /// not created for each call seperately
    return dd;
}

// Default Construct
Date::Date(): y{default_date().year()}, m{default_date().month()}, d{default_date().day()} {}

bool Date::is_valid() {
    if(int(m) < 1 || 12 < int(m)) return false;
    return true;
}

void Date::add_day(int n) {d++;}

ostream& operator<<(ostream& os, const Month& m) { /// operator<<(ostream& os, const T& obj)
    const vector<string> month_tbl = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September"
        "October", "November", "December"
    };
    return os << month_tbl[int(m)];
}

int main() {
    const Date dd {};
    
}