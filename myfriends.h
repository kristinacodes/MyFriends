#pragma once
#ifndef MYFRIENDS_H
#define MYFRIENDS_H
#include <iostream>
using namespace std;
#include <string>
class FriendNode
{
public:
	string name;
	string birthday;
	string address;
	string contact_number;
	FriendNode* next;
	FriendNode* prev;
public:
	FriendNode(string name, string birthday, string address, string contact_number, FriendNode* next = NULL, FriendNode* prev = NULL)
	{
		this->name = name;
		this->birthday = birthday;
		this->address = address;
		this->contact_number = contact_number;
		this->next = next;
		this->prev = prev;
	}
	void display()
	{
		cout << "Name : " << name << "\t" << "Birthday :" << birthday << "\t" << "Address :" << address << "\t" << " Contact Number :" << contact_number << endl;
	}
};
class MyFriends
{
public:
	MyFriends();
	~MyFriends();
	void insert(string name, string birthday, string address, string contact_number);
	bool deleteRecord(string name);
	void display();
	bool searchByName(string name);
	bool searchByBDay(string bday);
	bool searchByAddress(string add);
	bool searchByContactNumber(string contact);
private:
	FriendNode* ListHead;
};


#endif // !MYFRIENDS_H
