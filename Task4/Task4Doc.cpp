
// Task4Doc.cpp: реализация класса CTask4Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "Task4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTask4Doc

IMPLEMENT_DYNCREATE(CTask4Doc, CDocument)

BEGIN_MESSAGE_MAP(CTask4Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CTask4Doc

CTask4Doc::CTask4Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CTask4Doc::~CTask4Doc()
{
}

BOOL CTask4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CTask4Doc

void CTask4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}


// Диагностика CTask4Doc

#ifdef _DEBUG
void CTask4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTask4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CTask4Doc
