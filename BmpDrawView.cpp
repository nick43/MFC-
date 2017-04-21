// BmpDrawView.cpp : implementation of the CBmpDrawView class
//

#include "stdafx.h"
#include "BmpDraw.h"

#include "BmpDrawDoc.h"
#include "BmpDrawView.h"

#include "ImageStruct.h"

#include "MainFrm.h"

//����ͷ�ļ�
#include "TestCYDlg.h"

//��ʾԭͼֱ��ͼͷ�ļ�
#include "TestZFTDlg.h"

//����ֵ ����
#include<math.h>

//��������-�Ҷȼ���ֵ (�ҶȲ�ֵ��)
#include "TestHDCZFDlg.h"

//��������-��ת���� (0-360)
#include "TestXZDlg.h"

//ͼ����ǿ-ƽ��(4��ģ��)
#include "TestTXZQPHDlg.h"

//����ѹ��-��ʾ�Ҷ�ֵ�����
#include "TestBMDlg.h"

#include<stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView

IMPLEMENT_DYNCREATE(CBmpDrawView, CView)

BEGIN_MESSAGE_MAP(CBmpDrawView, CView)
	//{{AFX_MSG_MAP(CBmpDrawView)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_FILE1, OnUpdateFileMruFile1)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHOW_TWO, OnShowTwo)
	ON_COMMAND(ID_LH_2, OnLh2)
	ON_COMMAND(ID_LH_4, OnLh4)
	ON_COMMAND(ID_LH_8, OnLh8)
	ON_COMMAND(ID_LH_16, OnLh16)
	ON_COMMAND(ID_LH_32, OnLh32)
	ON_COMMAND(ID_LH_64, OnLh64)
	ON_COMMAND(ID_SHOW_HD, OnShowHd)
	ON_COMMAND(ID_CY, OnCy)
	ON_COMMAND(ID_XXHD_JX, OnXxhdJx)
	ON_COMMAND(ID_XXHD_QB, OnXxhdQb)
	ON_COMMAND(ID_XXHD_YD, OnXxhdYd)
	ON_COMMAND(ID_XXHD_ZQ, OnXxhdZq)
	ON_COMMAND(ID_ZFT_YT, OnZftYt)
	ON_COMMAND(ID_FXXHD_PF, OnFxxhdPf)
	ON_COMMAND(ID_FXXHD_HS, OnFxxhdHs)
	ON_COMMAND(ID_FXXHD_LS, OnFxxhdLs)
	ON_COMMAND(ID_ZFT_BH, OnZftBh)
	ON_COMMAND(ID_FXXHD_JHH, OnFxxhdJhh)
	ON_COMMAND(ID_JHYS_SXXCZ, OnJhysSxxcz)
	ON_COMMAND(ID_JHYS_ZJLCZ, OnJhysZjlcz)
	ON_COMMAND(ID_JHBH_PY, OnJhbhPy)
	ON_COMMAND(ID_JHBH_FZ, OnJhbhFz)
	ON_COMMAND(ID_JHBH_XZ, OnJhbhXz)
	ON_COMMAND(ID_TXZQ_PH, OnTxzqPh)
	ON_COMMAND(ID_RH_Laplacian, OnRHLaplacian)
	ON_COMMAND(ID_RH_Sobel, OnRHSobel)
	ON_COMMAND(ID_RH_Isotropic, OnRHIsotropic)
	ON_COMMAND(ID_RH_Prewitt, OnRHPrewitt)
	ON_COMMAND(ID_RH_GTMB, OnRhGtmb)
	ON_COMMAND(ID_BM_HFM, OnBmHfm)
	ON_COMMAND(ID_EZTX_XH, OnEztxXh)
	ON_COMMAND(ID_HD_BIT, OnHdBit)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSave)
	ON_COMMAND(ID_Hough_ZX, OnHoughZX)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView construction/destruction

CBmpDrawView::CBmpDrawView()
{
	// TODO: add construction code here
	//��ʼ����ʾͼƬ��x y����
}

CBmpDrawView::~CBmpDrawView()
{
}

BOOL CBmpDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView drawing

void CBmpDrawView::OnDraw(CDC* pDC)
{
	CBmpDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	/*��OnDraw������ʵ��ͼƬ�������ʾ����*/
	if(!pDoc)
		return;

	if( EntName.Compare(_T("bmp")) == 0 )      //bmp��ʽ
	{
		ReadBmp();                             //ͼƬ��Ϣ������ȫ�ֱ���
		ShowWindowInfo();                      //״̬����ʾ�ļ���Ϣ ·�� ��С ����
		ShowBitmap(pDC,BmpName);               //��ʾͼƬ
	}
	else if( EntName.Compare(_T("jpg")) == 0 )
	{
		//ShowJpgGif(pDC,BmpName,1,1);
	}


}

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView printing

BOOL CBmpDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBmpDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBmpDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView diagnostics

