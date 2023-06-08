#include "pch.h"
#include "Event.h"
using namespace std;


string Event::GetDate()
{
	return  Event::Date;
}

string Event::GetEventName()
{
	return  Event::EventName;
}

string Event::GetDescription()
{
	return  Event::Description;
}

vector<Contact> Event::GetEventContacts()
{
	return Event::EventContacts;
}

Event::Event(string date, string eventName, string description, vector<Contact> contacts)
{
	Event::Date = date;
	Event::EventName = eventName;
	Event::Description = description;
	Event::EventContacts = contacts;
}

Event::~Event()
{
}
