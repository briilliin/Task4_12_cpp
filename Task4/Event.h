#pragma once
#include <string>
#include <vector>
#include "Contact.h"
using namespace std;

class Event {
private:
	string Date;
	string EventName;
	string Description;
	vector<Contact> EventContacts;


public:
	string GetDate();
	string GetEventName();
	string GetDescription();
	vector<Contact> GetEventContacts();

	Event(string date, string eventName, string description, vector<Contact> contacts);
	~Event();
};