#if !defined(AFX_TESTZFTDLG_H__FAAECBA2_AD23_4722_B4F1_DDAEBC0EE9A8__INCLUDED_)
#define AFX_TESTZFTDLG_H__FAAECBA2_AD23_4722_B4F1_DDAEBC0EE9A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestZFTDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestZFTDlg dialog

class CTestZFTDlg : public CDialog
{
// Construction
public:
	CTestZFTDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestZFTDlg)
	enum { IDD = IDD_TEXT_ZFT };
	CString	m_redXS;
	CString	m_blueZZHD;
	CString	m_greenXS;
	CString	m_greenZZHD;
	CString	m_redZZHD;
	CString	m_blueXS;
	CString	m_redPJHD;
	CString	m_greenPJHD;
	CString	m_bluePJHD;
	CString	m_redBZC;
	CString	m_greenBZC;
	CString	m_blueBZC;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestZFTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestZFTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTZFTDLG_H__FAAECBA2_AD23_4722_B4F1_DDAEBC0EE9A8__INCLUDED_)
