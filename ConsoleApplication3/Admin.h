#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
#include "Raports.h"
#include <sstream>

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
        cout << "2. Show Reports about supplies" << endl;
        cout << "3. Show Reports about supplies by title" << endl;
        cin >> choice;
        string title;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                Raports:: Raports::CountSupplies();
                break;
            case 3:
                cout << "About which title you want to get report?" << endl;
                cin.ignore();
                getline(cin, title);
                Raports::CountSuppliesByTitle(title);
                break;
            case 4:
                Raports::RaportForAdmin();
                break;
            case 5:
                Raports::RaportOfRents();
                break;
        }
    }
};