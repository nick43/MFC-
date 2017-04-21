// TestZFTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmpDraw.h"
#include "TestZFTDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestZFTDlg dialog


CTestZFTDlg::CTestZFTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestZFTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestZFTDlg)
	m_redXS = _T("");
	m_blueZZHD = _T("");
	m_greenXS = _T("");
	m_greenZZHD = _T("");
	m_redZZHD = _T("");
	m_blueXS = _T("");
	m_redPJHD = _T("");
	m_greenPJHD = _T("");
	m_bluePJHD = _T("");
	m_redBZC = _T("");
	m_greenBZC = _T("");
	m_blueBZC = _T("");
	//}}AFX_DATA_INIT
}


void CTestZFTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestZFTDlg)
	DDX_Text(pDX, IDC_STATIC_XS_RED, m_redXS);
	DDX_Text(pDX, IDC_STATIC_ZZHD_BLUE, m_blueZZHD);
	DDX_Text(pDX, IDC_STATIC_XS_GREEN, m_greenXS);
	DDX_Text(pDX, IDC_STATIC_ZZHD_GREEN, m_greenZZHD);
	DDX_Text(pDX, IDC_STATIC_ZZHD_RED, m_redZZHD);
	DDX_Text(pDX, IDC_STATIC_XS_BLUE, m_blueXS);
	DDX_Text(pDX, IDC_STATIC_PJHD_RED, m_redPJHD);
	DDX_Text(pDX, IDC_STATIC_PJHD_GREEN, m_greenPJHD);
	DDX_Text(pDX, IDC_STATIC_PJHD_BLUE, m_bluePJHD);
	DDX_Text(pDX, IDC_STATIC_BZC_RED, m_redBZC);
	DDX_Text(pDX, IDC_STATIC_BZC_GREEN, m_greenBZC);
	DDX_Text(pDX, IDC_STATIC_BZC_BLUE, m_blueBZC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestZFTDlg, CDialog)
	//{{AFX_MSG_MAP(CTestZFTDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestZFTDlg message handlers

