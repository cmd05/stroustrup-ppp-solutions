#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>
#include <algorithm>

struct QuoteCoords {
    int start;
    int final;
};

class Punct_parser {
    public:
        Punct_parser(std::string whitespace): white{whitespace}, sensitive{true} {}
        void set_whitespace(const std::string& s) {white = s;}
        bool is_whitespace(char c);
        std::vector<QuoteCoords> get_quote_coords(std::string line);
        void parse_line(std::string& line);
        void case_sensitive(bool b) {sensitive = b;}
    private:
        std::string white;
        bool sensitive;
};

bool Punct_parser::is_whitespace(char c) {
    for(char w : white) if(c == w) return true;
    return false;
}

std::vector<QuoteCoords> Punct_parser::get_quote_coords(std::string line) {
    std::istringstream quote_coords {line};
    std::vector<QuoteCoords> quote_coords_v;

    int index = 0;  // set index for iterating over line
    for(char ch; quote_coords.get(ch);) {
        if(ch == '"') { // encountered opening ``"``
            int steps = 0;  // must be one more than position of element just read
            for(char ch; quote_coords.get(ch);) { // read again from ``"`` onwards
                steps++;

                if(ch == '"') { // we found the terminating ``"``
                    quote_coords_v.push_back(QuoteCoords {index, (index + steps)}); // push to coords
                    // statement is inside if only, because if the quote_coords didnt find a terminator till the 
                    // end, outer loop will automatically end
                    index += steps;  
                    break;
                }
            }
        }
        index++;
    }

    return quote_coords_v;
}

void Punct_parser::parse_line(std::string& line) {
    int i = 0;
    std::vector<QuoteCoords> points = get_quote_coords(line);
    for(char& ch : line) {
        bool in_coords = false;

        for(QuoteCoords cd : points)
            if(cd.start <= i && cd.final >= i) in_coords = true;

        if(is_whitespace(ch) && !in_coords)
            ch = ' ';
        else if(!sensitive)
            ch = tolower(ch);
        i++;
    }
}

int main() {
    // std::cout << "Enter a string of words [Ctrl+Z to quit]: ";
    const std::string punctuation = ";:,.?!(){}\"<>/&$@#%^*|~-";
    std::string line = "A-B \"c-d e.f\" g:h \"i/j\"";
    // for(std::string line; std::getline(std::cin, line);) {
        Punct_parser output {punctuation};
        output.parse_line(line);
        std::cout << "Modified Line: " << line << "\nTry Again [Ctrl+Z to quit]: ";
    // }
}