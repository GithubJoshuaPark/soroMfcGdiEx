
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
	

	// GDI+ Graphics 객체로 선 그리기
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

	BluePen.SetLineJoin(LineJoinRound);  // 모서리가 둥금
	BluePen.SetDashStyle(DashStyleDot);
	BluePen.SetStartCap(LineCapRoundAnchor);
	BluePen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLines(&BluePen, points, 4);

	// GDI+ Graphics 객체로 곡선 그리기
	Pen RPen(Color(255,255,0,0), 2.0f);
	Pen GPen(Color(255, 0, 255, 0), 2.0f);
	Pen BPen(Color(255, 0, 0, 255), 2.0f);
	Pen GrayPen(Color(255,192,192,192), 15.0);

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
	BlackPen.SetLineJoin(LineJoinRound);  // 모서리가 둥금
	graphics.DrawRectangle(&BlackPen, 100, 100, 100,100);

	// Drawing ARC and Pie 
	graphics.DrawEllipse(&GrayPen, 500, 200, 200, 200);
	graphics.DrawArc(&RPen, 500, 200, 200, 200, 0.0f, 90.0f);
	graphics.DrawPie(&GPen, 500, 200, 200, 200, 180.0f, 90.0f);

	// Drawing Polygon
	Point points6[6] = {
		Point(630,30),
		Point(780,30),
		Point(780,130),
		Point(730,130),
		Point(730,80),
		Point(630,80)
	};

	SolidBrush solidbrush(Color(255,0,0,192));
	graphics.DrawPolygon(&RPen, points6, 6);
	graphics.FillPolygon(&solidbrush, points6, 6);

	// Using HatchStyle brush
	int nStyle   = HatchStyleHorizontal;
	int nCounter = 0;

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			HatchBrush hatchbrush(
				(HatchStyle)(nStyle + nCounter),
				Color::DarkRed,
				Color::Transparent
				);
			
			graphics.FillEllipse(&hatchbrush, x * 50 + 800, y * 50 + 200, 40, 40);
			graphics.DrawEllipse(&RPen, x * 50 + 800, y * 50 + 200, 40, 40);

			nCounter++;
			if (nCounter >= HatchStyleMax) break;
		}
	}

}
