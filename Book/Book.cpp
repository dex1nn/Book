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

    explicit Book(const char* author, const char* name_book, const char* publisher, short int year, int pages) {
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


void BooksByAuthor(const Book books[], int size, const char* author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].getAutor(), author) == 0) {
            books[i].ShowBook();
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found." << endl;
}

void BooksByPublisher(const Book books[], int size, const char* publisher) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].getPublisher(), publisher) == 0) {
            books[i].ShowBook();
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found." << endl;
}

void BooksAfterYear(const Book books[], int size, int year) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].getYear() > year) {
            books[i].ShowBook();
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found." << endl;
}

int main() {
    const int SIZE = 5;
    Book books[SIZE] = {
        Book("Itstep", "C++ Basics", "StepPress", 1999, 253),
        Book("Smith", "OOP in C++", "TechBooks", 2005, 320),
        Book("Brown", "Algorithms", "StepPress", 2010, 500),
        Book("Smith", "Data Structures", "UniBooks", 2015, 410),
        Book("Clark", "C++ Advanced", "TechBooks", 2020, 600)
    };

    for (int i = 0; i < SIZE; i++) {
        books[i].ShowBook();
        cout << endl;
    }

    cout << "BooksByAuthor:\n";
    BooksByAuthor(books, SIZE, "Smith");
    cout << "BooksByPublisher:\n";
    BooksByPublisher(books, SIZE, "StepPress");
    cout << "BooksAfterYear:\n";
    BooksAfterYear(books, SIZE, 2000);

    return 0;
}