#ifdef _DEBUG
void CBmpDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpDrawDoc* CBmpDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpDrawDoc)));
	return (CBmpDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawView message handlers


/*****************************************************/
/*   numPicture=0ʱ��ʾ��ʾ������Ϣ                  */
/*   numPicture=1ʱ��ʾ1��ͼƬ��OnFileOpen�ж���     */
/*   numPicture=2ʱ��ʾ2��ͼƬ�ʹ����ڴ������ж��� */ 
/*****************************************************/

/*****************************************************/
/*   level=0ʱ��ʾ2��ͼƬ                            */
/*   level=1ʱ��ʾ�Ҷ�ͼƬ                           */
/*   level=2 4 8 16 32 63ʱ��ͬ����������ͼƬ        */ 
/*****************************************************/

int numPicture=0;       //��ʾͼƬ�� 
int level=0;            //��ʾ�����ȼ�


/*ֱ��ͼ��Ǳ��� signZFT=1ʱ���Ի�����Ա仯���ֱ��ͼ*/
int signZFT=0; 
int flagZFT=0;          
/*������ǰ����Ϊ�����������Ȳ������Ի�����Ա仯������Ҫ��ֵΪ0 ��ShowBitmap�и�ֵ����*/


/*������ʾͼ������ʱ�ĳ�������*/
int flagSF=0;          //ͼ�񼸺α任���ű任
int m_nDrawWidthSF=0;  //ͼ����ʾ������ź�
int	m_nDrawHeightSF=0; //ͼ����ʾ�߶����ź�

//��ʾBMP��ʽͼƬ
void CBmpDrawView::ShowBitmap(CDC *pDC, CString BmpName)
{
	//��ʾһ��ͼƬ numPicture == 1
	//��ʾͼƬ����LoadImage
	HBITMAP m_hBitmap;
	m_hBitmap = (HBITMAP) LoadImage(NULL,BmpName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
	//AfxMessageBox(BmpName);
	
	/**************************************************/
	/** 1.Ҫװ��OEMͼ������˲���ֵΪ0             **/
	/** OBM_ OEM��λͼ��OIC_OEMͼ�ꣻOCR_OEM�����   **/
	/** 2.BmpNameҪװ��ͼƬ���ļ���                  **/
	/** 3.װ��ͼ������: IMAGE_BITMAP-װ��λͼ        **/
	/**               IMAGE_CURSOR-װ�ع��          **/
	/**               IMAGE_ICON-װ��ͼ��            **/
	/** 4.ָ��ͼ�����Ŀ�Ⱥͳ��� ������Ϊ��λ    **/
	/** �˲���Ϊ�㲢��ֵLR_DEFAULTSIZEû�б�ʹ����ô **/
	/** ����ʹ��Ŀǰ����Դ���                       **/
	/**************************************************/
	
	if( m_bitmap.m_hObject )
	{
		m_bitmap.Detach();            //m_bitmapΪ������λͼ����
	}
	m_bitmap.Attach(m_hBitmap);
	
	//�߽�
	CRect rect;
	GetClientRect(&rect);
	
	//ͼƬ��ʾ(x,y)��ʼ����
	int m_showX=0;
	int m_showY=0;
	
	int m_nWindowWidth = rect.right - rect.left;   //����ͻ������
	int m_nWindowHeight = rect.bottom - rect.top;  //����ͻ����߶�
	
	//ͨ����ʾͼƬ�������ͼƬ����λ��
	m_nDrawWidth = m_nDrawWidth;
	m_nDrawHeight = m_nDrawHeight;
	
	if(m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_nDrawHeight/2;
	else
		m_showY = 0;
	
	
	//���岢����һ���ڴ��豸����
	CDC dcBmp;
	if( !dcBmp.CreateCompatibleDC(pDC) )   //���������Ե�DC
		return;
	
	BITMAP m_bmp;                          //��ʱbmpͼƬ����
	//MessageBox("ͼƬ���ڵ���!");
	m_bitmap.GetBitmap(&m_bmp);            //��ͼƬ����λͼ��
	   //MFC afxwin1.inl ���� GetBitmap��
	
	CBitmap *pbmpOld = NULL;
	dcBmp.SelectObject(&m_bitmap);         //��λͼѡ����ʱ�ڴ��豸����
	
	//ͼƬ��ʾ���ú���BitBlt 
	//pDC->BitBlt(m_showX,m_showY,m_bmp.bmWidth,m_bmp.bmHeight,&dcBmp,0,0,SRCCOPY);    //m_showX m_showY ��� 0 0 
	if(m_nDrawWidth<650 && m_nDrawHeight<650)
		pDC->StretchBlt(0,0,m_nDrawWidth,m_nDrawHeight,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
	else
		pDC->StretchBlt(0,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //��ʾ��С��Ϊ640*640
	
	//ShowWindowsInfo();
	
	/******************************************************/
	/** ����x��yλͼĿ��������Ͻ�x��y������ֵ ����      **/
	/** nWidth��nHeigthλͼĿ����ε��߼���Ⱥ͸߶�      **/
	/** pSrcDC��ʾԴ�豸CDCָ��                          **/
	/** xSrc��ySrc��ʾλͼԴ���ε����Ͻǵ�x��y�߼�����ֵ **/
	/** dwRop��ʾ��ʾλͼ�Ĺ�դ������ʽ                  **/
	/** SRCCOPY����ֱ�ӽ�λͼ���Ƶ�Ŀ�껷����            **/
	/******************************************************/
	
	dcBmp.SelectObject(pbmpOld);           //�ָ���ʱDC��λͼ
	DeleteObject(&m_bitmap);               //ɾ��λͼ
	dcBmp.DeleteDC();                      //ɾ����̨DC
	
	//��ʾ��2��ͼƬ
	if( numPicture == 2 )
	{
		//��ʾͼƬ����LoadImage
		HBITMAP m_hBitmapChange;
		if(level==0) //��ʾ2��ͼ
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else
		if(level==1) //�Ҷ�ͼƬ
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����2
		if(level==2)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else
		if(level==3) //ͼƬ����
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����4
		if(level==4)  
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����8
		if(level==8)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����16
		if(level==16)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����32
		if(level==32)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //����64
		if(level==64)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		//�Ҷ�ֱ��ͼ 
		else        //level=100 D(B)=D(A)*0.8 �Ҷȼ�С
		if(level==100)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //level=101 D(B)=-1*D(A)+255 �Ҷ���
		if(level==101)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //�Ҷȱ仯�ƶ� D(B)=D(A)+50
		if(level=102)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //�Ҷȱ仯��ǿ D(B)=1.5*D(A)
		if(level=103)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //�Ҷȱ仯��ǿ D(B)=D(A)*D(A)/255 �����Ա仯
		if(level=104)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //�Ҷȱ仯��ǿ D(B)=D(A)*D(A)/255 �����Ա仯
		if(level=105)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //�Ҷȱ仯���� �����Ա仯 �ڰ����� ��ֵ��
		if(level=106)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}

		else        //��ʾ���⻯ֱ��ͼ�ʹ���ͼ��
		if(level=200)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //���α任-�Ҷȼ���ֵ������ڲ�ֵ-ͼ������
		if(level==300)
		{
			signZFT=0;      //���ÿ���ֱ��ͼ
			flagZFT=0;
			flagSF=1;       //ͼ��������ʾ����ʱ��Ǳ���Ϊ1
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //��Ϊ�ڵ��� ͼ����ǿ--ƽ��ʱ���Ǳ���:File:afxinl.inl Line:418
		if(level==400)
		{
			signZFT=0;      //���ÿ���ֱ��ͼ
			flagZFT=0;
			flagSF=1;       //ͼ��������ʾ����ʱ��Ǳ���Ϊ1
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}

		if( m_bitmap.m_hObject )
		{
			m_bitmap.Detach();            //m_bitmapΪ������λͼ����
		}
		m_bitmap.Attach(m_hBitmapChange);

		//���岢����һ���ڴ��豸����
		CDC dcBmp;
		if( !dcBmp.CreateCompatibleDC(pDC) )   //���������Ե�DC
			return;
		
		BITMAP m_bmp;                          //��ʱbmpͼƬ����
		m_bitmap.GetBitmap(&m_bmp);            //��ͼƬ����λͼ��
		
		CBitmap *pbmpOld = NULL;
		dcBmp.SelectObject(&m_bitmap);         //��λͼѡ����ʱ�ڴ��豸����

		//ͼƬ��ʾ���ú���StretchBlt 
		if(flagSF==1)
		{
			CString str;
			str.Format("���ų�=%d ��%d ԭͼ��=%d ��=%d",m_nDrawWidthSF,m_nDrawHeightSF,m_nWidth,m_nHeight);
			AfxMessageBox(str);
			flagSF=0;
			//m_nDrawWidthSF���Ŵ˴����������ڲ�ֵ���и�ֵ
			if(m_nDrawWidthSF<650 && m_nDrawHeightSF<650)   
				pDC->StretchBlt(m_nWindowWidth-m_nDrawWidthSF,0,m_nDrawWidthSF,m_nDrawHeightSF,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
			else
				pDC->StretchBlt(m_nWindowWidth-640,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //��ʾ��СΪ640*640
		}
		else
		{
			if(m_nDrawWidth<650 && m_nDrawHeight<650)
				pDC->StretchBlt(m_nWindowWidth-m_nDrawWidth,0,m_nDrawWidth,m_nDrawHeight,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
			else
				pDC->StretchBlt(m_nWindowWidth-640,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //��ʾ��СΪ640*640
		}

		dcBmp.SelectObject(pbmpOld);           //�ָ���ʱDC��λͼ
	}
}

bool CBmpDrawView::ShowJpgGif(CDC *pDC, CString strPath, int x, int y)
{
	return false;
}


//************ ʹ�½��˵������� *********//
void CBmpDrawView::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//************ ʹ"������ļ�"������ *********//
void CBmpDrawView::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//**************�ļ���****************//
void CBmpDrawView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	//���ָ�ʽ���ļ���bmp gif jpg tiff
	CString filter;
	filter="�����ļ�(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter,NULL);          //�����򿪶Ի���
	
	//����ȷ����ť dlg.DoModal() ������ʾ�Ի���
	if( dlg.DoModal() == IDOK )
	{
		//��ȡ·�� �ļ��� ��չ�ļ���
		BmpName = dlg.GetPathName();
		BmpNameLin = "picture.bmp";
		//AfxMessageBox(BmpName);
		
		AfxMessageBox("ͼƬ�򿪳ɹ�",MB_OK,0);
		numPicture=1;

		/*CString�е�Format�����ַ���ת��*/
		//BmpName.Format(_T("%s",str));  //�ص㣺���� ����ִ����·��
		
		EntName = dlg.GetFileExt(); 
		EntName.MakeLower();             //�˳�Ա��������CString����ת��Ϊһ��Сд�ַ���
		
		Invalidate();
	}	
}


//******************�ļ�����*****************//
void CBmpDrawView::OnFileSave() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܱ���ͼƬ!",MB_OK,0);
		return;
	}

	CString filter;
	//filter=" BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	filter="�����ļ�(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	CFileDialog dlg(0,NULL,NULL,OFN_HIDEREADONLY,filter,NULL);          //�����򿪶Ի���
	//1-�ļ��� 0-�ļ�����
	
	//����ȷ����ť
	if( dlg.DoModal() == IDOK )
	{
		CString str;
		CString strName;
		CString filename;
		str = dlg.GetPathName();           //��ȡ�ļ���·��
		filename = dlg.GetFileTitle();     //��ȡ�ļ���
 		
		int nFilterIndex=dlg.m_ofn.nFilterIndex;
		if( nFilterIndex == 2 )            //���û�ѡ���ļ�������Ϊ".BMP"ʱ
		{
			str = str + ".bmp";	           //�Զ�����չ��.bmp
			SaveBmp(str);                  //����bmpͼƬ ����һ��д��ͼƬ�Ĺ��� 
			AfxMessageBox("ͼƬ����ɹ�",MB_OK,0);
		}
	}
}

//д��bmp��ʽͼƬ д��ͼƬ�Ĺ���
bool CBmpDrawView::ReadBmp()
{

	//ͼƬ�����洢���еĶ���
	FILE *fp = fopen(BmpName,"rb");
	if(fp==0)
	{		
		AfxMessageBox("�޷����ļ�!",MB_OK,0);
		return 0; 
	}
		
	//��ȡ�ļ�ͷ ȫ�ֱ���bfh  BITMAPFILEHEADER ������ImageStruct��
	//fread(&bfh,sizeof(BITMAPFILEHEADER),1,fp);
	
	//���BMP��ʽ���õķ��� ��CSDN
	fread(&bfh.bfType,sizeof(WORD),1,fp);
	fread(&bfh.bfSize,sizeof(DWORD),1,fp);
	fread(&bfh.bfReserved1,sizeof(WORD),1,fp);
	fread(&bfh.bfReserved2,sizeof(WORD),1,fp);
	fread(&bfh.bfOffBits,sizeof(DWORD),1,fp);

	//ͼ���ļ������ֽ���
	m_nSize = bfh.bfSize;

	//�ж��Ƿ���bmp��ʽͼƬ
	if(bfh.bfType!=0x4d42)   //'BM'
	{
		AfxMessageBox("����BMP��ʽͼƬ!",MB_OK,0);
		return 0;
	}

	//��ȡ��Ϣͷ
	//fread(&bih,sizeof(BITMAPINFOHEADER_),1,fp);

	//���BMP��ʽ���õķ��� ��CSDN
	fread(&bih.biSize,sizeof(DWORD),1,fp);
	fread(&bih.biWidth,sizeof(LONG),1,fp);
	fread(&bih.biHeight,sizeof(LONG),1,fp);
	fread(&bih.biPlanes,sizeof(WORD),1,fp);
	fread(&bih.biBitCount,sizeof(WORD),1,fp);
	fread(&bih.biCompression,sizeof(DWORD),1,fp);
	fread(&bih.biSizeImage,sizeof(DWORD),1,fp);
	fread(&bih.biXPelsPerMeter,sizeof(LONG),1,fp);
	fread(&bih.biYPelsPerMeter,sizeof(LONG),1,fp);
	fread(&bih.biClrUsed,sizeof(DWORD),1,fp);
	fread(&bih.biClrImportant,sizeof(DWORD),1,fp);

	if(bih.biSize!=sizeof(bih))
	{
		AfxMessageBox("���ṹ��ռ���ֽ������ִ���");
		return 0;
	}

	//λͼѹ�����ͣ������� 0����ѹ���� 1��BI_RLE8ѹ�����ͣ���2��BI_RLEѹ�����ͣ�֮һ
	if(bih.biCompression == BI_RLE8 || bih.biCompression == BI_RLE4)
	{
		AfxMessageBox("λͼ��ѹ��!");
		return 0;
	}
	
	//��ȡͼ��߿��ÿ��������ռλ��
	m_nHeight = bih.biHeight;
	m_nWidth = bih.biWidth;
	m_nDrawHeight = bih.biHeight;
	m_nDrawWidth = bih.biWidth;
	m_nBitCount = bih.biBitCount;   //ÿ��������ռλ��

	//����ͼ��ÿ��������ռ���ֽ�����������32�ı�����
	m_nLineByte = (m_nWidth*m_nBitCount+31)/32*4;
	
	//ͼƬ��С ����ϵͳ�Դ����ļ�ͷ BITMAPFILEHEADER bfh; BITMAPINFOHEADER bih; 
	//������ BITMAPFILEHEADER_ bfh; BITMAPINFOHEADER_ bih;Ҫ m_nImage = m_nLineByte * m_nHeight - 2;
	m_nImage = m_nLineByte * m_nHeight;
	
	//λͼʵ��ʹ�õ���ɫ���е���ɫ�� biClrUsed
	m_nPalette = 0;                       //��ʼ��
	if(bih.biClrUsed)
		m_nPalette = bih.biClrUsed;
	
	//����λͼ�ռ� ��СΪλͼ��С m_nImage
	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);
	fread(m_pImage,m_nImage,1,fp);

	fclose(fp);
	return true;
}


//����bmp��ʽͼƬ д��ͼƬ�Ĺ��� ֻ����24���ص�ͼƬ ��ͼƬ�޵�ɫ��
bool CBmpDrawView::SaveBmp(LPCTSTR lpFileName)
{
	//lpFileNameΪλͼ�ļ���
	//AfxMessageBox(lpFileName);

	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(lpFileName,"wb");

	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);
	fread(m_pImage,m_nImage,1,fpo);
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);
	return true;
}

//��ʾ����״̬����Ϣ �ļ�·�� ��С ����
void CBmpDrawView::ShowWindowInfo() 
{
	CString winInfo;
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬��ָ��
	
	if(pStatus)
	{ 
		winInfo.Format("����� = %d��%d | ͼ���С = %d�ֽ�  | BitCount = %d",m_nWidth,m_nHeight,m_nSize,m_nBitCount);
		pStatus->SetPaneText(0,BmpName);
		pStatus->SetPaneText(1,winInfo);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

}

//��ʾ����״̬����Ϣ ���λ��
void CBmpDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		
	CString winInfo;
	CString winPoint;

	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������

	if(pStatus)
	{
		winPoint.Format("X=%d,Y=%d",point.x,point.y);
		winInfo.Format("����� = %d��%d ͼ���С = %d",m_nWidth,m_nHeight,m_nSize);
		pStatus->SetPaneText(2,winPoint);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

	CView::OnMouseMove(nFlags, point);
}

//��ʾ2��ͼƬ
void CBmpDrawView::OnShowTwo() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ����ʾ2��ͼƬ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�������ʾ2��ͼƬ!");
		return;
	}

	AfxMessageBox("��ʾ����ͼƬ!",MB_OK,0);
	numPicture = 2;
	level=0;
	Invalidate();
}


//���� �����ȼ�Ϊ 2
void CBmpDrawView::OnLh2() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=2!",MB_OK,0);
	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�2����
	for( i=0; i<m_nImage; i++ )
	{
		//24λ��Ϊ��ɫ��Ϊ���ͼ Red Green Blue Ϊ3�ֽ� �����ȼ�Ϊ2ȡ�м�ֵΪ 64 �� 192
		if(m_pImage[i]<128)
		{
			m_pImage[i]=0;
		}
		else if(m_pImage[i]>=128)
		{
			m_pImage[i]=128;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=2;
	Invalidate();
}

//���� �����ȼ�Ϊ 4
void CBmpDrawView::OnLh4() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=4!",MB_OK,0);
	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�4����
	for( i=0; i<m_nImage; i++ )
	{
		if(m_pImage[i]<64)
		{
			m_pImage[i]=0;
		}
		else if( (m_pImage[i]>=64) && (m_pImage[i]<128) )
		{
			m_pImage[i]=64;
		}
		else if( (m_pImage[i]>=128) && (m_pImage[i]<192) )
		{
			m_pImage[i]=128;
		}
		else if(m_pImage[i]>=192)
		{
			m_pImage[i]=192;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=4;
	Invalidate();

}


//���� �����ȼ�Ϊ 8
void CBmpDrawView::OnLh8() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=8!",MB_OK,0);
	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�8����
	for( i=0; i<m_nImage; i++ )
	{
		if(m_pImage[i]<32)
		{
			m_pImage[i]=0;
		}
		else if( (m_pImage[i]>=32) && (m_pImage[i]<64) )
		{
			m_pImage[i]=32;
		}
		else if( (m_pImage[i]>=64) && (m_pImage[i]<96) )
		{
			m_pImage[i]=64;
		}
		else if( (m_pImage[i]>=96) && (m_pImage[i]<128) )
		{
			m_pImage[i]=96;
		}
		else if( (m_pImage[i]>=128) && (m_pImage[i]<160) )
		{
			m_pImage[i]=128;
		}
		else if( (m_pImage[i]>=160) && (m_pImage[i]<192) )
		{
			m_pImage[i]=160;
		}
		else if( (m_pImage[i]>=192) && (m_pImage[i]<224) )
		{
			m_pImage[i]=192;
		}
		else if(m_pImage[i]>=224)
		{
			m_pImage[i]=224;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=8;
	Invalidate();
}

//���� �����ȼ�Ϊ 16
void CBmpDrawView::OnLh16() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=16!",MB_OK,0);
	int i,j;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�16����
	for( i=0; i<m_nImage; i++ )
	{
		j=16;
		while(j<=256)
		{
			if(m_pImage[i]<j) 
			{
				if(m_pImage[i]<16) 
					m_pImage[i]=0;
				else 
					m_pImage[i]=j-16;
				break;
			}
			else j+=16;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=16;
	Invalidate();
}

//���� �����ȼ�Ϊ 32
void CBmpDrawView::OnLh32() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=32!",MB_OK,0);
	int i,j;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�16����
	for( i=0; i<m_nImage; i++ )
	{
		j=8;
		while(j<=256)
		{
			if(m_pImage[i]<j) 
			{
				if(m_pImage[i]<8) 
					m_pImage[i]=0;
				else 
					m_pImage[i]=j-8;
				break;
			}
			else j+=8;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=32;
	Invalidate();
}

//���� �����ȼ�Ϊ 64
void CBmpDrawView::OnLh64() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ���������!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ȼ�Level=64!",MB_OK,0);
	int i,j;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//mallocֻ������4�ֽڵĿռ� ��δ֪��
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//�ȼ�16����
	for( i=0; i<m_nImage; i++ )
	{
		j=4;
		while(j<=256)
		{
			if(m_pImage[i]<j) 
			{
				if(m_pImage[i]<16) 
					m_pImage[i]=0;
				else 
					m_pImage[i]=j-4;
				break;
			}
			else j+=4;
		}
	}
	
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=64;
	Invalidate();
}


/********************************************************************************************/
/* ���http://blog.csdn.net/xiakq/article/details/2956902����ϸ�ĻҶ��㷨                   */
/* ����24λ��ͼƬ�Ҷ�ʱ,���������㷨:                                                       */
/* 1.ƽ��ֵ�㷨 R=G=B=(R+G+B)/3                                                             */ 
/* 2.�����㷨 R=G=B=(R+G+B+128)/4>>2                                                        */  
/* 3.��Ȩƽ��ֵ�㷨 ���ݹ����������,��ʵ��ȷ�ĻҶȹ�ʽӦ����R=G=B=R*0.299+G*0.587+B0.144   */
/*   Ϊ������ٶ�������һ����ȫ���Խ��ܵĽ��ƣ���ʽ�������� R=G=B=(R*3+G*6+B)/10            */
/* 4.��ȷ��Ȩƽ��ֵ�㷨 R=G=B=R*0.299+G*0.587+B0.144                                        */
/********************************************************************************************/

//�Ҷ�ͼ����� R=G=B��Ϊ���ߵ�1/3 level=1ʱ�Ҷ�ͼ��
void CBmpDrawView::OnShowHd() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ���Ҷ� ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܻҶ�ͼƬ!",MB_OK,0);
		return;
	}

	AfxMessageBox("�Ҷ�ͼ��!",MB_OK,0);
	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;

	/********************************************************************/
	/* ע�⣺ԭ���������в�������for( i=0; i<m_nWidth*m_nHeight; i++ )  */
	/* �������ͼƬ���һ��û��������һ�����ݣ������ͼ��������   */
	/* ��ͼ���������Ϊm_nImage�������m_nImage/3�Ϳ��Ա�֤�������ض��� */
	/********************************************************************/

	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		color=(red+green+blue)/3;
		red=color;
		green=color;  
		blue=color;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=1;
	Invalidate();
}


//ͼƬ���� ���������������
void CBmpDrawView::OnCy() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܲ���!",MB_OK,0);
		return;
	}
	
	CTestCYDlg dlg;     //��������Ի���
	
	//��ʾ�Ի���
	if( dlg.DoModal()==IDOK )
	{
		//�����������ΪͼƬ����������
		if( dlg.m_xPlace==0 || dlg.m_yPlace==0 )
		{
			AfxMessageBox("����ͼƬ���ز���Ϊ0!",MB_OK,0);
			return;
		}
		if( dlg.m_xPlace>m_nWidth || dlg.m_yPlace>m_nHeight )
		{
			AfxMessageBox("ͼƬ���ز���Ϊ����ԭͼ����!",MB_OK,0);
			return;
		}

		AfxMessageBox("ͼƬ����!",MB_OK,0);
		
		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);
	
		/*ͼƬ����*/
		int numWidth,numHeight;     //ͼƬ������ȡ��ͬ�����ص�
		int numSYWidth,numSYHeight; //ʣ���ڼ����� 

		/*********************************************************/
		/* ��ʾnumWidth*numHeightΪһ������ ��������ɫ��ͬ       */
		/* �� 512/512=1 512/512=1 1*1Ϊһ������                  */
		/* dlg.m_xPlace*dlg.m_yPlace ��ʾ�µģ�x,y������         */
		/* numSYWidth��ʾʣ��ռ� ������ͳһΪһ����ɫ           */
		/*********************************************************/

		numWidth=m_nWidth/dlg.m_xPlace;        
		numHeight=m_nHeight/dlg.m_yPlace;      

		numSYWidth=m_nWidth%dlg.m_xPlace;     
		numSYHeight=m_nHeight%dlg.m_yPlace;   

		int Y,X;
		int i,j,m,n;
		unsigned char red,green,blue;  //�洢������ɫ
		
		/*�У���m_xPlace * m_yPlace��+ ʣ������ ����С����*/
		for( i=0; i<dlg.m_yPlace; i++ )       //�߶�
		{
			Y=numHeight*i;                    //��ȡY����
			for( j=0; j<dlg.m_yPlace; j++ )   //���
			{
				X=numWidth*j;                 //��ȡX����
				
				/*��ȡ�����ɫ*/
				red=m_pImage[(X+Y*m_nWidth)*3];
				green=m_pImage[(X+Y*m_nWidth)*3+1];
				blue=m_pImage[(X+Y*m_nWidth)*3+2];
				
				/*���ͼ��ѭ�� С�����еĳ���ѭ��*/
				for( n=0; n<numHeight; n++ )
				{
					for( m=0; m<numWidth*3; )
					{
						m_pImage[(X+Y*m_nWidth)*3+m+n*m_nWidth*3]=red;
						m++;
						m_pImage[(X+Y*m_nWidth)*3+m+n*m_nWidth*3]=green;
						m++;
						m_pImage[(X+Y*m_nWidth)*3+m+n*m_nWidth*3]=blue;
						m++;
					}
				}
			}
		}

		
		fwrite(m_pImage,m_nImage,1,fpw);
	
		fclose(fpo);
		fclose(fpw);

		numPicture = 2;
		level=3;
		Invalidate();
	}
}


/**********************************************************************/
/* 4�����Ա仯ֱ��ͼ��                                                */
/* ID_XXHD_YD:��ʾ���ԻҶȱ仯�ƶ�,D(B)=D(A)+50,�Ҷ�ֵ��������        */
/* ID_XXHD_ZQ:��ʾ���ԻҶȱ仯��ǿ,D(B)=1.5*D(A),ͼ��Աȶ���ǿ       */
/* ID_XXHD_JX:��ʾ���ԻҶȱ仯��С,D(B)=0.8*D(A),ͼ��Աȶȼ�С       */
/* ID_XXHD_QB:��ʾ���ԻҶ���,D(B)=-1*D(A)+255,ͼ��������,�����䰵 */
/**********************************************************************/

/*ȫ�ֱ�����TestZFTDlg.cpp������ ��extern BH(�仯���ֱ��ͼ����)*/
int RedBH[256],GreenBH[256],BlueBH[256];


/*ID_XXHD_JX:��ʾ���ԻҶȱ仯��СD(B)=0.8*D(A)*/
void CBmpDrawView::OnXxhdJx() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ��������ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷȼ�С D(B)=0.8*D(A)!",MB_OK,0);

	int i;

	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		
		red=(int)red*0.8;
		green=(int)green*0.8;  
		blue=(int)blue*0.8;

		//��¼�仯��ĻҶ�ͼ���仯���ֱ��ͼ��ʾ

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=100;


	Invalidate();
}


