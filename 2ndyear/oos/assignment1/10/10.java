import java.util.HashMap;
import java.util.Scanner;

class Book {
    String author;
    String title;
    float cost;

    // Appropriate constructor, getters, setters, and display method
    public Book(String author, String title, float cost) {
        this.author = author;
        this.title = title;
        this.cost = cost;
    }

    // Getters and setters (you can generate them using your IDE)
    // ...

    void display() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Cost: $" + cost);
    }
}

class BookStore {
    HashMap<String, Integer> inventory;
    HashMap<String, Book> bookDetails;

    BookStore() {
        inventory = new HashMap<>();
        bookDetails = new HashMap<>();
    }

    void updateInventory(Book book, int newInventoryCount) {
        String key = book.title + " BY : " + book.author;
        inventory.put(key, newInventoryCount);
        bookDetails.put(key, book);
    }

    void searchInventory(String title, String author) {
        String key = title + " BY : " + author;

        if (bookDetails.containsKey(key)) {
            Book book = bookDetails.get(key);
            book.display();

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the number of copies required: ");
            int requiredCopies = scanner.nextInt();

            if (requiredCopies <= inventory.get(key)) {
                float totalCost = requiredCopies * book.cost;
                System.out.println("Total cost for " + requiredCopies + " copies: $" + totalCost);
            } else {
                System.out.println("Required amount not available.");
            }
        } else {
            System.out.println("Book unavailable.");
        }
    }
}

class Main {
    public static void main(String[] args) {
        // Create 5 books
        Book book1 = new Book("Author1", "Title1", 20.0f);
        Book book2 = new Book("Author2", "Title2", 25.0f);
        Book book3 = new Book("Author3", "Title3", 30.0f);
        Book book4 = new Book("Author4", "Title4", 15.0f);
        Book book5 = new Book("Author5", "Title5", 18.0f);

        // Create bookstore
        BookStore bookstore = new BookStore();

        // Add books to bookstore with inventory
        bookstore.updateInventory(book1, 10);
        bookstore.updateInventory(book2, 15);
        bookstore.updateInventory(book3, 8);
        bookstore.updateInventory(book4, 20);
        bookstore.updateInventory(book5, 12);

        // Demonstrate searchInventory function of the bookstore
        bookstore.searchInventory("Title3", "Author3");
    }
}

