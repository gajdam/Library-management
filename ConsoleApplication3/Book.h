#include <iostream>
#include <fstream>
#include "Author.h"

using namespace std;

class Book
{
	private:
		string title;
		Author author;
		int distributionYear;
		string type;
        int bookId;
	public:
		string getTitle() {
			return title;
		}
		int getDistributionYear() {
			return distributionYear;
		}
		string getType() {
			return type;
		}
        int getBookId() {
            return bookId;
        }

		Book(int _bookId, string _title, Author _author,
			int _distributionYear, string _type) {
			title = _title;
			author = _author;
			distributionYear = _distributionYear;
			type = _type;
            bookId = _bookId;
		}

        void ShowBook()
        {
            cout<<"Book entitled "<< title << " written by " << author.getNameAuthor() <<" "<<author.getSurnameOfAuthor()<< "- year "<<distributionYear;
        }

        void SaveIntoFile() {
            ofstream file("SuppliesOfBooks.txt", ios::app);
            if (file.is_open()) {
                file<< bookId <<" "<< title << " " << author.getNameAuthor() <<  " " << author.getSurnameOfAuthor() <<" "<< distributionYear<<" " << type << endl;
            }
            else {
                cout << "err";
            }
        }
        static int AutoIncrementIdOfBook() {
            ifstream file("SuppliesOfBooks.txt");
            int bookid, distYear, temp;
            string titleOfBook, nameAuthor, surnameAuthor, typeOfBook;
            while (file >> bookid >> titleOfBook >> nameAuthor >> surnameAuthor >> distYear >> typeOfBook) {
                temp=bookid;
            }
            temp++;
            return temp;
        }


};

