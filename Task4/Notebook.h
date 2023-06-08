#pragma once
#include <vector>
#include "Contact.h"
#include "Event.h"


class Notebook {
public:
	string addNewContact(Notebook* notebook, string name, string surname, string phone, string group);
	vector<Contact> GetContacts();

	string addNewEvent(Notebook* notebook, string date, string eventName, string description, string contacts);
	vector<Event> GetEvents();

	Notebook();
	~Notebook();

	void SetContacts(vector<Contact>* contacts);
	void SetEvents(vector<Event>* events);

private:
	vector<Contact> Contacts;
	vector<Event> Events;
	vector<Contact> initContacts();
	vector<Event> initEvents();


	bool isEventDateValid(string date);
	vector<string> splitString(string s);
	vector<Contact> findContactBy(vector<string> id);

};
