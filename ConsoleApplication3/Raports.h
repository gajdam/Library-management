#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

class Raports {
    public:

    static void CountSupplies()
    {
        string line;
        ifstream file("SuppliesOfBooks.txt");
        int i=0;
        while(getline(file, line)){
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while(getline(ss, oneVar, ',')){
                lineVars.push_back(oneVar);
            }
            if(lineVars[6] == "0"){
                i++;
            }
        }
        cout<<"All supplies are "<<i<<endl;
    }
    static void CountSuppliesByTitle(string title)
    {
        ifstream file("SuppliesOfBooks.txt");
        int i=0;
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;

            while(getline(ss, oneVar, ',')){
                lineVars.push_back(oneVar);
            }

            if(lineVars[6] == "0"&&lineVars[1]==title){
                i++;
            }
        }
        cout<<"Amout of "<<title<<" is "<<i<<endl;
    }
    static void RaportForAdmin()
    {
        ifstream file("SuppliesOfBooks.txt");
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string oneVar;
            vector<string> lineVars;
            while(getline(ss, oneVar, ',')){
                lineVars.push_back(oneVar);
            }

            if (lineVars[6]=="0")
            {
                cout<<"\x1B[32mOK \033[0m"<<"book entitled "<<lineVars[1]<<" written by "<<lineVars[2]<<" "<<lineVars[3]<< " established in "<<lineVars[4]<<" \x1B[32mis rentable\033[0m"<<endl;
            }
            else
            {
                cout<<"\x1B[31mX  \033[0m"<<"book entitled "<<lineVars[1]<<" written by "<<lineVars[2]<<" "<<lineVars[3]<< " established in "<<lineVars[4]<<" \x1B[31misn't avalible to rent\033[0m"<<endl;
            }
        }
    }


};