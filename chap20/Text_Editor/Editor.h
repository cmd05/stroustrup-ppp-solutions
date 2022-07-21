#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

#include <iostream>

using Line = std::vector<char>;

class Text_iterator {
	std::list<Line>::iterator In;
	Line::iterator pos;
public:
	using iterator_category = std::input_iterator_tag;
    using value_type = char;
    using difference_type = std::ptrdiff_t;
    using pointer = char*;
    using reference = char&;

	Text_iterator(std::list<Line>::iterator II, Line::iterator pp): In{II}, pos{pp} {}

	char& operator*() { return *pos; }
	char* operator->() { return &(*pos); }	
	Text_iterator& operator++();
	Text_iterator& operator++(int) { return ++(*this); }

	bool operator==(const Text_iterator& other) const { return In==other.In && pos==other.pos; }
	bool operator!=(const Text_iterator& other) const { return !(*this == other); }

	const std::list<Line>::iterator& get_line_it() const { return In; }
	const Line::iterator& get_line_pos() const { return pos; }
};

// read only operation on Document
Text_iterator& Text_iterator::operator++() {
	++pos;
	// if last character of any given line
	if(pos==(*In).end()) { // (*In).end() -> (*list_iterator).end() -> (vector<char>).end()
		++In; // proceed to next line
		pos = (*In).begin();
	}
	return *this;
}

Text_iterator operator+(Text_iterator& a, int n) {
	Text_iterator b = a;
	for(; n > 0; n--, ++b);

	return b;
}

class Document {
public:	
	Document() { lines.push_back(Line{}); }

	Text_iterator begin() // first char of first line
		{ return Text_iterator( lines.begin(), (*lines.begin()).begin() ); } 

	Text_iterator end() // one beyond last char of last line
	{ 
		auto last_line = lines.end();
		last_line--;
		return Text_iterator( last_line, (*last_line).end() ); 
	}

	// get information
	int line_count() const { return lines.size(); }
	void char_count() const;
	void line_char_count(int n) const;
	std::list<Line>& get_lines() { return lines; } 
	
	// read operations
	Text_iterator find_char(Text_iterator first, Text_iterator last, char c) const;
	Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s) const;

	// write operations
	void erase_line(int n);
	void erase_line(Text_iterator& it);
	Text_iterator erase_first(Text_iterator first, Text_iterator last, const std::string& s) const;
private:
	std::list<Line> lines;
};

void Document::erase_line(Text_iterator& it) {
	if(line_count() == 1) return;

	auto last_line = lines.end();
	last_line--;
	if(it.get_line_it() == last_line) return;

	lines.erase(it.get_line_it());
}

void Document::erase_line(int n) {
	if(n < 0 || line_count()-1 <= n) return;
	auto p = lines.begin();
	std::advance(p, n);
	lines.erase(p);
}

std::istream& operator>>(std::istream& is, Document& doc) {
	for(char ch; is.get(ch);) {
		doc.get_lines().back().push_back(ch); // add character
		if(ch=='\n') doc.get_lines().push_back(Line{}); // add another line
	}

	if(doc.get_lines().back().size()) doc.get_lines().push_back(Line{}); // final empty line
	return is;
}

std::ostream& operator<<(std::ostream& os, Document& doc) {
	for(Line l : doc.get_lines()) {
		for(auto x : l) os << x;
	}

	return os;
}

Text_iterator Document::find_char(Text_iterator first, Text_iterator last, char c) const {
	for(; first != last && *first != c; ++first);
	return first;
}

bool match(Text_iterator first, Text_iterator last, std::string s) {
	auto si = s.begin();
	
	for(auto ti = first;
		ti != last && 
		*ti == *si &&
		si != s.end(); ++si, ++ti);

	return si == s.end();
}

Text_iterator Document::find_txt(Text_iterator first, Text_iterator last, const std::string& s) const {
	if(s.size() == 0) return last;

	while(true) {
		auto p = std::find(first, last, s[0]);
		if(p == last || match(p, last, s)) return p;
		first = p+1;
	}
}