// TestCYDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestCYDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestCYDlg dialog


CTestCYDlg::CTestCYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestCYDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestCYDlg)
	m_xPlace = 0;
	m_yPlace = 0;
	//}}AFX_DATA_INIT
}


void CTestCYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestCYDlg)
	DDX_Text(pDX, IDC_EDIT_X, m_xPlace);
	DDX_Text(pDX, IDC_EDIT_Y, m_yPlace);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestCYDlg, CDialog)
	//{{AFX_MSG_MAP(CTestCYDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCYDlg message handlers


//添加的采样对话框 初始化对话框
BOOL CTestCYDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
