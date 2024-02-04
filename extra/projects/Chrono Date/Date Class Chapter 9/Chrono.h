#pragma once
#include <iostream>
#include <string>

namespace Chrono {
	class Invalid {
	public:
		Invalid(std::string err);
		Invalid();
		std::string what();
	private:
		std::string msg;
	};


	enum class Month {
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul,
		Aug, Sep, Oct, Nov, Dec
	};

	enum class Day {
		Monday = 1, Tuesday, Wednesday, Thursday, Friday,
		Saturday, Sunday
	};

	class Date {
	public: 
		// Complete Constructor
		Date(int y, Month m, int d);

		// Default Constructor
		Date();

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		bool is_leap_year(int n);
	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d);

	bool is_leap_year(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);

	Day day_of_week(const Date& d);
	Date next_sunday(const Date& d);
	Date next_weekday(const Date& d);
};