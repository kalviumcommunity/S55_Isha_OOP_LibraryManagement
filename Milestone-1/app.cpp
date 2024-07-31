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
        void setBookNumber(string a) { bookNumber = a; }
        void setTitle(string b) { title = b; }           
        void setAuthor(string c) { author = c; }       
        void setAvailability(string d) { availability = d; }   

        // Getter methods for book number, title, author and availability
        string getBookNumber() { return bookNumber; } 
        string getTitle() { return title; }           
        string getAuthor() { return author; }         
        string getAvailability() { return availability; }       
        
        // Method to display book details like book number, title, author and availability
        void displayBook() {
            cout << "BookNumber: " << bookNumber << endl; 
            cout << "Title: " << title << endl;           
            cout << "Author: " << author << endl;       
            cout << "Availability: " << availability << endl;  
        }
};

// Class definition for Member
class Member {
    private:
        // Private data members for storing member details
        string memberId, name, contact;
    
    public:
        // Setter methods for setting member ID, name and contact
        void setMemberId(string id) { memberId = id; } 
        void setName(string n) { name = n; }      
        void setContact(string e) { contact = e; }   

        // Getter methods for setting member ID, name and contact
        string getMemberId() { return memberId; }
        string getName() { return name; }         
        string getContact() { return contact; }      

        // Method to display member details like member ID, name and contact
        void displayMember() {
            cout << "Member ID: " << memberId << endl; 
            cout << "Name: " << name << endl;    
            cout << "Contact: " << contact << endl;   
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
