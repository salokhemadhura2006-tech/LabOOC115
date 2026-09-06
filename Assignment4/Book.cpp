#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string bookName;
    string author;
    bool issued;

public:
    LibraryBook(string name, string auth) {
        bookName = name;
        author = auth;
        issued = false;
    }

    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book issued successfully!" << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "Book is already available." << endl;
        }
    }

    void displayBook() {
        cout << "\nBook Name: " << bookName << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

int main() {
    LibraryBook book1("C++ Programming", "Bjarne Stroustrup");

    book1.displayBook();

    book1.issueBook();
    book1.displayBook();

    book1.returnBook();
    //<<"Author:",<<book1.author
    book1.displayBook();

    return 0;
}