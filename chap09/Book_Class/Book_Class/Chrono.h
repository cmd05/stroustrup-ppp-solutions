#pragma once
#include <iostream>

namespace Chrono {
	enum class Month {
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul,
		Aug, Sep, Oct, Nov, Dec
	};

	class Date {
	public:
		// Complete Constructor
		Date(int y, Month m, int d);

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d);

	bool is_leap_year(int y);

	/// operator overloads for a class inside namespace are preferably defined inside the same namespace
	/// The compiler finds them through `argument dependant lookup` 

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);
};