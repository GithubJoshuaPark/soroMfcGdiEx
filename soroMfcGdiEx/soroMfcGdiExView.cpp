
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
	
	CRect cRect;
	GetClientRect(&cRect);

	CString ls_str = _T("");
	LARGE_INTEGER lnFreq, lnStart, lnEnd, lnResult;
	::QueryPerformanceFrequency(&lnFreq);

	// GDI+ Graphics 객체로 선 그리기
	Graphics graphics(dc);  // For Using GDI+

	// ⓐ
	::QueryPerformanceCounter(&lnStart);
	Bitmap bitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	CachedBitmap cashedbitmap(&bitmap, &graphics);
	graphics.DrawImage(&bitmap, 0, 0);
	::QueryPerformanceCounter(&lnEnd);

	lnResult.QuadPart = (lnEnd.QuadPart - lnStart.QuadPart) * 1000000 / lnFreq.QuadPart;
	ls_str.Format(_T("DrawCashedBitmap() counter: %u"), lnResult.QuadPart);

	dc.SetBkMode(TRANSPARENT);
	dc.TextOutW(cRect.Width() / 2, 50, ls_str);

	// ⓑ
	//Image image(_T("res\\dog.bmp"));
	//graphics.DrawImage(&image, 0, 0);

	Pen BluePen(Gdiplus::Color(255, 0, 0, 255), 20.0f);
	Pen BlackPen(Gdiplus::Color(128, 0, 0, 0), 20.0f);

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
	Pen RPen(Gdiplus::Color(255,255,0,0), 2.0f);
	Pen GPen(Gdiplus::Color(255, 0, 255, 0), 2.0f);
	Pen BPen(Gdiplus::Color(255, 0, 0, 255), 2.0f);
	Pen GrayPen(Gdiplus::Color(255,192,192,192), 15.0);

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

	SolidBrush solidbrush(Gdiplus::Color(255,0,0,192));
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
				Gdiplus::Color::DarkRed,
				Gdiplus::Color::Transparent
				);
			
			graphics.FillEllipse(&hatchbrush, x * 50 + 800, y * 50 + 200, 40, 40);
			graphics.DrawEllipse(&RPen, x * 50 + 800, y * 50 + 200, 40, 40);

			nCounter++;
			if (nCounter >= HatchStyleMax) break;
		}
	}

	// GradientBrush
	LinearGradientBrush lgBrush(
		Rect(0,0,100,100),
		Gdiplus::Color(128,221,236,255),
		Gdiplus::Color(255, 86, 125, 204),
		LinearGradientModeForwardDiagonal
	);
	dc.TextOutW(25, 525, _T("God will make a way"));
	graphics.FillRectangle(&lgBrush, 0, 500, 1200, 400);

	// DrawString
	Gdiplus::Font font(_T("Arial"), 100, FontStyleBold, UnitPixel);
	PointF ptText(10.0f, 10.0f);
	HatchBrush brush(HatchStyleSmallCheckerBoard,
		Color(255, 128, 0, 0),
		Color::Transparent);
	
	StringFormat sformat;
	sformat.SetHotkeyPrefix(HotkeyPrefixShow);

	graphics.DrawString(_T("Who knows &tomorrow?"), -1, &font, ptText, &sformat,&brush);

	// Path
	GraphicsPath path;
	path.AddRectangle(Rect(200, 200, 100, 100));
	path.AddEllipse(Rect(270, 270, 120, 120));
	FontFamily fontFamily(_T("Arial"));
	path.AddString(_T("He will make a way for me"), -1, &fontFamily,
		FontStyleBold, 48, Point(220, 220), NULL);
	
	path.SetFillMode(FillModeAlternate);  // 반전효과

	graphics.DrawPath(&BPen, &path);
	graphics.FillPath(&brush, &path);

	// Region
	Region Rgn1(Rect(400, 400, 140, 140));
	Region Rgn2(Rect(450, 450, 140, 140));

	Rgn2.Xor(&Rgn1);
	graphics.FillRegion(&brush, &Rgn2);

	ptText = PointF(450.0f, 450.0f);
	Gdiplus::Font font2(_T("굴림"), 30, FontStyleItalic, UnitPixel);
	graphics.DrawString(_T("Rgn2"), -1, &font2, ptText, &sformat, &solidbrush);

	// 좌표계 (회전)
	graphics.DrawRectangle(&GPen, Rect(500,500,150,150));
	ptText = PointF(550.0f, 550.0f);
	graphics.DrawString(_T("Before Rotate"), -1, &font2, ptText, &sformat, &solidbrush);

	Matrix transformMatrix;
	//transformMatrix.Translate(10.0f, 10.0f);
	transformMatrix.Rotate(10.0f);

	graphics.SetTransform(&transformMatrix);
	graphics.DrawRectangle(&RPen, Rect(500, 500, 150, 150));
	graphics.DrawString(_T("After Rotate"), -1, &font2, ptText, &sformat, &solidbrush);

	graphics.RotateTransform(10.0f);
	graphics.DrawRectangle(&RPen, Rect(500, 500, 150, 150));
	graphics.DrawString(_T("After2 Rotate"), -1, &font2, ptText, &sformat, &solidbrush);
}
