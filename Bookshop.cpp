
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Bookshop Class
class bookshope {
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
};

// menu
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. CHECK PARTICULAR BOOK";
	cout << "\n4. UPDATE BOOK";
	cout << "\n5. DELETE BOOK";
	cout << "\n6. EXIT";
}

// add book
void bookshope::add_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string book_name, author_name, book_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID : ";
	cin >> book_id;
	cout << "\nBook Name : ";
	cin >> book_name;
	cout << "\nAuthor Name : ";
	cin >> author_name;
	cout << "\nNo. of Books : ";
	cin >> no_copy;

	// Open file in append or
	// this is output mode
	file.open("D:// book.txt",
			ios::out | ios::app);
	file << " " << book_id << " "
		<< book_name << " " << author_name
		<< " " << no_copy << "\n";
	file.close();
}

// display book
void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string book_name, book_id, author_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nBook ID\t\tBook"
			<< "\t\tAuthor\t\tNo. of "
				"Books\n\n";
		file >> book_id >> book_name;
		file >> author_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {

			cout << " " << book_id
				<< "\t\t" << book_name
				<< "\t\t" << author_name
				<< "\t\t" << no_copy
				<< "\n\n";
			file >> book_id >> book_name;
			file >> author_name >> no_copy;
		}

		system("pause");

		// Close the file
		file.close();
	}
}

// check the book
void bookshope::check_book()
{
	system("cls");
	fstream file;
	int no_copy, count = 0;
	string book_id, book_name, author_name, book_idd;

	cout << "\n\n\t\t\t\tCheck "
		<< "Particular Book";

	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> book_idd;
		file >> book_id >> book_name;
		file >> author_name >> no_copy;

		while (!file.eof()) {

			if (book_idd == book_id) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Check Particular Book";
				cout << "\n\nBook ID : "
					<< book_id;
				cout << "\nName : "
					<< book_name;
				cout << "\nAuthor : "
					<< author_name;
				cout << "\nNo. of Books : "
					<< no_copy;
				cout << endl
					<< endl;
				count++;
				break;
			}
			file >> book_id >> book_name;
			file >> author_name >> no_copy;
		}
		system("pause");
		file.close();
		if (count == 0)
			cout << "\n\nBook ID Not"
				<< " Found...";
	}
}

// update the book
void bookshope::update_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	string book_name, b_na, author_name;
	string a_na, book_idd, book_id;

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D:// book1.txt",
			ios::app | ios::out);
	file.open("D:// book.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> book_id;
		file >> book_idd >> book_name;
		file >> author_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) {
			if (book_id == book_idd) {
				system("cls");
				cout << "\t\t\t\t"
					<< "Update Book Record";
				cout << "\n\nNew Book Name : ";
				cin >> b_na;
				cout << "\nAuthor Name : ";
				cin >> a_na;
				cout << "\nNo. of Books : ";
				cin >> no_co;
				file1 << " " << book_id << " "
					<< b_na << " "
					<< a_na << " " << no_co
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << book_idd
					<< " " << book_name
					<< " " << author_name
					<< " " << no_copy
					<< "\n\n";
			file >> book_idd >> book_name;
			file >> author_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nBook ID"
				<< " Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

// delete book
void bookshope::del_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, count = 0;
	string book_id, book_idd, book_name, author_name;
	cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("D:// book1.txt",
			ios::app | ios::out);
	file.open("D:// book.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nBook ID : ";
		cin >> book_id;
		file >> book_idd >> book_name;
		file >> author_name >> no_copy;
		while (!file.eof()) {

			if (book_id == book_idd) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				cout << "\n\nBook is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << book_idd
					<< " " << book_name
					<< " " << author_name
					<< " " << no_copy
					<< "\n\n";
			file >> book_idd >> book_name;
			file >> author_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nBook ID "
				<< "Not Found...";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

// book shop record
void bookShopRecord()
{
	int choice;
	char x;
	bookshope b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Driver Code
int main()
{
	// Function Call
	bookShopRecord();

	return 0;
}
