#include <iostream>
#include <string>
using namespace std;

// Class definition for Books
class Books {
private:
    // Private data members for storing book details
    string bookNumber, title, author, availability;

public:
    // Setter methods for setting book number, title, author, and availability
    void setBookNumber(string bookNumber) { this->bookNumber = bookNumber; }
    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setAvailability(string availability) { this->availability = availability; }

    // Getter methods for book number, title, author, and availability
    string getBookNumber() { return this->bookNumber; }
    string getTitle() { return this->title; }
    string getAuthor() { return this->author; }
    string getAvailability() { return this->availability; }

    // Method to display book details like book number, title, author, and availability
    void displayBook() {
        cout << "Book Number: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Availability: " << this->availability << endl;
    }
};

// Class definition for Member
class Member {
private:
    // Private data members for storing member details
    string memberId, name, contact;

public:
    // Setter methods for setting member ID, name, and contact
    void setMemberId(string memberId) { this->memberId = memberId; }
    void setName(string name) { this->name = name; }
    void setContact(string contact) { this->contact = contact; }

    // Getter methods for setting member ID, name, and contact
    string getMemberId() { return this->memberId; }
    string getName() { return this->name; }
    string getContact() { return this->contact; }

    // Method to display member details like member ID, name, and contact
    void displayMember() {
        cout << "Member ID: " << this->memberId << endl;
        cout << "Name: " << this->name << endl;
        cout << "Contact: " << this->contact << endl;
    }
};

int main() {
    // Creating an array of Books objects
    Books books[2];

    // Setting details for the books
    books[0].setBookNumber("1");
    books[0].setTitle("Staying On");
    books[0].setAuthor("Paul Scott");
    books[0].setAvailability("Available");

    books[1].setBookNumber("2");
    books[1].setTitle("Harry Potter and the Goblet of Fire");
    books[1].setAuthor("J.K. Rowling");
    books[1].setAvailability("Available");

    // Displaying book details
    for (int i = 0; i < 2; ++i) {
        cout << "Book " << i + 1 << " Details:" << endl;
        books[i].displayBook();
        cout << endl;
    }

    // Creating an array of Member objects
    Member members[2];

    // Setting details for the members
    members[0].setMemberId("M1");
    members[0].setName("Isha");
    members[0].setContact("+918010992527");

    members[1].setMemberId("M2");
    members[1].setName("Pranjal");
    members[1].setContact("+919699603487");

    // Displaying member details
    for (int i = 0; i < 2; ++i) {
        cout << "Member " << i + 1 << " Details:" << endl;
        members[i].displayMember();
        cout << endl;
    }

    return 0;
}
