#include <iostream>
#include <random>
#include <fstream>
#include "Usser.cpp"
using namespace std;



int main() {
	int choise = 0, id = 0;
	string name, surr, password;
	srand(time(NULL));
	cout << "1 Sign In - 2 Sign up";
	cin >> choise;
	if (choise == 1) {
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
	if (choise == 2) {
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
	return 0;
}