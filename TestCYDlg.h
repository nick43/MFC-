#if !defined(AFX_TESTCYDLG_H__802317A5_D7DC_456C_B254_8FEB08854741__INCLUDED_)
#define AFX_TESTCYDLG_H__802317A5_D7DC_456C_B254_8FEB08854741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestCYDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestCYDlg dialog

class CTestCYDlg : public CDialog
{
// Construction
public:
	CTestCYDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestCYDlg)
	enum { IDD = IDD_TEST_CY };
	int		m_xPlace;
	int		m_yPlace;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestCYDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCYDLG_H__802317A5_D7DC_456C_B254_8FEB08854741__INCLUDED_)
