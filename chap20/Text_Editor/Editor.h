#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>

#include <iostream>

using Line = std::vector<char>;

//================================================================================
// class Text_iterator
//================================================================================

class Text_iterator {
	std::list<Line>::iterator In;
	Line::iterator pos;
public:
	// typedefs
	using iterator_category = std::input_iterator_tag;
    using value_type = char;
    using difference_type = std::ptrdiff_t;
    using pointer = char*;
    using reference = char&;

    // constructor
	Text_iterator(std::list<Line>::iterator II, Line::iterator pp): In{II}, pos{pp} {}

	// access operators
	char& operator*() { return *pos; }
	char* operator->() { return &(*pos); }	
	
	// increment and decrement operations
	Text_iterator& operator++();
	Text_iterator& operator--();

	Text_iterator& operator++(int) { return ++(*this); }
	Text_iterator& operator--(int) { return --(*this); }

	// comparison operators
	bool operator==(const Text_iterator& other) const { return In==other.In && pos==other.pos; }
	bool operator!=(const Text_iterator& other) const { return !(*this == other); }

	// get iterator details
	const std::list<Line>::iterator& get_line() const { return In; }
	const Line::iterator& get_pos() const { return pos; }
};

/// --------------------------------------------------------------------------------

Text_iterator& Text_iterator::operator++() {
	++pos;

	// if iterator points to last character of any given line
	if(pos == (*In).end()) {
		++In; // proceed to next line
		pos = (*In).begin();
	}

	return *this;
}

Text_iterator& Text_iterator::operator--() {
	// if iterator points to first character of any given line 
	if(pos==(*In).begin()) {
		--In; // proceed to prev line
		pos = (*In).end() - 1;
	} else 
		--pos;

	return *this;
}

Text_iterator operator+(Text_iterator& a, int n) {
	Text_iterator b = a;
	for(; n > 0; n--, ++b);

	return b;
}

Text_iterator operator-(Text_iterator& a, int n) {
	Text_iterator b = a;
	for(; n > 0; n--, --b);

	return b;
}

/// --------------------------------------------------------------------------------

//================================================================================
// class Document
//================================================================================

class Document {
public:	
	Document() { lines.push_back(Line{}); }

	/// return iterators
	Text_iterator begin() // first char of first line
		{ return Text_iterator( lines.begin(), (*lines.begin()).begin() ); } 

	Text_iterator end() // one beyond last char of last line
	{ 
		auto last_line = lines.end();
		last_line--;
		return Text_iterator( last_line, (*last_line).end() ); 
	}

	/// get operations
	int line_count() const { return lines.size(); }
	int char_count() const;
	void line_char_count(int n) const;
	std::list<Line>& get_lines() { return lines; } 
	
	/// read operations
	Text_iterator find(Text_iterator first, Text_iterator last, char c) const;
	Text_iterator find(Text_iterator first, Text_iterator last, const std::string& s) const;

	/// write operations
	void erase_line(int n);
	void erase_line(Text_iterator& it);
	Text_iterator erase(Text_iterator pos);

	// insert (index before iterator) a character at a given position
	bool insert_char(Text_iterator pos, char c);
	// add (index after iterator) a character at a given position
	bool add_char(Text_iterator pos, char c) { ++pos; return insert_char(pos, c); }

	// replace a character at a given position with another character
	void replace_at(Text_iterator pos, char c) { *(pos.get_pos()) = c; }

	// insert (index before iterator) a string at a given position
	bool insert_str(Text_iterator pos, std::string s);
	// add (index after iterator) a string at a given position
	bool add_str(Text_iterator pos, std::string s) { ++pos; return insert_str(pos, s); }

	/**
	 * Replace n occurences of string search with string rep within subject [first, last)
	 * n = -1; Replace all occurences of search
	 * Returns iterator at the end of where last replace occured
	 */
	Text_iterator replace(Text_iterator first, Text_iterator last, 
		const std::string& search, const std::string& rep, int n = -1);
private:
	std::list<Line> lines;
};

int Document::char_count() const {
	return std::accumulate(lines.begin(), lines.end(), 0,
	    [](int x, Line y) { return x + y.size(); }
    );
}

/// --------------------------------------------------------------------------------

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

/// --------------------------------------------------------------------------------

Text_iterator Document::find(Text_iterator first, Text_iterator last, char c) const {
	for(; first != last && *first != c; ++first);
	return first;
}

bool match(Text_iterator first, Text_iterator last, std::string s) {
	auto si = s.begin();
	
	for(
		auto ti = first;
		ti != last && 
		*ti == *si &&
		si != s.end(); ++si, ++ti
	);

	return si == s.end();
}

Text_iterator Document::find(Text_iterator first, Text_iterator last, const std::string& s) const {
	if(s.size() == 0) return last;

	while(true) {
		auto p = std::find(first, last, s[0]);
		if(p == last || match(p, last, s)) return p;
		first = p + 1;
	}
}

/// --------------------------------------------------------------------------------

bool Document::insert_char(Text_iterator pos, char c) {
	// lines must end with newline character
	auto vi = pos.get_pos();
	Line& v = *(pos.get_line());
	
	if(vi == v.end()) return false;

	v.insert(vi,c);

	return true;
}

bool Document::insert_str(Text_iterator pos, std::string s) {
	for(char c : s) {
		if(!insert_char(pos, c)) return false;
		pos++;
	}

	return true;
}

/// --------------------------------------------------------------------------------

Text_iterator Document::erase(Text_iterator pos) {
	auto vi = pos.get_pos();
	auto ii = pos.get_line();
	Line& v = *(pos.get_line());
	int index = vi - v.begin();

	if(vi == v.end()) return end();

	v.erase(vi);

	return {ii, v.begin() + index};
}

void Document::erase_line(Text_iterator& it) {
	if(line_count() == 1) return;

	auto last_line = lines.end();
	last_line--;
	if(it.get_line() == last_line) return;

	lines.erase(it.get_line());
}

void Document::erase_line(int n) {
	if(n < 0 || line_count()-1 <= n) return;
	auto p = lines.begin();
	std::advance(p, n);
	lines.erase(p);
}

/// --------------------------------------------------------------------------------

// NOT OPTIMIZED COMPLETELY!!!1!1!

Text_iterator Document::replace(Text_iterator first, Text_iterator last,
	const std::string& search, const std::string& rep, int n) {
	bool replace_all = (n == -1);
	
	if(n <= 0 && !replace_all) return last; // invalid value of n

	// iterate over [first, last) using p
	Text_iterator p = first;

	// exit if no match is found OR replace has occurred n times
	while( (p = find(p, last, search)) != last && (replace_all || n--) ) {
		// check if replace string is larger than search string
		bool rep_larger = (search.size() <= rep.size());
		int lim = (rep_larger) ? search.size() : rep.size();

		// replace characters of search with replace till end of either string
		int i = 0;
		for(; i < lim; i++, ++p) replace_at(p, rep[i]);

		if(rep_larger) {
			--p; // point to last replaced character

			// add remaining characters in replace string to document
			for (int j = i; j < rep.size(); ++j, ++p)
				add_char(p, rep[j]);
		} else {
			// remove excess characters in search string
			for (int j = i; j < search.size(); ++j)
				p = erase(p);
		}
	}

	// return iterator to end of last replaced string
	return p;
}