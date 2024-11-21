#include <iostream>
#include <string>
using namespace std;

// Book Class Definition
class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    // Constructor to initialize a book
    Book() : title(""), author(""), isbn(""), isAvailable(true) {}

    // Method to set book details
    void setBookDetails(const string& bookTitle, const string& bookAuthor, const string& bookISBN, bool availability = true) {
        title = bookTitle;
        author = bookAuthor;
        isbn = bookISBN;
        isAvailable = availability;
    }

    // Method to display book details
    void displayBookDetails() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn
             << "\nAvailability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    // Method to borrow a book
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "The book \"" << title << "\" has been borrowed successfully.\n";
            return true;
        } else {
            cout << "The book \"" << title << "\" is currently unavailable.\n";
            return false;
        }
    }

    // Method to return a book
    void returnBook() {
        isAvailable = true;
        cout << "The book \"" << title << "\" has been returned successfully.\n";
    }

    // Method to check the ISBN
    bool checkISBN(const string& bookISBN) const {
        return isbn == bookISBN;
    }
};

// Main Application
int main() {
    // Initialize library with 5 books
    Book library[5];
 library[0].setBookDetails("A Time To Kill", "John Grisham", "1111");
    library[1].setBookDetails("A Scanner Darkly", "Philip", "2222");
    library[2].setBookDetails("Number of The Stars", "Lois Lowry", "3333");
    library[3].setBookDetails("Cold Comfort Farm", "Stella Gibbons", "4444");
    library[4].setBookDetails("Band of Brother", "Stephen", "5555");

    string userISBN;

    // User Interaction Loop
    while (true) {
        cout << "\nEnter the ISBN of the book you wish to borrow (or enter 0 to quit): ";
        cin >> userISBN;

        if (userISBN == "0") {
            cout << "Exiting the system. Thank you!\n";
            break;
        }

        // Search for the book by ISBN
        bool found = false;
        for (int i = 0; i < 5; ++i) {
            if (library[i].checkISBN(userISBN)) {
                found = true;
                library[i].displayBookDetails(); // Display book details
                library[i].borrowBook();         // Attempt to borrow the book
                break;
            }
        }

        if (!found) {
            cout << "No book found with the provided ISBN. Please try again.\n";
        }
    }

    return 0;
}

