#include <iostream>
#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;  // Lista som lagrar alla böcker

public:
    void addBook(std::string title, std::string author);  // Lägg till bok i biblioteket
    void borrowBook(std::string title);  // Låna bok
    void returnBook(std::string title);  // Återlämna bok
    void showAllBooks() const;  // Visa alla böcker i biblioteket
};

void Library::addBook(std::string title, std::string author) {
    books.push_back(Book(title, author));  // Lägger till en ny bok i biblioteket
    std::cout << "Book added: " << title << " by " << author << "\n";
}

void Library::borrowBook(std::string title) {
    for (auto& book : books) {
        if (book.checkAvailability() && book.checkAvailability() == true) {
            book.borrowBook();  // Låna boken
            return;
        }
    }
    std::cout << "Book not found or is already borrowed.\n";  // Om boken inte finns eller redan är utlånad
}

void Library::returnBook(std::string title) {
    for (auto& book : books) {
        if (book.checkAvailability() == false) {
            book.returnBook();  // Återlämna boken
            return;
        }
    }
    std::cout << "Book not found or not borrowed.\n";  // Om boken inte finns eller inte är utlånad
}

void Library::showAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";  // Om biblioteket är tomt
        return;
    }
    std::cout << "\nLibrary Books:\n";
    for (const auto& book : books) {
        book.displayBookInfo();  // Visa information om alla böcker i biblioteket
        std::cout << "------------------\n";
    }
}

int main() {
    Library library;  // Skapa en instans av biblioteket
    int choice;
    std::string title, author;

    do {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Borrow Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Show All Books\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::cin.ignore();  // Rensa newline från föregående input
                std::getline(std::cin, title);  // Läs in boktiteln
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);  // Läs in författarens namn
                library.addBook(title, author);  // Lägg till boken i biblioteket
                break;

            case 2:
                std::cout << "Enter book title to borrow: ";
                std::cin.ignore();  // Rensa newline från föregående input
                std::getline(std::cin, title);  // Läs in boktitel för att låna
                library.borrowBook(title);  // Låna boken
                break;

            case 3:
                std::cout << "Enter book title to return: ";
                std::cin.ignore();  // Rensa newline från föregående input
                std::getline(std::cin, title);  // Läs in boktitel för att återlämna
                library.returnBook(title);  // Återlämna boken
                break;

            case 4:
                library.showAllBooks();  // Visa alla böcker i biblioteket
                break;

            case 5:
                std::cout << "Goodbye!\n";  // Avsluta programmet
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";  // Ogiltigt val
        }
    } while (choice != 5);  // Fortsätt tills användaren väljer att avsluta

    return 0;  // Programmet avslutas här
}
