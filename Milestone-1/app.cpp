#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

// Class definition for Books
class Books {
    private:
        // Private data members for storing book details
        string bookNumber, title, author, availability;
    
    public:
        // Setter methods for setting book number, title, author and availability
        void setBookNumber(string a) { this->bookNumber = a; }
        void setTitle(string b) { this->title = b; }
        void setAuthor(string c) { this->author = c; }
        void setAvailability(string d) { this->availability = d; }

        // Getter methods for book number, title, author and availability
        string getBookNumber() { return this->bookNumber; }
        string getTitle() { return this->title; }
        string getAuthor() { return this->author; }
        string getAvailability() { return this->availability; }
        
        // Method to display book details like book number, title, author and availability
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
        // Setter methods for setting member ID, name and contact
        void setMemberId(string id) { this->memberId = id; }
        void setName(string n) { this->name = n; }
        void setContact(string e) { this->contact = e; }

        // Getter methods for setting member ID, name and contact
        string getMemberId() { return this->memberId; }
        string getName() { return this->name; }
        string getContact() { return this->contact; }

        // Method to display member details like member ID, name and contact
        void displayMember() {
            cout << "Member ID: " << this->memberId << endl;
            cout << "Name: " << this->name << endl;
            cout << "Contact: " << this->contact << endl;
        }
};

int main() {
    // Two instances of the Books class
    Books book1, book2;

    // Setting details for book1
    book1.setBookNumber("1");
    book1.setTitle("Staying on");
    book1.setAuthor("Paul Stock");
    book1.setAvailability("Available");
    
    // Setting details for book2
    book2.setBookNumber("2");
    book2.setTitle("Harry Potter and the Goblet of Fire");
    book2.setAuthor("J. K. Rowling");
    book2.setAvailability("Available");
    
    // Display details for book1
    cout << "Book 1 Details:" << endl;
    book1.displayBook();
    cout << endl;

    // Display details for book2
    cout << "Book 2 Details:" << endl;
    book2.displayBook();
    cout << endl;

    // Create two instances of the Member class
    Member member1, member2;

    // Set details for member1
    member1.setMemberId("M1");
    member1.setName("Isha");
    member1.setContact("+918010992527");

    // Set details for member2
    member2.setMemberId("M2");
    member2.setName("Pranjal");
    member2.setContact("+919699603487");

    // Display details for member1
    cout << "Member 1 Details:" << endl;
    member1.displayMember();
    cout << endl;

    // Display details for member2
    cout << "Member 2 Details:" << endl;
    member2.displayMember();
    cout << endl;

    return 0;
}
