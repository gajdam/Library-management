#include <iostream>
#include <random>
#include <fstream>
#include "Rents.h"
#include "Author.h"
#include "Admin.h"

using namespace std;

int signIn() {
    int id = 0;
    string password;

    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;

    User user(id, password);
    if (user.CheckIntoFile()) {
        if (user.getPermissions() == 1) {
            cout << "Welcome, admin!" << endl;
            Admin admin;
            admin.AdminMenu();
        } else {
            cout << "Welcome, user!" << endl;
        }
    }
    else {
        cout << "Invalid ID or password. Please try again." << endl;
    }
    return id;
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



void rentABook(int userId) {
    int idOfRent, bookId;
    Rents::showRentable();
    cin.ignore();
    cin >> bookId;
    time_t now = time(0);
    struct tm gmtm = *localtime(&now);
    char rentDate[80];
    char returnDate[80];
    strftime(rentDate, sizeof(rentDate), "%Y-%m-%d", &gmtm);
    gmtm.tm_mon += 1;
    strftime(returnDate, sizeof(returnDate), "%Y-%m-%d", &gmtm);

    idOfRent = Rents::AutoIncrementIdOfRent();
    Rents rent(idOfRent, userId, bookId, rentDate, returnDate);
    rent.saveRentToFile();
}

void RentedBook(int userId) {
    ifstream file("BookRents.txt");
    string line;
    bool found = false;

    cout << "Your rented books:" << endl;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }

            if (stoi(lineVars[2]) == userId) {
                ifstream bookFile("SuppliesOfBooks.txt");
                string bookLine;

                if (bookFile.is_open()) {
                    while (getline(bookFile, bookLine)) {
                        stringstream bookSS(bookLine);
                        string bookVar;
                        vector<string> bookVars;

                        while (getline(bookSS, bookVar, ',')) {
                            bookVars.push_back(bookVar);
                        }

                        if (stoi(bookVars[0]) == stoi(lineVars[1])) {
                            cout << "- \"" << bookVars[1] << "\": " << bookVars[2] << " " << bookVars[3] << " - " << bookVars[4] << endl;
                            found = true;
                            break;
                        }
                    }

                    bookFile.close();
                }
            }
        }
        file.close();

        if (!found) {
            cout << "You haven't rented any books yet." << endl;
        }
    }
    else {
        cout << "File could not open" << endl;
    }
}


int main() {
    string choice;
    int userID = 0;
    string nameAuthor, surnameAuthor;
    srand(time(NULL));

    Author author;
    string title, typeOfBook;

    cout << "1. Sign In" << endl;
    cout << "2. Sign up" << endl;
    cout << "Choose: ";

    while(userID == 0) {
        getline(cin, choice);
        if (choice == "1") {
            userID = signIn();
        }
        else if (choice == "2") {
            signUp();
        }
        else
            cout << "There's no such option, try again!: ";
    }
    //system("cls");

    do {
        cout << "Welcome to the book library!!" << endl;
        cout << "1. Rent a book" << endl;
        cout << "2. Show your rented books" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        if (choice == "1") {
            rentABook(userID);
        }
        else if (choice == "2") {
            RentedBook(userID);
        }
    } while(choice != "3");
    cout << "Goodbye!" << endl;

    return 0;
}
