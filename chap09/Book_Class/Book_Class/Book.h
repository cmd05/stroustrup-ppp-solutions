#pragma once
//#include <iostream>
#include <string>
#include <vector>
#include "Chrono.h" /// includes chrono.h as Date class is used (part of chrono namespace)

/// date must be prequalified with Chrono since no using directive is used

namespace Library {
	enum class Genre {
		Fiction = 1, NonFiction, Periodical, Biography, Children
	};

	class Book {
	public:
		Book(std::string ISBN, std::string title, std::string author, Chrono::Date copyrightDate, Genre genre, bool checkedOut);
		Book(std::string ISBN, std::string title, std::string author, Chrono::Date copyrightDate, Genre genre);

		std::string getISBN() const;
		std::string getTitle() const;
		std::string getAuthor() const;
		Genre getGenre() const;
		Chrono::Date getCopyrightDate() const;
		int getBookId() const;

		bool isCheckedOut() const;
		void checkout();
		void setLibId(int n);

	private:
		int libraryId;
		std::string ISBN;
		std::string title;
		std::string author;
		Chrono::Date copyrightDate;
		Genre genre;
		bool checkedOut;

		bool checkISBN(std::string ISBN);
	};

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	std::ostream& operator<<(std::ostream& os, const Book& d);
	//std::istream& operator>>(std::istream& is, Book& dd);

	class Patron {
	public:
		Patron();
		Patron(std::string name, std::string libCardNum, int fees);
		Patron(std::string name, std::string libCardNum);

		std::string getName() const { return name; }
		std::string getLibCardNum() const { return libCardNum; }
		int getFees() const { return fees; }
		void setFees(int newFees) { fees = newFees; }
		bool owesFees() const { return (fees > 0); }

	private:
		std::string name;
		std::string libCardNum;
		int fees = 0;
	};

	class Lib {
	public:
		Lib(std::string libName);

		std::string getLibName() const { return libName; }
		void addBook(std::string ISBN, std::string title, std::string author, Chrono::Date copyrightDate, Genre genre);
		void addPatron(std::string name, std::string libCardNum);
		void createTransaction(std::string ISBN, std::string libCardNum);
		void checkout(std::string cardNum, int libBookId, Chrono::Date dt);
		bool patronExists(std::string cardNum);
		void listBooks();
	private:
		std::string libName;

		std::vector<Book> books;
		std::vector<Patron> patrons;
		std::vector<Chrono::Date> dates;

		struct Transaction { /// define a new struct inside class 
			int bookId;
			std::string patronId;
			Chrono::Date date;
			bool isReturned = false;
		};
		std::vector<Transaction> transactions;
	};
};