/*ID_XXHD_QB:��ʾ���ԻҶ���,D(B)=-1*D(A)+255*/
void CBmpDrawView::OnXxhdQb() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ��������ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷ��� D(B)=-1*D(A)+255!",MB_OK,0);

	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		
		red=(int)red*(-1)+255;
		green=(int)green*(-1)+255;  
		blue=(int)blue*(-1)+255;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=101;
	Invalidate();
}

/*ID_XXHD_YD:��ʾ���ԻҶȱ仯�ƶ�,D(B)=D(A)+50*/
void CBmpDrawView::OnXxhdYd() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ��������ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷȱ仯�ƶ� D(B)=D(A)+50!",MB_OK,0);

	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		if( (int)red+50 >255 )
			red=255;
		else
			red=(int)red+50;

		if( (int)green+50>255 )
			green=255;
		else
			green=(int)green+50;  
		
		if( (int)blue+50>255 )
			blue=255;
		else
			blue=(int)blue+50;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=102;
	Invalidate();
}

/*ID_XXHD_ZQ:��ʾ���ԻҶȱ仯��ǿ,D(B)=1.5*D(A)*/
void CBmpDrawView::OnXxhdZq() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ��������ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷȱ仯��ǿ D(B)=1.5*D(A)!",MB_OK,0);

	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		if( (int)red*1.5 >255 )
			red=255;
		else
			red=(int)red*1.5;

		if( (int)green*1.5>255 )
			green=255;
		else
			green=(int)green*1.5;  
		
		if( (int)blue*1.5>255 )
			blue=255;
		else
			blue=(int)blue*1.5;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=103;
	Invalidate();
}


/**************************************************/
/* ���ֱ��ͼ��ʾ���ܣ�����ֱ��ͼ�·���ʾ�����Ϣ */
/* ��ƽ���Ҷȡ���ֵ�Ҷȡ���׼�����������         */
/* ID_ZFT_YT:ֱ��ͼԭͼ��ʾ                       */
/**************************************************/


/*ȫ�ֱ�����TestZFTDlg.cpp������ ��extern*/
int Red[256],Green[256],Blue[256];

void CBmpDrawView::OnZftYt() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ԭͼֱ��ͼ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�������ʾԭͼֱ��ͼ!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("��ʾԭͼֱ��ͼ!",MB_OK,0);
	
	flagZFT=1;

	CTestZFTDlg dlg;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	int i,j;
	for(j=0;j<256;j++)   //�������鲢����
	{
		Red[j]=0;
		Green[j]=0;
		Blue[j]=0;
	}
	
	//����4������
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;               //ǿ��ת��
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //��¼�����ܵĻҶ�ֵ��
	for(i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		IntRed=int(red);
		sumRedHD=sumRedHD+IntRed;
		if( IntRed>=0 && IntRed<256 ) Red[IntRed]++;
		
		fread(&green,sizeof(char),1,fpo);
		IntGreen=int(green);
		sumGreenHD=sumGreenHD+IntGreen;
		if( IntGreen>=0 && IntGreen<256 ) Green[IntGreen]++;
		
		fread(&blue,sizeof(char),1,fpo);
		IntBlue=int(blue);
		sumBlueHD=sumBlueHD+IntBlue;
		if( IntBlue>=0 && IntBlue<256 ) Blue[IntBlue]++;
	}
	fclose(fpo);
	
	//����:int��ת��ΪCString�� 
	dlg.m_redXS.Format("%d",m_nImage);
	dlg.m_greenXS.Format("%d",m_nImage);
	dlg.m_blueXS.Format("%d",m_nImage);
	
	//ƽ���Ҷ�ֵ:����24λbmpͼƬ�ĻҶ�ֵ,���Ǽ�¼RGB�е�����ƽ��ֵ	
	float pinRedHD,pinGreenHD,pinBlueHD; 
	pinRedHD=sumRedHD*3/m_nImage;
	pinGreenHD=sumGreenHD*3/m_nImage;     //ƽ���Ҷ�=�ܻҶ�/������
	pinBlueHD=sumBlueHD*3/m_nImage;
	
	dlg.m_redPJHD.Format("%.2f",pinRedHD);
	dlg.m_greenPJHD.Format("%.2f",pinGreenHD);
	dlg.m_bluePJHD.Format("%.2f",pinBlueHD);
	
	/****************************************************************/
	/* ��ֵ�Ҷ�:�㷨�ص�(�ƿ������ṩ)                              */
	/* ��ֵ�Ҷ�:���������е���λ��,Ӧ���������������ҵ��м�ĻҶ�ֵ */
	/* �㷨:num[256]��¼���Ҷȳ��ִ���,sum+=num[i],�ҵ�sum=������/2 */
	/****************************************************************/
	int sumRedZZHD=0,sumGreenZZHD=0,sumBlueZZHD=0;
	int redZZHD,greenZZHD,blueZZHD;
	for(i=0;i<256;i++)
	{
		sumRedZZHD=sumRedZZHD+Red[i];
		if(sumRedZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			redZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumGreenZZHD=sumGreenZZHD+Green[i];
		if(sumGreenZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			greenZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumBlueZZHD=sumBlueZZHD+Blue[i];
		if(sumBlueZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			blueZZHD=i;
			break;
		}
	}
	
	dlg.m_redZZHD.Format("%d",redZZHD);
	dlg.m_greenZZHD.Format("%d",greenZZHD);
	dlg.m_blueZZHD.Format("%d",blueZZHD);
	
	/******************************************************************/
	/*��׼��:��׼��=���������ƽ����                                  */ 
	/*       ����s^2=[(x1-x)^2+(x2-x)^2+......(xn-x)^2]/n             */
	/* �㷨:���ÿ�m_nImage������м��� ��num[256]��������             */
	/* ����=(ƽ���Ҷ�-i)*(ƽ���Ҷ�-i)*Red[i]  ��Red[i]���Ҷ�ֵΪi���� */
	/******************************************************************/
	float redBZC,greenBZC,blueBZC;       //��׼��
	float LinRed,LinGreen,LinBlue;
	double redFC=0,greenFC=0,blueFC=0;    //����
	for(i=0;i<256;i++)
	{
		redFC=redFC+(pinRedHD-i)*(pinRedHD-i)*Red[i];   //��Red[i]������i
		greenFC=greenFC+(pinGreenHD-i)*(pinGreenHD-i)*Green[i];
		blueFC=blueFC+(pinBlueHD-i)*(pinBlueHD-i)*Blue[i];
	}
	
	redBZC=sqrt(redFC*3/m_nImage);
	greenBZC=sqrt(greenFC*3/m_nImage);
	blueBZC=sqrt(blueFC*3/m_nImage);
	
	dlg.m_redBZC.Format("%.2lf",redBZC);
	dlg.m_greenBZC.Format("%.2lf",greenBZC);
	dlg.m_blueBZC.Format("%.2lf",blueBZC);
	

	//�ص������Ӹ������ܵ����Ի���
	if(dlg.DoModal()==IDOK)
	{

	}
}


/************************************************************************/
/* 4�ַ����Ա仯ֱ��ͼ��                                                */
/* ID_FXXHD_PF:��ʾ������ƽ���Ҷȱ仯,D(B)=D(A)*D(A)/255                */
/* ID_FXXHD_HS:��ʾ�����Ժ����Ҷȱ仯,D(B)=D(A)+0.8*D(A)*(255-D(A))/255 */
/* ID_FXXHD_LS:��ʾ�����ԻҶȶԱȶ�����仯                             */
/************************************************************************/


/*ID_FXXHD_PF:��ʾ������ƽ���Ҷȱ仯,D(B)=D(A)*D(A)/252*/
void CBmpDrawView::OnFxxhdPf() 
{
	// TODO: Add your command handler code here
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܷ����ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("�����ԻҶȱ仯 D(B)=D(A)*D(A)/255!",MB_OK,0);

	int i;
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		red=(int)red*(int)red/255;
		green=(int)green*(int)green/255;
		blue=(int)blue*(int)blue/255;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=104;
	Invalidate();
}


/*ID_FXXHD_HS:��ʾ�����Ժ����Ҷȱ仯,D(B)=D(A)+0.8*D(A)*(255-D(A))/255*/
void CBmpDrawView::OnFxxhdHs() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܷ����ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷȱ仯��ǿ D(B)=D(A)+0.8*D(A)*(255-D(A))/255!",MB_OK,0);

	int i;
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		if( ((int)red+0.8*(int)red*(255-(int)red)/255) > 255 )
			red=255;
		else
			red=(int)red+0.8*(int)red*(255-(int)red)/255;

		if( ((int)green+0.8*(int)green*(255-(int)green)/255) > 255 )
			green=255;
		else
			green=(int)green+0.8*(int)green*(255-(int)green)/255;  
		
		if( ((int)blue+0.8*(int)blue*(255-(int)blue)/255) > 255 )
			blue=255;
		else
			blue=(int)blue+0.8*(int)blue*(255-(int)blue)/255;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=103;
	Invalidate();
}

/**************************************************************/
/* ID_FXXHD_LS:��ʾ�����ԻҶȶԱȶ�����仯                   */
/* �˴��������ǣ���ֵ��(thresholding)���Կ�����������һ������ */
/* ֻҪ�������е�g1old=g2old��ʵ������ֵ����                  */
/* ��ֵ������ż�����������ǰף�����С���Ǻ�,��ֵ            */
/**************************************************************/

void CBmpDrawView::OnFxxhdLs() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܷ����ԻҶ�ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("���ԻҶ�ֱ��ͼ-�Ҷȱ仯��ǿ D(B)=D(A)+0.8*D(A)*(255-D(A))/255!",MB_OK,0);

	int i;
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//�Ҷ�ͼ��
	unsigned char color;
	unsigned char red,green,blue;
	for( i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		if( (int)red > 128 )
			red=255;
		else
			red=0;

		if( (int)green > 128 )
			green=255;
		else
			green=0;  
		
		if( (int)blue > 128 )
			blue=255;
		else
			blue=0;

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=106;
	Invalidate();
}


