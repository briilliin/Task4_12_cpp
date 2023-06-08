#pragma once
#include "afxdialogex.h"
#include "Notebook.h"


// Диалоговое окно MyDialog

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)
private:
	Notebook notebook;

public:
	MyDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~MyDialog();
	BOOL OnInitDialog();
	CEdit* m_pMyTextField;

	Notebook* p_notebook;


	


	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedAddEvent();
	afx_msg void OnBnClickedShowContacts();
	afx_msg void OnBnClickedShowEvents1();
};
