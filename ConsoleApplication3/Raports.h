#include <iostream>
#include <fstream>


using namespace std;

class Raports {
    private:

    public:
    Raports()
    {

    }

    static void CountSupplies()
    {
        ifstream file("SuppliesOfBooks.txt");
        int i=0;
        int bookid, distYear;
        string titleOfBook, nameAuthor, surnameAuthor, typeOfBook;
        string isRent;
        while (file >> bookid >> titleOfBook >> nameAuthor >> surnameAuthor >> distYear >> typeOfBook>>isRent)
        {
            if (isRent == "0")
            {
                i++;
            }
        }
        cout<<"All supplies are "<<i<<endl;
    }
    static void CountSuppliesByTitle(string title)
    {
        ifstream file("SuppliesOfBooks.txt");
        int i=0;
        int bookid, distYear;
        string titleOfBook, nameAuthor, surnameAuthor, typeOfBook;
        string isRent;
        while (file >> bookid >> titleOfBook >> nameAuthor >> surnameAuthor >> distYear >> typeOfBook>>isRent)
        {
            if (isRent == "0" && titleOfBook==title)
            {
                i++;
            }
            cout<<"The supplies of "<< title<<" supplies are "<<i<<endl;
        }
    }

};

