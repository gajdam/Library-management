#include <iostream>
#include <random>
#include <fstream>
using namespace std;
class Usser {
private:
    string imie;
    string nazwisko;
    int id;
    string has�o;
    bool loginSuccess;

public:

    string getImie() { return imie; }
    void setImie(string _imie) { imie = _imie; }

    string getNazwisko() { return nazwisko; }
    void setNazwisko(string _nazwisko) { nazwisko = _nazwisko; }

    int getId() { return id; }
    void setId(int _id) { id = _id; }

    string getHaslo() { return has�o; }
    void setHaslo(string _haslo) { has�o = _haslo; }

    Usser(string _imie, string _nazwisko, int _id, string _has�o) {
        imie = _imie;
        nazwisko = _nazwisko;
        id = _id;
        has�o = _has�o;
    }

    void SaveIntoFile() {
        ofstream file("Users.txt", ios::app);
        if (file.is_open()) {
            file << imie << " " << nazwisko << " " << id << " " << has�o << endl;
        }
        else {
            cout << "err";
        }
    }

    bool CheckIntoFile(string _imie, string _nazwisko, int _id, string _haslo) {
        ifstream file("users.txt");
        string imie, nazwisko, haslo;
        while (file >> imie >> nazwisko >> id >> haslo) {
            if (imie == _imie && nazwisko == _nazwisko && id == _id && haslo == _haslo) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }


};