/*ID_FXXHD_JHH:��ʾͼ����⻯ ����㷨*/
void CBmpDrawView::OnFxxhdJhh() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����⻯!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����⻯!",MB_OK,0);

    //��һ��:��ȡͼ���������Ϣ���˲��������ڴ�ͼƬʱ�ͽ��У���ֱ��ͼ����(ZFTCY)��Ҳ�иô��룬���۴���
	FILE *fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	int i,j;
	for(j=0;j<256;j++)   //�������鲢����
	{
		Red[j]=0;
		RedBH[j]=0;
		Green[j]=0;
		GreenBH[j]=0;
		Blue[j]=0;
		BlueBH[j]=0;
	}
	
	//����4������
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;                  //ǿ��ת��
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //��¼�����ܵĻҶ�ֵ��
	for(i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		IntRed=int(red);
		sumRedHD=sumRedHD+IntRed;
		if( IntRed>=0 && IntRed<256 ) Red[IntRed]++;
		
		fread(&green,sizeof(char),1,fpo);
		IntGreen=int(green);
		sumGreenHD=sumGreenHD+IntGreen;
		if( IntGreen>=0 && IntGreen<256 ) Green[IntGreen]++;
		
		fread(&blue,sizeof(char),1,fpo);
		IntBlue=int(blue);
		sumBlueHD=sumBlueHD+IntBlue;
		if( IntBlue>=0 && IntBlue<256 ) Blue[IntBlue]++;
	}
	fclose(fpo);

	
	/*****************************************************************/
	/* ͼ����⻯����                                                */
	/* ����ȫ�ֱ��� Red[256] Blue[256] Green[256]                    */
	/* ��һ��:��3������Count..��¼0-255�Ҷȳ��ֵĸ��ʣ���            */
	/*        ����=�ûҶȳ��ִ���*3/�ܵ����� (��Ϊ�ֳ�3����RGB)      */
	/* �ڶ���:i��1��ʼ����s[i]=s[i]+s[i-1] ��¼�¸�����              */
	/* ������:��һ������L��¼�µĵ�ɫ������ֵ����                    */
	/*        L[i]=s[i]��(256-1)�����������2.8��Ϊ3                 */
	/* ���Ĳ�:���ϵ�����ֵ��Ӧ�ĸ��ʺϲ�����Ϊ��Ӧ���µ�����ֵ�ĸ��� */
	/*   1.ԭ��������ֵ0,1����Ӧ���µ�����ֵ0����Ҷ�����ֵΪ0�ĸ��� */
	/*     ΪP0+P1=0.03                                              */
	/*   2.�µ�����ֵ3��7�Ҳ����ϵ�����ֵ��֮��Ӧ��������Q3��Q7Ϊ0   */
	/*****************************************************************/

	float CountRed[256],CountGreen[256],CountBlue[256];            //��¼���ֵĸ���,��ӵ�1 ������ӵ���ɫ��
	float CountRedLin[256],CountGreenLin[256],CountBlueLin[256];   //��¼ԭʼ����,������ӵ�1 ���ڼ����»Ҷȸ���
	for(int k=0 ; k<256 ; k++ )
	{
		CountRed[k]=(float)(Red[k])*3/m_nImage;
		CountRedLin[k]=CountRed[k];
		CountGreen[k]=(float)(Green[k])*3/m_nImage;
		CountGreenLin[k]=CountGreen[k];
		CountBlue[k]=(float)(Blue[k])*3/m_nImage;
		CountBlueLin[k]=CountBlue[k];
	}
	
	for( k=1 ; k<256 ; k++ )
	{ 
		CountRed[k]=CountRed[k]+CountRed[k-1];
		CountGreen[k]=CountGreen[k]+CountGreen[k-1];
		CountBlue[k]=CountBlue[k]+CountBlue[k-1];
	}

	/****************************************************/
	/* �˴��ٶȵ�һ���������븡���͵��㷨:              */
	/* float a=3.456;   ������С�������λ              */
	/* float b=(int)((a * 100) + 0.5) / 100.0;          */
	/* output b=3.46                                    */
	/****************************************************/

	int LRed[256],LGreen[256],LBlue[256];                    //��¼��ɫ��
	for( k=0 ; k<256 ; k++ )
	{
		LRed[k]=(int)(CountRed[k]*(256-1)+0.5);
		LGreen[k]=(int)(CountGreen[k]*(256-1)+0.5);
		LBlue[k]=(int)(CountBlue[k]*(256-1)+0.5);
	}


	//������:������⻯ͼ��д�� ����ʱ��ͼƬ
	fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	FILE *fpw = fopen(BmpNameLin,"wb+");
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//m_nWidth*m_nHeight ��ȡͼƬ���һ�в�Ϊm_nWidthʱ�ᱨ��
	for( i=0; i<m_nImage/3 ; i++ )
	{	
		fread(&red,sizeof(char),1,fpo);
		fread(&green,sizeof(char),1,fpo);
		fread(&blue,sizeof(char),1,fpo);

		red=LRed[int(red)];
		green=LGreen[int(green)];
		blue=LBlue[int(blue)];

		fwrite(&red,sizeof(char),1,fpw);
		fwrite(&green,sizeof(char),1,fpw);
		fwrite(&blue,sizeof(char),1,fpw);
	}
	fclose(fpw);
	
	//�洢���⻯���ֱ��ͼ����
	for( k=0 ; k<256 ; k++ )
	{
		for(int n=k+1 ; n<256 ; n++ )
		{
			if(LRed[k]==LRed[n])                   //�»Ҷ���ͬ���ϻҶȵĸ��ʺϲ�
				CountRedLin[k]+=CountRedLin[n];
			else break;                            //LRed�϶��ǵ������У�ֻҪ����ͬ�Ϳ���ִ����һ���Ҷ�
		}
		for( n=k+1 ; n<256 ; n++ )
		{
			if(LGreen[k]==LGreen[n])
				CountGreenLin[k]+=CountGreenLin[n];
			else break;
		}
		for( n=k+1 ; n<256 ; n++ )
		{
			if(LBlue[k]==LBlue[n])
				CountBlueLin[k]+=CountBlueLin[n];
			else break;
		}

		//¼��RedBH(�任)����
		RedBH[k]=(int)(CountRedLin[k]*m_nImage/3);
		GreenBH[k]=(int)(CountGreenLin[k]*m_nImage/3);
		BlueBH[k]=(int)(CountBlueLin[k]*m_nImage/3);
	}

	
	numPicture = 2;
	level=200;
	Invalidate();	
}




/**************************************************/
/* ���ͼƬ���Ի�����Ա仯ֱ��ͼ��ʾ����         */
/*                                                */
/* ID_ZFT_BH:�仯���ֱ��ͼ                       */
/**************************************************/

void CBmpDrawView::OnZftBh() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ԭͼֱ��ͼ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�������ʾԭͼֱ��ͼ!",MB_OK,0);
		return;
	}
	
	//���û�е���ͼƬֱ�ӵ��ԭͼֱ��ͼ ��ʾ��Ϣ
	if(signZFT==0)
	{
		AfxMessageBox("ͼƬ���Ա仯������Ա仯�������ʾ�仯ֱ��ͼ!",MB_OK,0);
		return;
	}

	AfxMessageBox("��ʾ���Ա仯������Ա仯���ֱ��ͼ!",MB_OK,0);
	
	CTestZFTDlg dlg;
	
	FILE *fpo = fopen(BmpNameLin,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	for(int j=0;j<256;j++)   //�������鲢����
	{
		RedBH[j]=0;
		GreenBH[j]=0;
		BlueBH[j]=0;
	}
	
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;               //ǿ��ת��
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //��¼�����ܵĻҶ�ֵ��
	for(int i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		IntRed=int(red);
		sumRedHD=sumRedHD+IntRed;
		if( IntRed>=0 && IntRed<256 ) RedBH[IntRed]++;
		
		fread(&green,sizeof(char),1,fpo);
		IntGreen=int(green);
		sumGreenHD=sumGreenHD+IntGreen;
		if( IntGreen>=0 && IntGreen<256 ) GreenBH[IntGreen]++;
		
		fread(&blue,sizeof(char),1,fpo);
		IntBlue=int(blue);
		sumBlueHD=sumBlueHD+IntBlue;
		if( IntBlue>=0 && IntBlue<256 ) BlueBH[IntBlue]++;
	}
	fclose(fpo);

	//����:int��ת��ΪCString�� 
	dlg.m_redXS.Format("%d",m_nImage);
	dlg.m_greenXS.Format("%d",m_nImage);
	dlg.m_blueXS.Format("%d",m_nImage);
	
	//ƽ���Ҷ�ֵ:����24λbmpͼƬ�ĻҶ�ֵ,���Ǽ�¼RGB�е�����ƽ��ֵ	
	float pinRedHD,pinGreenHD,pinBlueHD; 
	pinRedHD=sumRedHD*3/m_nImage;
	pinGreenHD=sumGreenHD*3/m_nImage;     //ƽ���Ҷ�=�ܻҶ�/������
	pinBlueHD=sumBlueHD*3/m_nImage;
	
	dlg.m_redPJHD.Format("%.2f",pinRedHD);
	dlg.m_greenPJHD.Format("%.2f",pinGreenHD);
	dlg.m_bluePJHD.Format("%.2f",pinBlueHD);
	
	/****************************************************************/
	/* ��ֵ�Ҷ�:�㷨�ص�(�ƿ������ṩ)                              */
	/* ��ֵ�Ҷ�:���������е���λ��,Ӧ���������������ҵ��м�ĻҶ�ֵ */
	/* �㷨:num[256]��¼���Ҷȳ��ִ���,sum+=num[i],�ҵ�sum=������/2 */
	/****************************************************************/

	int sumRedZZHD=0,sumGreenZZHD=0,sumBlueZZHD=0;
	int redZZHD,greenZZHD,blueZZHD;
	for(i=0;i<256;i++)
	{
		sumRedZZHD=sumRedZZHD+RedBH[i];
		if(sumRedZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			redZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumGreenZZHD=sumGreenZZHD+GreenBH[i];
		if(sumGreenZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			greenZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumBlueZZHD=sumBlueZZHD+BlueBH[i];
		if(sumBlueZZHD>=m_nImage/6)          //m_nImage���ֳ�3��RGB����sum=������/2
		{
			blueZZHD=i;
			break;
		}
	}
	
	dlg.m_redZZHD.Format("%d",redZZHD);
	dlg.m_greenZZHD.Format("%d",greenZZHD);
	dlg.m_blueZZHD.Format("%d",blueZZHD);
	
	/******************************************************************/
	/*��׼��:��׼��=���������ƽ����                                  */ 
	/*       ����s^2=[(x1-x)^2+(x2-x)^2+......(xn-x)^2]/n             */
	/* �㷨:���ÿ�m_nImage������м��� ��num[256]��������             */
	/* ����=(ƽ���Ҷ�-i)*(ƽ���Ҷ�-i)*Red[i]  ��Red[i]���Ҷ�ֵΪi���� */
	/******************************************************************/
	float redBZC,greenBZC,blueBZC;       //��׼��
	float LinRed,LinGreen,LinBlue;
	double redFC=0,greenFC=0,blueFC=0;    //����
	for(i=0;i<256;i++)
	{
		redFC=redFC+(pinRedHD-i)*(pinRedHD-i)*RedBH[i];   //��Red[i]������i
		greenFC=greenFC+(pinGreenHD-i)*(pinGreenHD-i)*GreenBH[i];
		blueFC=blueFC+(pinBlueHD-i)*(pinBlueHD-i)*BlueBH[i];
	}
	
	redBZC=sqrt(redFC*3/m_nImage);
	greenBZC=sqrt(greenFC*3/m_nImage);
	blueBZC=sqrt(blueFC*3/m_nImage);
	
	dlg.m_redBZC.Format("%.2lf",redBZC);
	dlg.m_greenBZC.Format("%.2lf",greenBZC);
	dlg.m_blueBZC.Format("%.2lf",blueBZC);
	

	//�ص������Ӹ������ܵ����Ի���
	if(dlg.DoModal()==IDOK)
	{

	}
}


//Ϊ�˷�������ֻ��0%-200%֮�䣬���㷨����Ҫ

/*******************************************************************/
/* ID_JHYS_SXXCZ: ��������-�Ҷȼ���ֵ-˫���Բ�ֵ�㷨               */
/* ���ĺ���˼����:                                                 */
/* 1.���ű���Ϊa,�����һ���µ�����ͼ��(��*a)*(��*a)             */
/* 2.��ͼ����Դͼ���λ��=������/���ű���a ��Ϊdouble��            */
/* 3.��Ϊ4.4:��ʾ�����ڵ���Χ�ĸ���Ϊ:A B C D,ͼ��Ϊ�ĵ�Ҷ�ֵ��� */
/* 4.���ĻҶ�Ϊ:(1-fx)*(1-fy)*A+(1-fx)*fy*C+fx*(1-fy)*B+fx*fy*D    */
/*******************************************************************/

/*******************************************************************/
/* ͼ��Ϊ:                                                         */
/*            A oooooooooooooooooooooooooooooooo B                 */
/*              o        .                     o                   */
/*              o        .                     o                   */
/*              o        .(fy)                 o                   */
/*              o        .                     o                   */
/*              o........a                     o                   */
/*              o   (fx)                       o                   */
/*              o                              o                   */
/*              o                              o                   */
/*              o                              o                   */
/*              o                              o                   */
/*            C oooooooooooooooooooooooooooooooo D                 */
/*                                                                 */
/*     (1-fx)*(1-fy)*A+(1-fx)*fy*C+fx*(1-fy)*B+fx*fy*D             */
/*******************************************************************/

//�õ�������ܵ�4�����Լ��,���Խ�˫���ԻҶȲ�ֵ�㷨
//1-fx��ʾ������A��ľ���,��fxԽ��,��ʾ����AԽԶ,�ܵ���Ӱ��ԽС,����(1-fx)*A��ĻҶȱ�ʾx����

void CBmpDrawView::OnJhysSxxcz() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܼ�������ͼ��!",MB_OK,0);
		return;
	}
	
	CTestHDCZFDlg dlg;     //��������Ի���
	if( dlg.DoModal()==IDOK )
	{
		//�����������ΪͼƬ����������  m_sfbs(���ű���)
		if( dlg.m_sfbs==0 )
		{
			AfxMessageBox("����ͼƬ���ű�������Ϊ0!",MB_OK,0);
			return;
		}

		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

		/*�������ź�ĳ���*/
		int sfWidth,sfHeight;                            //���ź�ĳ���
		int sfSize;                                      //���ź��ͼ���С
		sfWidth=(int)(m_nWidth*(dlg.m_sfbs*1.0)/100);    //24λͼ��RGB������3�ı��� ѭ���ж�ȡʱΪR G B
		sfHeight=(int)(m_nHeight*(dlg.m_sfbs*1.0)/100);
		int number;                                      //��¼ÿ�ж����ͼ����������

		//�ص�:ͼ���ÿ�����ض�������4�ı�����1*1��ͼ��Ϊ r g b 00H 
		if(sfWidth*3%4!=0)
		{
			number=(4-sfWidth*3%4);
			sfSize=(sfWidth*3+(4-sfWidth*3%4))*sfHeight;
		}
		else
		{
			number=0;
			sfSize=sfWidth*sfHeight*3;
		}
		//ע��:�������һ�����ز���,��Ĭ�ϴ���Ϊ������һ��,���㲹00H
		//��֮������ͼ������m*n��Ϊ4����,ÿ�ж���������

		/*�����ļ�ͷ��Ϣ ������ʱ�ļ�ͷ�ṹ����*/
		BITMAPFILEHEADER bfhsf;
		BITMAPINFOHEADER bihsf;                //����(sf)
		bfhsf=bfh;
		bihsf=bih;

		bfhsf.bfSize=sfSize+54;		
		bihsf.biWidth=sfWidth;
		bihsf.biHeight=sfHeight;

		//��ʾ����m_nDrawWidth<650��ʾԭͼ,������ʾ
		flagSF=1;                         //ͼ������Ϊ1��ʶ����
		m_nDrawWidthSF=sfWidth;
		m_nDrawHeightSF=sfHeight;

		fwrite(&bfhsf,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bihsf,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);	
		
		unsigned char red,green,blue;
		unsigned char other=0;                       //����00H='\0'
		int placeX;                                  //��¼��ԭͼ�еĵڼ��е�λ��
		int placeY;									 //��¼��ԭͼ�е�λ��(x,y)
		int placeBH;                                 //��¼�任���ڱ任ͼ�е�λ��

		/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[sfSize]; 

		/*��ȡ�ļ�������Ϣ (1-fx)*(1-fy)*A+(1-fx)*fy*C+fx*(1-fy)*B+fx*fy*D */
		for(int i=0; i<sfHeight ; i++ )                  //��
		{
			placeX=(int)(i/(dlg.m_sfbs*1.0/100)+0.5)*bih.biWidth*3;
			for(int j=0; j<sfWidth ; j++ )               //��
			{
				red=green=blue=0;

				placeY=placeX+(int)(j/(dlg.m_sfbs*1.0/100)+0.5)*3;    //�Ŵ���Ϊ(dlg.m_sfbs*1.0/100)
			
				//�ص���:number*i����00H,�����numerͼ��ᱻ�г�2��
				placeBH=(i*sfWidth*3+number*i)+j*3;                  

				if(placeY+2<m_nImage)
				{
					ImageSize[placeBH]=m_pImage[placeY];
					ImageSize[placeBH+1]=m_pImage[placeY+1];
					ImageSize[placeBH+2]=m_pImage[placeY+2];
				}
				else
				{
					ImageSize[placeBH]=0;
					ImageSize[placeBH+1]=0;
					ImageSize[placeBH+2]=0;
				}
			}

		}
		
		fwrite(ImageSize,sfSize,1,fpw);

		fclose(fpo);
		fclose(fpw);

		numPicture = 2;
		level=300;
		Invalidate();
	}
	
}

