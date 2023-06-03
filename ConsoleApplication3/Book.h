#include <iostream>
#include "Author.h"

using namespace std;

class Book
{
	private:
		string title;
		Author author;
		string distributionYear;
		string type;
        int bookId;
	public:
		string getTitle() {
			return title;
		}
		string getDistributionYear() {
			return distributionYear;
		}
		string getType() {
			return type;
		}
        int getBookId() {
            return bookId;
        }

		Book(string _title, Author _author,
			string _distributionYear, string _type, int _bookId) {
			title = _title;
			author = _author;
			distributionYear = _distributionYear;
			type = _type;
            bookId = _bookId;
		}

};

