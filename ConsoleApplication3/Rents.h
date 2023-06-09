#include <iostream>
#include <ctime>

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
            rentDate.tm_year = year - 1900;
            rentDate.tm_mon = month - 1;
            rentDate.tm_mday = day;
        }
};