#pragma once

#include <string>
#include <fstream>
#include <vector>

namespace Weather_Data {
    // ---------------- UTILITY FUNCTIONS ---------------- //
    int get_line_num(std::istream& is);
    
    void throw_err(std::string msg);
    void throw_err(std::string msg, std::istream& is);

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

    // ---------------- INTERFACE CLASS ---------------- //
    class Weather_Parser {
        Data data;
    public:
        Weather_Parser(std::string file);
        Data operator()() const { return data; }
    };
};