#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author) {
    this->title = title;
    this->author = author;
    this->isAvailable = true;  // Boken är tillgänglig vid skapandet
}

void Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;  // Gör boken otillgänglig
        std::cout << "You have borrowed: " << title << " by " << author << "\n";
    } else {
        std::cout << "Sorry, the book is currently unavailable.\n";
    }
}

void Book::returnBook() {
    isAvailable = true;  // Gör boken tillgänglig igen
    std::cout << "You have returned: " << title << "\n";
}

void Book::displayBookInfo() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
}

bool Book::checkAvailability() const {
    return isAvailable;
}
