#include<iostream>
#include<string>
#include"Illustration.h"
#include"Node.h"
#include"Book.h"
#include"Library.h"

using namespace std;


int main()
{

	Library library;
	library.run();
	return 0;



	/*
	short Choice = 0;
	do
	{
		system("cls");
		cout << "=========================================\n";
		cout << "\tMyTemplate Container\n";
		cout << "=========================================\n";
		cout << "[1] Add New Book\n";
		cout << "[2] Delete Book\n";
		cout << "[3] Borrow Book\n";
		cout << "[4] printStatistics\n";
		cout << "[5] Print Books\n";
		cout << "[6] Exits\n";
		cout << "=========================================\n";
		cout << "Please Enter Your Choice [1 to 6]: ";
		cin >> Choice;

		while (Choice > 6 || Choice < 1)
		{
			cout << "Please Enter Your Choice [1 to 6]: ";
			cin >> Choice;
		}

		string title, author, ISBN, genre;

		bool available;

		switch (Choice)
		{

		case 1:
		{
			system("cls");
			cout << "Enter Book Title: ";
			cin >> title;

			cout << "Enter Book author: ";
			cin >> author;

			cout << "Enter Book ISBN: ";
			cin >> ISBN;

			cout << "Enter Book genre: ";
			cin >> genre;

			cout << "Enter if book available [0 , 1]: ";
			cin >> available;

			Book B(title, author, ISBN, genre, available);

			Library Lib;
			Lib.addBook(B);
		}

		}

	} while (Choice != 6);
	*/
}



