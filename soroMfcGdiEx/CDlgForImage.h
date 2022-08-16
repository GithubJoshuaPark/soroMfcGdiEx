#pragma once
#include "afxdialogex.h"


// CDlgForImage dialog

class CDlgForImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgForImage)

public:
	CDlgForImage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgForImage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
