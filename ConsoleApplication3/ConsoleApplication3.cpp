#include <iostream>
#include <random>
#include <fstream>
#include "Usser.cpp"
#include "Rents.h"
using namespace std;


int main() {
	int choice = 0, id = 0;
	string name, surr, password;
	srand(time(NULL));
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
		Usser user(name, surr, id, password);
		if (user.CheckIntoFile(name, surr, id, password)) {
			cout << "Login Successful!" << endl;
		}
		else {
			cout << "Invalid username, surrname, id or password. Please try again." << endl;
		}
	}
	if (choice == 2) {
		cout << "Set Name: ";
		cin >> name;
		cout << "Set SurrName: ";
		cin >> surr;
		cout << "Set Password: ";
		cin >> password;
		int iSecret = rand() % 1000 + 1;
		id = iSecret;
		Usser user(name, surr, id, password);
		user.SaveIntoFile();
		cout << "Account Created Succesfully!";
	}

    if (choice == 3) //
    {
        int borrowerId = 1;
        int bookId = 2;
        int year = 2023;
        int month = 6;
        int day = 3;

        Rents rents(borrowerId, bookId, year, month, day);
        std::tm rentDate = rents.getRentDate();
        std::cout << "Data wypożyczenia: " << rentDate.tm_year + 1900 << "-" << rentDate.tm_mon + 1 << "-" << rentDate.tm_mday << std::endl;

    }
	return 0;
}