
// soroMfcGdiEx.h : main header file for the soroMfcGdiEx application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CsoroMfcGdiExApp:
// See soroMfcGdiEx.cpp for the implementation of this class
//

class CsoroMfcGdiExApp : public CWinApp
{
public:
	CsoroMfcGdiExApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsoroMfcGdiExApp theApp;
