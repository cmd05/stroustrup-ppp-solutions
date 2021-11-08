#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

/* class Weather_Parse {
    Data data;
public:
    Weather_Parse(std::string file) {
        std::ifstream ist {file};
        ist >> data;
    }    

    Data operator()() const { return data; }
};

Weather_Parse parser{"file.txt"}
Data data = parser(); */


// ---------------- UTILITY FUNCTIONS ---------------- //
int get_line_num(std::istream& is) {
    int line_count =  1;
    is.clear();
    int original_pos = is.tellg();

    // return -1 on fail
    if(original_pos < 0) return -1;
    
    // count newline chars
    is.seekg(0);
    char c;
    while(is.tellg() < original_pos && is.get(c)) if(c == '\n') line_count++;

    return line_count;
}

void throw_err(std::string msg) { throw std::runtime_error(msg); }

void throw_err(std::string msg, std::istream& is) {
    std::string err = msg + " <line " + std::to_string(get_line_num(is)) + ">";
    throw std::runtime_error(err);
}

// ---------------- WEATHER DATA STRUCTURES ---------------- //
const std::vector<std::string> month_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

struct Day {
    double max_temp;
    double min_temp;
    double avg_temp;
};

struct Month {
    std::string month;
    std::vector<Day> days;
};

struct City {
    std::string city;
    std::vector<Month> months;
};

struct Data {
    std::vector<City> cities;
};

// ---------------- INPUT DAY ---------------- //
/**
 * Input temperatures for single day of month
 * Format: (10 12 12 12 15 5)
 */
std::istream& operator>>(std::istream& is, Day& day) {
    char open;
    is >> open;
    
    if(open != '(') { // No more new days. Exit
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    
    // Placeholder values
    double min_day = 250;
    double max_day = -250;
    double avg_day = 0;
    int count =  0;

    while(true) {
        double temp; 
        
        if(!(is >> temp)) break; // No more temperature readings

        avg_day += temp;
        if(temp < min_day) min_day = temp;
        if(temp > max_day) max_day = temp; 

        count++;
    }

    avg_day /= count;

    // Save readings to day
    day.avg_temp = avg_day;
    day.max_temp = max_day;
    day.min_temp = min_day;

    is.unget();
    is.clear();

    // Check for closing parenthesis to day
    char ch;
    is >> ch;
    if(ch != ')') throw_err("missing ')' end of day", is);
    
    return is;
}

// ---------------- INPUT MONTH ---------------- //
/**
 * Input single month of the year
 * Format: month <month> { .... }
 */
std::istream& operator>>(std::istream& is, Month& month) {
    std::string month_open;
    is >> month_open;

    // End of months. Exit
    if(month_open != "month") {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    
    std::string month_name;
    char open;
    is >> month_name >> open;

    // Check if valid month of the year
    if(std::find(month_tbl.begin(), month_tbl.end(), month_name) == month_tbl.end()) throw_err("invalid month " + month_name, is);
    // Check for curly brace after month name
    if(open != '{') throw_err("missing '{' for month", is);

    // save month name
    month.month = month_name;
    
    // input days of the month
    while(true) {
        Day dd;
        if(!(is >> dd)) break; // end of days input
        month.days.push_back(dd);
    }

    // check for closing brace
    if(is.fail()) {
        is.clear();
        char end;
        is >> end;
        if(end != '}') throw_err("missing '}' at end of month", is);
    }
    
    return is;
}

// ---------------- INPUT CITY ---------------- //
/**
 * Input single city of data
 * Format: { city <city_name> .... }
 */
std::istream& operator>>(std::istream& is, City& city) {
    char open;
    is >> open;

    // end of cities. Exit
    if(open != '{') {
        is.unget();
        is.clear(std::ios_base::failbit); 
        return is;
    }

    // Read city marker and city name
    std::string city_mark, city_name;
    is >> city_mark >> city_name;

    if(city_mark != "city") throw_err("missing city marker", is);
    if(city_name.length() > 25) throw_err("city name exceeds max length", is);

    // save city
    city.city = city_name;

    // Input months
    int month_count = 0; // save current month index

    while(true) {
        Month m;

        if(!(is >> m)) { // end of months
            if(month_count != 12) throw_err("month count is not 12", is); // throw error if month count is not 12
            break;
        }
        
        // check if month name matches to month at current index
        if(m.month != month_tbl[month_count]) throw_err("month order is invalid", is);
        
        // save month data
        city.months.push_back(m);
        month_count++;

        // stop reading if month count exceeds 12
        if(month_count > 12) throw_err("month count exceeds 12", is);
    }
    
    // check for closing brace for city 
    if(is.fail()) {
        is.clear();
        char end;
        is >> end;
        if(end != '}') throw_err("closing '}' not found for city", is);
    }

    return is;
}

// ---------------- INPUT DATA ---------------- //
/**
 * Input data of cities in correct format
 * Format: 
    START
    <...>
    END
 */
std::istream& operator>>(std::istream& is, Data& data) {
    std::string start;
    is >> start;

    // check for START identifier
    if(start != "START") throw_err("Missing 'START' identifier", is);
    
    // Read all cities
    while(true) {
        City city;
        if(!(is >> city)) break; // end of cities
        data.cities.push_back(city);
    }

    // check for END identifier
    if(is.fail()) {
        is.clear();

        std::string end;
        is >> end;
        if(end != "END") throw_err("Missing 'END' identifier", is);
    }

    return is;
}

/**
 * Solid - Avg temp
 * Dashed - Avg Max temp
 * Dotted - Avg min temp
 */

int main() {
    try {
        std::ifstream ist {"data.txt"};
        Data data;
        ist >> data;
        
        // avg max temp
        for(City city : data.cities) {
            for(Month month : city.months) {
                double avg = 0;
                int i = 0;
                for(Day day : month.days) {
                    avg += day.min_temp;
                    i++;
                }
                avg /= i;
                std::cout << city.city << " - Mean of minm of " << month.month << " = " << avg << "\n";
            }
        }
    } catch(std::runtime_error& err) {
        std::cout << err.what();
    }
}