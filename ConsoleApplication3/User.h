#include <iostream>
#include <random>
#include <fstream>
#include <utility>
using namespace std;
class User {
    private:
        string name;
        string surname;
        int id;
        string password;
        bool loginSuccess{};

    public:


        User(int _id, string _name, string _surname, string _password) {
            name = std::move(_name);
            surname = std::move(_surname);
            id = _id;
            password = std::move(_password);
        }

        void SaveIntoFile() {
            ofstream file("Users.txt", ios::app);
            if (file.is_open()) {
                file<< id<<" "<< name << " " << surname <<  " " << password << endl;
            }
            else {
                cout << "err";
            }
        }

        bool CheckIntoFile() {
            ifstream file("users.txt");
            int idCheck;
            string nameCheck, surnameCheck, passwordCheck;
            while (file >> idCheck >> nameCheck >> surnameCheck >> passwordCheck) {
                if (nameCheck == name && surnameCheck == surname && idCheck == id && passwordCheck == password) {
                    file.close();
                    return true;
                }
            }
            file.close();
            return false;
        }


};
