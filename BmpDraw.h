// BmpDraw.h : main header file for the BMPDRAW application
//

#if !defined(AFX_BMPDRAW_H__4259B87B_DE5E_487F_AB5D_1B8AA9D9F449__INCLUDED_)
#define AFX_BMPDRAW_H__4259B87B_DE5E_487F_AB5D_1B8AA9D9F449__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawApp:
// See BmpDraw.cpp for the implementation of this class
//

class CBmpDrawApp : public CWinApp
{
public:
	CBmpDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBmpDrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPDRAW_H__4259B87B_DE5E_487F_AB5D_1B8AA9D9F449__INCLUDED_)
