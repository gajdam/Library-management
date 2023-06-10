#include <iostream>
#include <random>
#include <fstream>
#include "User.h"
#include "Rents.h"
#include "Author.h"
#include "Book.h"

using namespace std;

void signIn() {
    int id;
    string password;

    cout << "enter your id: ";
    cin >> id;
    cout << "enter password: ";
    cin >> password;

    User user(id, password);
    if (user.CheckIntoFile()) {
        cout << "Login Successful!" << endl;
    }
    else {
        cout << "Invalid ID or password. Please try again." << endl;
    }
}

void signUp() {
    string name, surname, password;
    int id;

    cout << "set name: ";
    cin >> name;
    cout << "set surname: ";
    cin >> surname;
    cout << "set password: ";
    cin >> password;

    id = rand() % 1000 + 1;

    User user(id, password);
    user.setName(name);
    user.setSurname(surname);
    user.SaveIntoFile();

    cout << "Account Created Successfully!" << endl;
    cout << "Your id is: " << id << endl;
}

void addBook() {
    Author author;
    string title, authorName, authorSurname, typeOfBook;
    int distYear, idOfBook;

    cout << "Set title: ";
    cin >> title;
    cout << "Set name of the author: ";
    cin >> authorName;
    cout << "Set surname of the author: ";
    cin >> authorSurname;
    cout << "Set distribution year: ";
    cin >> distYear;
    cout << "Set type of the book: ";
    cin >> typeOfBook;

    author.setNameAuthor(authorName);
    author.setSurnameAuthor(authorSurname);

    idOfBook = Book::AutoIncrementIdOfBook();
    Book book(idOfBook, title, author, distYear, typeOfBook);
    book.SaveIntoFile();
    book.ShowBook();
}

int main() {
    int choice = 0, id = 0, distYear, idOfBook;
    string nameAuthor, surnameAuthor;
    srand(time(NULL));

    Author author;
    string title, typeOfBook;

    cout << "1. Sign In" << endl;
    cout << "2. Sign up" << endl;
    cin >> choice;

    if (choice == 1) {
        signIn();
    }
    else if (choice == 2) {
        signUp();
    }
    else if (choice == 3) {
        addBook();
    }
    else if (choice == 4) {
        int borrowerId = 1;
        int bookId = 2;
        int year = 2023;
        int month = 6;
        int day = 3;

        Rents rents(borrowerId, bookId, year, month, day);
        std::tm rentDate = rents.getRentDate();
        std::cout << "Date of rent: " << rentDate.tm_year << "-" << rentDate.tm_mon << "-" << rentDate.tm_mday << std::endl;


    }
    else {
        cout << "bye";
        return 0;
    }

    return 0;
}
