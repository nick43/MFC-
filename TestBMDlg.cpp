// TestBMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestBMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestBMDlg dialog


CTestBMDlg::CTestBMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestBMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestBMDlg)
	m_BM_100 = _T("");
	m_BM_10 = _T("");
	m_BM_110 = _T("");
	m_BM_120 = _T("");
	m_BM_128 = _T("");
	m_BM_130 = _T("");
	m_BM_140 = _T("");
	m_BM_150 = _T("");
	m_BM_160 = _T("");
	m_BM_170 = _T("");
	m_BM_180 = _T("");
	m_BM_190 = _T("");
	m_BM_192 = _T("");
	m_BM_20 = _T("");
	m_BM_200 = _T("");
	m_BM_210 = _T("");
	m_BM_220 = _T("");
	m_BM_230 = _T("");
	m_BM_240 = _T("");
	m_BM_250 = _T("");
	m_BM_255 = _T("");
	m_BM_30 = _T("");
	m_BM_40 = _T("");
	m_BM_50 = _T("");
	m_BM_60 = _T("");
	m_BM_64 = _T("");
	m_BM_70 = _T("");
	m_BM_80 = _T("");
	m_BM_90 = _T("");
	m_BM_1 = _T("");
	//}}AFX_DATA_INIT
}


void CTestBMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestBMDlg)
	DDX_Text(pDX, IDC_STATIC_100, m_BM_100);
	DDX_Text(pDX, IDC_STATIC_10, m_BM_10);
	DDX_Text(pDX, IDC_STATIC_110, m_BM_110);
	DDX_Text(pDX, IDC_STATIC_120, m_BM_120);
	DDX_Text(pDX, IDC_STATIC_128, m_BM_128);
	DDX_Text(pDX, IDC_STATIC_130, m_BM_130);
	DDX_Text(pDX, IDC_STATIC_140, m_BM_140);
	DDX_Text(pDX, IDC_STATIC_150, m_BM_150);
	DDX_Text(pDX, IDC_STATIC_160, m_BM_160);
	DDX_Text(pDX, IDC_STATIC_170, m_BM_170);
	DDX_Text(pDX, IDC_STATIC_180, m_BM_180);
	DDX_Text(pDX, IDC_STATIC_190, m_BM_190);
	DDX_Text(pDX, IDC_STATIC_192, m_BM_192);
	DDX_Text(pDX, IDC_STATIC_20, m_BM_20);
	DDX_Text(pDX, IDC_STATIC_200, m_BM_200);
	DDX_Text(pDX, IDC_STATIC_210, m_BM_210);
	DDX_Text(pDX, IDC_STATIC_220, m_BM_220);
	DDX_Text(pDX, IDC_STATIC_230, m_BM_230);
	DDX_Text(pDX, IDC_STATIC_240, m_BM_240);
	DDX_Text(pDX, IDC_STATIC_250, m_BM_250);
	DDX_Text(pDX, IDC_STATIC_255, m_BM_255);
	DDX_Text(pDX, IDC_STATIC_30, m_BM_30);
	DDX_Text(pDX, IDC_STATIC_40, m_BM_40);
	DDX_Text(pDX, IDC_STATIC_50, m_BM_50);
	DDX_Text(pDX, IDC_STATIC_60, m_BM_60);
	DDX_Text(pDX, IDC_STATIC_64, m_BM_64);
	DDX_Text(pDX, IDC_STATIC_70, m_BM_70);
	DDX_Text(pDX, IDC_STATIC_80, m_BM_80);
	DDX_Text(pDX, IDC_STATIC_90, m_BM_90);
	DDX_Text(pDX, IDC_STATIC_1, m_BM_1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestBMDlg, CDialog)
	//{{AFX_MSG_MAP(CTestBMDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestBMDlg message handlers
