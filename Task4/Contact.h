#pragma once
#include <string>
using namespace std;

class Contact {
private:
	int Id;
	string ContactName;
	string ContactSurname;
	string ContactPhone;
	string ContactType;
public:
	int GetId();
	string GetName();
	string GetPhone();
	string GetSurname();
	string GetType();

	~Contact();
	Contact(string name, string surname, string phone, string group, int contactSize);
};