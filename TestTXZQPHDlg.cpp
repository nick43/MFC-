// TestTXZQPHDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestTXZQPHDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestTXZQPHDlg dialog


CTestTXZQPHDlg::CTestTXZQPHDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestTXZQPHDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestTXZQPHDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTestTXZQPHDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestTXZQPHDlg)
	DDX_Control(pDX, IDC_TXZQ_PH, m_txzq_ph);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestTXZQPHDlg, CDialog)
	//{{AFX_MSG_MAP(CTestTXZQPHDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestTXZQPHDlg message handlers


/*��ȡ��ǰ�����˵�������*/
int Index;          

//����OnOK����,��ʹ��extern��������:View.cpp��void CBmpDrawView::OnTxzqPh()�е��� 
void CTestTXZQPHDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
	
	Index=m_txzq_ph.GetCurSel();

}
