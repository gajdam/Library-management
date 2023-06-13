#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;
void addBook() {
    Author author;
    string title, authorName, authorSurname, typeOfBook;
    int distYear, idOfBook;

    cout << "Set title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Set name of the author: ";
    getline(cin, authorName);
    cout << "Set surname of the author: ";
    getline(cin, authorSurname);
    cout << "Set distribution year: ";
    cin >> distYear;
    cout << "Set type of the book: ";
    cin.ignore();
    getline(cin, typeOfBook);

    author.setNameAuthor(authorName);
    author.setSurnameAuthor(authorSurname);

    idOfBook = Book::AutoIncrementIdOfBook();
    Book book(idOfBook, title, author, distYear, typeOfBook);
    book.SaveIntoFile();
    book.ShowBook();
}


class Admin {
public:
      void AdminMenu() {
        int choice = 0;
        cout << "Select Option From Menu"<<endl;
        cout << "1. Add Book" << endl;
        cout << "2. Show Reports" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                break;
        }
    }
};