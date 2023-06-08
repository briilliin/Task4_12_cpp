
// Task4View.cpp: реализация класса CTask4View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "Task4Doc.h"
#include "Task4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDialog.h"


// CTask4View

IMPLEMENT_DYNCREATE(CTask4View, CView)

BEGIN_MESSAGE_MAP(CTask4View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTask4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CTask4View

CTask4View::CTask4View() noexcept
{
	// TODO: добавьте код создания

}

CTask4View::~CTask4View()
{
}

BOOL CTask4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CTask4View

void CTask4View::OnDraw(CDC* /*pDC*/)
{
	CTask4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	MyDialog dialog;
	dialog.DoModal();

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CTask4View


void CTask4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTask4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CTask4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CTask4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CTask4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTask4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CTask4View

#ifdef _DEBUG
void CTask4View::AssertValid() const
{
	CView::AssertValid();
}

void CTask4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTask4Doc* CTask4View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTask4Doc)));
	return (CTask4Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CTask4View
