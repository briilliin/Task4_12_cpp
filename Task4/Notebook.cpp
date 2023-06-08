#include "pch.h"
#include "Notebook.h"
#include <vector>
#include <stdexcept>
#include <regex>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Event.h"

string Notebook::addNewContact(Notebook* notebook, string name, string surname, string phone, string group)
{
	try {
		if (name.length() == 0 || surname.length() == 0 || phone.length() == 0)
			throw invalid_argument("Недостаточно параметров!");

		if (!regex_match(phone, regex("8[0-9]{10}")))
			throw invalid_argument("Недопустимый формат номера!");
	}
	catch (invalid_argument& IA) {
		return IA.what();
	}

	Contact* contact = new Contact(name, surname, phone, group, notebook->GetContacts().size());
	vector<Contact> newContacts;
	newContacts.push_back(*contact);

	for (Contact cont : notebook->GetContacts()) {
		newContacts.push_back(cont);
	}
	notebook->SetContacts(&newContacts);

	return "Добавлено!";
}

string Notebook::addNewEvent(Notebook* notebook, string date, string eventName, string description, string contacts)
{
	try {
		if (date.length() == 0 || eventName.length() == 0)
			throw invalid_argument("Недостаточно параметров!");

		if (!isEventDateValid(date))
			throw invalid_argument("Недопустимый формат даты!");
	}
	catch (invalid_argument& IA) {
		return IA.what();
	}

	if (contacts.length() == 0) {
		vector<Contact> contact;

		vector<Event> events;
		Event* event = new Event(date, eventName, description, contact);
		events.push_back(*event);

		for (Event ev : notebook->GetEvents()) {
			events.push_back(ev);
		}
		notebook->SetEvents(&events);
		return "Добавлено!";
	}

	vector<string> params = splitString(contacts);
	vector<Contact> eventContacts = findContactBy(params);
	Event* event = new Event(date, eventName, description, eventContacts);

	vector<Event> events;
	events.push_back(*event);

	for (Event ev : notebook->GetEvents()) {
		events.push_back(ev);
	}
	notebook->SetEvents(&events);

	return "Добавлено!";
}
vector<string> Notebook::splitString(string s) {
	vector<string> arr;

	istringstream iss(s);
	string token;
	while (iss >> token) {
		arr.push_back(token);
	}
	return arr;
}

bool Notebook::isEventDateValid(string date)
{
	regex date_regex("^([0-2][0-9]|3[01])\\.(0[1-9]|1[012])\\.\\d{4}$");
	if (!regex_match(date, date_regex))
		return false;

	auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

	std::tm currentTime_tm;
	localtime_s(&currentTime_tm, &currentTime_t);

	int year = currentTime_tm.tm_year + 1900;
	int month = currentTime_tm.tm_mon + 1;
	int day = currentTime_tm.tm_mday;

	tm userDate = {};
	std::istringstream ss(date);
	ss >> get_time(&userDate, "%d.%m.%Y");

	int useryear = userDate.tm_year + 1900;
	int usermonth = userDate.tm_mon + 1;
	int userday = userDate.tm_mday;

	if (year <= useryear) {
		if (month < usermonth) {
			return true;
		}
		if (month == usermonth && day <= userday) {
			return true;
		}
	}
	return false;

}

vector<Contact> Notebook::findContactBy(vector<string> arr)
{
	vector<Contact> contacts;

	if (arr[0] == "g") {
		int i = 1;
		for (Contact contact : Notebook::Contacts) {
			if (i < arr.size()) {
				if (contact.GetType() == arr[i]) {
					contacts.push_back(contact);
				}
			}
			else break;
		}
	}


	if (arr[0] == "i") {
		int i = 1;
		for (Contact contact : Notebook::Contacts) {
			if (i < arr.size()) {
				if (contact.GetId() == stoi(arr[i])) {
					contacts.push_back(contact);
				}
			}
			else break;
		}
	}

	return contacts;
}


vector<Contact> Notebook::GetContacts()
{
	return Notebook::Contacts;
}

vector<Event> Notebook::GetEvents() {
	return Notebook::Events;
}

Notebook::Notebook()
{
	Notebook::Contacts = initContacts();
	Notebook::Events = initEvents();
}

Notebook::~Notebook()
{
}

vector<Contact> Notebook::initContacts()
{
	vector<Contact> contacts;
	Contact* contact = new Contact("Алина", "Бредихина", "89521061705", "Личные", 0);
	contacts.push_back(*contact);
	return contacts;
}

vector<Event> Notebook::initEvents()
{
	vector<Contact> contacts;
	vector<Event> events;
	Event* event = new Event("10.05.2023", "зачёт по C++", "сессия", contacts);
	events.push_back(*event);
	return events;
}

void Notebook::SetContacts(vector<Contact>* contacts) {
	Notebook::Contacts = *contacts;
}

void Notebook::SetEvents(vector<Event>* events) {
	Notebook::Events = *events;
}
