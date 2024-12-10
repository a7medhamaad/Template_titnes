#pragma

#include <iostream>
using namespace std;

class Book
{

public:

    string title, author, ISBN, genre;
    bool available;

    Book()

    {
        title = "";
        author = "";
        string ISBN = "";
        string genre = "";
        bool available = 1;

    }

    Book(string title, string author , string ISBN , string genre , bool available )
    {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->genre = genre;
        this->available = available;
    }

    bool operator<(const Book& other)const
    {
        return title < other.title;
    }

    bool operator==(const Book& other)const
    {
        return title == other.title;
    }

    bool operator>(const Book& other)const
    {
        return title > other.title;
    }

    void readData()
    {
        cout << "Enter the title of the book: " << endl;
        cin >> title;
        cout << "\nEnter the author of the book: " << endl;
        cin >> author;
        cout << "\nEnter the ISBN of the book: " << endl;
        cin >> ISBN;
        cout << "\nEnter the genre of the book: " << endl;
        cin >> genre;
        cout << "The Book is Saved Successfully" << endl << endl;
    }

    friend ostream& operator<<(ostream& output, Book book)
    {
        output << "Book's title is " << book.title << endl;
        output << "Book's author is " << book.author << endl;
        output << "Book's ISBN is " << book.ISBN << endl;
        output << "Book's number of reservations is " << book.genre << endl;
        return output;
    }

};