#include "pch.h"
#include "Contact.h"
#include "Notebook.h"
#include <vector>


int Contact::GetId()
{
	return Contact::Id;
}

string Contact::GetName()
{
	return Contact::ContactName;
}

string Contact::GetPhone()
{
	return Contact::ContactPhone;
}

string Contact::GetSurname()
{
	return Contact::ContactSurname;
}


string Contact::GetType()
{
	return Contact::ContactType;
}

Contact::~Contact()
{
}

Contact::Contact(string name, string surname, string phone, string group, int contactSize)
{
	Contact::Id = contactSize;
	Contact::ContactName = name;
	Contact::ContactSurname = surname;
	Contact::ContactPhone = phone;

	if (group.length() == 0) Contact::ContactType = "без групппы";
	Contact::ContactType = group;
}
