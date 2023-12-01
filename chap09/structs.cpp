#include <iostream>
using namespace std;

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n); //Increase Date By n days
};

Date::Date(int yy, int mm, int dd) :y{yy}, m{mm}, d{dd} {} /// constructor is similar to class

struct Str {};

int main() {
    Date today(2007, 12, 5);
    today.add_day(2);
    /* 
        Date:
        -------------
        | y: 2005   |
        -------------
        | m: 12     |
        -------------
        | d: 24     |
        -------------
     */
}