/*******************************************************************/
/* ID_JHYS_ZJLCZ: ��������-�Ҷȼ���ֵ-����ڲ�ֵ�㷨               */
/* �㷨˼��:���ͼ��ĻҶȵ���������ӳ��λ�����������ͼ��ĻҶ�ֵ */
/* �ȼ�����Ŵ���С��ĳ���������������ԭͼ�еĵ�Ҷȣ���������  */
/*******************************************************************/

void CBmpDrawView::OnJhysZjlcz() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܼ�������ͼ��!",MB_OK,0);
		return;
	}

	CTestHDCZFDlg dlg;           //����Ի��� (�ҶȲ�ֵ��)
	if( dlg.DoModal()==IDOK )
	{
		//�����������ΪͼƬ����������  m_sfbs(���ű���)
		if( dlg.m_sfbs==0 )
		{
			AfxMessageBox("����ͼƬ���ű�������Ϊ0!",MB_OK,0);
			return;
		}
		
		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		/*�������ź�ĳ���*/
		int sfWidth,sfHeight;                            //���ź�ĳ���
		int sfSize;                                      //���ź��ͼ���С
		sfWidth=(int)(m_nWidth*(dlg.m_sfbs*1.0)/100);    //24λͼ��RGB������3�ı��� ѭ���ж�ȡʱΪR G B
		sfHeight=(int)(m_nHeight*(dlg.m_sfbs*1.0)/100);
		int number;                                      //��¼ÿ�ж����ͼ����������

		//�ص�:ͼ���ÿ�����ض�������4�ı�����1*1��ͼ��Ϊ r g b 00H 
		if(sfWidth*3%4!=0)
		{
			number=(4-sfWidth*3%4);
			sfSize=(sfWidth*3+(4-sfWidth*3%4))*sfHeight;
		}
		else
		{
			number=0;
			sfSize=sfWidth*sfHeight*3;
		}
		//ע��:�������һ�����ز���,��Ĭ�ϴ���Ϊ������һ��,���㲹00H
		//��֮������ͼ������m*n��Ϊ4����,ÿ�ж���������

//		CString str;
//		str.Format("�任��:��=%d ��=%d sfSize=%d",sfWidth,sfHeight,sfSize);
//		AfxMessageBox(str);
	
		/*�����ļ�ͷ��Ϣ ������ʱ�ļ�ͷ�ṹ����*/
		BITMAPFILEHEADER bfhsf;
		BITMAPINFOHEADER bihsf;                //����(sf)
		bfhsf=bfh;
		bihsf=bih;

		bfhsf.bfSize=sfSize+54;		
		bihsf.biWidth=sfWidth;
		bihsf.biHeight=sfHeight;

		//��ʾ����m_nDrawWidth<650��ʾԭͼ,������ʾ
		flagSF=1;                         //ͼ������Ϊ1��ʶ����
		m_nDrawWidthSF=sfWidth;
		m_nDrawHeightSF=sfHeight;

		fwrite(&bfhsf,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bihsf,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);	
		
		unsigned char red,green,blue;
		unsigned char other=0;                       //����00H='\0'
		int placeX;                                  //��¼��ԭͼ�еĵڼ��е�λ��
		int placeY;									 //��¼��ԭͼ�е�λ��(x,y)
		int placeBH;                                 //��¼�任���ڱ任ͼ�е�λ��

		/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[sfSize]; 

		/*��ȡ�ļ�������Ϣ ����ע��:1.������Ҷ� 2.�������뷨(�㷨+0.5)*/
		for(int i=0; i<sfHeight ; i++ )                  //��
		{
			placeX=(int)(i/(dlg.m_sfbs*1.0/100)+0.5)*bih.biWidth*3;
			for(int j=0; j<sfWidth ; j++ )               //��
			{
				red=green=blue=0;

				placeY=placeX+(int)(j/(dlg.m_sfbs*1.0/100)+0.5)*3;    //�Ŵ���Ϊ(dlg.m_sfbs*1.0/100)
			
				//�ص���:number*i����00H,�����numerͼ��ᱻ�г�2��
				placeBH=(i*sfWidth*3+number*i)+j*3;                  

				if(placeY+2<m_nImage)
				{
					ImageSize[placeBH]=m_pImage[placeY];
					ImageSize[placeBH+1]=m_pImage[placeY+1];
					ImageSize[placeBH+2]=m_pImage[placeY+2];
				}
				else
				{
					ImageSize[placeBH]=0;
					ImageSize[placeBH+1]=0;
					ImageSize[placeBH+2]=0;
				}
			}

		}
		
		fwrite(ImageSize,sfSize,1,fpw);

		fclose(fpo);
		fclose(fpw);

		numPicture = 2;
		level=300;
		Invalidate();
	}

}

/********************************************************/
/* ͼ��ռ伸�α任��ͼ��ƽ�� ID_JHBH_PY(���α任-ƽ��) */
/* ʹ�ò����ĶԻ���CTestCYDlg dlg                     */
/* �㷨��f(x,y)=f(x+x0,y+y0)ͼ�����е�ƽ�ƣ��յĲ���'0' */
/* ע���ͼ��ƽ�Ʒ���ֻ�Ǵ����Ͻ�(0,0)����ʼƽ��        */
/* ��������ԭ����ͬ���Լ�ȥŪ                           */
/********************************************************/

void CBmpDrawView::OnJhbhPy() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ���ռ�ƽ�� ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܿռ�ƽ��!",MB_OK,0);
		return;
	}
	
	CTestCYDlg dlg;     //��������Ի���Ҳ�������ռ�任ƽ�Ƶ�����
	
	//��ʾ�Ի���
	if( dlg.DoModal()==IDOK )
	{
		//�����������ΪͼƬ����������
		if( dlg.m_xPlace>m_nWidth || dlg.m_yPlace>m_nHeight )
		{
			AfxMessageBox("ͼƬƽ�Ʋ���Ϊ����ԭͼ����!",MB_OK,0);
			return;
		}

		AfxMessageBox("ͼƬ�ռ�任-ƽ��!",MB_OK,0);
		
		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);

		/************************************************************/
		/* ͼƬ�ռ�任-ƽ��                                        */
		/* ����(dlg.m_xPlace,dlg.m_yPlace)��ʾͼ��ƽ�Ƶ�����        */
		/* ����Plave�����ƽ�ƺ����ʼ���꣬���������긳ֵΪ'0'��ɫ */
		/* Ȼ������ƽ�����꣬�յĸ�Ϊ��ɫ���������                 */
		/************************************************************/
		
		/******************************************************************/
		/* ���ش���1�����������ֵ���                                    */
		/* ��View.h�ж������ BYTE *m_pImage ����ͼƬ���ݺ��ָ��         */
		/* ������ʱ��������,����ƽ�Ʊ任 unsigned char *ImageSize         */
		/* ImageSize=m_pImage(����)                                       */
		/* �ᵼ��ImageSize��ֵ�任ʱm_pImageҲ�����˱任,�������ȫΪ��ɫ */
		/*     ��Ϊ����ָ������ͬ�������ַ                               */
		/* ���������ʹ������C++��new������̬�����forѭ��i=m_nImage��ֵ  */
		/******************************************************************/

		/*��ʱ�����洢��������m_pImage��ͬ�����ڴ���ͼ��*/
		unsigned char *ImageSize;      
	    ImageSize=new unsigned char[m_nImage];    //new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�

		int Place;                    //������ʱ���꣬��¼��ʼ����(0,0)ƽ�ƹ�����λ��
		int m_pImagePlace;            //ԭʼͼ��ƽ��Ϊ(0,0)��ͼ�����ƽ�Ƶ�Placeλ��
		unsigned char black;          //����ɫ='0' 
		int flag;                     //��Ǳ�������flag=1ʱ��ʾͼ���Ѿ���ͼ��ƽ�ƶ���������ɫ

		/************************************************************/
		/* for(int i=0 ; i<m_nHeight ; i++ )                        */
		/* for(int j=0 ; j<m_nWidth ; j++ )                         */
		/* ����ʹ�õ��������Ϊ����ͼ������һ��û��������һ������ */
		/* ���������exe����,ʹ��m_nImage��д�������رȽ���ȷ       */
		/************************************************************/

		Place=dlg.m_yPlace*m_nWidth*3; //ǰm_yPlace�ж�Ҫ���Ϊ��ɫ          
		black=0;                       //��ɫΪ��ɫ
		m_pImagePlace=0;               //ͼ����λ��Ϊ(0,0),�Ѹõ�����ƽ�ƹ�ȥ 
		int countWidth=0;              //��¼ÿ�е����ظ���,����ʱ���0
		int number=0;                  //���ּ�¼ʹ�õ���������,ƽ��ʱʹ��

		for(int i=0 ; i<m_nImage ; i++ )
		{
			/*���ÿ�е���������ʱ��Ϊ0*/
			if(countWidth==m_nWidth*3)
			{
				countWidth=0;
			}
			
			/*��һ���֣���ƽ�ƺ�����λ��ǰ����������ص㸳ֵΪ��ɫ*/
			if(i<Place)
			{
				ImageSize[i]=black;     //��ֵΪ��ɫ
				continue;
			}
			
			/*�ڶ����֣�ƽ���������߲��ָ�ֵΪ��ɫ*/
			else if(i>=Place && countWidth<dlg.m_xPlace*3)     //RGB��3
			{
				ImageSize[i]=black;     //��ֵΪ��ɫ
				countWidth++;
				continue;
			}
	
			/****************************/
			/* ��������ͼ��ʾ:          */
			/* 000000000000000000000000 */
			/* 000000000000000000000000 */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* ���ʾ���ز���,0Ϊ��ɫ   */
			/****************************/

			/* �ص������ʾ������bmpͼ����ʾ�Ǵ����½ǿ�ʼ�洢(0,0)���������ͼ��Ϊ */
			/* bmpͼ���Ǵ����½ǵ����Ͻ����е� */

			/****************************/
			/* ��������ͼ��ʾ:          */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 000000000000000000000000 */
			/* 000000000000000000000000 */
			/* ���ʾ���ز���,0Ϊ��ɫ   */
			/****************************/
		
			/*�������֣�ͼ������ƽ������*/
			else if(i>=Place && countWidth>=dlg.m_xPlace*3)
			{
				
				ImageSize[i]=m_pImage[m_pImagePlace];     
				m_pImagePlace++;
				countWidth++;
				if(countWidth==m_nWidth*3)
				{
					number++;
					m_pImagePlace=number*m_nWidth*3;
				}
			}
		}
		
		fwrite(ImageSize,m_nImage,1,fpw);  
	
		fclose(fpo);
		fclose(fpw);

		numPicture = 2;
		level=3;                  //��level���ò����Ի�������Ļ�ͼ��������,����Ҫ�ڸ���ֵ
		Invalidate();
	}
}


/*ͼ��ת���Լ���������ܱȽϸ���Ȥ,����ͼ��ת*/
void CBmpDrawView::OnJhbhFz() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ���ռ䷴ת ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܿռ䷴ת!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("ͼƬ�ռ�任-��תͼ��!",MB_OK,0);

	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);
	
	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];    
	int countWidth=0;        //��¼ÿ�е����ظ���,����ʱ���0
	int Place;               //��¼ͼ��ÿ�е�λ��,����ͼ��ת
	int number=0;            //���ּ�¼ʹ�õ���������
	Place=m_nWidth*3-1;

	for(int i=0 ; i<m_nImage ; i++ )
	{
		if(countWidth==m_nWidth*3)
		{
			countWidth=0;
		}

		ImageSize[i]=m_pImage[Place];
		Place--;
		countWidth++;
		if(countWidth==m_nWidth*3)
		{
			number++;
			Place=number*m_nWidth*3-1;
		}
	}
		
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	numPicture = 2;
	level=3;                  //ͼƬ����ʹ��,����Ҫ�������µ�level         
	Invalidate();
}


/********************************************************/
/* ���α任��ͼƬ����ת                                 */
/* ����ӶԻ���:IDD_XZ_DS(��ת����),��������CTestXZDlg  */
/* �������������:m_xzds Member variables Ϊint 0-360�� */
/********************************************************/

