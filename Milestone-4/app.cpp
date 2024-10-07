#include <iostream>
#include <string>
using namespace std;

// Abstract class for general functionalities (Base class for single inheritance)
class LibraryEntity {
public:
    // Pure virtual function to be implemented by derived classes
    virtual void displayDetails() const = 0; // Abstract method
};

// Class definition for Books, inheriting from LibraryEntity (Single Inheritance)
class Books : public LibraryEntity {
private:
    // Private member variables (Encapsulation)
    string bookNumber, title, author, availability;

    // Static variable to count the number of Books objects
    static int bookCount;

public:
    // Default Constructor
    Books() {
        bookCount++;
        cout << "Default Constructor of Books called\n";
    }

    // Parameterized Constructor
    Books(string bookNumber, string title, string author, string availability) 
        : bookNumber(bookNumber), title(title), author(author), availability(availability) {
        bookCount++;
        cout << "Parameterized Constructor of Books called\n";
    }

    // Destructor
    ~Books() {
        cout << "Destructor of Books called\n";
    }

    // Public setter methods (Mutators)
    void setBookNumber(string bookNumber) { this->bookNumber = bookNumber; }
    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setAvailability(string availability) { this->availability = availability; }

    // Getter methods (Accessors)
    string getBookNumber() const { return this->bookNumber; }
    string getTitle() const { return this->title; }
    string getAuthor() const { return this->author; }
    string getAvailability() const { return this->availability; }

    // Static method to get the total number of books
    static int getBookCount() {
        return bookCount;
    }

    // Overloaded method for polymorphism (Function Overloading)
    void displayDetails() const override {
        cout << "Book Number: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Availability: " << this->availability << endl;
    }

    // Overloaded function to display book details with additional info (Polymorphism)
    void displayDetails(bool showCount) const {
        displayDetails(); // Call the basic version
        if (showCount) {
            cout << "Total Books Available: " << getBookCount() << endl;
        }
    }
};

// Initialize the static variable
int Books::bookCount = 0;

// Class definition for EBook, inheriting from Books (Multi-level Inheritance)
class EBook : public Books {
private:
    string fileSize, format;

public:
    // Default Constructor
    EBook() {
        cout << "Default Constructor of EBook called\n";
    }

    // Parameterized Constructor
    EBook(string bookNumber, string title, string author, string availability, string fileSize, string format) 
        : Books(bookNumber, title, author, availability), fileSize(fileSize), format(format) {
        cout << "Parameterized Constructor of EBook called\n";
    }

    // Destructor
    ~EBook() {
        cout << "Destructor of EBook called\n";
    }

    // Additional setter and getter methods for EBook-specific details
    void setFileSize(string fileSize) { this->fileSize = fileSize; }
    void setFormat(string format) { this->format = format; }

    string getFileSize() const { return this->fileSize; }
    string getFormat() const { return this->format; }

    // Override displayDetails to show additional information for EBook
    void displayDetails() const override {
        Books::displayDetails(); // Call base class method to display book details
        cout << "File Size: " << this->fileSize << endl;
        cout << "Format: " << this->format << endl;
    }
};

// Class definition for Member, inheriting from LibraryEntity (Single Inheritance)
class Member : public LibraryEntity {
private:
    // Private member variables (Encapsulation)
    string memberId, name, contact;

    // Static variable to count the number of Member objects
    static int memberCount;

public:
    // Default Constructor
    Member() {
        memberCount++;
        cout << "Default Constructor of Member called\n";
    }

    // Parameterized Constructor
    Member(string memberId, string name, string contact) 
        : memberId(memberId), name(name), contact(contact) {
        memberCount++;
        cout << "Parameterized Constructor of Member called\n";
    }

    // Destructor
    ~Member() {
        cout << "Destructor of Member called\n";
    }

    // Public setter methods (Mutators)
    void setMemberId(string memberId) { this->memberId = memberId; }
    void setName(string name) { this->name = name; }
    void setContact(string contact) { this->contact = contact; }

    // Getter methods (Accessors)
    string getMemberId() const { return this->memberId; }
    string getName() const { return this->name; }
    string getContact() const { return this->contact; }

    // Static method to get the total number of members
    static int getMemberCount() {
        return memberCount;
    }

    // Implementation of the abstract method to display details
    void displayDetails() const override {
        cout << "Member ID: " << this->memberId << endl;
        cout << "Name: " << this->name << endl;
        cout << "Contact: " << this->contact << endl;
    }
};

// Initialize the static variable
int Member::memberCount = 0;

int main() {
    int numBooks = 2;
    int numMembers = 2;

    // Using parameterized constructor for Books
    Books* books = new Books[2]{
        Books("1", "Staying On", "Paul Scott", "Available"),
        Books("2", "Harry Potter and the Goblet of Fire", "J.K. Rowling", "Available")
    };

    // Displaying book details using polymorphism (Function Overloading)
    for (int i = 0; i < numBooks; ++i) {
        cout << "Book " << i + 1 << " Details:" << endl;
        books[i].displayDetails(true); // Using the overloaded function to display the total count
        cout << endl;
    }

    // Using parameterized constructor for Member
    Member* members = new Member[2]{
        Member("M1", "Isha", "+918010992527"),
        Member("M2", "Pranjal", "+919699603487")
    };

    // Displaying member details using abstraction
    for (int i = 0; i < numMembers; ++i) {
        cout << "Member " << i + 1 << " Details:" << endl;
        members[i].displayDetails();
        cout << endl;
    }

    // Creating EBook object using parameterized constructor
    EBook ebook("3", "Digital Fortress", "Dan Brown", "Available", "5MB", "PDF");

    // Displaying EBook details (Multi-level inheritance)
    cout << "EBook Details:" << endl;
    ebook.displayDetails();
    cout << endl;

    // Deallocating memory (calls destructors)
    delete[] books;
    delete[] members;

    return 0;
}
