//
// Created by gajda on 12.06.2023.
//

#ifndef LIBRARY_MANAGEMENT_ADMIN_H
#define LIBRARY_MANAGEMENT_ADMIN_H


#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"

using namespace std;

class Admin : public User {
    private:
        int id;
        string password, name, surname;

//    void addBook() {
//        Author author;
//        string title, authorName, authorSurname, typeOfBook;
//        int distYear, idOfBook;
//
//        cout << "Set title: ";
//        cin >> title;
//        cout << "Set name of the author: ";
//        cin >> authorName;
//        cout << "Set surname of the author: ";
//        cin >> authorSurname;
//        cout << "Set distribution year: ";
//        cin >> distYear;
//        cout << "Set type of the book: ";
//        cin >> typeOfBook;
//
//        author.setNameAuthor(authorName);
//        author.setSurnameAuthor(authorSurname);
//
//        idOfBook = Book::AutoIncrementIdOfBook();
//        Book book(idOfBook, title, author, distYear, typeOfBook);
//        book.SaveIntoFile();
//        book.ShowBook();
//    }

};


#endif //LIBRARY_MANAGEMENT_ADMIN_H
