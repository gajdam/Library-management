#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Rents {
    private:
        int borrowerId;
        int bookId;
        tm rentDate{};

    public:
         [[nodiscard]] tm getRentDate() const {
            return rentDate;
        }

        Rents(int _borrowerId, int _bookId, int year, int month, int day) {
            borrowerId = _borrowerId;
            bookId = _bookId;
            rentDate.tm_year = year ;
            rentDate.tm_mon = month;
            rentDate.tm_mday = day;
        }




        static void showRentable(){
            ifstream file("SuppliesOfBooks.txt");
            string line;
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
            }
            else{
                cout << "File could not open" << endl;
            }
         }

         void saveRentToFile(){

         }
};