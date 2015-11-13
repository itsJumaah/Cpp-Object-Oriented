#include <iostream>
#include <string>

using namespace std;

void displayInfo();

class Media {
	private:
		int ID;
		string title;
		int year;
	
	public:
		Media(int inputID, string inputTitle, int inputYear) : ID(inputID), title(inputTitle), year(inputYear)
	{}
		void changeID(int newID);
		void print();
};

class DVD: public Media {
	private:
		string director;
	public:
		DVD(int inputID, string inputTitle, int inputYear, string inputDirector = "unknown") : director(inputDirector), Media(inputID, inputTitle, inputYear)
	{}
		void print();
};

class Book: public Media {
	private:
		string author;
		int numPages;
	public:
		Book(int inputID, string inputTitle, int inputYear, string inputAuthor, int inputNumPages) : author(inputAuthor), numPages(inputNumPages), Media(inputID, inputTitle, inputYear)
	{}
		void print();
};

class Journal: public Media {
	private:
		int volume;
		int number;
	public:
		Journal(int inputID, string inputTitle, int inputYear, int inputVolume, int inputNumber) : volume(inputVolume), number(inputNumber), Media(inputID, inputTitle, inputYear)
	{}
		void print();
};

int main() {
	displayInfo();
	Media *ptr[10];
	ptr[0] = new DVD(352, "Remember The Alamo", 1945, "George Smith");
	ptr[1] = new DVD(831, "High School Blues", 1984);
	ptr[2] = new DVD(194, "Going For The Touchdown", 1984, "Frank Madden");
	ptr[3] = new DVD(576, "Martian Hairdresser", 1992, "Debbie Gold");
	ptr[4] = new Book(608,"How to Make Money", 1987, "Phil Barton", 324);
	ptr[5] = new Book(442,"Garden Projects At Home", 1998, "Mary Freeman", 164);
	ptr[6] = new Book(185,"The Haunted House Mystery", 1996, "Bert Morgan", 53);
	ptr[7] = new Journal(294, "ACM", 2009, 6, 8);
	ptr[8] = new Journal(521, "J of Logic", 2008, 23, 14);
	ptr[9] = new Journal(630, "J of AI", 2009, 35, 11);
	cout << "Printing 10 items..." << endl << endl;
	for (int i = 0; i < 10; ++i) {
		ptr[i]->print();
	}
	ptr[3]->changeID(707);
	ptr[5]->changeID(808);
	ptr[7]->changeID(909);
	cout << endl << "Printing again..." << endl << endl;
	ptr[3]->print();
	ptr[5]->print();
	ptr[7]->print();
}

void displayInfo() {
	cout << "----------------------------------------" << endl;
	cout << " Bilal Jumaah, 12232659                 " << endl;
	cout << " 159.234 Assignment 3 2014 S1 Albany    " << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void changeID(int newID){

}

void Media::print(){
	cout << "ID " << ID << "Title " << title << "("  << year << ")";	
}

void Book::print(){
	cout << "Book: ";
	Media::print();
	cout << "By " << author << ", " << numPages << "pages";
}

void Journal::print(){
	cout << "Journal: ";
	Media::print();
	cout << "Volume: " << volume << ", Number: " << number;
}

void DVD::print(){
	cout << "DVD: ";
	Media::print();
	cout << "Directed by " << director;
}
