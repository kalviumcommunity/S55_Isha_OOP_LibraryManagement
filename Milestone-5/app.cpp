#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 
// Abstract class for general functionalities (Base class for single inheritance)
// Demonstrates the Open/Closed Principle (OCP) by providing a base for extension
// without modification for derived classes like Books and Member
class LibraryEntity {
public:
    // Pure virtual function (Virtual Function)
    virtual void displayDetails() const = 0;  // Abstract method
    virtual ~LibraryEntity() {
        cout << "Destructor of LibraryEntity called\n";
    }
};

// Class definition for Books, inheriting from LibraryEntity (Single Inheritance)
// Demonstrates Single Responsibility Principle (SRP) by focusing only on book-related details
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

    // Virtual Destructor
    virtual ~Books() {
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
    // Demonstrates Open/Closed Principle by providing a flexible way to display book details
    void displayDetails() const override {
        cout << "Book Number: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Availability: " << this->availability << endl;
    }

    // Overloaded function to display book details with additional info
    void displayDetails(bool showCount) const {
        displayDetails();  // Call the basic version
        if (showCount) {
            cout << "Total Books Available: " << getBookCount() << endl;
        }
    }
};

// Initialize the static variable
int Books::bookCount = 0;

// Class definition for EBook, inheriting from Books (Multi-level Inheritance)
// Demonstrates Liskov Substitution Principle (LSP) as EBook can replace Books where needed
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

    // Virtual Destructor
    virtual ~EBook() {
        cout << "Destructor of EBook called\n";
    }

    // Additional setter and getter methods for EBook-specific details
    void setFileSize(string fileSize) { this->fileSize = fileSize; }
    void setFormat(string format) { this->format = format; }

    string getFileSize() const { return this->fileSize; }
    string getFormat() const { return this->format; }

    // Override displayDetails to show additional information for EBook
    void displayDetails() const override {
        Books::displayDetails();  // Call base class method to display book details
        cout << "File Size: " << this->fileSize << endl;
        cout << "Format: " << this->format << endl;
    }
};

// Class definition for Member, inheriting from LibraryEntity (Single Inheritance)
// Demonstrates Single Responsibility Principle (SRP) by focusing only on member-related details
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

    // Virtual Destructor
    virtual ~Member() {
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
    // Demonstrates Open/Closed Principle by providing a specific implementation for members
    void displayDetails() const override {
        cout << "Member ID: " << this->memberId << endl;
        cout << "Name: " << this->name << endl;
        cout << "Contact: " << this->contact << endl;
    }
};

// Initialize the static variable
int Member::memberCount = 0;

int main() {
    vector<LibraryEntity*> entities;

    // Adding books to the library
    entities.push_back(new Books("1", "Staying On", "Paul Scott", "Available"));
    entities.push_back(new Books("2", "Harry Potter and the Goblet of Fire", "J.K. Rowling", "Available"));

    // Displaying book details
    cout << "Book Details:" << endl;
    for (size_t i = 0; i < entities.size(); ++i) {
        entities[i]->displayDetails();
        cout << endl;
    }

    // Adding members to the library
    entities.push_back(new Member("M1", "Isha", "+918010992527"));
    entities.push_back(new Member("M2", "Pranjal", "+919699603487"));

    // Displaying member details
    cout << "Member Details:" << endl;
    for (int i = 0; i < entities.size(); ++i) {
        entities[i]->displayDetails();
        cout << endl;
    }

    // Adding an EBook to the library
    entities.push_back(new EBook("3", "Digital Fortress", "Dan Brown", "Available", "5MB", "PDF"));

    // Displaying EBook details
    cout << "EBook Details:" << endl;
    for (size_t i = 0; i < entities.size(); ++i) {
        entities[i]->displayDetails();
        cout << endl;
    }

    // Cleaning up dynamically allocated memory
    for (size_t i = 0; i < entities.size(); ++i) {
        delete entities[i];
    }

    return 0;
}
