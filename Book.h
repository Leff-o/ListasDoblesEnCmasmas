//
// Created by Biss on 3/09/2021.
//

#ifndef LINKDOUBLE_BOOK_H
#define LINKDOUBLE_BOOK_H

#include <string>
#include <ostream>
// Holaaaaaaaaaa
class Book {
public:
    Book();

    Book(const std::string &ISBN, const std::string &title, const std::string &author, int pages, int year);

    const std::string &getISBN() const;

    void setISBN(const std::string &ISBN);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getAuthor() const;

    void setAuthor(const std::string &author);

    int getPages() const;

    void setPages(int pages);

    int getYear() const;

    void setYear(int year);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    virtual ~Book();

private:
    std::string ISBN;
    std::string title;
    std::string author;
    int pages;
    int year;
};


#endif //LINKDOUBLE_BOOK_H