BOOL CTestZFTDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CTestZFTDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	/********************************************************************************/
	/* �ص�֪ʶ:(�ٶ�)                                                              */
	/* �����View.cpp�а�һ��������ֵ���������Ի���                                 */
	/*                                                                              */
	/* ����һ:��View.h�ж����pubic����ֻ����View.cpp����                           */
	/* �����:����һ��Struct.h�д�ȫ�ֱ���,��2�������зֱ����#include "Struct.h"   */
	/*                                                                              */
	/* �������һ: (CSDN ����)������ A& a �����Ի����ﶼ���Է���a                   */
	/* ���������: (CSDN ����)����                                                  */
	/*                                                                              */
	/* ���:��View.cpp�ж���ȫ�ֱ��� void CBmpDrawView::OnZftYt() ǰ�� �������в��� */
	/*      ��dialog��cpp�м�void CTestZFTDlg::OnPaint()���ڶ���һ��extern int a    */
	/********************************************************************************/

	extern int Red[256],Green[256],Blue[256];
	extern int RedBH[256],GreenBH[256],BlueBH[256];
	extern int signZFT,flagZFT;
	
	/*signZFT��ʼ��ȫ�ֱ���Ϊ0,flagZFT��void CBmpDrawView::OnZftYt()�и�ֵΪ3 */
	if(flagZFT==1 || signZFT==0 )
	{
		/*д�ڸÿռ��п���ʡ��Invalidate()���*/
		/*��ȡ�ؼ���CDCָ��*/
		CRect rectpic;
		GetDlgItem(IDC_STATIC_KJ)->GetWindowRect(&rectpic);
		
		int x,y;
		x=rectpic.Width();
		y=rectpic.Height();
		
		CWnd *pWnd=GetDlgItem(IDC_STATIC_KJ);
		CDC *pDC=pWnd->GetDC();
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *RedPen=new CPen();                              //�������ʶ���
		RedPen->CreatePen(PS_SOLID,1,RGB(255,0,0));           //��ɫ����
		CGdiObject *RedOlderPen=pDC->SelectObject(RedPen);    //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		/*��ͼ*/
		pDC->Rectangle(9,16,312,147);      //��һ�����ο�
		
		pDC->MoveTo(15,20);                //����������
		pDC->LineTo(15,128);               //Y����
		pDC->LineTo(305,128);              //X����
		
		pDC->MoveTo(305,128);              //����X��ͷ
		pDC->LineTo(300,123);              //�����ϱ߼�ͷ
		pDC->MoveTo(305,128); 
		pDC->LineTo(300,133);              //�����±߼�ͷ
		
		pDC->MoveTo(15,20);                //����Y��ͷ
		pDC->LineTo(10,25);                //������߼�ͷ
		pDC->MoveTo(15,20);
		pDC->LineTo(20,25);                //�����ұ߼�ͷ
		
		/**********************************************************************/
		/* TextOut��������:                                                   */
		/* �ú����õ�ǰѡ������塢������ɫ��������ɫ��һ���ַ���д��ָ��λ�� */
		/* BOOL TextOut(HDC hdc,int x,int y,LPCTSTR str,int numStr)           */
		/* ��ʾ:x��ʼ����,y��ʼ����,�ַ���,�ַ������ַ�����                   */
		/**********************************************************************/
		
		/**********************************************************************/
		/* SetTextColor��������:                                              */
		/* ����ָ���豸����(HDC)��������ɫ                                    */
		/* SetTextColor (HDC, COLORREF) ��:SetTextColor(HDC,RGB(255,0,0));    */
		/**********************************************************************/
		
		CString str;
		for(int i=0;i<=5;i++)                    //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,130,str);       //�������
			
			pDC->MoveTo(15+48*i,128);            //����X��̶�
			pDC->LineTo(15+48*i,125);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,128-20*i);            //����Y��̶�
			pDC->LineTo(18,128-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,128);
			if( (128-16) > (Red[i]/40) )
				pDC->LineTo(15+i,128-(Red[i]/40));   
			else
				pDC->LineTo(15+i,16);            //�������εĻ����θ�
		}
		
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *GreenPen=new CPen();                             //�������ʶ���
		GreenPen->CreatePen(PS_SOLID,1,RGB(0,255,0));          //��ɫ����
		CGdiObject *GreenOlderPen=pDC->SelectObject(GreenPen); //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		pDC->Rectangle(9,167,312,308);     //��һ�����ο�
		
		pDC->MoveTo(15,171);               //����������
		pDC->LineTo(15,288);               //Y����
		pDC->LineTo(305,288);              //X����
		
		pDC->MoveTo(305,288);              //����X��ͷ
		pDC->LineTo(300,283);              //�����ϱ߼�ͷ
		pDC->MoveTo(305,288);
		pDC->LineTo(300,293);              //�����±߼�ͷ
		
		pDC->MoveTo(15,171);                //����Y��ͷ
		pDC->LineTo(10,176);                //������߼�ͷ
		pDC->MoveTo(15,171);
		pDC->LineTo(20,176);                //�����ұ߼�ͷ
		
		for(i=0;i<=5;i++)                   //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,290,str);       //�������
			
			pDC->MoveTo(15+48*i,288);            //����X��̶�
			pDC->LineTo(15+48*i,285);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,288-20*i);            //����Y��̶�
			pDC->LineTo(18,288-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,288);
			if( (288-167) > (Green[i]/40) )
				pDC->LineTo(15+i,288-(Green[i]/40));   
			else
				pDC->LineTo(15+i,167);            //�������εĻ����θ�
		}
		
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *BluePen=new CPen();                             //�������ʶ���
		BluePen->CreatePen(PS_SOLID,1,RGB(0,0,255));         //��ɫ����
		CGdiObject *BlueOlderPen=pDC->SelectObject(BluePen);  //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		pDC->Rectangle(9,327,312,468);      //��һ�����ο�
		
		pDC->MoveTo(15,331);                //����������
		pDC->LineTo(15,448);                //Y����
		pDC->LineTo(305,448);               //X����
		
		pDC->MoveTo(305,448);               //����X��ͷ
		pDC->LineTo(300,443);               //�����ϱ߼�ͷ
		pDC->MoveTo(305,448);
		pDC->LineTo(300,453);               //�����±߼�ͷ
		
		pDC->MoveTo(15,331);                //����Y��ͷ
		pDC->LineTo(10,336);                //������߼�ͷ
		pDC->MoveTo(15,331);
		pDC->LineTo(20,336);                //�����ұ߼�ͷ
		
		
		for(i=0;i<=5;i++)                   //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,450,str);       //�������
			
			pDC->MoveTo(15+48*i,448);            //����X��̶�
			pDC->LineTo(15+48*i,445);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,448-20*i);            //����Y��̶�
			pDC->LineTo(18,448-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,448);
			if( (448-327) > (Blue[i]/40) )
				pDC->LineTo(15+i,448-(Blue[i]/40));   
			else
				pDC->LineTo(15+i,327);            //�������εĻ����θ�
		}
		
		
		
		//�ָ���ǰ�Ļ���
		pDC->SelectObject(RedOlderPen);
		pDC->SelectObject(GreenOlderPen);
		pDC->SelectObject(BlueOlderPen);
		delete RedPen;
		delete GreenPen;
		delete BluePen;
		
		ReleaseDC(pDC);
		
		/************************************************************/
		/* �ص㣺û��returnʱ��һ��ԭͼֱ��ͼ����ȷ��ʾ��           */
		/* �������Ա仯������Ա仯��ͻ����ִ������ı仯��ֱ��ͼ */
		/************************************************************/

		return;
	}
	
	if(signZFT==1)
	{
		/*��ȡ�ؼ���CDCָ��*/
		CRect rectpic;
		GetDlgItem(IDC_STATIC_KJ)->GetWindowRect(&rectpic);
		
		int x,y;
		x=rectpic.Width();
		y=rectpic.Height();
		
		CWnd *pWnd=GetDlgItem(IDC_STATIC_KJ);
		CDC *pDC=pWnd->GetDC();
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *RedPen=new CPen();                              //�������ʶ���
		RedPen->CreatePen(PS_SOLID,1,RGB(255,0,0));           //��ɫ����
		CGdiObject *RedOlderPen=pDC->SelectObject(RedPen);    //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		/*��ͼ*/
		pDC->Rectangle(9,16,312,147);      //��һ�����ο�
		
		pDC->MoveTo(15,20);                //����������
		pDC->LineTo(15,128);               //Y����
		pDC->LineTo(305,128);              //X����
		
		pDC->MoveTo(305,128);              //����X��ͷ
		pDC->LineTo(300,123);              //�����ϱ߼�ͷ
		pDC->MoveTo(305,128); 
		pDC->LineTo(300,133);              //�����±߼�ͷ
		
		pDC->MoveTo(15,20);                //����Y��ͷ
		pDC->LineTo(10,25);                //������߼�ͷ
		pDC->MoveTo(15,20);
		pDC->LineTo(20,25);                //�����ұ߼�ͷ
		
		/**********************************************************************/
		/* TextOut��������:                                                   */
		/* �ú����õ�ǰѡ������塢������ɫ��������ɫ��һ���ַ���д��ָ��λ�� */
		/* BOOL TextOut(HDC hdc,int x,int y,LPCTSTR str,int numStr)           */
		/* ��ʾ:x��ʼ����,y��ʼ����,�ַ���,�ַ������ַ�����                   */
		/**********************************************************************/
		
		/**********************************************************************/
		/* SetTextColor��������:                                              */
		/* ����ָ���豸����(HDC)��������ɫ                                    */
		/* SetTextColor (HDC, COLORREF) ��:SetTextColor(HDC,RGB(255,0,0));    */
		/**********************************************************************/
		
		CString str;
		for(int i=0;i<=5;i++)                    //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,130,str);       //�������
			
			pDC->MoveTo(15+48*i,128);            //����X��̶�
			pDC->LineTo(15+48*i,125);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,128-20*i);            //����Y��̶�
			pDC->LineTo(18,128-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,128);
			if( (128-16) > (RedBH[i]/40) )
				pDC->LineTo(15+i,128-(RedBH[i]/40));   
			else
				pDC->LineTo(15+i,16);            //�������εĻ����θ�
		}
		
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *GreenPen=new CPen();                             //�������ʶ���
		GreenPen->CreatePen(PS_SOLID,1,RGB(0,255,0));          //��ɫ����
		CGdiObject *GreenOlderPen=pDC->SelectObject(GreenPen); //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		pDC->Rectangle(9,167,312,308);     //��һ�����ο�
		
		pDC->MoveTo(15,171);               //����������
		pDC->LineTo(15,288);               //Y����
		pDC->LineTo(305,288);              //X����
		
		pDC->MoveTo(305,288);              //����X��ͷ
		pDC->LineTo(300,283);              //�����ϱ߼�ͷ
		pDC->MoveTo(305,288);
		pDC->LineTo(300,293);              //�����±߼�ͷ
		
		pDC->MoveTo(15,171);                //����Y��ͷ
		pDC->LineTo(10,176);                //������߼�ͷ
		pDC->MoveTo(15,171);
		pDC->LineTo(20,176);                //�����ұ߼�ͷ
		
		for(i=0;i<=5;i++)                   //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,290,str);       //�������
			
			pDC->MoveTo(15+48*i,288);            //����X��̶�
			pDC->LineTo(15+48*i,285);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,288-20*i);            //����Y��̶�
			pDC->LineTo(18,288-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,288);
			if( (288-167) > (GreenBH[i]/40) )
				pDC->LineTo(15+i,288-(GreenBH[i]/40));   
			else
				pDC->LineTo(15+i,167);            //�������εĻ����θ�
		}
		
		
		/********************/
		/*�ص�:��ֱ��ͼ,��ɫ*/
		/********************/
		CPen *BluePen=new CPen();                             //�������ʶ���
		BluePen->CreatePen(PS_SOLID,1,RGB(0,0,255));         //��ɫ����
		CGdiObject *BlueOlderPen=pDC->SelectObject(BluePen);  //ѡ�е�ǰ��ɫ����,��������ǰ�Ļ���
		
		pDC->Rectangle(9,327,312,468);      //��һ�����ο�
		
		pDC->MoveTo(15,331);                //����������
		pDC->LineTo(15,448);                //Y����
		pDC->LineTo(305,448);               //X����
		
		pDC->MoveTo(305,448);               //����X��ͷ
		pDC->LineTo(300,443);               //�����ϱ߼�ͷ
		pDC->MoveTo(305,448);
		pDC->LineTo(300,453);               //�����±߼�ͷ
		
		pDC->MoveTo(15,331);                //����Y��ͷ
		pDC->LineTo(10,336);                //������߼�ͷ
		pDC->MoveTo(15,331);
		pDC->LineTo(20,336);                //�����ұ߼�ͷ
		
		
		for(i=0;i<=5;i++)                   //дX��̶���
		{
			str.Format("%d",i*50);               //0-255֮�����6���̶�ֵ
			pDC->SetTextColor(RGB(255,0,255));   //����������ɫ
			pDC->TextOut(15+48*i,450,str);       //�������
			
			pDC->MoveTo(15+48*i,448);            //����X��̶�
			pDC->LineTo(15+48*i,445);
		}
		
		for(i=0;i<=5;i++)                        //дY��̶���
		{
			pDC->MoveTo(15,448-20*i);            //����Y��̶�
			pDC->LineTo(18,448-20*i);
		}
		
		/*����ֱ��ͼ��Ҫ�Ĵ���*/
		for(i=1;i<256;i++)
		{
			pDC->MoveTo(15+i,448);
			if( (448-327) > (BlueBH[i]/40) )
				pDC->LineTo(15+i,448-(BlueBH[i]/40));   
			else
				pDC->LineTo(15+i,327);            //�������εĻ����θ�
		}
		
		
		
		//�ָ���ǰ�Ļ���
		pDC->SelectObject(RedOlderPen);
		pDC->SelectObject(GreenOlderPen);
		pDC->SelectObject(BlueOlderPen);
		delete RedPen;
		delete GreenPen;
		delete BluePen;
		
		ReleaseDC(pDC);
	}
	
	// Do not call CDialog::OnPaint() for painting messages
}
