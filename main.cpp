#include <iostream>
#include "myfriends.h"
using namespace std;
int main()
{
	int choice = 0;
	MyFriends friendList;
	string name;
	string birthday;
	string address;
	string contact_number;
	do
	{
		cout << "\n----------------------------------------------------------------\n";
		cout << "******************Let's Make Some Friends***********************\n";
		cout << "----------------------------------------------------------------\n";
		cout << "\n 1 - Add New Friend";
		cout << "\n 2 - Delete a Friend";
		cout << "\n 3 - Display Friends";
		cout << "\n 4 - Search Friend by Name";
		cout << "\n 5 - Search Friend by Address";
		cout << "\n 6 - Search Friend by Contact Number";
		cout << "\n 7 - Search Friend by Birthday";
		cout << "\n 8 - Exit\n";
		cout << "\n----------------------------------------------------------------\n";
		cout << "Enter your choice:> ";
		cin >> choice;
		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter Friend name:> ";
			getline(cin, name);
			cout << "Enter address:> ";
			getline(cin, address);
			cout << "Enter birthday:> ";
			getline(cin, birthday);
			cout << "Enter contact number:> ";
			getline(cin, contact_number);
			friendList.insert(name, birthday, address, contact_number);
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter name you want to delete:> ";
			getline(cin, name);
			if (friendList.deleteRecord(name))
			{
				cout << "\n-----------------------------------------------------------------------------\n";
				cout << "Deleted Successfully! Don't forget to also block them on all social media! :) ";
				cout << "\n-----------------------------------------------------------------------------\n";
			}
			else {
				cout << "\n------------\n";
				cout << "Friend Not found\n";
				cout << "\n------------\n";
			}

		}
		else if (choice == 3)
		{
			friendList.display();
		}
		else if (choice == 4)
		{
			cin.ignore();
			cout << "Enter Friend Name you want to search:> ";
			getline(cin, name);
			if (friendList.searchByName(name))
			{
				cout << "\n------------\n";
				cout << "!!!--- Record found ---!!!";
				cout << "\n------------\n";
			}
			else {
				cout << "\n------------\n";
				cout << "!!!--- Record NOT found ---!!!\n";
				cout << "\n------------\n";
			}
		}
		else if (choice == 5)
		{
			cin.ignore();
			cout << "Enter address you want to search:> ";
			getline(cin, address);
			if (friendList.searchByAddress(address))
			{
				cout << "\n------------\n";
				cout << "!!!--- Record found ---!!!";
				cout << "\n------------\n";
			}
			else {
				cout << "\n------------\n";
				cout << "!!!--- Record NOT found ---!!!";
				cout << "\n------------\n";
			}
		}
		else if (choice == 6)
		{
			cin.ignore();
			cout << "Enter contact number you want to search:> ";
			getline(cin, contact_number);
			if (friendList.searchByContactNumber(contact_number))
			{
				cout << "\n------------\n";
				cout << "!!!--- Record found ---!!!";
				cout << "\n------------\n";
			}
			else {
				cout << "\n------------\n";
				cout << "!!!--- Record NOT found ---!!!";
				cout << "\n------------\n";
			}
		}
		else if (choice == 7)
		{
			cin.ignore();
			cout << "Enter birthday you want to search:> ";
			getline(cin, birthday);
			if (friendList.searchByBDay(birthday))
			{
				cout << "\n------------\n";
				cout << "!!!--- Record found ---!!!";
				cout << "\n------------\n";
			}
			else {
				cout << "\n------------\n";
				cout << "!!!--- Record NOT found ---!!!";
				cout << "\n------------\n";
			}
		}
		else if (choice == 8)
		{
			break;
		}
		else
		{
			cout << "Please Enter correct choice:> ";
		}
	} while (true);
}