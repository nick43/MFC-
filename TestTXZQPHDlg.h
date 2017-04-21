#if !defined(AFX_TESTTXZQPHDLG_H__AED06547_A066_4126_A8F0_82E16A2B8F14__INCLUDED_)
#define AFX_TESTTXZQPHDLG_H__AED06547_A066_4126_A8F0_82E16A2B8F14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestTXZQPHDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestTXZQPHDlg dialog

class CTestTXZQPHDlg : public CDialog
{

// Construction
public:
	CTestTXZQPHDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestTXZQPHDlg)
	enum { IDD = IDD_TXZQ_MB };
	CComboBox	m_txzq_ph;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestTXZQPHDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestTXZQPHDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTXZQPHDLG_H__AED06547_A066_4126_A8F0_82E16A2B8F14__INCLUDED_)
