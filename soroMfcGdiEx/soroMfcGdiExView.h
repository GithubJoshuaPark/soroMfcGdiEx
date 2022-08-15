
// soroMfcGdiExView.h : interface of the CsoroMfcGdiExView class
//

#pragma once


class CsoroMfcGdiExView : public CView
{
protected: // create from serialization only
	CsoroMfcGdiExView() noexcept;
	DECLARE_DYNCREATE(CsoroMfcGdiExView)

// Attributes
public:
	CsoroMfcGdiExDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CsoroMfcGdiExView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // debug version in soroMfcGdiExView.cpp
inline CsoroMfcGdiExDoc* CsoroMfcGdiExView::GetDocument() const
   { return reinterpret_cast<CsoroMfcGdiExDoc*>(m_pDocument); }
#endif

