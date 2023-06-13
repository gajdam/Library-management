#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

class Raports {
public:

    static void CountSupplies() {
        string line;
        ifstream file("SuppliesOfBooks.txt");
        int i = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }
            if (lineVars[6] == "0") {
                i++;
            }
        }
        cout << "All supplies are " << i << endl;
    }

    static void CountSuppliesByTitle(string title) {
        ifstream file("SuppliesOfBooks.txt");
        int i = 0;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }

            if (lineVars[6] == "0" && lineVars[1] == title) {
                i++;
            }
        }
        cout << "Amout of " << title << " is " << i << endl;
    }

    static void RaportForAdmin() {
        ifstream file("SuppliesOfBooks.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;
            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }

            if (lineVars[6] == "0") {
                cout << "\x1B[32mOK \033[0m" << "book entitled " << lineVars[1] << " written by " << lineVars[2] << " "
                     << lineVars[3] << " established in " << lineVars[4] << " \x1B[32mis rentable\033[0m" << endl;
            } else {
                cout << "\x1B[31mX  \033[0m" << "book entitled " << lineVars[1] << " written by " << lineVars[2] << " "
                     << lineVars[3] << " established in " << lineVars[4] << " \x1B[31misn't avalible to rent\033[0m"
                     << endl;
            }
        }
    }

    static void RaportOfRents() {
        ifstream file("BookRents.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }

            string rentId = lineVars[0];
            string bookId = lineVars[1];
            string borrowerId = lineVars[2];
            string rentDate = lineVars[3];
            string returnDate = lineVars[4];

            cout << "Rent ID: " << rentId << endl;
            cout << "Book title: " << getBookById(bookId) << endl;
            cout << "Borrower username: " << getUserById(borrowerId) << endl;
            cout << "Rent Date: " << rentDate << endl;
            cout << "Return Date: " << returnDate << endl;


            if (isDateToDay(returnDate)) {
                cout << "\x1B[33mStatus: Book is due today!\033[0m" << endl;
            } else if (isDateOverdue(returnDate)) {
                cout << "\x1B[31mStatus: Book is overdue!\033[0m" << endl;
            } else {
                cout << "\x1B[32mStatus: Book is not yet due.\033[0m" << endl;
            }
            cout<<endl;

        }
    }

    private:
        static string getUserById(string userId) {
            ifstream file("Users.txt");
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string oneVar;
                vector<string> lineVars;

                while (getline(ss, oneVar, ' ')) {
                    lineVars.push_back(oneVar);
                }
                if(lineVars[0]==userId)
                {
                    return lineVars[1];
                }
            }
        return "No User";
    }
    static bool isDateToDay(const std::string& returnDate)
    {
        std::tm tmReturnDate = {};
        std::istringstream iss(returnDate);
        iss >> std::get_time(&tmReturnDate, "%Y-%m-%d");

        if (iss.fail()) {
            return false;
        }

        std::time_t timeReturnDate = std::mktime(&tmReturnDate);
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);

        return localTime->tm_year == tmReturnDate.tm_year &&
               localTime->tm_mon == tmReturnDate.tm_mon &&
               localTime->tm_mday == tmReturnDate.tm_mday;
    }

    static bool isDateOverdue(string returnDate)
    {
        std::tm tmReturnDate = {};
        std::istringstream iss(returnDate);
        iss >> std::get_time(&tmReturnDate, "%Y-%m-%d");

        std::time_t timeReturnDate = std::mktime(&tmReturnDate);
        std::time_t currentTime = std::time(nullptr);
        return timeReturnDate < currentTime;
    }
    static string getBookById(string bookId)
    {
        ifstream file("SuppliesOfBooks.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;
            while (getline(ss, oneVar, ',')) {
                lineVars.push_back(oneVar);
            }

            if (lineVars[0] == bookId) {
                return lineVars[1];
            }
        }
        return "No such a book in a base";
    }



};
