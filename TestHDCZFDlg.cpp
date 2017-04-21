// TestHDCZFDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestHDCZFDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestHDCZFDlg dialog


CTestHDCZFDlg::CTestHDCZFDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestHDCZFDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestHDCZFDlg)
	m_sfbs = 0;
	//}}AFX_DATA_INIT
}


void CTestHDCZFDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestHDCZFDlg)
	DDX_Text(pDX, IDC_JHYS_SFBS, m_sfbs);
	DDV_MinMaxInt(pDX, m_sfbs, 0, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestHDCZFDlg, CDialog)
	//{{AFX_MSG_MAP(CTestHDCZFDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestHDCZFDlg message handlers
