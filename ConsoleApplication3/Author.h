#pragma once
#include <iostream>
#include <utility>

using namespace std;

class Author
{
	private:
		string nameOfAuthor;
        string surnameOfAuthor;

	public:
		string getNameAuthor() {
			return nameOfAuthor;
		}
        string getSurnameOfAuthor(){
            return surnameOfAuthor;
        }
        void setNameAuthor(string _nameOfAuthor)
        {
            nameOfAuthor=std::move(_nameOfAuthor);
        }
        void setSurnameAuthor(string _surnameAuthor)
        {
            surnameOfAuthor=std::move(_surnameAuthor);
        }
};

