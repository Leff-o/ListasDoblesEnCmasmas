//
// Created by Biss on 3/09/2021.
//

#include "Book.h"

Book::Book() {}

Book::Book(const std::string &ISBN, const std::string &title, const std::string &author, int pages, int year) : ISBN(
        ISBN), title(title), author(author), pages(pages), year(year) {}

const std::string &Book::getISBN() const {
    return ISBN;
}

void Book::setISBN(const std::string &ISBN) {
    Book::ISBN = ISBN;
}

const std::string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string &title) {
    Book::title = title;
}

const std::string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string &author) {
    Book::author = author;
}

int Book::getPages() const {
    return pages;
}

void Book::setPages(int pages) {
    Book::pages = pages;
}

int Book::getYear() const {
    return year;
}

void Book::setYear(int year) {
    Book::year = year;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << "ISBN: " << book.ISBN << " title: " << book.title << " author: " << book.author << " pages: " << book.pages
       << " year: " << book.year;
    return os;
}

Book::~Book() {

}