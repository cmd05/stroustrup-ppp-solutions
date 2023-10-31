/* Read (day-of-the-week,value) pairs from standard input. For
example:
Tuesday 23 Friday 56 Tuesday –3 Thursday 99
Collect all the values for each day of the week in a vector<int>.
Write out the values of the seven day-of-the-week vectors. Print out
the sum of the values in each vector. Ignore illegal days of the week,
such as Funday, but accept common synonyms such as Mon and
monday. Write out the number of rejected values. */

#include <iostream>
#include <vector>
#include <string>

std::vector<int> mondays;
std::vector<int> tuesdays;
std::vector<int> wednesdays;
std::vector<int> thursdays;
std::vector<int> fridays;
std::vector<int> saturdays;
std::vector<int> sundays;


void print_days() {
    int sum = 0;
    std::cout << "Monday: ";
    for(int x : mondays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;

    std::cout << "Tuesday: ";
    for(int x : tuesdays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;

    std::cout << "Wednesday: ";
    for(int x : wednesdays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;

    std::cout << "Thursday: ";
    for(int x : thursdays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;
    
    std::cout << "Friday: ";
    for(int x : fridays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;

    std::cout << "Saturday: ";
    for(int x : saturdays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;
        std::cout << "Sunday: ";
    for(int x : sundays) {
        std::cout << x << " ";
        sum+=x;
    }
    std::cout << "{" << sum << "}" << "\n";
    sum = 0;
}
int main() {
    std::string day;
    int val;
    int rejected;
    std::cout << "Enter day value pairs: ";

    for(; std::cin >> day >> val;) {
        if(day == "Monday" || day == "monday" || day == "mon") mondays.push_back(val);
        else if(day == "Tuesday" || day == "tuesday" || day == "tue") tuesdays.push_back(val);
        else if(day == "Wednesday" || day == "wednesday" || day == "wed") wednesdays.push_back(val);
        else if(day == "Thursday" || day == "thursday" || day == "thu") thursdays.push_back(val);
        else if(day == "Friday" || day == "friday" || day == "fri") fridays.push_back(val);
        else if(day == "Saturday" || day == "saturday" || day == "sat") saturdays.push_back(val);
        else if(day == "Sunday" || day == "sunday" || day == "sun") sundays.push_back(val);
        else rejected++;
    }

    print_days();
    std::cout << "Rejected: " << rejected;
}