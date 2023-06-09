#include <iostream>
#include <random>
#include <fstream>
#include "User.h"
#include "Rents.h"
#include "Author.h"
#include "Book.h"

using namespace std;

//void displayUserOptions(const User& user) {
//    // Opcje dla u¿ytkownika biblioteki
//    cout << "User Options" << endl;
//    cout << "1. Option 1" << endl;
//    cout << "2. Option 2" << endl;
//    // ...
//
//    // Opcje dla pracownika biblioteki
//    if (user.getPermission() == 1) {
//        cout << "Staff Options" << endl;
//        cout << "3. Option 3" << endl;
//        cout << "4. Option 4" << endl;
//        // ...
//    }
//
//    cout << "0. Exit" << endl;
//}

int main() {
    int choice = 0, id = 0, distYear, idOfBook;
    string name, surr, password, nameAuthor, surnameAuthor;
    srand(time(NULL));

    Author author;
    string title, typeOfBook;

    cout << "1. Sign In" << endl;
    cout << "2. Sign up" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Your Password: ";
        cin >> password;

        User user(id, password);
        if (user.CheckIntoFile()) {
            cout << "Login Successful!" << endl;
//            displayUserOptions(user);
        }
        else {
            cout << "Invalid ID or password. Please try again." << endl;
        }
    }

    if (choice == 2) {
        cout << "Set Name: ";
        cin >> name;
        cout << "Set Surname: ";
        cin >> surr;
        cout << "Set Password: ";
        cin >> password;

        int iSecret = rand() % 1000 + 1;
        id = iSecret;

        int permission = 0;
        User user(id, password);
        user.setName(name); // Ustawiamy imiê
        user.setSurname(surr); // Ustawiamy nazwisko
        user.SaveIntoFile();

        cout << "Account Created Successfully!" << endl;
        cout << "Your id is: " << id << endl;
//        displayUserOptions(user);
    }

    if (choice == 3) {
        cout << "Set title: ";
        cin >> title;
        cout << "Set name of the author: ";
        cin >> nameAuthor;
        cout << "Set surname of the author: ";
        cin >> surnameAuthor;
        cout << "Set distribution year: ";
        cin >> distYear;
        cout << "Set type of the book: ";
        cin >> typeOfBook;

        author.setNameAuthor(nameAuthor);
        author.setSurnameAuthor(surnameAuthor);

        idOfBook = Book::AutoIncrementIdOfBook();
        Book book(idOfBook, title, author, distYear, typeOfBook);
        book.SaveIntoFile();
        book.ShowBook();

        // Warunki dla u¿ytkownika biblioteki
        // ...
    }

    if (choice == 4) {
        int borrowerId = 1;
        int bookId = 2;
        int year = 2023;
        int month = 6;
        int day = 3;

        Rents rents(borrowerId, bookId, year, month, day);
        std::tm rentDate = rents.getRentDate();
        std::cout << "Date of rent: " << rentDate.tm_year << "-" << rentDate.tm_mon << "-" << rentDate.tm_mday << std::endl;

        // Warunki dla u¿ytkownika biblioteki
        // ...
    }

    return 0;
}
