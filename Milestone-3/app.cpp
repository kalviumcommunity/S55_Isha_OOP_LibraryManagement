#include <iostream>
#include <string>
using namespace std;

// Class definition for Books
class Books {
private:
    // Private member variables (Encapsulation)
    string bookNumber, title, author, availability;
    
    // Static variable to count the number of Books objects
    static int bookCount;

public:
    // Constructor to increment the book count when a new object is created
    Books() {
        bookCount++;
    }

    // Public setter methods to set the values of private variables which ensure encapsulation
    void setBookNumber(string bookNumber) { this->bookNumber = bookNumber; }
    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setAvailability(string availability) { this->availability = availability; }

    // Public getter methods to retrieve the values of private variables which ensure encapsulation

    string getBookNumber() { return this->bookNumber; }
    string getTitle() { return this->title; }
    string getAuthor() { return this->author; }
    string getAvailability() { return this->availability; }

    // Static method to get the total number of books
    static int getBookCount() {
        return bookCount;
    }

    // Static member function to display the total number of books
    static void displayTotalBooks() {
        cout << "Total number of books: " << bookCount << endl;
    }

    // Method to display details of the book
    void displayBook() {
        cout << "Book Number: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Availability: " << this->availability << endl;
    }
};

// Initialize the static variable
int Books::bookCount = 0;

// Class definition for Member
class Member {
private:
    // Private member variables (Encapsulation)
    string memberId, name, contact;
    
    // Static variable to count the number of Member objects
    static int memberCount;

public:
    // Constructor to increment the member count when a new object is created
    Member() {
        memberCount++;
    }

    // Public setter methods (Mutators) to set the values of private variables for controlled modification of private data
    void setMemberId(string memberId) { this->memberId = memberId; }
    void setName(string name) { this->name = name; }
    void setContact(string contact) { this->contact = contact; }

    // Public getter methods (Accessors) to retrieve the values of private variables to provide controlled access to private data
    string getMemberId() { return this->memberId; }
    string getName() { return this->name; }
    string getContact() { return this->contact; }

    // Static method to get the total number of members
    static int getMemberCount() {
        return memberCount;
    }

    // Static member function to display the total number of members
    static void displayTotalMembers() {
        cout << "Total number of members: " << memberCount << endl;
    }

    // Method to display details of the member
    void displayMember() {
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

    // Dynamically allocating memory for an array of Books objects
    Books* books = new Books[numBooks];

    // Setting details for the books using encapsulation (access through setters)
    books[0].setBookNumber("1");
    books[0].setTitle("Staying On");
    books[0].setAuthor("Paul Scott");
    books[0].setAvailability("Available");

    books[1].setBookNumber("2");
    books[1].setTitle("Harry Potter and the Goblet of Fire");
    books[1].setAuthor("J.K. Rowling");
    books[1].setAvailability("Available");

    // Displaying book details using encapsulation (access through getters)
    for (int i = 0; i < numBooks; ++i) {
        cout << "Book " << i + 1 << " Details:" << endl;
        books[i].displayBook();  // Calls display method to show details
        cout << endl;
    }

    // Dynamically allocating memory for an array of Member objects
    Member* members = new Member[numMembers];

    // Setting details for the members using encapsulation (access through setters)
    members[0].setMemberId("M1");
    members[0].setName("Isha");
    members[0].setContact("+918010992527");

    members[1].setMemberId("M2");
    members[1].setName("Pranjal");
    members[1].setContact("+919699603487");

    // Displaying member details using encapsulation (access through getters)
    for (int i = 0; i < numMembers; ++i) {
        cout << "Member " << i + 1 << " Details:" << endl;
        members[i].displayMember();  // Calls display method to show details
        cout << endl;
    }

    // Using static member functions to display the total counts
    Books::displayTotalBooks();
    Member::displayTotalMembers();

    // Deallocating memory
    delete[] books;
    delete[] members;

    return 0;
}
