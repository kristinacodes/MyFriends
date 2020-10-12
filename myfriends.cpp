#include "myfriends.h"
MyFriends::MyFriends()
{
	ListHead = NULL;
}
MyFriends::~MyFriends()
{
	if (ListHead != NULL)
	{
		FriendNode* curr = ListHead->next, * prev;
		while (curr != NULL && curr != ListHead)
		{
			prev = curr->next;
			delete curr;
			curr = NULL;
			curr = prev;
		}
		delete ListHead;
		ListHead = NULL;
	}
}
void MyFriends::insert(string name, string birthday, string address, string contact_number)
{
	FriendNode* node = new FriendNode(name, birthday, address, contact_number);
	if (ListHead != NULL)
	{
		node->next = ListHead;
		node->prev = ListHead->prev;
		ListHead->prev->next = node;
		ListHead->prev = node;
		//ListHead = node;
	}
	else
	{
		//if list is empty
		ListHead = node;
		node->next = node;
		node->prev = node;
	}

}
bool MyFriends::deleteRecord(string name)
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead && curr->name != name)
	{
		curr = curr->next;
	}
	//if found then update pointers and delete it
	if (curr->name == name)
	{
		if (curr->next == curr && curr->prev == curr)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			curr = NULL;
			ListHead = NULL;
			return true;
		}
		else
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
			curr = NULL;
			return true;
		}
	}
	return false;
}
void MyFriends::display()
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead)
	{
		curr->display();
		curr = curr->next;
	}
	if (curr != NULL)
		curr->display();
}
bool MyFriends::searchByName(string name)
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead && curr->name != name)
	{
		curr = curr->next;
	}
	if (curr != NULL && curr->name == name)
	{
		return true;
	}
	return false;
}
bool MyFriends::searchByBDay(string bday)
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead && curr->birthday != bday)
	{
		curr = curr->next;
	}
	if (curr != NULL && curr->birthday == bday)
	{
		return true;
	}
	return false;
}
bool MyFriends::searchByAddress(string add)
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead && curr->address != add)
	{
		curr = curr->next;
	}
	if (curr != NULL && curr->address == add)
	{
		return true;
	}
	return false;
}
bool MyFriends::searchByContactNumber(string contact)
{
	FriendNode* curr = ListHead;
	//search for node
	while (curr != NULL && curr->next != ListHead && curr->contact_number != contact)
	{
		curr = curr->next;
	}
	if (curr != NULL && curr->contact_number == contact)
	{
		return true;
	}
	return false;
}