void CBmpDrawView::OnJhbhXz() 
{
	// TODO: Add your command handler code here
	
		
	//���û�е���ͼƬֱ�ӵ���ռ���ת ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܿռ���ת!",MB_OK,0);
		return;
	}
	
	
	//����Ի��򲢵��öԻ���
	CTestXZDlg dlg;    
	
	//��ʾ�Ի���
	if( dlg.DoModal()==IDOK )
	{
		AfxMessageBox("ͼƬ�ռ�任-��תͼ��!",MB_OK,0);
		
		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");


		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
		
		fread(m_pImage,m_nImage,1,fpo);
		
		/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[m_nImage];    
		int Place;               //��¼ͼ��ÿ�е�λ��,����ͼ����ת


		/*����PA=3.14ʱʹ�õķ�����arcsin(1.0/2)*6��Ϊ��*/
		double PA;
		PA=asin(0.5)*6;
		
		/*�������0-360������������ת��Ϊ�Ƕ�,30��=��/6*/
		double degree; 
		degree=PA*dlg.m_xzds/180;   //����dlg.m_xzds(��ת����)
		
		//��Ӧ�Ķ�ά����,ע��ͼ���������½ǿ�ʼ����,������Ҫת����һά�洢
		int X,Y;               //ͼ��任ǰͨ��һά����ת��Ϊ��ά
		int XPlace,YPlace;

		//���ת��Ϊ�ĽǶ�
		CString str;
		str.Format("ת����ĽǶ�=%f",degree);
		AfxMessageBox(str);


		//ͼ����ת����
		for(int i=0 ; i<m_nImage ; i++ )
		{
			//ԭͼ��һά����ת��Ϊ��ά����
			X=(i/3)%m_nWidth;
			Y=(i/3)/m_nWidth;
			//ע�����X=i/m_nHeight; Y=i%m_nWidth; ֻ������1/3

			//ͼ����תΪ��a(x,y)=x*cos-y*sin b(x,y)=x*sin+y*cos
			XPlace=(int)(X*cos(degree)-Y*sin(degree));
			YPlace=(int)(X*sin(degree)+Y*cos(degree));
			
			//XPlace=X;         //��ʾԭͼ�����ʹ��
			//YPlace=Y;
			

			//��ת��Ϊһάͼ�����
			if( (XPlace>=0 && XPlace<=m_nWidth) && (YPlace>=0 && YPlace<=m_nHeight) )
			{
				Place=YPlace*m_nWidth*3+XPlace*3;

				//��ͼ��Χ�ڸ�ֵΪ������
				if(Place+2<m_nImage) 
				{
					ImageSize[i]=m_pImage[Place];
					i++;
					ImageSize[i]=m_pImage[Place+1];
					i++;
					ImageSize[i]=m_pImage[Place+2];
				}

				//����ֵΪ��ɫ
				else 
				{
					ImageSize[i]=0; 
					i++;
					ImageSize[i]=0;
					i++;
					ImageSize[i]=0;
				}
			}

			//����ֵΪ��ɫ
			else
			{
				ImageSize[i]=0;
				i++;
				ImageSize[i]=0;
				i++;
				ImageSize[i]=0;
			}
		}
	
		fwrite(ImageSize,m_nImage,1,fpw);  
		
		fclose(fpo);
		fclose(fpw);
		
		numPicture = 2;
		level=3;                  //ͼƬ����ʹ��,����Ҫ�������µ�level         
		Invalidate();

	}
}


/**************************************************/
/* �ھ���--ͼ����ǿ                               */
/* Menu�У�ID_TXZQ_PH (ƽ��) ID_TXZQ_RH (��)    */
/* Dialog�У������Ի��� ID_TXZQ_MB (ͼ����ǿģ��) */
/**************************************************/

/********************************************************/
/* �ص㣺Dialog��������е��÷�                         */
/*  1.�����ڶԻ����д���һ����Ͽ�(����) IDC_TXZQ_PH    */
/*  2.ʹ�������������ʱ,ctrl+�س�����,����ĸ�ģ��     */
/*  3.Ctrl+W�����ർ�򣺴����öԻ������ CTestTXZQPHDlg */
/*  4.Member Variable ΪIDC_TXZQ_PH���һ��Control����  */
/*  5.�����Ϳ���ʹ�ð�������,����ҵ�ǰѡ�еڼ���ģ��   */
/********************************************************/


/*ͼ����ǿ--ƽ��*/
void CBmpDrawView::OnTxzqPh() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(ƽ��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(ƽ��)!",MB_OK,0);
		return;
	}


	//����ģ��Ի���
	CTestTXZQPHDlg dlg;
	

	//��ʾ�Ի���
	if(dlg.DoModal()==IDOK)
	{
		/******************************************************************/
		/* ͼ��ƽ�����㷨��                                               */
		/*   1.���峣�õ��ĸ�ģ��,���ǵ�ά����Ϊ3,����ĸ�����Ϊ9������   */
		/*   2.����˼���ǰ�һ�����ɢ������Χ��9������,����ʹͼ���ģ��   */
		/*   3.ͨ���������Χ�Ƹõ�ľ������غ�,������ƽ��ֵ(��9)��ֵ���� */
		/*   4.ģ�鲻ͬ,������ͼ��Ҳ������ͬ                            */
		/******************************************************************/


		/*��һ�����ȶ�������ģ��*/

		int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

		float H1[3][3]={{1.0/10,1.0/10,1.0/10}, //ģ��һ:ϵ��1/10
						{1.0/10,2.0/10,1.0/10},
						{1.0/10,1.0/10,1.0/10}};
		
		float H2[3][3]={{1.0/16,2.0/16,1.0/16}, //ģ���:ϵ��1/16
						{2.0/16,4.0/16,2.0/16},
						{1.0/16,2.0/16,1.0/16}};

		float H3[3][3]={{1.0/8,1.0/8,1.0/8},    //ģ����:ϵ��1/8,�������Ϊ�ѵ�תΪ���ľ���
						{1.0/8,0.0/8,1.0/8},
						{1.0/8,1.0/8,1.0/8}};

		float H4[3][3]={{0.0,1.0/8,0.0},        //ģ����:ϵ�������ݺ�ľ���
						{1.0/8,1.0/2,1.0/8},
						{0.0,1.0/8,0.0}};


		//����ʱ��ͼƬ
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");
		
		AfxMessageBox("bbbbb!",MB_OK,0);

		//��ȡ�ļ�
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
		
		fread(m_pImage,m_nImage,1,fpo);
		

		//��ȡģ���Ӧ�����:(��0��λģ��һ)
		
		//int Index=dlg.m_txzq_ph.GetCurSel();
		
		/**********************************************************************/
		/* afxwin2.inl ���� Line:711                                          */
		/* For information on how your program can cause an assertion failure */
		/* see the Visual C++ documentation asserts.                          */
		/**********************************************************************/

		/**********************************************************************/
		/* ���ԭ��:��������ֽ������                                        */
		/* if(aboutDlg.DoModal()==IDOK)                                       */
		/* if(aboutDlg.m_combo.GetCurSel()!=CB_ERR)ʱ�ͻᱨ��                 */
		/* Dlg.DoModal()���������Ժ�,���ھ��Ѿ��ر�,�����ϵĿؼ����Ѿ��ͷ���  */
		/* ��Ȼ�޷��õ���ǰѡ�����,����OnOk���õ���ǰѡ�����                */
		/* �������Dlg��OnOk����,����IDOK��Command��Ϣ,��������ȡѡ��������   */
		/**********************************************************************/

		/**********************************************************/
		/* �ص�֪ʶ:�������                                      */
		/* 1.��Ctrl+W����Dlg�Ի����OnOK()����                    */
		/* 2.��TestTXZQPHDlg.cpp��OnOK����ǰ����ȫ�ֱ���Index     */
		/*		ע�⣺������ȫ�ֱ���,�������ֺ����������Ͳ�һ�� */
		/* 3.�ڸú�����ʹ��extern int Index��ȡ�Ӻ����е�ֵ(����) */
		/**********************************************************/

		//������Ӱ����File:afxinl.inl Line:418����
		extern int Index;

		AfxMessageBox("cccccc!",MB_OK,0);

		CString str;
		str.Format("ͼ����ǿ(ƽ��)!ѡȡ��ģ��Ϊ:%d",Index+1);
		AfxMessageBox(str);

		
		/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[m_nImage];     //ʹ��newʱ,��һ���ܳɹ����,����ͻ��
		float red,green,blue;
		
		int X,Y;       //һά����ת��Ϊ��ά����
		int TR,TG,TB;  //��¼����������λ��
	
	
		//ͼ����ǿ:ƽ��
		for(int i=0; i<m_nImage ; i=i+3 )
		{
			//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
			
			//ԭͼ��һά����ת��Ϊ��ά����
			X=(i/3)%m_nWidth;    //ͼ����X��
			Y=(i/3)/m_nWidth;    //ͼ����Y��
			
			//��ֵΪ��ɫ,�൱������
			red=green=blue=0;

			//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
			for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
			{
				for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
				{
					if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
					{			
						//ģ��һ
						//����ģ��ƽ��,�Ѹõ����ط�ɢ������
						if(Index==0)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						
						//ģ���
						else if(Index==1)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						//ģ����
						else if(Index==2)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						//ģ����
						else if(Index==3)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H4[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H4[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H4[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
					}
				}
			}
			
			//����ͼ��ֵ
			ImageSize[i]=(unsigned char)(red);
			ImageSize[i+1]=(unsigned char)(green);
			ImageSize[i+2]=(unsigned char)(blue);
		
		}
		
		fwrite(ImageSize,m_nImage,1,fpw);  
		
		fclose(fpo);
		fclose(fpw);
		

		/******************************************************/
		/* д����������ᱨ��                                 */
		/* File:afxinl.inl Line:418                           */
		/* �����Ǹ�ͼƬ�Ѿ��༭һ��,�Ѵ���,�����ڵ�����ʾ��ͼ */
		/* ԭ����һ�� level=3;                                */
		/******************************************************/

		/****************************************************************/
		/* _AFXWIN_INLINE int CBitmap::GetBitmap(BITMAP* pBitMap)       */
		/* {                                                            */ 
		/* ASSERT(m_hObject != NULL); //�ڴ��г���Ӧ����LoadBitmapʧ��  */
		/* return ::GetObject(m_hObject, sizeof(BITMAP), pBitMap);      */
		/* }                                                            */
		/****************************************************************/

		numPicture = 2;
		level=400;
		Invalidate();

	}
}




/*****************************************/
/* ͼ����:����menu�д���5���ӵ�menu    */
/* ��ֹ����ƽ������,һ��ֻ����һ�������� */
/* ID_RH_Laplacian Laplacian������˹���� */
/* ID_RH_Sobel Sobel����                 */
/* ID_RH_Prewitt Prewitt����             */
/* ID_RH_Isotropic Isotropic����         */
/* ID_RH_GTMB ��ͨģ��H2                 */
/*****************************************/


void CBmpDrawView::OnRHLaplacian() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(��)!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����ǿ(��):����������˹(Laplacian)����!");

	int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

	int H[3][3]={{0,-1,0},    //ģ��Ϊ������˹����(����Ϊ4��Laplacian)
				{-1,4,-1},
				{0,-1,0}};

	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //һά����ת��Ϊ��ά����
	int TR,TG,TB;  //��¼����������λ��
	
	
	//ͼ����ǿ:ƽ��
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
		
		//ԭͼ��һά����ת��Ϊ��ά����
		X=(i/3)%m_nWidth;    //ͼ����X��
		Y=(i/3)/m_nWidth;    //ͼ����Y��
		
		//��ֵΪ��ɫ,�൱������
		red=green=blue=0;
		
		//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
			{
				if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
				{			
					
					TR=j*m_nWidth*3+k*3;	
					red+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					TG=j*m_nWidth*3+k*3+1;
					green+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					TB=j*m_nWidth*3+k*3+2;
					blue+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
				}
			}
		}
		
		//����ͼ��ֵ:Ϊ������ԭ���Ĳ�׼ȷ��ֵ,�Ұ�ԭ����ע�͵�������
		if(red>=0 && red<256) ImageSize[i]=red;
		else if(red<0) ImageSize[i]=0;      //ImageSize[i]=-red;
		else ImageSize[i]=0;
		
		if(green>=0 && green<256) ImageSize[i+1]=green;
		else if(green<0) ImageSize[i+1]=0;  //ImageSize[i+1]=-green;
		else ImageSize[i+1]=0;
		
		if(blue>=0 && blue<256) ImageSize[i+2]=blue;
		else if(blue<0) ImageSize[i+2]=0;   //ImageSize[i+2]=-blue;
		else ImageSize[i+2]=0;
			
	}
	
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	
	numPicture = 2;
	level=3;	
	Invalidate();
}

//Sobel���Ӳ���PPT�ϵ�d(x)d(y)ģ��
void CBmpDrawView::OnRHSobel() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(��)!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����ǿ(��):����Sobel����!");

	int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

	//ģ��ΪSobel����
	int HX[3][3]={{1,0,-1},{2,0,-2},{1,0,-1}};
	int HY[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int redX,greenX,blueX;
	int redY,greenY,blueY;
	
	int X,Y;       //һά����ת��Ϊ��ά����
	int TR,TG,TB;  //��¼����������λ��
	
	
	//ͼ����ǿ:ƽ��
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
		
		//ԭͼ��һά����ת��Ϊ��ά����
		X=(i/3)%m_nWidth;    //ͼ����X��
		Y=(i/3)/m_nWidth;    //ͼ����Y��
		
		//��ֵΪ��ɫ,�൱������
		redX=greenX=blueX=0;
		redY=greenY=blueY=0;
		
		//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
			{
				if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
				{			
					
					TR=j*m_nWidth*3+k*3;	
					redX+=HX[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					redY+=HY[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					TG=j*m_nWidth*3+k*3+1;
					greenX+=HX[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					greenY+=HY[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					TB=j*m_nWidth*3+k*3+2;
					blueX+=HX[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
					blueY+=HY[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
				}
			}
		}
		
		//����ͼ��ֵ:Ϊ������ԭ���Ĳ�׼ȷ��ֵ,�Ұ�ԭ����ע�͵�������
		//s=(d(x)*d(x)+d(y)*d(y))������
		
		int R,G,B;
		R=(int)(sqrt(redX*redX*1.0+redY*redY*1.0));
		G=(int)(sqrt(greenX*greenX*1.0+greenY*greenY*1.0));
		B=(int)(sqrt(blueX*blueX*1.0+blueY*blueY*1.0));

		if(redX<0 && redY<0) ImageSize[i]=0;
		else if(R>255) ImageSize[i]=255;
		else ImageSize[i]=R;
		
		
		if(greenX<0 && greenY<0) ImageSize[i+1]=0;
		else if(G>255) ImageSize[i+1]=255;
		else ImageSize[i+1]=G;

		if(blueX<0 && blueY<0) ImageSize[i+2]=0;
		else if(B>255) ImageSize[i+2]=255;
		else ImageSize[i+2]=B;

	}
	
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	
	numPicture = 2;
	level=3;	
	Invalidate();
}

//Isotropic���Ӳ���PPT�ϵ�d(x)ģ��,����d(y)
void CBmpDrawView::OnRHIsotropic() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(��)!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����ǿ(��):����Isotropic����!");

	int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

	//ģ��ΪIsotropic����
	float H[3][3]={{1,0,-1}, 
					{sqrt(2.0),0,-sqrt(2.0)}, 
					{1,0,-1}};

	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	float red,green,blue;
	
	int X,Y;       //һά����ת��Ϊ��ά����
	int TR,TG,TB;  //��¼����������λ��
	
	
	//ͼ����ǿ:ƽ��
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
		
		//ԭͼ��һά����ת��Ϊ��ά����
		X=(i/3)%m_nWidth;    //ͼ����X��
		Y=(i/3)/m_nWidth;    //ͼ����Y��
		
		//��ֵΪ��ɫ,�൱������
		red=green=blue=0;
		
		//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
			{
				if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
				{			
					
					TR=j*m_nWidth*3+k*3;	
					red+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					TG=j*m_nWidth*3+k*3+1;
					green+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					TB=j*m_nWidth*3+k*3+2;
					blue+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
				}
			}
		}
		
		//����ͼ��ֵ:Ϊ������ԭ���Ĳ�׼ȷ��ֵ,�Ұ�ԭ����ע�͵�������
		if(red>=0 && red<256) ImageSize[i]=(int)red;
		else if(red<0) ImageSize[i]=0;      //ImageSize[i]=-red;
		else ImageSize[i]=0;
		
		if(green>=0 && green<256) ImageSize[i+1]=(int)green;
		else if(green<0) ImageSize[i+1]=0;  //ImageSize[i+1]=-green;
		else ImageSize[i+1]=0;
		
		if(blue>=0 && blue<256) ImageSize[i+2]=(int)blue;
		else if(blue<0) ImageSize[i+2]=0;   //ImageSize[i+2]=-blue;
		else ImageSize[i+2]=0;
			
	}
	
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	
	numPicture = 2;
	level=3;	
	Invalidate();
	
}


//Prewitt���Ӳ���PPT�ϵ�d(x)ģ��,����d(y)
void CBmpDrawView::OnRHPrewitt() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(��)!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����ǿ(��):����Prewitt����!");

	int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

	int H[3][3]={{1,0,-1},    //ģ��ΪPrewitt����
				{1,0,-1},
				{1,0,-1}};


	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //һά����ת��Ϊ��ά����
	int TR,TG,TB;  //��¼����������λ��
	
	
	//ͼ����ǿ:ƽ��
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
		
		//ԭͼ��һά����ת��Ϊ��ά����
		X=(i/3)%m_nWidth;    //ͼ����X��
		Y=(i/3)/m_nWidth;    //ͼ����Y��
		
		//��ֵΪ��ɫ,�൱������
		red=green=blue=0;
		
		//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
			{
				if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
				{			
					
					TR=j*m_nWidth*3+k*3;	
					red+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					TG=j*m_nWidth*3+k*3+1;
					green+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					TB=j*m_nWidth*3+k*3+2;
					blue+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
				}
			}
		}
		
		//����ͼ��ֵ:Ϊ������ԭ���Ĳ�׼ȷ��ֵ,�Ұ�ԭ����ע�͵�������
		if(red>=0 && red<256) ImageSize[i]=red;
		else if(red<0) ImageSize[i]=0;      //ImageSize[i]=-red;
		else ImageSize[i]=0;
		
		if(green>=0 && green<256) ImageSize[i+1]=green;
		else if(green<0) ImageSize[i+1]=0;  //ImageSize[i+1]=-green;
		else ImageSize[i+1]=0;
		
		if(blue>=0 && blue<256) ImageSize[i+2]=blue;
		else if(blue<0) ImageSize[i+2]=0;   //ImageSize[i+2]=-blue;
		else ImageSize[i+2]=0;
			
	}
	
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	
	numPicture = 2;
	level=3;	
	Invalidate();
	
}


