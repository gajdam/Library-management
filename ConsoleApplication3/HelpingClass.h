#include <iostream>
#include <string>
#include <string>

using namespace std;
class HelpingClass {
public:
    static string ConcatingTitles(const string& title)
    {
        string result;
        for(char i : title)
        {
            if(isspace(i))
            {
                result+="_";
            }
            else
            {
                result+=i;
            }
        }
        return result;
    }
};

