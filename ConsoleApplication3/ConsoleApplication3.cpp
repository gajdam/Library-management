#include <iostream>
#include <random>
#include <fstream>
#include "User.cpp"
#include "Rents.h"
#include "Author.h"
#include "Book.h"

using namespace std;

int main() {
	int choice = 0, id = 0, distYear, idOfBook;
	string name, surr, password, nameAuthor, surnameAuthor;
	srand(time(NULL));
    Author author;
    string title, typeOfBook;
	cout << "1 Sign In - 2 Sign up";
	cin >> choice;
	if (choice == 1) {
		cout << "Enter Your Name: ";
		cin >> name;
		cout << "Enter Your SurrName: ";
		cin >> surr;
		cout << "Enter ID";
		cin >> id;
		cout << "Enter Your Password: ";
		cin >> password;
		User user(id, name, surr, password);
		if (user.CheckIntoFile()) {
			cout << "Login Successful!" << endl;
		}
		else {
			cout << "Invalid username, surrname, id or password. Please try again." << endl;
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
		User user(id, name, surr, password);
		user.SaveIntoFile();
		cout << "Account Created Succesfully!"<<endl;
        cout<<"Your id is" << " "<< id;
	}
    if (choice == 3)
    {
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

        idOfBook= Book::AutoIncrementIdOfBook();
        Book book(idOfBook, title, author, distYear, typeOfBook);
        book.SaveIntoFile();
        book.ShowBook();
    }


    if (choice == 4) //
    {
        int borrowerId = 1;
        int bookId = 2;
        int year = 2023;
        int month = 6;
        int day = 3;

        Rents rents(borrowerId, bookId, year, month, day);
        std::tm rentDate = rents.getRentDate();
        std::cout << "Date of rent: " << rentDate.tm_year << "-" << rentDate.tm_mon << "-" << rentDate.tm_mday << std::endl;

    }
	return 0;
}