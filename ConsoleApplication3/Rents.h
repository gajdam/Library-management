#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Rents {
    private:
        int rentId;
        int borrowerId;
        int bookId;
        string rentDate;
        string returnDate;

    public:

        Rents(int _rentId, int _borrowerId, int _bookId, char _rentDate[80], char _returnDate[80]) {
             rentId = _rentId;
            borrowerId = _borrowerId;
            bookId = _bookId;
            rentDate = _rentDate;
            returnDate = _returnDate;
        }

        static void showRentable(){
            ifstream file("SuppliesOfBooks.txt");
            string line;
            cout << "List of books to rent:" << endl;
            if(file.is_open()){
                while(getline(file, line)){
                    stringstream ss(line);
                    string oneVar;
                    vector<string> lineVars;

                    while(getline(ss, oneVar, ',')){
                        lineVars.push_back(oneVar);
                    }

                    if(lineVars[6] == "0"){
                        cout << lineVars[0] << ". \"" << lineVars[1] << "\": " << lineVars[2] << " " << lineVars[3] << " - " << lineVars[4] << endl;
                    }
                }
                file.close();
                cout << "Choose an id of a book you'd like to rent: ";
            }
            else{
                cout << "File could not open" << endl;
            }
         }

         void saveRentToFile(){
             ofstream file("BookRents.txt", ios::app);
             if (file.is_open()) {
                 file << rentId << "," << bookId << "," << borrowerId << "," << rentDate << "," << returnDate << endl;
                 cout << "Succesfully rented, you have time until: " << returnDate << endl;


             }
             else {
                 cout << "err";
             }
         }

        static int AutoIncrementIdOfRent() {
            ifstream file("BookRents.txt");
            int temp = 1;
            string line;
            while (getline(file, line)) {
                temp++;
            }
            return temp;
        }
};