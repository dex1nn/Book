#include <iostream>


using namespace std;

class Book {
    char* author;
    char* name_book;
    char* publisher;
    short int year;
    int pages;

public:
    ~Book() {
        delete[] author;
        delete[] name_book;
        delete[] publisher;
    }

    Book(const char* author, const char* name_book, const char* publisher, short int year, int pages) {
        SetAutor(author);
        SetNameBook(name_book);
        SetPublisher(publisher);
        this->year = year;
        this->pages = pages;
    };

    void ShowBook() const {
        cout << "Author: " << author << endl;
        cout << "Book name: " << name_book << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;
        cout << "Pages: " << pages << endl;
    }

    void SetAutor(const char* a) {
        if (a) {
            author = new char[strlen(a) + 1];
            strcpy_s(author, strlen(a) + 1, a);
        }
    }

    void SetNameBook(const char* NB) {
        if (NB) {
            name_book = new char[strlen(NB) + 1];
            strcpy_s(name_book, strlen(NB) + 1, NB);
        }
    }

    void SetPublisher(const char* p) {
        if (p) {
            publisher = new char[strlen(p) + 1];
            strcpy_s(publisher, strlen(p) + 1, p);
        }
    }

    const char* getAutor() const { return author; }
    const char* getPublisher() const { return publisher; }
    int getYear() const { return year; }
};

int main() {
    Book books[5] = {
        Book("Itstep", "cppppppp", "Itstep", 1999, 253),
        Book("Itste", "cpppppp", "Itste", 1998, 263),
        Book("Itst", "cppppp", "Itst", 1997, 273),
        Book("Its", "cpppp", "Its", 1996, 283),
        Book("It", "cppp", "It", 1995, 293)
    };

    for (int i = 0; i < 5; i++) {
        books[i].ShowBook();
        cout << endl;
    }

    return 0;
}

