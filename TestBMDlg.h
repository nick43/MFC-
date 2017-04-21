#if !defined(AFX_TESTBMDLG_H__B558A8E4_EF86_4F3B_A02E_EDE70FAF19F0__INCLUDED_)
#define AFX_TESTBMDLG_H__B558A8E4_EF86_4F3B_A02E_EDE70FAF19F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestBMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestBMDlg dialog

class CTestBMDlg : public CDialog
{
// Construction
public:
	CTestBMDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestBMDlg)
	enum { IDD = IDD_BM };
	CString	m_BM_100;
	CString	m_BM_10;
	CString	m_BM_110;
	CString	m_BM_120;
	CString	m_BM_128;
	CString	m_BM_130;
	CString	m_BM_140;
	CString	m_BM_150;
	CString	m_BM_160;
	CString	m_BM_170;
	CString	m_BM_180;
	CString	m_BM_190;
	CString	m_BM_192;
	CString	m_BM_20;
	CString	m_BM_200;
	CString	m_BM_210;
	CString	m_BM_220;
	CString	m_BM_230;
	CString	m_BM_240;
	CString	m_BM_250;
	CString	m_BM_255;
	CString	m_BM_30;
	CString	m_BM_40;
	CString	m_BM_50;
	CString	m_BM_60;
	CString	m_BM_64;
	CString	m_BM_70;
	CString	m_BM_80;
	CString	m_BM_90;
	CString	m_BM_1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestBMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestBMDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTBMDLG_H__B558A8E4_EF86_4F3B_A02E_EDE70FAF19F0__INCLUDED_)
