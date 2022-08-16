// CDlgForImage.cpp : implementation file
//

#include "pch.h"
#include "soroMfcGdiEx.h"
#include "afxdialogex.h"
#include "CDlgForImage.h"


// CDlgForImage dialog

IMPLEMENT_DYNAMIC(CDlgForImage, CDialogEx)

CDlgForImage::CDlgForImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgForImage::~CDlgForImage()
{
}

void CDlgForImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgForImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgForImage message handlers


BOOL CDlgForImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgForImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	CRect cRect;
	GetClientRect(&cRect);

	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Image image(_T("res\\dog1.jpg"));  // dog.bmp
	TextureBrush txBrush(&image, WrapModeTile);
	
	graphics.FillRectangle(&txBrush,
		0, 0,
		cRect.Width(),
		cRect.Height());


}