//��ͨ�˲����õ���ģ��H2
void CBmpDrawView::OnRhGtmb() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ��ͼ����ǿ(��) 
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ͼ����ǿ(��)!",MB_OK,0);
		return;
	}

	AfxMessageBox("ͼ����ǿ(��):����Prewitt����!");

	int HWS=3;                                //ģ��ά��:���ĸ�ģ���Ϊ3ά��

	int H[3][3]={{-1,-1,-1},    //ģ��ΪPrewitt����
				{-1,8,-1},
				{-1,-1,-1}};

	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //һά����ת��Ϊ��ά����
	int TR,TG,TB;  //��¼����������λ��
	
	
	//ͼ����ǿ:ƽ��
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//��Ҫ��ȡԴͼ����Χ9����ľ������ģ��9����ľ���,��һάͼ��ת��ά
		
		//ԭͼ��һά����ת��Ϊ��ά����
		X=(i/3)%m_nWidth;    //ͼ����X��
		Y=(i/3)/m_nWidth;    //ͼ����Y��
		
		//��ֵΪ��ɫ,�൱������
		red=green=blue=0;
		
		//��ͼ�����������Ͳ�ȡƽ��ֵ HWSά��
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //��j��
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //��k��
			{
				if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
				{			
					
					TR=j*m_nWidth*3+k*3;	
					red+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TR]);
					TG=j*m_nWidth*3+k*3+1;
					green+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TG]);
					TB=j*m_nWidth*3+k*3+2;
					blue+=H[(j-Y+HWS/2)][(k-X+HWS/2)]*(m_pImage[TB]);
				}
			}
		}
		
		//����ͼ��ֵ:Ϊ������ԭ���Ĳ�׼ȷ��ֵ,�Ұ�ԭ����ע�͵�������
		if(red>=0 && red<256) ImageSize[i]=red;
		else if(red<0) ImageSize[i]=0;      //ImageSize[i]=-red;
		else ImageSize[i]=0;
		
		if(green>=0 && green<256) ImageSize[i+1]=green;
		else if(green<0) ImageSize[i+1]=0;  //ImageSize[i+1]=-green;
		else ImageSize[i+1]=0;
		
		if(blue>=0 && blue<256) ImageSize[i+2]=blue;
		else if(blue<0) ImageSize[i+2]=0;   //ImageSize[i+2]=-blue;
		else ImageSize[i+2]=0;
			
	}
	
	fwrite(ImageSize,m_nImage,1,fpw);  
	
	fclose(fpo);
	fclose(fpw);
	
	numPicture = 2;
	level=3;	
	Invalidate();	
}


/**************************************************************************/
/* huffman���� ID_BM_HFM(���������)                                      */
/* 1.����ͼ��ĻҶȼ���                                                   */
/* 2.����ͼ��Ҷȵĸ��ʷֲ�                                               */
/* 3.��ͼ��Ҷȸ��ʽ��д�С���������                                     */
/* 4.�������������                                                       */
/*   (�ص�)���ǶԸ��Ҷȸ��ʽ�������,�����ĸ�����С������Ԫ�����        */
/*   ��Ϊһ���µ�Ԫ��ȡ�������и�����С������Ԫ��,������������С��2������ */
/* 5.��λͼ���б���ѹ��                                                   */
/**************************************************************************/          

void CBmpDrawView::OnBmHfm() 
{

	//���û�е���ͼƬֱ�ӵ������������ ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܽ��й���������!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("ͼƬ����-Huffman����ѹ��ͼ��!",MB_OK,0);
		
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");


	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
//	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
//	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	int Red[256],Green[256],Blue[256];
	int i,j,k;
	for(j=0;j<256;j++)   //�������鲢����
	{
		Red[j]=0;
		Green[j]=0;
		Blue[j]=0;
	}
	
	//�ص�:ֻ��24λ�ĻҶ�ͼ�����ѹ��,�����ͼ��Ҷ�����Ͳ���ΪR G B(3������)	

	int HD[256];                                  //��¼�Ҷ�ֵ
	double HDGL[256];                             //�Ҷȸ���ֵ��¼
	int Relation[256];                            //HDGL[256]��str_HFM[256]��ӳ���ϵ
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;                  //ǿ��ת��

	//��ʼ��
	memset(HD,0,sizeof(HD));
    memset(HDGL,0,sizeof(HDGL));

	//��һ��:����ͼ��ĻҶȼ��� 
	for(i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		IntRed=int(red);
		if( IntRed>=0 && IntRed<256 ) HD[IntRed]++;   //ԭ��ʹ�õ���Red[IntRed]++;��¼RGB ����ͳһΪ�Ҷ�ͼ
		
		fread(&green,sizeof(char),1,fpo);
		IntGreen=int(green);
		if( IntGreen>=0 && IntGreen<256 ) HD[IntGreen]++;
		
		fread(&blue,sizeof(char),1,fpo);
		IntBlue=int(blue);
		if( IntBlue>=0 && IntBlue<256 ) HD[IntBlue]++;
	}

	//�ڶ���:����256�Ҷ�ֵ�ķֲ�����
	double sum=0;    //������ʺ�
	for(i=0; i<255; i++ )
	{
		HDGL[i]=(HD[i]*1.0)/m_nImage;
		sum+=HDGL[i];
	}
	//Ϊ�˱�֤���ǵĸ��ʺ�Ϊ1,���һ���Ҷȸ��ʲ���1�����к�
	HDGL[255]=1.0-sum;

	//HDGL[256]��str_HFM[256]��ӳ���ϵRelation[256]��ʼ��
	for(i=0; i<256; i++ )
	{
		Relation[i]=i;
	}

	//������:��ͼ��ĻҶȵȼ������ʴ�С���д�С�������� ð������
	double T;                        
	for(j=0; j<256-1; j++)   //��Ϊѭ������i+1,��ֹԽ��д��256-1
	{
		for(i=0; i<256-j-1; i++) 
		{
			//��������
			if(HDGL[i]>HDGL[i+1])
			{
				T=HDGL[i];
				HDGL[i]=HDGL[i+1];
				HDGL[i+1]=T;
			}

			//����ӳ���ϵ
			for(k=0; k<256; k++)
			{
				//�ж��Ƿ���HDGL[256]���ӽڵ�
				if(Relation[k]==i)
				{
					//ӳ�䵽�ڵ�j+1
					Relation[k]=i+1;	
				}
				else if(Relation[k]==i+1)
				{
					//ӳ�䵽�ڵ�i
					Relation[k]=i;
				}
			}

		}
	}

	
	//���Ĳ�:��������������(������ �������Ϊ��̬�Ļ�����������������������ͽṹ)
	for(i=0; i<256-1; i++)
	{
		//Ѱ�ҵ�һ����Ϊ0�ĸ��ʻҶȼ�
		if(HDGL[i]>0) break;
	}

	//����������Ĵ洢������ 0 1 �ı���
	CString str_HFM[256];                         

	//��ʼ����
	for(i=i; i<256-1 ; i++)
	{
		//����str_HFM
		for(k=0; k<256; k++)
		{
			//�ж��Ƿ���Relation[i]���ӽڵ㲢�����ַ���
			if(Relation[k]==i)
				str_HFM[k]="1"+str_HFM[k];
			else if(Relation[k]==i+1) 
				str_HFM[k]="0"+str_HFM[k];
		}

		//������С�������������,������浽HDGL[i+1]
		HDGL[i+1]=HDGL[i+1]+HDGL[i];

		//�ı�ӳ���ϵ
		for(k=0; k<256; k++)
		{
			//�ж��Ƿ���HDGL[i]���ӽڵ�
			if(Relation[k]==i)
			{
				//ӳ�䵽�ڵ�i+1
				Relation[k]=i+1;
			}
		}

		//��������
		for(j=i+1; j<256-1; j++)
		{
			if(HDGL[j]>HDGL[j+1])
			{
				//����
				double sign = HDGL[j];
				HDGL[j]=HDGL[j+1];
				HDGL[j+1]=sign;

				//����ӳ���ϵ
				for(k=0; k<256; k++)
				{
					//�ж��Ƿ���HDGL[i]���ӽڵ�
					if(Relation[k]==j)
						Relation[k]=j+1;   //ӳ�䵽�ڵ�j+1
					else if(Relation[k]==j+1)
						Relation[k]=j;
				}
			}

			//�˳�ѭ��
			else break;
		}
	}

	//��ʾ����ѹ���ĸ��ʷֲ�
	CTestBMDlg dlg;    
	//��ʾ���Եķֲ�
	dlg.m_BM_1=str_HFM[1];
	dlg.m_BM_10=str_HFM[10];
	dlg.m_BM_20=str_HFM[20];
	dlg.m_BM_30=str_HFM[30];
	dlg.m_BM_40=str_HFM[40];
	dlg.m_BM_50=str_HFM[50];
	dlg.m_BM_60=str_HFM[60];
	dlg.m_BM_70=str_HFM[70];
	dlg.m_BM_80=str_HFM[80];
	dlg.m_BM_90=str_HFM[90];
	dlg.m_BM_100=str_HFM[100];
	dlg.m_BM_110=str_HFM[110];
	dlg.m_BM_120=str_HFM[120];
	dlg.m_BM_130=str_HFM[130];
	dlg.m_BM_140=str_HFM[140];
	dlg.m_BM_150=str_HFM[150];
	dlg.m_BM_160=str_HFM[160];
	dlg.m_BM_170=str_HFM[170];
	dlg.m_BM_180=str_HFM[180];
	dlg.m_BM_190=str_HFM[190];
	dlg.m_BM_200=str_HFM[200];
	dlg.m_BM_210=str_HFM[210];
	dlg.m_BM_220=str_HFM[220];
	dlg.m_BM_230=str_HFM[230];
	dlg.m_BM_240=str_HFM[240];
	dlg.m_BM_250=str_HFM[250];
	dlg.m_BM_64=str_HFM[64];
	dlg.m_BM_128=str_HFM[128];
	dlg.m_BM_192=str_HFM[192];
	dlg.m_BM_255=str_HFM[255];

//	fwrite(m_pImage,m_nImage,1,fpw);  

	//��ʾ�Ի���
	if( dlg.DoModal()==IDOK )
	{
	}
	

	//���岽:��ͼ����л���������ѹ��

	//λ����
	unsigned char Array[8]={128,64,32,16,8,4,2,1};
	//8λ�Ļ���������ͼ��
	CString picture="";
	unsigned char flag=0;
	
	//��ͼ������ؽ��б���
	for(i=0; i<m_nImage; i++)
	{
		picture+=str_HFM[m_pImage[i]];
		int length=picture.GetLength();			
		int loop=0;
		
		do{
			flag=0;
			for(k=0; k<min(8,picture.GetLength()) ; k++ )
			{
				if(picture.Mid(k,1)=="1")
					flag |=Array[k];
			}
			fwrite(&flag,1,1,fpw);
			loop++;
			length=length-8;
			
			if(picture.GetLength()<8)
				break;
			else
				picture=picture.Right(picture.GetLength()-8);
		}while(length>=8);
	}
	
	fclose(fpo);
	fclose(fpw);
		
	numPicture = 1;           //ֻ��ʾһ��ͼ��
	Invalidate();
}



/***************************************************************/
/* ��ֵͼ���ϸ��                                              */
/* ��ֵͼ��������ͼ�����Ҫ�Ӽ���ָ�Ҷ�ֵֻȡ����ֵ��ͼ��      */
/* �����Ҷ�ֵ��ȡΪ 0-��Ӧ�ĵ㹹�ɱ��� �� 1-��Ӧ�ĵ㹹�ɾ���   */
/* ��ֵ��̬ѧ�����㷨����������,��ʴ�����������������Ϊ������ */
/***************************************************************/

/****************************************************************************/
/* ϸ���ĺ���:�����и�ʴ������,����ֱ����������������                       */
/* ������ͨ���жϸô����Ƿ�ı�ԭͼ�����ͨ��,������ı�,����ǰ������ʴ�� */
/* ����ı�,��Ҫ������б���                                                */
/* ϸ������ʵ����һ�ֱ���ͼ��ԭ����ͨ�Եĸ�ʴ����                           */
/* ���л����б任   PPT-��13��-15ҳ                                         */
/****************************************************************************/

