#include <iostream>
#include <vector>
#include <unordered_map>
#include<string>
class Author {
public:
    std::string name;
    Author(const std::string& authorName) : name(authorName) {}
};

class Book {
public:
    std::string isbn;
    std::string title;
    std::vector<Author> authors;
    double price;

    Book(const std::string& bookIsbn, const std::string& bookTitle, const std::vector<Author>& bookAuthors, double bookPrice)
        : isbn(bookIsbn), title(bookTitle), authors(bookAuthors), price(bookPrice) {}
};

class BookStore {
private:
    //hashtable for o(1) access
    std::unordered_map<std::string, int> bookCopies;  
    std::vector<Book> books;  
public:
    void addBook(const Book& book, int numberOfCopies) {
        books.push_back(book);
        bookCopies[book.isbn] += numberOfCopies;}

    std::vector<std::string> uniqueIsbns() const {
        std::vector<std::string> uniqueIsbns;
        for (const auto& book : books) {
            uniqueIsbns.push_back(book.isbn);
        }
        return uniqueIsbns;
    }

    int noOfCopies(const std::string& isbn) const {
        auto it = bookCopies.find(isbn);
        if (it != bookCopies.end()) {
            return it->second;
        }
        return 0;  // ISBN not found
    }

    double totalPrice() const {
        double total = 0.0;
        for (const auto& book : books) {
            total += book.price * bookCopies.at(book.isbn);
        }
        return total;
    }

    void printCopiesAndTitle() const {
        for (const auto& book : books) {
            std::cout << "Title: " << book.title << "\tCopies: " << bookCopies.at(book.isbn) << std::endl;
        }
    }
};

int main() {
    // Create authors
    Author author1("Author1");
    Author author2("Author2");

    // Create books
    Book book1("ISBN001", "Book1", {author1}, 199.99);
    Book book2("ISBN002", "Book2", {author1, author2}, 259.99);
    Book book3("ISBN003", "Book3", {author2}, 115.99);

    // Create a bookstore
    BookStore bookstore;

    // Add books to the bookstore with multiple copies
    bookstore.addBook(book1, 5);
    bookstore.addBook(book2, 3);
    bookstore.addBook(book3, 2);

    // Print number of copies and title for each book
    bookstore.printCopiesAndTitle();
    std::cout<<"total price : "<<bookstore.totalPrice();

    return 0;
}

