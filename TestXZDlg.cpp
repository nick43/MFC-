// TestXZDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestXZDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestXZDlg dialog


CTestXZDlg::CTestXZDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestXZDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestXZDlg)
	m_xzds = 0;
	//}}AFX_DATA_INIT
}


void CTestXZDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestXZDlg)
	DDX_Text(pDX, IDC_XZ_DS, m_xzds);
	DDV_MinMaxInt(pDX, m_xzds, 0, 360);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestXZDlg, CDialog)
	//{{AFX_MSG_MAP(CTestXZDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestXZDlg message handlers