void CBmpDrawView::OnEztxXh() 
{
	// TODO: Add your command handler code here

	//���û�е���ͼƬֱ�ӵ��ϸ�� ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ�����ϸ��ͼƬ!",MB_OK,0);
		return;
	}

	AfxMessageBox("ϸ��ͼ��!",MB_OK,0);
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	//�Ҷ�ͼ��
	int i,j,m,n;
	unsigned char color;
	unsigned char red,green,blue;
	
	//5*5�����ھ���,�������ڱ����õ�,����ȥ��
	unsigned char Array[5][5];
	
	unsigned char Count;   //������
	unsigned char sign;    //ѭ��������־,trueʱ����,false����ѭ��

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  

	//��ʼ��,��ʼֵΪ255 ��ɫ
	memset(ImageSize,(BYTE)255,m_nImage);
	
	//��¼������ͼ���е�λ��
	int place;          //�任���λ��

	sign=true;
	while(sign)
	{
		sign=false;
		
		//��ʼ��,��ʼֵΪ255
		memset(ImageSize,(BYTE)255,m_nImage);

		//����ʹ��5*5�ĽṹԪ��,Ϊ��ֹԽ��,��������Χ��2��2������
		for(i=2; i<m_nHeight-2; i++)
		{
			for(j=2*3; j<m_nWidth*3-2*3; j+=3 )  //��*3=ÿ�е�����
			{
				//ֻ��Դͼ������i��,��j�����ص�λ��
				place=i*m_nWidth*3+j;                    //��ȡ��ǰ�����λ��

			//	CString str;
			//	str.Format("%d",place);
			//	AfxMessageBox(str);

				//���Դͼ���еĵ�λ��ɫ,������
				if(m_pImage[place]>127) continue;        //ֱ������Ϊ��ɫ

				//��ȡ��ǰ�����ڵ�5*5����������ֵ,��ɫ��0��ʾ,��ɫ��1��ʾ
				for(m=0; m<5; m++)
				{
					for(n=0; n<5; n++)
					{
						/********************************/
						/*  .....ooooooooooooooooooooo  */
						/*  .....ooooooooooooooooooooo  */
						/*  ..A..ooooooooooooooooooooo  */
						/*  .....ooooooooooooooooooooo  */
						/*  .....ooooooooooooooooooooo  */
						/********************************/

						//ͼ��A��Ϊ��һ����,��A�㿪ʼ��place=A
						//place+(2-m)*m_nWidth*3+(n-2)*3��ʾA����Χ��5*5�ľ���,��ΪΪ��ֹԽ��,��������Χ��2��2������
					
						if(m_pImage[place+(2-m)*m_nWidth*3+(n-2)*3]>127)
							Array[m][n]=0;
						else
							Array[m][n]=1;
					}
				}


//�ж�����1�Ƿ����

				/*********/
				/* ..... */
				/* .ooo. */
				/* .o.o. */
				/* .ooo. */
				/* ..... */
				/*********/
				
				Count=0;
				Count=Array[1][1]+Array[1][2]+Array[1][3]+Array[2][1]+Array[2][3]+Array[3][1]+Array[3][2]+Array[3][3];

				if(Count<2 || Count>6)  //�ı�
				{
					ImageSize[place]=255;
					ImageSize[place+1]=255;
					ImageSize[place+2]=255;
					continue;
				}

//�ж�����2�Ƿ����

				/*********/
				/* ..... */
				/* .ooo. */
				/* .o.o. */
				/* .ooo. */
				/* ..... */
				/*********/

				Count=0;
				if(Array[1][2]==0 && Array[1][1]==1)
					Count++;
				if(Array[1][1]==0 && Array[2][1]==1)
					Count++;
				if(Array[2][1]==0 && Array[3][1]==1)
					Count++;
				if(Array[3][1]==0 && Array[3][2]==1)
					Count++;
				if(Array[3][2]==0 && Array[3][3]==1)
					Count++;
				if(Array[3][3]==0 && Array[2][3]==1)
					Count++;
				if(Array[2][3]==0 && Array[1][3]==1)
					Count++;
				if(Array[1][3]==0 && Array[1][2]==1)
					Count++;

				if(Count!=1)
				{
					ImageSize[place]=0;
					ImageSize[place+1]=0;
					ImageSize[place+2]=0;
					continue;
				}

//�ж�����3�Ƿ����
				if(Array[1][2]*Array[2][1]*Array[2][3]!=0)
				{
					Count=0;
					if (Array[0][2]==0 && Array[0][1]==1) Count++;
                    if (Array[0][1]==0 && Array[1][1]==1) Count++;
                    if (Array[1][1]==0 && Array[2][1]==1) Count++;
                    if (Array[2][1]==0 && Array[2][2]==1) Count++;
                    if (Array[2][2]==0 && Array[2][3]==1) Count++;
                    if (Array[2][3]==0 && Array[1][3]==1) Count++;
                    if (Array[1][3]==0 && Array[0][3]==1) Count++;
                    if (Array[0][3]==0 && Array[0][2]==1) Count++;

					if(Count==1)
					{
						ImageSize[place]=0;
						ImageSize[place+1]=0;
						ImageSize[place+2]=0;
						continue;
					}
				}

//�ж�����4�Ƿ����

				if (Array[1][2]*Array[2][1]*Array[3][2]!=0)
                {
                    Count=0;
                    if (Array[1][1]==0 && Array[1][0]==1) Count++;
                    if (Array[1][0]==0 && Array[2][0]==1) Count++;
                    if (Array[2][0]==0 && Array[3][0]==1) Count++;
                    if (Array[3][0]==0 && Array[3][1]==1) Count++;
                    if (Array[3][1]==0 && Array[3][2]==1) Count++;
                    if (Array[3][2]==0 && Array[2][2]==1) Count++;
                    if (Array[2][2]==0 && Array[1][2]==1) Count++;
                    if (Array[1][2]==0 && Array[1][1]==1) Count++;

                    if (Count==1)
                    {
                        ImageSize[place]=0;
						ImageSize[place+1]=0;
						ImageSize[place+2]=0;
						continue;
                    }
                }

				//���������������ɾ���õ�
				ImageSize[place]=255;
				ImageSize[place+1]=255;
				ImageSize[place+2]=255;

				sign=true;
			}
		}
		if(i==m_nHeight-2 && j==m_nWidth*3-2*3) break;
	}

	fwrite(ImageSize,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=3;
	Invalidate();
	
}


// 8λͼ����õ�ɫ��ҶȻ�����                 
// biBitcount=8ʱ,��256������,1������ռ1���ֽ� 

void CBmpDrawView::OnHdBit() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�ӵ��ϸ�� ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܻҶȻ�ͼƬ!",MB_OK,0);
		return;
	}

	if(m_nBitCount!=8)
	{
		AfxMessageBox("������8λbmpͼƬ,������8λͼƬ����ܻҶȻ�ͼƬ!",MB_OK,0);
		return;
	}

	AfxMessageBox("�Ҷ�8bitͼ��!",MB_OK,0);
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);


	/*****************************************************************/
	/* �ص����: "0x7c9.."ָ�����õ�"0x00a.."�ڴ�,���ڴ治��Ϊ"read" */
	/* ��Ϊ:                                                         */
	/*    fread(&m_pPal,sizeof(RGBQUAD),256,fpo);                    */
	/*    fwrite(&m_pPal,sizeof(RGBQUAD),256,fpw);                   */
	/* ��һ�ζ�ȡ256���ṹ��,������Ҳд��256���ṹ��,�����������    */
	/*****************************************************************/
	
	//����RGB�����¼��ɫ��
	BYTE RED[256];
	BYTE BLUE[256];
	BYTE GREEN[256];

	//��ȡ��ɫ��
	for(int i=0;i<256;i++)
	{
		fread(&m_pPal,sizeof(RGBQUAD),1,fpo);
		RED[i]=m_pPal.rgbRed;
		BLUE[i]=m_pPal.rgbBlue;
		GREEN[i]=m_pPal.rgbGreen;

		//8λ�Ĳ�ɫͼ��Ҷ�,ֻ��ı����ĵ�ɫ�弴��.
		RED[i]=BLUE[i]=GREEN[i]=(RED[i]+BLUE[i]+GREEN[i])/3;
		m_pPal.rgbRed=RED[i];
		m_pPal.rgbBlue=BLUE[i];
		m_pPal.rgbGreen=GREEN[i];
		fwrite(&m_pPal,sizeof(RGBQUAD),1,fpw);
	}
	

	//����8ΪͼƬ���ز��ֵĴ�С
	int size_eight;
	size_eight=m_nSize-sizeof(BITMAPFILEHEADER)-sizeof(BITMAPINFOHEADER)-sizeof(RGBQUAD)*256;

	//�Զ�������
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[size_eight]; 
	
	fread(ImageSize,size_eight,1,fpo);
	fwrite(ImageSize,size_eight,1,fpw);

	fclose(fpo);
	fclose(fpw);

	numPicture = 2;
	level=3;
	Invalidate();
}


//���û���任���ֱ�ߺ�Բ
//����Hough���任����������ͼ��ȫ�����Զ�ֱ�Ӽ��Ŀ����������ͼ��ı�Ե�������������ĳ��÷���

void CBmpDrawView::OnHoughZX() 
{
	// TODO: Add your command handler code here
	
	//���û�е���ͼƬֱ�Ӽ�� ��ʾ��Ϣ
	if(numPicture==0)
	{
		AfxMessageBox("����ͼƬ����ܼ��ͼƬ��ֱ��!",MB_OK,0);
		return;
	}

	AfxMessageBox("���û���任���ֱ��!",MB_OK,0);
	
	//����ʱ��ͼƬ
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//��ȡ�ļ�
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	fread(m_pImage,m_nImage,1,fpo);

	/*new��delete��Ч�Ľ��ж�̬�ڴ�ķ�����ͷ�*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  

	//��ʼ��,��ʼֵΪ255 ��ɫ
	memset(ImageSize,(BYTE)255,m_nImage);

	//�洢�任���е��������ֵ
	int MaxValue1;
	int MaxValue2;
	int MaxDist1;
	int MaxDist2;
	int MaxAngleNumber1;
	int MaxAngleNumber2;

	//����任��ĳߴ� ������ �Խ���
	int MaxDist;
	MaxDist = (int) sqrt(m_nWidth*m_nWidth + m_nHeight*m_nHeight);

	//�Ƕȴ�0��180��ÿ��2��
	int MaxAngleNumber;
	MaxAngleNumber = 90;

	//��ǰλ��
	int place;

	//�任�������
	int Dist;
	int AngleNumber;

	//�任���¼ֵ
	int TransArea[100000];

	int i,j;
	for(j=0; j<m_nHeight; j++)
	{
		for(i=0; i<m_nWidth*3; i+=3)
		{
			//��ȡ��ǰλ��
			place=j*m_nWidth*3+i;

			//Ŀ��ͼ���к���0��255��������Ҷ�ֱֵ�ӷ���
			if(m_pImage[place]!=255 && m_pImage[place]!=0)
			{
				AfxMessageBox("����任ֱ�߼��,ֻ���Ƕ�ֵͼ��!");
				return;
			}	

			//����Ǻڵ㣬���ڱ任��Ķ�Ӧ�����ϼ�1
			if(m_pImage[place]==0)
			{
				//�任������� ע�ⲽ����2�� AngleNumber*2*3.14/180.0�е�2
				for(AngleNumber=0; AngleNumber<MaxAngleNumber; AngleNumber++)
				{
					//X*cos(theta) + y*sin(theta) = r ���нǶ�thetaָr��X��֮��ļн�

					Dist = (int) fabs(i*cos(AngleNumber*2*3.14/180.0) + 
						j*sin(AngleNumber*2*3.14/180.0));

					//�任��Ķ�Ӧ���ϼ�1
					int t;
					t=Dist*MaxAngleNumber+AngleNumber;
					TransArea[t]=TransArea[t]+1;

				//	CString str;
				//	str.Format("%d %d",Dist,Dist*MaxAngleNumber+AngleNumber);
				//	AfxMessageBox(str);
				}
			}
		}
	}
	
	
	//�ҵ��任���е��������ֵ��
	MaxValue1=0;
	MaxValue2=0;

	//�ҵ���һ�����ֵ��
	for (Dist=0; Dist<MaxDist; Dist++)
	{
		for(AngleNumber=0; AngleNumber<MaxAngleNumber; AngleNumber++)
		{
			if(TransArea[Dist*MaxAngleNumber+AngleNumber]>MaxValue1)
			{
				MaxValue1 = TransArea[Dist*MaxAngleNumber+AngleNumber];
				MaxDist1 = Dist;
				MaxAngleNumber1 = AngleNumber;
			}

		}
	}

	//����һ�����ֵ�㸽������
	for (Dist=-9; Dist<10; Dist++)
	{
		for(AngleNumber=-1; AngleNumber<2 ; AngleNumber++)
		{
			if(Dist+MaxDist1>=0 && Dist+MaxDist1<MaxDist 
				&& AngleNumber+MaxAngleNumber1>=0 && AngleNumber+MaxAngleNumber1<=MaxAngleNumber)
			{
				TransArea[(Dist+MaxDist)*MaxAngleNumber+AngleNumber+MaxAngleNumber1]=0;
			}
		}
	}

	//�ҵ��ڶ������ֵ��
	for (Dist=0; Dist<MaxDist; Dist++)
	{
		for(AngleNumber=0; AngleNumber<MaxAngleNumber; AngleNumber++)
		{
			if(TransArea[Dist*MaxAngleNumber+AngleNumber]>MaxValue1)
			{
				MaxValue2 = TransArea[Dist*MaxAngleNumber+AngleNumber];
				MaxDist2 = Dist;
				MaxAngleNumber2 = AngleNumber;
			}

		}
	}

	//�ж���ֱ���Ƿ�ƽ��
	if( fabs(MaxAngleNumber1-MaxAngleNumber2) <= 2 )
	{
		//��ֱ��ƽ�У��ڻ���ͼ�����ػ�������ֱ��
		for(j=0; j<m_nHeight; j++)
		{
			for(i=0; i<m_nWidth*3; i+=3)
			{	

				// ָ�򻺴�ͼ������j��,��i�����ص�ָ��			
				place=m_nWidth*3*j+i;	

				//����õ���ĳһ��ƽ��ֱ���ϣ����ڽ��õ㸳Ϊ��

				//�ڵ�һ��ֱ����
				Dist = (int) fabs(i*cos(MaxAngleNumber1*2*3.14/180.0) + 
							j*sin(MaxAngleNumber1*2*3.14/180.0));
				if (Dist == MaxDist1)
					ImageSize[place]=0;
			
				//�ڵڶ���ֱ����
				Dist = (int) fabs(i*cos(MaxAngleNumber2*2*3.14/180.0) + 
							j*sin(MaxAngleNumber2*2*3.14/180.0));
				if (Dist == MaxDist2)
					ImageSize[place]=0;
			}
		}
	}

	AfxMessageBox("��ʾ!");

	fwrite(ImageSize,m_nImage,1,fpw);

	//��������ᱨ��:File:afxinl.inl Line:418
	fclose(fpo);
	fclose(fpw);
	
	numPicture = 2;
	level=3;
	Invalidate();
}
