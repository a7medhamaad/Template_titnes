#pragma

#include <iostream>
#include"Book.h"
#include"Illustration.h"

using namespace std;

class Library
{

private:

    LinkedList<Book> catlog;
    int NumberBooks, NumberBorrowedBooks, NumberavailableBooks;

public:

    void addBook(Book book)
    {
        NumberBooks++;
        NumberavailableBooks++;
        catlog.insertRight(book);
    }

    void returnBook(Book book)
    {
        NumberBorrowedBooks--;
        NumberavailableBooks++;
        catlog.insertRight(book);
    }
    void withdrawBook(Book book)
    {
        int bookIdx = catlog.search(book);
        if (bookIdx != -1)
        {
            NumberBorrowedBooks++;
            NumberavailableBooks--;
            catlog.removeAtPosition(bookIdx);
        }
    }

    void BorrowBook(Book book)
    {
        int bookIdx = catlog.search(book);
        if (bookIdx != -1)
        {
            NumberBorrowedBooks++;
            NumberavailableBooks--;
            catlog.removeAtPosition(bookIdx);
        }
    }
    void allowedBooks()
    {
        cout << "The available books are:\n";
        catlog.print();
    }

    void sort()
    {
        catlog.sortList();
    }

    void printStatistics()
    {
        cout << "Number of books in the library is " << NumberBooks << "\n";
        cout << "Number of borrowed books in the library is " << NumberBorrowedBooks << "\n";
        cout << "Number of available books in the library is " << NumberavailableBooks << "\n";
    }

    void printMenu()
    {
        cout << "Library System Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. return a book" << endl;
        cout << "3. withdraw a book" << endl;
        cout << "4. What are the available books?" << endl;
        cout << "5. sort the current available books" << endl;
        cout << "6. print the statistics of the library" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice (1-7): " << endl;
    }

    void run()
    {
        while (true)
        {
            printMenu();
            int choice;
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
            {
                Book book;
                book.readData();
                addBook(book);
                break;
            }
            case 2:
            {
                Book book;
                book.readData();
                returnBook(book);
                break;
            }
            case 3:
            {
                Book book;
                book.readData();
                withdrawBook(book);
                break;
            }
            case 4:
            {
                allowedBooks();
                break;
            }
            case 5:
            {
                sort();
                break;
            }
            case 6:
            {
                printStatistics();
                break;
            }
            case 7:
            {
                cout << "Exiting the program." << endl;
                return;
            }
            default:
                cout << "Invalid choice. Please enter a valid option (1-7)." << endl;
            }
        }
    }
};
