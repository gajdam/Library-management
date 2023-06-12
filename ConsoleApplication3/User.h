#include <iostream>
#include <random>
#include <fstream>
#include <utility>

using namespace std;

class User {
protected:
    string name;
    string surname;
    int id;
    string password;
    int permissions;
public:
    User(int _id, string _password) {
        id = _id;
        password = std::move(_password);
        LoadToDataFile();
        permissions = 0;
    }

    int getPermissions() const {
        return permissions;
    }

    void SaveIntoFile() {
        ofstream file("Users.txt", ios::app);
        if (file.is_open()) {
            file << id << " " << name << " " << surname << " " << password << " "  << permissions << endl;
        }
        else {
            cout << "Error opening file." << endl;
        }
    }

    bool CheckIntoFile() {
        ifstream file("Users.txt");
        int idCheck;
        string nameCheck, surnameCheck, passwordCheck;
        while (file >> idCheck >> nameCheck >> surnameCheck >> passwordCheck >> permissions) {
            if (idCheck == id && passwordCheck == password) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    void LoadToDataFile() {
        ifstream file("Users.txt");
        int idCheck, permissionsCheck;
        string nameCheck, surnameCheck, passwordCheck;
        while (file >> idCheck >> nameCheck >> surnameCheck >> passwordCheck >> permissionsCheck) {
            if (idCheck == id) {
                name = nameCheck;
                surname = surnameCheck;
                permissions = permissionsCheck;
                break;
            }
        }
        file.close();
    }

    void setName(const string& _name) {
        name = _name;
    }

    void setSurname(const string& _surname) {
        surname = _surname;
    }
};
