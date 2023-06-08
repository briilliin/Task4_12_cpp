// MyDialog.cpp: файл реализации
//

#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "MyDialog.h"
#include <string>
#include "Notebook.h"
using namespace std;


// Диалоговое окно MyDialog

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)


MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent) 
{
	//Notebook* notebook = new Notebook();
	//p_notebook = notebook;
	Notebook notebook();
}

MyDialog::~MyDialog()
{
}

BOOL MyDialog::OnInitDialog()
{
	// вызов базовой функции для инициализации
	CDialog::OnInitDialog();

	GetDlgItem(ID_NAME_FIELD);
	string name = "Введите имя здесь..";
	CString strName(name.c_str());
	SetDlgItemText(ID_NAME_FIELD, strName);

	GetDlgItem(ID_SURNAME_FIELD);
	string surname = "Введите фамилию здесь..";
	CString strSurname(surname.c_str());
	SetDlgItemText(ID_SURNAME_FIELD, strSurname);

	GetDlgItem(ID_PHONE_FIELD);
	string phone = "Введите номер здесь..";
	CString strPhone(phone.c_str());
	SetDlgItemText(ID_PHONE_FIELD, strPhone);

	GetDlgItem(ID_GROUP_FIELD);
	string group = "Введите группу здесь..";
	CString strGroup(group.c_str());
	SetDlgItemText(ID_GROUP_FIELD, strGroup);

	GetDlgItem(ID_TIME_FIELD);
	string date = "Введите дату здесь..";
	CString strDate(date.c_str());
	SetDlgItemText(ID_TIME_FIELD, strDate);

	GetDlgItem(ID_EVENT_FIELD);
	string eventName = "Введите название здесь..";
	CString strEventName(eventName.c_str());
	SetDlgItemText(ID_EVENT_FIELD, strEventName);

	GetDlgItem(ID_DESCRIPTION_FIELD);
	string eventDesc = "Введите пояснение здесь..";
	CString strEventDesc(eventDesc.c_str());
	SetDlgItemText(ID_DESCRIPTION_FIELD, strEventDesc);

	GetDlgItem(ID_CONTACT_FIELD);
	string eventContact = "Введите id или группу здесь..";
	CString strEventContact(eventContact.c_str());
	SetDlgItemText(ID_CONTACT_FIELD, strEventContact);

	return TRUE;

}



void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(ID_ADD_BUTTON, &MyDialog::OnBnClickedAddButton)
	ON_BN_CLICKED(ID_ADD_EVENT, &MyDialog::OnBnClickedAddEvent)
	ON_BN_CLICKED(ID_SHOW_CONTACTS, &MyDialog::OnBnClickedShowContacts)
	ON_BN_CLICKED(ID_SHOW_EVENTS, &MyDialog::OnBnClickedShowEvents1)
END_MESSAGE_MAP()


// Обработчики сообщений MyDialog


void MyDialog::OnBnClickedAddButton()
{
	UpdateData(TRUE);
	// TODO: добавьте свой код обработчика уведомлений
	CString tempStr;

	m_pMyTextField = (CEdit*)GetDlgItem(ID_NAME_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string name(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_SURNAME_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string surname(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_PHONE_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string phone(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_GROUP_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string group(CStringA(tempStr).GetString());


	string response = notebook.addNewContact(&notebook, name, surname, phone, group);
	CListBox* pListBox = (CListBox*)GetDlgItem(ID_SHOW_INF);
	CString cresponse(response.c_str());
	pListBox->ResetContent();
	pListBox->AddString(cresponse);

	UpdateData(FALSE);
}


void MyDialog::OnBnClickedAddEvent()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString tempStr;

	m_pMyTextField = (CEdit*)GetDlgItem(ID_TIME_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string date(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_EVENT_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string eventName(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_DESCRIPTION_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string desc(CStringA(tempStr).GetString());

	m_pMyTextField = (CEdit*)GetDlgItem(ID_CONTACT_FIELD);
	m_pMyTextField->GetWindowText(tempStr);
	string contacts(CStringA(tempStr).GetString());


	string response = notebook.addNewEvent(&notebook, date, eventName, desc, contacts);
	CListBox* pListBox = (CListBox*)GetDlgItem(ID_SHOW_INF);
	CString cresponse(response.c_str());
	pListBox->ResetContent();
	pListBox->AddString(cresponse);
}


void MyDialog::OnBnClickedShowContacts()
{
	UpdateData(TRUE);
	// TODO: добавьте свой код обработчика уведомлений
	CListBox* pListBox = (CListBox*)GetDlgItem(ID_SHOW_INF);
	pListBox->ResetContent();

	vector<Contact> names = notebook.GetContacts();
	for (Contact contact : names) {
		CString cId(to_string(contact.GetId()).c_str());
		CString cName(contact.GetName().c_str());
		CString cSurname(contact.GetSurname().c_str());
		CString cPhone(contact.GetPhone().c_str());
		CString cGroup(contact.GetType().c_str());

		pListBox->AddString(cId + " " + cName + " " + cSurname + " " + cPhone + " " + cGroup);
	}
	UpdateData(FALSE);
}


void MyDialog::OnBnClickedShowEvents1()
{
	// TODO: добавьте свой код обработчика уведомлений
	CListBox* pListBox = (CListBox*)GetDlgItem(ID_SHOW_INF);
	pListBox->ResetContent();

	vector<Event> events = notebook.GetEvents();
	for (Event event : events) {
		CString cDate(event.GetDate().c_str());
		CString cEventName(event.GetEventName().c_str());
		CString cEventDesc(event.GetDescription().c_str());

		pListBox->AddString(cDate + " " + cEventName + " " + cEventDesc);

		if (event.GetEventContacts().size() == 0) continue;

		vector<Contact> names = event.GetEventContacts();
		for (Contact contact : names) {
			CString cId(to_string(contact.GetId()).c_str());
			CString cName(contact.GetName().c_str());
			CString cSurname(contact.GetSurname().c_str());
			CString cPhone(contact.GetPhone().c_str());
			CString cGroup(contact.GetType().c_str());
			pListBox->AddString(cId + " " + cName + " " + cSurname + " " + cPhone + " " + cGroup);
		}

	}
}
