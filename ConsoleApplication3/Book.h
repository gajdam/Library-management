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

		Book(string _title, Author _author,
			string _distributionYear, string _type) {
			title = _title;
			author = _author;
			distributionYear = _distributionYear;
			type = _type;
		}

};

