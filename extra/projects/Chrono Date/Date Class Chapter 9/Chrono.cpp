#include "Chrono.h"
#include <iostream>
#include <vector>
#include <string>

namespace Chrono {
    // Invalid Class
    Invalid::Invalid(std::string err) : msg{ err } {}

    Invalid::Invalid() : msg{ "Invalid Exception Thrown" } {}
    
    std::string Invalid::what() {return msg;}

    // Date Class
    Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd } {
        if (!is_date(yy, mm, dd)) throw Invalid{"Invalid Date"};
    }

    const Date& default_date() {
        // Epoch Date
        static Date d{ 1970, Month::Jan, 1 };
        return d;
    }

    Date::Date(): y{ default_date().year() },
                  m{ default_date().month() },
                  d{ default_date().day() } {}

    void Date::add_day(int n) {
        //...
    }

    void Date::add_month(int n) {
        //...
    }

    void Date::add_year(int n) {
        if (m == Month::Feb && d == 29 && !is_leap_year(y + n)) {
            m = Month::Mar;
            d = 1;
        }
        y += n;
    }

    bool is_date(int y, Month m, int d) {
        if (d <= 0) return false;
        
        if (m < Month::Jan || Month::Dec < m) return false;

        int days_max = 31;

        switch (m)
        {
        case Month::Feb: 
            days_max = is_leap_year(y) ? 29 : 28;
            break;
        case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
            days_max = 30;
            break;
        }

        if (d > days_max) return false;

        return true;
    }

    bool is_leap_year(int y) {
        return true;
    }

    bool operator==(const Date& a, const Date& b) {
        return a.year() == b.year() &&
               a.month() == b.month() &&
               a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b) {
        return !(a == b);
    }

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os << "(" <<
               d.year() << ", " <<
               int(d.month()) << ", " <<
               d.day() << ")";
    }

    std::istream& operator>>(std::istream& is, Date& dd) {
        int y = 0, m = 0, d = 0;
        std::vector<char> chars(4);

        std::cout << "Enter the date exactly in the format (y,m,d) [including brackets + no spaces]: ";
        is >> chars[0] >> y >> chars[1] >> m >> chars[2] >> d >> chars[3];

        if (!is) return is;

        if (chars[0] != '(' || chars[1] != ',' || chars[2] != ',' || chars[3] != ')') {
            is.clear(std::ios_base::failbit);
            return is;
        }

        dd = Date(y, Month(m), d);

        return is;
    }

    Day day_of_week(const Date& d) {
        //..
        return Day::Monday;
    }

    Date next_sunday(const Date& d) {
        //..
        return Date{};
    }

    Date next_weekday(const Date& d) {
        //..
        return Date{};
    }

    bool Date::is_leap_year(const int n) {
        if ((n % 4 == 0) && (n % 100 != 0) && (n % 400 == 0)) return true;
        return false;
    }
};
