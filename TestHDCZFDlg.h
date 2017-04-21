#if !defined(AFX_TESTHDCZFDLG_H__EA328B00_B3A5_4386_91BC_39FEBD3FCDC0__INCLUDED_)
#define AFX_TESTHDCZFDLG_H__EA328B00_B3A5_4386_91BC_39FEBD3FCDC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestHDCZFDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestHDCZFDlg dialog

class CTestHDCZFDlg : public CDialog
{
// Construction
public:
	CTestHDCZFDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestHDCZFDlg)
	enum { IDD = IDD_HDCZF };
	int		m_sfbs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestHDCZFDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestHDCZFDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTHDCZFDLG_H__EA328B00_B3A5_4386_91BC_39FEBD3FCDC0__INCLUDED_)
