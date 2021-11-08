#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>

// celsius, ymd
constexpr int INVALID_READING = -2000;  // below abs 0
constexpr int NOT_MONTH = -1;
constexpr int implausible_min = -200;  // impossible value
constexpr int implausible_max = 200;
constexpr int min_year = 1900;
constexpr int max_year = 2021;

void end_of_loop(std::istream& ist, char term, const std::string& message) {
    if(ist.fail()) {
        ist.clear();
        char ch;
        if(ist >> ch && ch == term) return;
        throw std::runtime_error("IST fail");
    }
}

bool is_comment(std::istream& ist) {
    std::string input;
    ist >> input;
    if(input == "//") return true;
    else {
        ist.unget();
        return false;
    }
}

void throw_err(std::string message, char ch) {throw std::runtime_error(message + " " + ch);}
void throw_err(std::string message, int i) {throw std::runtime_error(message + ". Value: " + std::to_string(i));}
void throw_err(std::string message, double i) {throw std::runtime_error(message + ". Value: " + std::to_string(i));}

struct Reading {
    int day;
    int hour;
    double temperature;
};

struct Day {
    std::vector<double> hour {std::vector<double>(24, INVALID_READING)};
};

struct Month {
    int month = NOT_MONTH;  // 0-11 jan=0
    std::vector<Day> day {32};   // 1-31 one per day
};

struct Year {
    int year;
    std::vector<Month> month {12}; //jan=0
};

struct Collection {
    std::string location;
    std::vector<Year> years; //jan=0
};

std::istream& operator>>(std::istream& ist, Reading& r) {
    char ch_1;
    if(ist >> ch_1 && ch_1 != '(') {
        ist.unget();
        ist.clear(std::ios_base::failbit);
        return ist;
    }

    char ch_2;
    int d;
    int h;
    double temp;
    ist >> d >> h >> temp >> ch_2;
    
    if(!ist || ch_2 != ')') throw_err("bad reading", d);
    r.day = d;
    r.hour = h;
    r.temperature = temp;

    return ist;
}

bool is_valid(const Reading& r) {
    if(r.day < 1 || 31 < r.day) return false;
    if(r.hour < 0 || r.hour > 23) return false;
    if(r.temperature < implausible_min || r.temperature > implausible_max) return false;

    return true;
}

const std::vector<std::string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

const std::vector<std::string> month_output_tbl = {
    "January", "February", "March", "April",
    "May", "June", "July", "August", "September"
    "October", "November", "December"
};

int month_to_int(std::string month_name) {
    for(int i = 0; i < 12; i++) if(month_input_tbl[i] == month_name) return i;
    return -1;
}

std::string int_to_month(int i) {
    if(i < 0 || 12 <= i) throw std::runtime_error("Bad month index");
    return month_output_tbl[i];
}

std::istream& operator>>(std::istream& ist, Month& m) {
    char ch = 0;
    if(ist >> ch && ch != '{') {
        ist.unget();
        ist.clear(std::ios_base::failbit);
        return ist;
    }

    std::string month_marker;
    std::string mm;
    ist >> month_marker >> mm;
    if(!ist || month_marker != "month") throw std::runtime_error("Bad start of month");
    if (std::find(month_input_tbl.begin(), month_input_tbl.end(), mm) == month_input_tbl.end()) throw std::runtime_error("Month Not found");

    m.month = month_to_int(mm);

    int duplicates = 0;
    int invalids = 0;

    // 
    /* 
        month has day vector containing days as:
        {
            Day 1: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
            Day 2: {-1, 67.6, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
        }
    
     */
    for(Reading r; ist >> r;) {
        if(is_valid(r)) {
            if(m.day[r.day].hour[r.hour] != INVALID_READING) ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature;
        } else {
            ++invalids;
        }
    }

    if(invalids > 0) throw std::runtime_error("Invalid Readings in month ");
    if(duplicates > 0) throw std::runtime_error("Duplicate Readings in month ");
    end_of_loop(ist, '}', "Month not terminated properly");

    return ist;
}

std::istream& operator>>(std::istream& ist, Year& y) {
    char ch;
    ist >> ch;
    if(ch != '{') {
        ist.unget();
        ist.clear(std::ios_base::failbit);
        return ist;
    }

    std::string year_marker;
    int yy;
    ist >> year_marker >> yy;
    if(!ist || year_marker != "year") throw std::runtime_error("Invalid Year start ");
    if(yy < min_year || yy > max_year) throw std::runtime_error("Year outside range");
        
    y.year = yy;

    /* 
        2010:
        {
            Jan
            {
                Day 1: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
                Day 2: {-1, 67.6, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
            }
        
            Feb
            {
                Day 1: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
                Day 2: {-1, 61, -1, -1, -1, -1, -1, -1, -1, -1} // 24 times
            }
        }
     */
    while(true) {
        Month m;
        if(!(ist >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(ist, '}', "Invalid year end");
    return ist;
}

std::istream& operator>>(std::istream& ist, Collection& collection) {
    std::string start;
    ist >> start;
    if(start != "START") throw std::runtime_error("No 'START' identifier found");

    // mentioned location
    std::string city, country;
    char ch_1, ch_2;
    int zipcode;
    ist >> ch_1 >> city >> country >> zipcode >> ch_2;

    std::string location = city + + " " +std::to_string(zipcode) + ", " + country;
    const int zipsize = (zipcode <= 1) ? 1 : (log10(zipcode) + 1);

    if(ch_1 != '[' || ch_2 != ']' || !ist) {
        throw std::runtime_error("Invalid location format.");
    } else if(zipsize != 6) {
        throw std::runtime_error("Invalid zipcode");
    } else if(location.size() > 100) {
        throw std::runtime_error("Location name exceeds 100 characters");
    }
    
    std::cout << location;
    collection.location = location;

    while(true) {
        Year y;
        if(!(ist >> y)) break;
        for(Year yy : collection.years) if(yy.year == y.year) throw std::runtime_error("Year repeated ");
        collection.years.push_back(y);
    }
    
    if(ist.fail()) {
        ist.clear();
        std::string terminator;
        if(!(ist >> terminator && terminator == "END")) throw std::runtime_error("did not terminate collection with 'END' identifier");
    }
    
    return ist;
}

void print_years(std::ofstream& os, Collection& collection) {
    std::cout << collection.location << "\n";
    for(Year y : collection.years) {
        std::cout << "Year " << y.year << "\n";
        for(Month m : y.month) {
            if(m.month != NOT_MONTH) {
                std::cout << "\t" << int_to_month(m.month) << ": \n";
                for(int h = 0; h < m.day.size(); h++) {
                    const Day d = m.day[h];
                    std::string message;
                    for(int i = 0; i < d.hour.size(); i++) {
                        const double reading = d.hour[i];
                        if(reading != INVALID_READING) message += "\t\t\tHour: " + std::to_string(i) + " Reading: " + std::to_string(reading) + "\n"; 
                    }
                    if(message != "") std::cout << "\t\tDay " << h << ": \n" << message;
                }
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ifstream ifs {"ymd_temp_readings.txt"};
    if(!ifs) throw std::runtime_error("Could not open file");
    Collection readings{};
    try {
        ifs >> readings;
        ifs.close();
        std::ofstream ofs {"ymd_temp_output.txt"};
        print_years(ofs, readings);
    } catch(std::runtime_error& e) {
        std::cerr << e.what();
    }
}