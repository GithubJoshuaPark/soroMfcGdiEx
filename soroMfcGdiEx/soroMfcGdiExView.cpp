
// soroMfcGdiExView.cpp : implementation of the CsoroMfcGdiExView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "soroMfcGdiEx.h"
#endif

#include "soroMfcGdiExDoc.h"
#include "soroMfcGdiExView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsoroMfcGdiExView

IMPLEMENT_DYNCREATE(CsoroMfcGdiExView, CView)

BEGIN_MESSAGE_MAP(CsoroMfcGdiExView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CsoroMfcGdiExView construction/destruction

CsoroMfcGdiExView::CsoroMfcGdiExView() noexcept
{
	// TODO: add construction code here

}

CsoroMfcGdiExView::~CsoroMfcGdiExView()
{
}

BOOL CsoroMfcGdiExView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsoroMfcGdiExView drawing

void CsoroMfcGdiExView::OnDraw(CDC* /*pDC*/)
{
	CsoroMfcGdiExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsoroMfcGdiExView printing

BOOL CsoroMfcGdiExView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsoroMfcGdiExView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsoroMfcGdiExView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CsoroMfcGdiExView diagnostics

#ifdef _DEBUG
void CsoroMfcGdiExView::AssertValid() const
{
	CView::AssertValid();
}

void CsoroMfcGdiExView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsoroMfcGdiExDoc* CsoroMfcGdiExView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsoroMfcGdiExDoc)));
	return (CsoroMfcGdiExDoc*)m_pDocument;
}
#endif //_DEBUG


// CsoroMfcGdiExView message handlers


void CsoroMfcGdiExView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages
	

	// GDI+ Graphics ��ü�� �� �׸���
	Graphics graphics(dc);  // For Using GDI+

	Pen BluePen(Color(255, 0, 0, 255), 20.0f);
	Pen BlackPen(Color(128, 0, 0, 0), 20.0f);

	graphics.DrawLine(&BluePen, Point(10, 50), Point(210,50));
	graphics.DrawLine(&BlackPen, Point(20, 60), Point(220, 60));


	Point pt1(30, 10);
	Point pt2(30, 110);
	Point pt3(230, 20);
	Point pt4(230, 120);
	Point points[4] = { pt1, pt2, pt3, pt4 };

	BluePen.SetLineJoin(LineJoinRound);  // �𼭸��� �ձ�
	BluePen.SetDashStyle(DashStyleDot);
	BluePen.SetStartCap(LineCapRoundAnchor);
	BluePen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLines(&BluePen, points, 4);

	// GDI+ Graphics ��ü�� � �׸���
	Pen RPen(Color(255,255,0,0), 2.0f);
	Pen GPen(Color(255, 0, 255, 0), 2.0f);
	Pen BPen(Color(255, 0, 0, 255), 2.0f);

	Point pointsForCurve[6] = {
		Point(100,300),
		Point(150,140),
		Point(300,340),
		Point(350,100),
		Point(400,240),
		Point(500,10)
	};

	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.DrawCurve(&RPen, pointsForCurve, 6, 0.0f);
	graphics.DrawCurve(&GPen, pointsForCurve, 6, 0.5f);
	graphics.DrawCurve(&BPen, pointsForCurve, 6, 1.0f);
	
	CRect cRect;
	GetClientRect(&cRect);
	BlackPen.SetLineJoin(LineJoinRound);  // �𼭸��� �ձ�
	graphics.DrawRectangle(&BlackPen, 100, 100, 100,100);

}
