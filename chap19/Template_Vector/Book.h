#pragma once
#include "vector.h"
#include <fstream>
#include <string>

struct My_Exception {};

struct Chapter {
	Chapter(std::string t, int i): title{t}, index{i} {
		if(t == "" || index <= 0) throw My_Exception{};
	}

	std::string title;
	int index;
};

struct Book {
	Book(Book& b) {
		Book(b.title, b.id);
	}

	Book(std::string t, int i): title{t}, id{i} {
		if(t == "") throw My_Exception{};
	}

	void add_from_record(std::string filename);
	void add_chap(Chapter& c) { chapters.push_back(c); }
	void add_chap(Chapter&& c) { chapters.push_back(c); }

	vector<Chapter> chapters;
	std::string title;
	int id;
};

void Book::add_from_record(std::string filename) {
    std::ifstream ist {filename};

	int i = 1;
    for(std::string t; std::getline(ist, t);) {
		add_chap({t, i});
		i++;
	}
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
	os << b.title << "\n";

	for (int i = 0; i < b.chapters.size(); ++i) {
		os << "\t" << b.chapters[i].index << ". " << b.chapters[i].title << "\n";
	}

	return os;
}