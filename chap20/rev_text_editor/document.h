#pragma once

#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <string>

using line = std::vector<char>;

/*
 * document consists of atleast one line (default: one empty line)
 *
*/
class document {
public:
    class text_iterator;

    document() { lines.push_back(line{}); }
    
    void add_char(char ch);
    void add_newline() { lines.push_back(line{}); }

    void erase_line(int n); 

    void print(std::ostream& os, text_iterator first, text_iterator last);
    void print_all(std::ostream& os);

    text_iterator find(const std::string& s);
    text_iterator find_range(text_iterator first, text_iterator last, const std::string& s);

    const line& back() { return lines.back(); }
    
    text_iterator begin(); // define const_iterator for making begin() const  
    text_iterator end();
private:
    std::list<line> lines;
};


/// Document Iterator

class document::text_iterator {
public:
	friend class list;
    
    text_iterator(std::list<line>::iterator lst_it, line::iterator ln_it): list_it{lst_it}, line_it{ln_it} {}

    char& operator*() { return *line_it; }
    const char operator*() const { return *line_it; }

    text_iterator& operator++();
    text_iterator& operator--();

    bool operator==(const text_iterator b) const { return list_it == b.list_it && line_it == b.line_it; }
    bool operator!=(const text_iterator b) const { return !operator==(b); }
private:
    std::list<line>::iterator list_it;
    line::iterator line_it;
};

// user should not increment past document::end()
document::text_iterator& document::text_iterator::operator++() {
    line_it++;

    if(line_it == (*list_it).end()) {
        list_it++;
        line_it = (*list_it).begin();
    }

    return *this;
}

// user should not decrement past document::begin()
document::text_iterator& document::text_iterator::operator--() {
    if(line_it == (*list_it).begin()) {
        list_it--;
        line_it = (*list_it).end() - 1;
    } else {
        line_it--;
    }

    return *this;
}

/// Document

void document::print(std::ostream& os, text_iterator first, text_iterator last) {
    for(auto p = first; p != last; ++p)
        os << *p;
}

void document::print_all(std::ostream& os) { print(os, begin(), end()); }

void document::erase_line(int n) {
    // assume lines numbered 1 to n
    if(n <= 0 || n > lines.size()) return;
    
    auto p = lines.begin();
    for(; n > 1; n--) p++;

    lines.erase(p);
}

// find in [first, last)
document::text_iterator document::find_range(text_iterator first, text_iterator last, const std::string& s) {
    for(auto p = first; p != last; ++p)
        if(*p == s[0]) {
            bool found = true;
            auto p2 = p; ++p2;

            for(int i = 1; i < s.length() && p2 != last; ++p2, i++) {
                if(*p2 != s[i]) {
                    found = false;
                    break;
                }
            }

            if(found) return p;
        }

    return last;
}

document::text_iterator document::find(const std::string& s) {
    return find_range(begin(), end(), s);
}

document::text_iterator document::end() {
    return text_iterator{--lines.end(), lines.back().end()};
}

document::text_iterator document::begin() {
    return text_iterator{lines.begin(), lines.front().begin()};
}

void document::add_char(char ch) {
    lines.back().push_back(ch);
    if(ch == '\n')
        add_newline();
}

std::istream& operator>>(std::istream& is, document& d) {
    for(char ch; is.get(ch);)
        d.add_char(ch);

    if(d.back().size()) d.add_newline(); // add final empty line

    return is;
}