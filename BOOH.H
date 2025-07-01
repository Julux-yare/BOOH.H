#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;      // Bokens titel
    std::string author;     // Författarens namn
    bool isAvailable;       // Om boken är tillgänglig eller utlånad

public:
    Book(std::string title, std::string author);  // Konstruktor
    void borrowBook();  // Låna boken (gör den otillgänglig)
    void returnBook();  // Återlämna boken (gör den tillgänglig igen)
    void displayBookInfo() const;  // Visa bokens information
    bool checkAvailability() const;  // Kolla om boken är tillgänglig
};

#endif
