// BmpDrawView.cpp : implementation of the CBmpDrawView class
//

#include "stdafx.h"
#include "BmpDraw.h"

#include "BmpDrawDoc.h"
#include "BmpDrawView.h"

#include "ImageStruct.h"

#include "MainFrm.h"

//采样头文件
#include "TestCYDlg.h"

//显示原图直方图头文件
#include "TestZFTDlg.h"

//绝对值 根号
#include<math.h>

//几何运算-灰度级插值 (灰度插值法)
#include "TestHDCZFDlg.h"

//几何运算-旋转度数 (0-360)
#include "TestXZDlg.h"

//图像增强-平滑(4个模块)
#include "TestTXZQPHDlg.h"

//编码压缩-显示灰度值与编码
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
	//初始化显示图片的x y坐标
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

	/*在OnDraw函数中实现图片的最后显示功能*/
	if(!pDoc)
		return;

	if( EntName.Compare(_T("bmp")) == 0 )      //bmp格式
	{
		ReadBmp();                             //图片信息保存如全局变量
		ShowWindowInfo();                      //状态栏显示文件信息 路径 大小 长宽
		ShowBitmap(pDC,BmpName);               //显示图片
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
/*   numPicture=0时显示提示错误信息                  */
/*   numPicture=1时显示1张图片在OnFileOpen中定义     */
/*   numPicture=2时显示2张图片和处理在处理函数中定义 */ 
/*****************************************************/

/*****************************************************/
/*   level=0时显示2张图片                            */
/*   level=1时显示灰度图片                           */
/*   level=2 4 8 16 32 63时不同量化级量化图片        */ 
/*****************************************************/

int numPicture=0;       //显示图片数 
int level=0;            //显示量化等级


/*直方图标记变量 signZFT=1时线性或非线性变化后的直方图*/
int signZFT=0; 
int flagZFT=0;          
/*定义在前面因为在量化采样等不是线性或非线性变化操作中要赋值为0 在ShowBitmap中赋值方便*/


/*定义显示图像缩放时的长宽与标记*/
int flagSF=0;          //图像几何变换缩放变换
int m_nDrawWidthSF=0;  //图像显示宽度缩放后
int	m_nDrawHeightSF=0; //图像显示高度缩放后

//显示BMP格式图片
void CBmpDrawView::ShowBitmap(CDC *pDC, CString BmpName)
{
	//显示一张图片 numPicture == 1
	//显示图片函数LoadImage
	HBITMAP m_hBitmap;
	m_hBitmap = (HBITMAP) LoadImage(NULL,BmpName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
	//AfxMessageBox(BmpName);
	
	/**************************************************/
	/** 1.要装载OEM图像，则设此参数值为0             **/
	/** OBM_ OEM：位图；OIC_OEM图标；OCR_OEM：光标   **/
	/** 2.BmpName要装载图片的文件名                  **/
	/** 3.装载图像类型: IMAGE_BITMAP-装载位图        **/
	/**               IMAGE_CURSOR-装载光标          **/
	/**               IMAGE_ICON-装载图标            **/
	/** 4.指定图标或光标的宽度和长度 以像素为单位    **/
	/** 此参数为零并且值LR_DEFAULTSIZE没有被使用那么 **/
	/** 函数使用目前的资源宽度                       **/
	/**************************************************/
	
	if( m_bitmap.m_hObject )
	{
		m_bitmap.Detach();            //m_bitmap为创建的位图对象
	}
	m_bitmap.Attach(m_hBitmap);
	
	//边界
	CRect rect;
	GetClientRect(&rect);
	
	//图片显示(x,y)起始坐标
	int m_showX=0;
	int m_showY=0;
	
	int m_nWindowWidth = rect.right - rect.left;   //计算客户区宽度
	int m_nWindowHeight = rect.bottom - rect.top;  //计算客户区高度
	
	//通过显示图片长宽调整图片中心位置
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
	
	
	//定义并创建一个内存设备环境
	CDC dcBmp;
	if( !dcBmp.CreateCompatibleDC(pDC) )   //创建兼容性的DC
		return;
	
	BITMAP m_bmp;                          //临时bmp图片变量
	//MessageBox("图片正在导入!");
	m_bitmap.GetBitmap(&m_bmp);            //将图片载入位图中
	   //MFC afxwin1.inl 错误 GetBitmap中
	
	CBitmap *pbmpOld = NULL;
	dcBmp.SelectObject(&m_bitmap);         //将位图选入临时内存设备环境
	
	//图片显示调用函数BitBlt 
	//pDC->BitBlt(m_showX,m_showY,m_bmp.bmWidth,m_bmp.bmHeight,&dcBmp,0,0,SRCCOPY);    //m_showX m_showY 替代 0 0 
	if(m_nDrawWidth<650 && m_nDrawHeight<650)
		pDC->StretchBlt(0,0,m_nDrawWidth,m_nDrawHeight,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
	else
		pDC->StretchBlt(0,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //显示大小横为640*640
	
	//ShowWindowsInfo();
	
	/******************************************************/
	/** 参数x、y位图目标矩形左上角x、y的坐标值 居中      **/
	/** nWidth、nHeigth位图目标矩形的逻辑宽度和高度      **/
	/** pSrcDC表示源设备CDC指针                          **/
	/** xSrc、ySrc表示位图源矩形的左上角的x、y逻辑坐标值 **/
	/** dwRop表示显示位图的光栅操作方式                  **/
	/** SRCCOPY用于直接将位图复制到目标环境中            **/
	/******************************************************/
	
	dcBmp.SelectObject(pbmpOld);           //恢复临时DC的位图
	DeleteObject(&m_bitmap);               //删除位图
	dcBmp.DeleteDC();                      //删除后台DC
	
	//显示第2张图片
	if( numPicture == 2 )
	{
		//显示图片函数LoadImage
		HBITMAP m_hBitmapChange;
		if(level==0) //显示2张图
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else
		if(level==1) //灰度图片
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化2
		if(level==2)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else
		if(level==3) //图片采样
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化4
		if(level==4)  
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化8
		if(level==8)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化16
		if(level==16)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化32
		if(level==32)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //量化64
		if(level==64)
		{
			signZFT=0; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		//灰度直方图 
		else        //level=100 D(B)=D(A)*0.8 灰度减小
		if(level==100)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //level=101 D(B)=-1*D(A)+255 灰度求补
		if(level==101)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //灰度变化移动 D(B)=D(A)+50
		if(level=102)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //灰度变化增强 D(B)=1.5*D(A)
		if(level=103)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //灰度变化增强 D(B)=D(A)*D(A)/255 非线性变化
		if(level=104)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //灰度变化增强 D(B)=D(A)*D(A)/255 非线性变化
		if(level=105)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else        //灰度变化拉伸 非线性变化 黑白拉伸 阈值化
		if(level=106)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}

		else        //显示均衡化直方图和处理图像
		if(level=200)
		{
			signZFT=1; 
			flagZFT=0;
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //几何变换-灰度级插值：最近邻插值-图像拉伸
		if(level==300)
		{
			signZFT=0;      //不用考虑直方图
			flagZFT=0;
			flagSF=1;       //图像缩放显示像素时标记标量为1
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}
		else         //因为在调用 图像增强--平滑时总是报错:File:afxinl.inl Line:418
		if(level==400)
		{
			signZFT=0;      //不用考虑直方图
			flagZFT=0;
			flagSF=1;       //图像缩放显示像素时标记标量为1
			m_hBitmapChange = (HBITMAP) LoadImage(NULL,BmpNameLin,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);
		}

		if( m_bitmap.m_hObject )
		{
			m_bitmap.Detach();            //m_bitmap为创建的位图对象
		}
		m_bitmap.Attach(m_hBitmapChange);

		//定义并创建一个内存设备环境
		CDC dcBmp;
		if( !dcBmp.CreateCompatibleDC(pDC) )   //创建兼容性的DC
			return;
		
		BITMAP m_bmp;                          //临时bmp图片变量
		m_bitmap.GetBitmap(&m_bmp);            //将图片载入位图中
		
		CBitmap *pbmpOld = NULL;
		dcBmp.SelectObject(&m_bitmap);         //将位图选入临时内存设备环境

		//图片显示调用函数StretchBlt 
		if(flagSF==1)
		{
			CString str;
			str.Format("缩放长=%d 宽%d 原图长=%d 宽=%d",m_nDrawWidthSF,m_nDrawHeightSF,m_nWidth,m_nHeight);
			AfxMessageBox(str);
			flagSF=0;
			//m_nDrawWidthSF缩放此存见函数最近邻插值法中赋值
			if(m_nDrawWidthSF<650 && m_nDrawHeightSF<650)   
				pDC->StretchBlt(m_nWindowWidth-m_nDrawWidthSF,0,m_nDrawWidthSF,m_nDrawHeightSF,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
			else
				pDC->StretchBlt(m_nWindowWidth-640,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //显示大小为640*640
		}
		else
		{
			if(m_nDrawWidth<650 && m_nDrawHeight<650)
				pDC->StretchBlt(m_nWindowWidth-m_nDrawWidth,0,m_nDrawWidth,m_nDrawHeight,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);
			else
				pDC->StretchBlt(m_nWindowWidth-640,0,640,640,&dcBmp,0,0,m_bmp.bmWidth,m_bmp.bmHeight,SRCCOPY);  //显示大小为640*640
		}

		dcBmp.SelectObject(pbmpOld);           //恢复临时DC的位图
	}
}

bool CBmpDrawView::ShowJpgGif(CDC *pDC, CString strPath, int x, int y)
{
	return false;
}


//************ 使新建菜单不可用 *********//
void CBmpDrawView::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//************ 使"最近的文件"不可用 *********//
void CBmpDrawView::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//**************文件打开****************//
void CBmpDrawView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	//四种格式的文件：bmp gif jpg tiff
	CString filter;
	filter="所有文件(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter,NULL);          //产生打开对话框
	
	//按下确定按钮 dlg.DoModal() 函数显示对话框
	if( dlg.DoModal() == IDOK )
	{
		//获取路径 文件名 扩展文件名
		BmpName = dlg.GetPathName();
		BmpNameLin = "picture.bmp";
		//AfxMessageBox(BmpName);
		
		AfxMessageBox("图片打开成功",MB_OK,0);
		numPicture=1;

		/*CString中的Format进行字符串转换*/
		//BmpName.Format(_T("%s",str));  //重点：错误 会出现错误的路径
		
		EntName = dlg.GetFileExt(); 
		EntName.MakeLower();             //此成员函数将此CString对象转换为一个小写字符串
		
		Invalidate();
	}	
}


//******************文件保存*****************//
void CBmpDrawView::OnFileSave() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击保存 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能保存图片!",MB_OK,0);
		return;
	}

	CString filter;
	//filter=" BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	filter="所有文件(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";
	CFileDialog dlg(0,NULL,NULL,OFN_HIDEREADONLY,filter,NULL);          //产生打开对话框
	//1-文件打开 0-文件保存
	
	//按下确定按钮
	if( dlg.DoModal() == IDOK )
	{
		CString str;
		CString strName;
		CString filename;
		str = dlg.GetPathName();           //获取文件的路径
		filename = dlg.GetFileTitle();     //获取文件名
 		
		int nFilterIndex=dlg.m_ofn.nFilterIndex;
		if( nFilterIndex == 2 )            //当用户选择文件过滤器为".BMP"时
		{
			str = str + ".bmp";	           //自动加扩展名.bmp
			SaveBmp(str);                  //保存bmp图片 就是一个写出图片的过程 
			AfxMessageBox("图片保存成功",MB_OK,0);
		}
	}
}

//写入bmp格式图片 写入图片的过程
bool CBmpDrawView::ReadBmp()
{

	//图片读出存储其中的东西
	FILE *fp = fopen(BmpName,"rb");
	if(fp==0)
	{		
		AfxMessageBox("无法打开文件!",MB_OK,0);
		return 0; 
	}
		
	//读取文件头 全局变量bfh  BITMAPFILEHEADER 定义在ImageStruct中
	//fread(&bfh,sizeof(BITMAPFILEHEADER),1,fp);
	
	//解决BMP格式倒置的方法 见CSDN
	fread(&bfh.bfType,sizeof(WORD),1,fp);
	fread(&bfh.bfSize,sizeof(DWORD),1,fp);
	fread(&bfh.bfReserved1,sizeof(WORD),1,fp);
	fread(&bfh.bfReserved2,sizeof(WORD),1,fp);
	fread(&bfh.bfOffBits,sizeof(DWORD),1,fp);

	//图像文件的总字节数
	m_nSize = bfh.bfSize;

	//判断是否是bmp格式图片
	if(bfh.bfType!=0x4d42)   //'BM'
	{
		AfxMessageBox("不是BMP格式图片!",MB_OK,0);
		return 0;
	}

	//读取信息头
	//fread(&bih,sizeof(BITMAPINFOHEADER_),1,fp);

	//解决BMP格式倒置的方法 见CSDN
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
		AfxMessageBox("本结构所占用字节数出现错误");
		return 0;
	}

	//位图压缩类型，必须是 0（不压缩） 1（BI_RLE8压缩类型）或2（BI_RLE压缩类型）之一
	if(bih.biCompression == BI_RLE8 || bih.biCompression == BI_RLE4)
	{
		AfxMessageBox("位图被压缩!");
		return 0;
	}
	
	//获取图像高宽和每个像素所占位数
	m_nHeight = bih.biHeight;
	m_nWidth = bih.biWidth;
	m_nDrawHeight = bih.biHeight;
	m_nDrawWidth = bih.biWidth;
	m_nBitCount = bih.biBitCount;   //每个像素所占位数

	//计算图像每行像素所占的字节数（必须是32的倍数）
	m_nLineByte = (m_nWidth*m_nBitCount+31)/32*4;
	
	//图片大小 调用系统自带的文件头 BITMAPFILEHEADER bfh; BITMAPINFOHEADER bih; 
	//否则用 BITMAPFILEHEADER_ bfh; BITMAPINFOHEADER_ bih;要 m_nImage = m_nLineByte * m_nHeight - 2;
	m_nImage = m_nLineByte * m_nHeight;
	
	//位图实际使用的颜色表中的颜色数 biClrUsed
	m_nPalette = 0;                       //初始化
	if(bih.biClrUsed)
		m_nPalette = bih.biClrUsed;
	
	//申请位图空间 大小为位图大小 m_nImage
	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);
	fread(m_pImage,m_nImage,1,fp);

	fclose(fp);
	return true;
}


//保存bmp格式图片 写出图片的过程 只处理24像素的图片 该图片无调色板
bool CBmpDrawView::SaveBmp(LPCTSTR lpFileName)
{
	//lpFileName为位图文件名
	//AfxMessageBox(lpFileName);

	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(lpFileName,"wb");

	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);
	fread(m_pImage,m_nImage,1,fpo);
	fwrite(m_pImage,m_nImage,1,fpw);

	fclose(fpo);
	fclose(fpw);
	return true;
}

//显示窗口状态栏信息 文件路径 大小 长宽
void CBmpDrawView::ShowWindowInfo() 
{
	CString winInfo;
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//获得主框架窗口
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//获得状态栏指针
	
	if(pStatus)
	{ 
		winInfo.Format("宽×高 = %d×%d | 图像大小 = %d字节  | BitCount = %d",m_nWidth,m_nHeight,m_nSize,m_nBitCount);
		pStatus->SetPaneText(0,BmpName);
		pStatus->SetPaneText(1,winInfo);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

}

//显示窗口状态栏信息 鼠标位置
void CBmpDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		
	CString winInfo;
	CString winPoint;

	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//获得主框架窗口
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//获得状态栏对象

	if(pStatus)
	{
		winPoint.Format("X=%d,Y=%d",point.x,point.y);
		winInfo.Format("宽×高 = %d×%d 图像大小 = %d",m_nWidth,m_nHeight,m_nSize);
		pStatus->SetPaneText(2,winPoint);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

	CView::OnMouseMove(nFlags, point);
}

//显示2张图片
void CBmpDrawView::OnShowTwo() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击显示2张图片 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能显示2张图片!");
		return;
	}

	AfxMessageBox("显示两张图片!",MB_OK,0);
	numPicture = 2;
	level=0;
	Invalidate();
}


//量化 量化等级为 2
void CBmpDrawView::OnLh2() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=2!",MB_OK,0);
	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级2量化
	for( i=0; i<m_nImage; i++ )
	{
		//24位的为调色板为真彩图 Red Green Blue 为3字节 量化等级为2取中间值为 64 和 192
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

//量化 量化等级为 4
void CBmpDrawView::OnLh4() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=4!",MB_OK,0);
	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级4量化
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


//量化 量化等级为 8
void CBmpDrawView::OnLh8() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=8!",MB_OK,0);
	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级8量化
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

//量化 量化等级为 16
void CBmpDrawView::OnLh16() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=16!",MB_OK,0);
	int i,j;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级16量化
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

//量化 量化等级为 32
void CBmpDrawView::OnLh32() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=32!",MB_OK,0);
	int i,j;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级16量化
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

//量化 量化等级为 64
void CBmpDrawView::OnLh64() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击量化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能量化!",MB_OK,0);
		return;
	}

	AfxMessageBox("量化等级Level=64!",MB_OK,0);
	int i,j;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//malloc只能申请4字节的空间 （未知）
	m_pImage=(BYTE*)malloc(m_nImage);

	fread(m_pImage,m_nImage,1,fpo);

	//等级16量化
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
/* 祥见http://blog.csdn.net/xiakq/article/details/2956902有详细的灰度算法                   */
/* 其中24位的图片灰度时,采用如下算法:                                                       */
/* 1.平均值算法 R=G=B=(R+G+B)/3                                                             */ 
/* 2.快速算法 R=G=B=(R+G+B+128)/4>>2                                                        */  
/* 3.加权平均值算法 根据光的亮度特性,其实正确的灰度公式应当是R=G=B=R*0.299+G*0.587+B0.144   */
/*   为了提高速度我们做一个完全可以接受的近似，公式变形如下 R=G=B=(R*3+G*6+B)/10            */
/* 4.精确加权平均值算法 R=G=B=R*0.299+G*0.587+B0.144                                        */
/********************************************************************************************/

//灰度图像就是 R=G=B且为三者的1/3 level=1时灰度图像
void CBmpDrawView::OnShowHd() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击灰度 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能灰度图片!",MB_OK,0);
		return;
	}

	AfxMessageBox("灰度图像!",MB_OK,0);
	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
	unsigned char color;
	unsigned char red,green,blue;

	/********************************************************************/
	/* 注意：原来下面所有操作都是for( i=0; i<m_nWidth*m_nHeight; i++ )  */
	/* 后发现如果图片最后一行没有完整的一行数据，会出现图像变多或变少   */
	/* 但图像的总像素为m_nImage，如果是m_nImage/3就可以保证所有像素都有 */
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


//图片采样 淡出采样坐标采样
void CBmpDrawView::OnCy() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能采样!",MB_OK,0);
		return;
	}
	
	CTestCYDlg dlg;     //定义采样对话框
	
	//显示对话框
	if( dlg.DoModal()==IDOK )
	{
		//采样坐标最初为图片的自身像素
		if( dlg.m_xPlace==0 || dlg.m_yPlace==0 )
		{
			AfxMessageBox("输入图片像素不能为0!",MB_OK,0);
			return;
		}
		if( dlg.m_xPlace>m_nWidth || dlg.m_yPlace>m_nHeight )
		{
			AfxMessageBox("图片像素不能为超过原图长宽!",MB_OK,0);
			return;
		}

		AfxMessageBox("图片采样!",MB_OK,0);
		
		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);
	
		/*图片采样*/
		int numWidth,numHeight;     //图片此区间取相同的像素点
		int numSYWidth,numSYHeight; //剩余期间区域 

		/*********************************************************/
		/* 表示numWidth*numHeight为一个区域 该区域颜色相同       */
		/* 如 512/512=1 512/512=1 1*1为一个区域                  */
		/* dlg.m_xPlace*dlg.m_yPlace 表示新的（x,y）坐标         */
		/* numSYWidth表示剩余空间 该区域统一为一个颜色           */
		/*********************************************************/

		numWidth=m_nWidth/dlg.m_xPlace;        
		numHeight=m_nHeight/dlg.m_yPlace;      

		numSYWidth=m_nWidth%dlg.m_xPlace;     
		numSYHeight=m_nHeight%dlg.m_yPlace;   

		int Y,X;
		int i,j,m,n;
		unsigned char red,green,blue;  //存储三种颜色
		
		/*有（（m_xPlace * m_yPlace）+ 剩余区域 ）个小区域*/
		for( i=0; i<dlg.m_yPlace; i++ )       //高度
		{
			Y=numHeight*i;                    //获取Y坐标
			for( j=0; j<dlg.m_yPlace; j++ )   //宽度
			{
				X=numWidth*j;                 //获取X坐标
				
				/*获取填充颜色*/
				red=m_pImage[(X+Y*m_nWidth)*3];
				green=m_pImage[(X+Y*m_nWidth)*3+1];
				blue=m_pImage[(X+Y*m_nWidth)*3+2];
				
				/*填出图像循环 小区域中的长宽循环*/
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
/* 4种线性变化直方图：                                                */
/* ID_XXHD_YD:表示线性灰度变化移动,D(B)=D(A)+50,灰度值上移下移        */
/* ID_XXHD_ZQ:表示线性灰度变化增强,D(B)=1.5*D(A),图像对比度增强       */
/* ID_XXHD_JX:表示线性灰度变化减小,D(B)=0.8*D(A),图像对比度减小       */
/* ID_XXHD_QB:表示线性灰度求补,D(B)=-1*D(A)+255,图像暗区变亮,亮区变暗 */
/**********************************************************************/

/*全局变量在TestZFTDlg.cpp中引用 用extern BH(变化后的直方图数组)*/
int RedBH[256],GreenBH[256],BlueBH[256];


/*ID_XXHD_JX:表示线性灰度变化减小D(B)=0.8*D(A)*/
void CBmpDrawView::OnXxhdJx() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度减小 D(B)=0.8*D(A)!",MB_OK,0);

	int i;

	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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

		//记录变化后的灰度图，变化后的直方图显示

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


/*ID_XXHD_QB:表示线性灰度求补,D(B)=-1*D(A)+255*/
void CBmpDrawView::OnXxhdQb() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度求补 D(B)=-1*D(A)+255!",MB_OK,0);

	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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

/*ID_XXHD_YD:表示线性灰度变化移动,D(B)=D(A)+50*/
void CBmpDrawView::OnXxhdYd() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度变化移动 D(B)=D(A)+50!",MB_OK,0);

	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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

/*ID_XXHD_ZQ:表示线性灰度变化增强,D(B)=1.5*D(A)*/
void CBmpDrawView::OnXxhdZq() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度变化增强 D(B)=1.5*D(A)!",MB_OK,0);

	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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
/* 添加直方图显示功能，并在直方图下方显示相关信息 */
/* 如平均灰度、中值灰度、标准差和像素总数         */
/* ID_ZFT_YT:直方图原图显示                       */
/**************************************************/


/*全局变量在TestZFTDlg.cpp中引用 用extern*/
int Red[256],Green[256],Blue[256];

void CBmpDrawView::OnZftYt() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击原图直方图 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能显示原图直方图!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("显示原图直方图!",MB_OK,0);
	
	flagZFT=1;

	CTestZFTDlg dlg;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	int i,j;
	for(j=0;j<256;j++)   //定义数组并清零
	{
		Red[j]=0;
		Green[j]=0;
		Blue[j]=0;
	}
	
	//计算4个数据
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;               //强制转换
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //记录像素总的灰度值和
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
	
	//像素:int型转换为CString型 
	dlg.m_redXS.Format("%d",m_nImage);
	dlg.m_greenXS.Format("%d",m_nImage);
	dlg.m_blueXS.Format("%d",m_nImage);
	
	//平均灰度值:计算24位bmp图片的灰度值,我是记录RGB中的所有平均值	
	float pinRedHD,pinGreenHD,pinBlueHD; 
	pinRedHD=sumRedHD*3/m_nImage;
	pinGreenHD=sumGreenHD*3/m_nImage;     //平均灰度=总灰度/总像素
	pinBlueHD=sumBlueHD*3/m_nImage;
	
	dlg.m_redPJHD.Format("%.2f",pinRedHD);
	dlg.m_greenPJHD.Format("%.2f",pinGreenHD);
	dlg.m_bluePJHD.Format("%.2f",pinBlueHD);
	
	/****************************************************************/
	/* 中值灰度:算法重点(黄凯大神提供)                              */
	/* 中值灰度:所有像素中的中位数,应该所有像素排序找到中间的灰度值 */
	/* 算法:num[256]记录各灰度出现次数,sum+=num[i],找到sum=总像素/2 */
	/****************************************************************/
	int sumRedZZHD=0,sumGreenZZHD=0,sumBlueZZHD=0;
	int redZZHD,greenZZHD,blueZZHD;
	for(i=0;i<256;i++)
	{
		sumRedZZHD=sumRedZZHD+Red[i];
		if(sumRedZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			redZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumGreenZZHD=sumGreenZZHD+Green[i];
		if(sumGreenZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			greenZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumBlueZZHD=sumBlueZZHD+Blue[i];
		if(sumBlueZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			blueZZHD=i;
			break;
		}
	}
	
	dlg.m_redZZHD.Format("%d",redZZHD);
	dlg.m_greenZZHD.Format("%d",greenZZHD);
	dlg.m_blueZZHD.Format("%d",blueZZHD);
	
	/******************************************************************/
	/*标准差:标准差=方差的算术平方根                                  */ 
	/*       方差s^2=[(x1-x)^2+(x2-x)^2+......(xn-x)^2]/n             */
	/* 算法:不用开m_nImage数组进行计算 用num[256]中数进行             */
	/* 方差=(平均灰度-i)*(平均灰度-i)*Red[i]  有Red[i]个灰度值为i的数 */
	/******************************************************************/
	float redBZC,greenBZC,blueBZC;       //标准差
	float LinRed,LinGreen,LinBlue;
	double redFC=0,greenFC=0,blueFC=0;    //方差
	for(i=0;i<256;i++)
	{
		redFC=redFC+(pinRedHD-i)*(pinRedHD-i)*Red[i];   //有Red[i]个像素i
		greenFC=greenFC+(pinGreenHD-i)*(pinGreenHD-i)*Green[i];
		blueFC=blueFC+(pinBlueHD-i)*(pinBlueHD-i)*Blue[i];
	}
	
	redBZC=sqrt(redFC*3/m_nImage);
	greenBZC=sqrt(greenFC*3/m_nImage);
	blueBZC=sqrt(blueFC*3/m_nImage);
	
	dlg.m_redBZC.Format("%.2lf",redBZC);
	dlg.m_greenBZC.Format("%.2lf",greenBZC);
	dlg.m_blueBZC.Format("%.2lf",blueBZC);
	

	//重点必须添加该语句才能弹出对话框
	if(dlg.DoModal()==IDOK)
	{

	}
}


/************************************************************************/
/* 4种非线性变化直方图：                                                */
/* ID_FXXHD_PF:表示非线性平方灰度变化,D(B)=D(A)*D(A)/255                */
/* ID_FXXHD_HS:表示非线性函数灰度变化,D(B)=D(A)+0.8*D(A)*(255-D(A))/255 */
/* ID_FXXHD_LS:表示非线性灰度对比度拉伸变化                             */
/************************************************************************/


/*ID_FXXHD_PF:表示非线性平方灰度变化,D(B)=D(A)*D(A)/252*/
void CBmpDrawView::OnFxxhdPf() 
{
	// TODO: Add your command handler code here
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能非线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("非线性灰度变化 D(B)=D(A)*D(A)/255!",MB_OK,0);

	int i;
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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


/*ID_FXXHD_HS:表示非线性函数灰度变化,D(B)=D(A)+0.8*D(A)*(255-D(A))/255*/
void CBmpDrawView::OnFxxhdHs() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能非线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度变化增强 D(B)=D(A)+0.8*D(A)*(255-D(A))/255!",MB_OK,0);

	int i;
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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
/* ID_FXXHD_LS:表示非线性灰度对比度拉伸变化                   */
/* 此处的拉伸是：阈值化(thresholding)可以看作是削波的一个特例 */
/* 只要令削波中的g1old=g2old就实现了阈值化。                  */
/* 阈值就象个门槛，比它大就是白，比它小就是黑,二值            */
/**************************************************************/

void CBmpDrawView::OnFxxhdLs() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能非线性灰度直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("线性灰度直方图-灰度变化增强 D(B)=D(A)+0.8*D(A)*(255-D(A))/255!",MB_OK,0);

	int i;
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//灰度图像
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


/*ID_FXXHD_JHH:表示图像均衡化 相见算法*/
void CBmpDrawView::OnFxxhdJhh() 
{
	// TODO: Add your command handler code here
	
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像均衡化!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像均衡化!",MB_OK,0);

    //第一步:获取图像的数据信息，此操作可以在打开图片时就进行，在直方图采样(ZFTCY)中也有该代码，杂糅代码
	FILE *fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	int i,j;
	for(j=0;j<256;j++)   //定义数组并清零
	{
		Red[j]=0;
		RedBH[j]=0;
		Green[j]=0;
		GreenBH[j]=0;
		Blue[j]=0;
		BlueBH[j]=0;
	}
	
	//计算4个数据
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;                  //强制转换
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //记录像素总的灰度值和
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
	/* 图像均衡化处理                                                */
	/* 利用全局变量 Red[256] Blue[256] Green[256]                    */
	/* 第一步:用3个数组Count..记录0-255灰度出现的概率，即            */
	/*        概率=该灰度出现次数*3/总得像素 (因为分成3部分RGB)      */
	/* 第二步:i从1开始，令s[i]=s[i]+s[i-1] 记录新概率数              */
	/* 第三步:用一个数组L记录新的调色板索引值，即                    */
	/*        L[i]=s[i]×(256-1)结果四舍五入2.8即为3                 */
	/* 第四步:将老的索引值对应的概率合并，作为对应的新的索引值的概率 */
	/*   1.原来的索引值0,1都对应了新的索引值0，则灰度索引值为0的概率 */
	/*     为P0+P1=0.03                                              */
	/*   2.新的索引值3和7找不到老的索引值与之对应，所以令Q3和Q7为0   */
	/*****************************************************************/

	float CountRed[256],CountGreen[256],CountBlue[256];            //记录出现的概率,会加到1 用于相加到调色板
	float CountRedLin[256],CountGreenLin[256],CountBlueLin[256];   //记录原始数据,不会相加到1 用于计算新灰度概率
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
	/* 此处百度到一个四舍五入浮点型的算法:              */
	/* float a=3.456;   保留到小数点后两位              */
	/* float b=(int)((a * 100) + 0.5) / 100.0;          */
	/* output b=3.46                                    */
	/****************************************************/

	int LRed[256],LGreen[256],LBlue[256];                    //记录调色板
	for( k=0 ; k<256 ; k++ )
	{
		LRed[k]=(int)(CountRed[k]*(256-1)+0.5);
		LGreen[k]=(int)(CountGreen[k]*(256-1)+0.5);
		LBlue[k]=(int)(CountBlue[k]*(256-1)+0.5);
	}


	//第三步:处理均衡化图像写入 打开临时的图片
	fpo = fopen(BmpName,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	FILE *fpw = fopen(BmpNameLin,"wb+");
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	//m_nWidth*m_nHeight 读取图片最后一行不为m_nWidth时会报错
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
	
	//存储均衡化后的直方图操作
	for( k=0 ; k<256 ; k++ )
	{
		for(int n=k+1 ; n<256 ; n++ )
		{
			if(LRed[k]==LRed[n])                   //新灰度相同，老灰度的概率合并
				CountRedLin[k]+=CountRedLin[n];
			else break;                            //LRed肯定是递增序列，只要不相同就可以执行下一个灰度
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

		//录入RedBH(变换)数据
		RedBH[k]=(int)(CountRedLin[k]*m_nImage/3);
		GreenBH[k]=(int)(CountGreenLin[k]*m_nImage/3);
		BlueBH[k]=(int)(CountBlueLin[k]*m_nImage/3);
	}

	
	numPicture = 2;
	level=200;
	Invalidate();	
}




/**************************************************/
/* 添加图片线性或非线性变化直方图显示功能         */
/*                                                */
/* ID_ZFT_BH:变化后的直方图                       */
/**************************************************/

void CBmpDrawView::OnZftBh() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击原图直方图 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能显示原图直方图!",MB_OK,0);
		return;
	}
	
	//如果没有导入图片直接点击原图直方图 提示信息
	if(signZFT==0)
	{
		AfxMessageBox("图片线性变化或非线性变化后才能显示变化直方图!",MB_OK,0);
		return;
	}

	AfxMessageBox("显示线性变化或非线性变化后的直方图!",MB_OK,0);
	
	CTestZFTDlg dlg;
	
	FILE *fpo = fopen(BmpNameLin,"rb");
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	for(int j=0;j<256;j++)   //定义数组并清零
	{
		RedBH[j]=0;
		GreenBH[j]=0;
		BlueBH[j]=0;
	}
	
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;               //强制转换
	double sumRedHD=0,sumGreenHD=0,sumBlueHD=0;   //记录像素总的灰度值和
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

	//像素:int型转换为CString型 
	dlg.m_redXS.Format("%d",m_nImage);
	dlg.m_greenXS.Format("%d",m_nImage);
	dlg.m_blueXS.Format("%d",m_nImage);
	
	//平均灰度值:计算24位bmp图片的灰度值,我是记录RGB中的所有平均值	
	float pinRedHD,pinGreenHD,pinBlueHD; 
	pinRedHD=sumRedHD*3/m_nImage;
	pinGreenHD=sumGreenHD*3/m_nImage;     //平均灰度=总灰度/总像素
	pinBlueHD=sumBlueHD*3/m_nImage;
	
	dlg.m_redPJHD.Format("%.2f",pinRedHD);
	dlg.m_greenPJHD.Format("%.2f",pinGreenHD);
	dlg.m_bluePJHD.Format("%.2f",pinBlueHD);
	
	/****************************************************************/
	/* 中值灰度:算法重点(黄凯大神提供)                              */
	/* 中值灰度:所有像素中的中位数,应该所有像素排序找到中间的灰度值 */
	/* 算法:num[256]记录各灰度出现次数,sum+=num[i],找到sum=总像素/2 */
	/****************************************************************/

	int sumRedZZHD=0,sumGreenZZHD=0,sumBlueZZHD=0;
	int redZZHD,greenZZHD,blueZZHD;
	for(i=0;i<256;i++)
	{
		sumRedZZHD=sumRedZZHD+RedBH[i];
		if(sumRedZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			redZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumGreenZZHD=sumGreenZZHD+GreenBH[i];
		if(sumGreenZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			greenZZHD=i;
			break;
		}
	}
	for(i=0;i<256;i++)
	{
		sumBlueZZHD=sumBlueZZHD+BlueBH[i];
		if(sumBlueZZHD>=m_nImage/6)          //m_nImage被分成3份RGB并且sum=总像素/2
		{
			blueZZHD=i;
			break;
		}
	}
	
	dlg.m_redZZHD.Format("%d",redZZHD);
	dlg.m_greenZZHD.Format("%d",greenZZHD);
	dlg.m_blueZZHD.Format("%d",blueZZHD);
	
	/******************************************************************/
	/*标准差:标准差=方差的算术平方根                                  */ 
	/*       方差s^2=[(x1-x)^2+(x2-x)^2+......(xn-x)^2]/n             */
	/* 算法:不用开m_nImage数组进行计算 用num[256]中数进行             */
	/* 方差=(平均灰度-i)*(平均灰度-i)*Red[i]  有Red[i]个灰度值为i的数 */
	/******************************************************************/
	float redBZC,greenBZC,blueBZC;       //标准差
	float LinRed,LinGreen,LinBlue;
	double redFC=0,greenFC=0,blueFC=0;    //方差
	for(i=0;i<256;i++)
	{
		redFC=redFC+(pinRedHD-i)*(pinRedHD-i)*RedBH[i];   //有Red[i]个像素i
		greenFC=greenFC+(pinGreenHD-i)*(pinGreenHD-i)*GreenBH[i];
		blueFC=blueFC+(pinBlueHD-i)*(pinBlueHD-i)*BlueBH[i];
	}
	
	redBZC=sqrt(redFC*3/m_nImage);
	greenBZC=sqrt(greenFC*3/m_nImage);
	blueBZC=sqrt(blueFC*3/m_nImage);
	
	dlg.m_redBZC.Format("%.2lf",redBZC);
	dlg.m_greenBZC.Format("%.2lf",greenBZC);
	dlg.m_blueBZC.Format("%.2lf",blueBZC);
	

	//重点必须添加该语句才能弹出对话框
	if(dlg.DoModal()==IDOK)
	{

	}
}


//为了方便缩放只在0%-200%之间，但算法更重要

/*******************************************************************/
/* ID_JHYS_SXXCZ: 几何运算-灰度级插值-双线性插值算法               */
/* 它的核心思想是:                                                 */
/* 1.缩放倍数为a,则绘制一个新的缩放图像：(长*a)*(宽*a)             */
/* 2.新图像在源图像的位置=新坐标/缩放倍数a 它为double型            */
/* 3.如为4.4:表示它相邻的周围四个点为:A B C D,图像为四点灰度值相关 */
/* 4.它的灰度为:(1-fx)*(1-fy)*A+(1-fx)*fy*C+fx*(1-fy)*B+fx*fy*D    */
/*******************************************************************/

/*******************************************************************/
/* 图像为:                                                         */
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

//该点的像素受到4个点的约束,所以叫双线性灰度插值算法
//1-fx表示它距离A点的距离,当fx越大,表示它距A越远,受到的影响越小,故用(1-fx)*A点的灰度表示x方向

void CBmpDrawView::OnJhysSxxcz() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能几何缩放图像!",MB_OK,0);
		return;
	}
	
	CTestHDCZFDlg dlg;     //定义采样对话框
	if( dlg.DoModal()==IDOK )
	{
		//采样坐标最初为图片的自身像素  m_sfbs(缩放倍数)
		if( dlg.m_sfbs==0 )
		{
			AfxMessageBox("输入图片缩放倍数不能为0!",MB_OK,0);
			return;
		}

		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

		/*先求缩放后的长宽*/
		int sfWidth,sfHeight;                            //缩放后的长宽
		int sfSize;                                      //缩放后的图像大小
		sfWidth=(int)(m_nWidth*(dlg.m_sfbs*1.0)/100);    //24位图像RGB必须是3的倍数 循环中读取时为R G B
		sfHeight=(int)(m_nHeight*(dlg.m_sfbs*1.0)/100);
		int number;                                      //记录每行多余的图像素数个数

		//重点:图像的每行像素都必须是4的倍数：1*1的图像为 r g b 00H 
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
		//注意:假如最后一行像素不足,我默认处理为完整的一行,不足补00H
		//总之处理后的图像总是m*n且为4倍数,每行都完整存在

		/*更改文件头信息 定义临时文件头结构变量*/
		BITMAPFILEHEADER bfhsf;
		BITMAPINFOHEADER bihsf;                //缩放(sf)
		bfhsf=bfh;
		bihsf=bih;

		bfhsf.bfSize=sfSize+54;		
		bihsf.biWidth=sfWidth;
		bihsf.biHeight=sfHeight;

		//显示部分m_nDrawWidth<650显示原图,否则显示
		flagSF=1;                         //图像缩放为1标识变量
		m_nDrawWidthSF=sfWidth;
		m_nDrawHeightSF=sfHeight;

		fwrite(&bfhsf,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bihsf,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);	
		
		unsigned char red,green,blue;
		unsigned char other=0;                       //补码00H='\0'
		int placeX;                                  //记录在原图中的第几行的位置
		int placeY;									 //记录在原图中的位置(x,y)
		int placeBH;                                 //记录变换后在变换图中的位置

		/*new和delete有效的进行动态内存的分配和释放*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[sfSize]; 

		/*读取文件像素信息 (1-fx)*(1-fy)*A+(1-fx)*fy*C+fx*(1-fy)*B+fx*fy*D */
		for(int i=0; i<sfHeight ; i++ )                  //行
		{
			placeX=(int)(i/(dlg.m_sfbs*1.0/100)+0.5)*bih.biWidth*3;
			for(int j=0; j<sfWidth ; j++ )               //列
			{
				red=green=blue=0;

				placeY=placeX+(int)(j/(dlg.m_sfbs*1.0/100)+0.5)*3;    //放大倍数为(dlg.m_sfbs*1.0/100)
			
				//重点是:number*i补充00H,如果是numer图像会被切成2块
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
/* ID_JHYS_ZJLCZ: 几何运算-灰度级插值-最近邻插值算法               */
/* 算法思想:输出图像的灰度等于离它所映射位置最近的输入图像的灰度值 */
/* 先计算出放大缩小后的长宽，根据它计算找原图中的点灰度，四舍五入  */
/*******************************************************************/

void CBmpDrawView::OnJhysZjlcz() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击采样 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能几何缩放图像!",MB_OK,0);
		return;
	}

	CTestHDCZFDlg dlg;           //定义对话框 (灰度插值法)
	if( dlg.DoModal()==IDOK )
	{
		//采样坐标最初为图片的自身像素  m_sfbs(缩放倍数)
		if( dlg.m_sfbs==0 )
		{
			AfxMessageBox("输入图片缩放倍数不能为0!",MB_OK,0);
			return;
		}
		
		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		/*先求缩放后的长宽*/
		int sfWidth,sfHeight;                            //缩放后的长宽
		int sfSize;                                      //缩放后的图像大小
		sfWidth=(int)(m_nWidth*(dlg.m_sfbs*1.0)/100);    //24位图像RGB必须是3的倍数 循环中读取时为R G B
		sfHeight=(int)(m_nHeight*(dlg.m_sfbs*1.0)/100);
		int number;                                      //记录每行多余的图像素数个数

		//重点:图像的每行像素都必须是4的倍数：1*1的图像为 r g b 00H 
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
		//注意:假如最后一行像素不足,我默认处理为完整的一行,不足补00H
		//总之处理后的图像总是m*n且为4倍数,每行都完整存在

//		CString str;
//		str.Format("变换后:宽=%d 长=%d sfSize=%d",sfWidth,sfHeight,sfSize);
//		AfxMessageBox(str);
	
		/*更改文件头信息 定义临时文件头结构变量*/
		BITMAPFILEHEADER bfhsf;
		BITMAPINFOHEADER bihsf;                //缩放(sf)
		bfhsf=bfh;
		bihsf=bih;

		bfhsf.bfSize=sfSize+54;		
		bihsf.biWidth=sfWidth;
		bihsf.biHeight=sfHeight;

		//显示部分m_nDrawWidth<650显示原图,否则显示
		flagSF=1;                         //图像缩放为1标识变量
		m_nDrawWidthSF=sfWidth;
		m_nDrawHeightSF=sfHeight;

		fwrite(&bfhsf,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bihsf,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);	
		
		unsigned char red,green,blue;
		unsigned char other=0;                       //补码00H='\0'
		int placeX;                                  //记录在原图中的第几行的位置
		int placeY;									 //记录在原图中的位置(x,y)
		int placeBH;                                 //记录变换后在变换图中的位置

		/*new和delete有效的进行动态内存的分配和释放*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[sfSize]; 

		/*读取文件像素信息 缩放注意:1.找最近灰度 2.四舍五入法(算法+0.5)*/
		for(int i=0; i<sfHeight ; i++ )                  //行
		{
			placeX=(int)(i/(dlg.m_sfbs*1.0/100)+0.5)*bih.biWidth*3;
			for(int j=0; j<sfWidth ; j++ )               //列
			{
				red=green=blue=0;

				placeY=placeX+(int)(j/(dlg.m_sfbs*1.0/100)+0.5)*3;    //放大倍数为(dlg.m_sfbs*1.0/100)
			
				//重点是:number*i补充00H,如果是numer图像会被切成2块
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
/* 图像空间几何变换：图像平移 ID_JHBH_PY(几何变换-平移) */
/* 使用采样的对话框：CTestCYDlg dlg                     */
/* 算法：f(x,y)=f(x+x0,y+y0)图像所有点平移，空的补黑'0' */
/* 注意该图像平移方法只是从左上角(0,0)处开始平移        */
/* 其他方向原理相同，自己去弄                           */
/********************************************************/

void CBmpDrawView::OnJhbhPy() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击空间平移 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能空间平移!",MB_OK,0);
		return;
	}
	
	CTestCYDlg dlg;     //定义采样对话框也是用来空间变换平移的坐标
	
	//显示对话框
	if( dlg.DoModal()==IDOK )
	{
		//采样坐标最初为图片的自身像素
		if( dlg.m_xPlace>m_nWidth || dlg.m_yPlace>m_nHeight )
		{
			AfxMessageBox("图片平移不能为超过原图长宽!",MB_OK,0);
			return;
		}

		AfxMessageBox("图片空间变换-平移!",MB_OK,0);
		
		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");

		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

		fread(m_pImage,m_nImage,1,fpo);

		/************************************************************/
		/* 图片空间变换-平移                                        */
		/* 坐标(dlg.m_xPlace,dlg.m_yPlace)表示图像平移的坐标        */
		/* 先用Plave计算出平移后的起始坐标，其他的坐标赋值为'0'黑色 */
		/* 然后依次平移坐标，空的赋为黑色，否则填充                 */
		/************************************************************/
		
		/******************************************************************/
		/* 严重错误1：数组变量赋值相等                                    */
		/* 在View.h中定义变量 BYTE *m_pImage 读入图片数据后的指针         */
		/* 建立临时变量数组,让它平移变换 unsigned char *ImageSize         */
		/* ImageSize=m_pImage(错误)                                       */
		/* 会导致ImageSize赋值变换时m_pImage也产生了变换,所以输出全为黑色 */
		/*     因为它俩指向了相同的数组地址                               */
		/* 解决方法：使用下面C++的new方法动态分配或for循环i=m_nImage赋值  */
		/******************************************************************/

		/*临时变量存储的像素与m_pImage相同，便于处理图像*/
		unsigned char *ImageSize;      
	    ImageSize=new unsigned char[m_nImage];    //new和delete有效的进行动态内存的分配和释放

		int Place;                    //建立临时坐标，记录起始坐标(0,0)平移过来的位置
		int m_pImagePlace;            //原始图像平移为(0,0)，图像把它平移到Place位置
		unsigned char black;          //填充黑色='0' 
		int flag;                     //标记变量，当flag=1时表示图像已经有图像平移而不是填充黑色

		/************************************************************/
		/* for(int i=0 ; i<m_nHeight ; i++ )                        */
		/* for(int j=0 ; j<m_nWidth ; j++ )                         */
		/* 不能使用的上面的因为可能图像的最后一行没有完整的一行像素 */
		/* 这样会出现exe报错,使用m_nImage读写所有像素比较正确       */
		/************************************************************/

		Place=dlg.m_yPlace*m_nWidth*3; //前m_yPlace行都要填充为黑色          
		black=0;                       //颜色为黑色
		m_pImagePlace=0;               //图像处事位置为(0,0),把该点像素平移过去 
		int countWidth=0;              //记录每行的像素个数,满行时变回0
		int number=0;                  //数字记录使用的像素行数,平移时使用

		for(int i=0 ; i<m_nImage ; i++ )
		{
			/*如果每行的像素填满时清为0*/
			if(countWidth==m_nWidth*3)
			{
				countWidth=0;
			}
			
			/*第一部分：到平移后像素位置前面的所有像素点赋值为黑色*/
			if(i<Place)
			{
				ImageSize[i]=black;     //赋值为黑色
				continue;
			}
			
			/*第二部分：平移区域的左边部分赋值为黑色*/
			else if(i>=Place && countWidth<dlg.m_xPlace*3)     //RGB乘3
			{
				ImageSize[i]=black;     //赋值为黑色
				countWidth++;
				continue;
			}
	
			/****************************/
			/* 各部分如图所示:          */
			/* 000000000000000000000000 */
			/* 000000000000000000000000 */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 点表示像素部分,0为黑色   */
			/****************************/

			/* 重点错误提示：由于bmp图像显示是从左下角开始存储(0,0)点所以输出图像为 */
			/* bmp图像是从左下角到右上角排列的 */

			/****************************/
			/* 各部分如图所示:          */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 0000000................. */
			/* 000000000000000000000000 */
			/* 000000000000000000000000 */
			/* 点表示像素部分,0为黑色   */
			/****************************/
		
			/*第三部分：图像像素平移区域*/
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
		level=3;                  //让level调用采样对话框和它的绘图函数即可,不需要在赋新值
		Invalidate();
	}
}


/*图像反转：自己对这个功能比较感兴趣,做个图像反转*/
void CBmpDrawView::OnJhbhFz() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击空间反转 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能空间反转!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("图片空间变换-反转图像!",MB_OK,0);

	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);
	
	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];    
	int countWidth=0;        //记录每行的像素个数,满行时变回0
	int Place;               //记录图像每行的位置,便于图像反转
	int number=0;            //数字记录使用的像素行数
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
	level=3;                  //图片采样使用,不需要在申请新的level         
	Invalidate();
}


/********************************************************/
/* 几何变换：图片给旋转                                 */
/* 先添加对话框:IDD_XZ_DS(旋转度数),创建新类CTestXZDlg  */
/* 创建输入度数的:m_xzds Member variables 为int 0-360间 */
/********************************************************/

void CBmpDrawView::OnJhbhXz() 
{
	// TODO: Add your command handler code here
	
		
	//如果没有导入图片直接点击空间旋转 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能空间旋转!",MB_OK,0);
		return;
	}
	
	
	//定义对话框并调用对话框
	CTestXZDlg dlg;    
	
	//显示对话框
	if( dlg.DoModal()==IDOK )
	{
		AfxMessageBox("图片空间变换-旋转图像!",MB_OK,0);
		
		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");


		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
		
		fread(m_pImage,m_nImage,1,fpo);
		
		/*new和delete有效的进行动态内存的分配和释放*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[m_nImage];    
		int Place;               //记录图像每行的位置,便于图像旋转


		/*定义PA=3.14时使用的方法是arcsin(1.0/2)*6即为π*/
		double PA;
		PA=asin(0.5)*6;
		
		/*把输入的0-360的正整数度数转换为角度,30度=π/6*/
		double degree; 
		degree=PA*dlg.m_xzds/180;   //调用dlg.m_xzds(旋转度数)
		
		//对应的二维矩阵,注意图像矩阵从左下角开始处理,它最终要转换成一维存储
		int X,Y;               //图像变换前通过一维矩阵转换为二维
		int XPlace,YPlace;

		//输出转换为的角度
		CString str;
		str.Format("转换后的角度=%f",degree);
		AfxMessageBox(str);


		//图像旋转处理
		for(int i=0 ; i<m_nImage ; i++ )
		{
			//原图：一维矩阵转换为二维矩阵
			X=(i/3)%m_nWidth;
			Y=(i/3)/m_nWidth;
			//注意错误：X=i/m_nHeight; Y=i%m_nWidth; 只输出最后1/3

			//图像旋转为：a(x,y)=x*cos-y*sin b(x,y)=x*sin+y*cos
			XPlace=(int)(X*cos(degree)-Y*sin(degree));
			YPlace=(int)(X*sin(degree)+Y*cos(degree));
			
			//XPlace=X;         //显示原图像测试使用
			//YPlace=Y;
			

			//在转换为一维图想输出
			if( (XPlace>=0 && XPlace<=m_nWidth) && (YPlace>=0 && YPlace<=m_nHeight) )
			{
				Place=YPlace*m_nWidth*3+XPlace*3;

				//在图像范围内赋值为该像素
				if(Place+2<m_nImage) 
				{
					ImageSize[i]=m_pImage[Place];
					i++;
					ImageSize[i]=m_pImage[Place+1];
					i++;
					ImageSize[i]=m_pImage[Place+2];
				}

				//否则赋值为黑色
				else 
				{
					ImageSize[i]=0; 
					i++;
					ImageSize[i]=0;
					i++;
					ImageSize[i]=0;
				}
			}

			//否则赋值为黑色
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
		level=3;                  //图片采样使用,不需要在申请新的level         
		Invalidate();

	}
}


/**************************************************/
/* 第九章--图像增强                               */
/* Menu中：ID_TXZQ_PH (平滑) ID_TXZQ_RH (锐化)    */
/* Dialog中：创建对话框 ID_TXZQ_MB (图像增强模板) */
/**************************************************/

/********************************************************/
/* 重点：Dialog添加下拉列的用法                         */
/*  1.其中在对话框中创建一个组合框(下拉) IDC_TXZQ_PH    */
/*  2.使用它添加下拉表时,ctrl+回车换行,添加四个模块     */
/*  3.Ctrl+W建立类导向：创建该对话框的类 CTestTXZQPHDlg */
/*  4.Member Variable 为IDC_TXZQ_PH添加一个Control类型  */
/*  5.该类型可以使用按键函数,如查找当前选中第几个模板   */
/********************************************************/


/*图像增强--平滑*/
void CBmpDrawView::OnTxzqPh() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击图像增强(平滑) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(平滑)!",MB_OK,0);
		return;
	}


	//调用模块对话框
	CTestTXZQPHDlg dlg;
	

	//显示对话框
	if(dlg.DoModal()==IDOK)
	{
		/******************************************************************/
		/* 图想平滑的算法：                                               */
		/*   1.定义常用的四个模板,它们的维数均为3,矩阵的个数均为9个数据   */
		/*   2.它的思想是把一个点分散到这周围的9个点上,这样使图像更模糊   */
		/*   3.通过卷积计算围绕该点的矩阵像素和,计算其平均值(除9)赋值给点 */
		/*   4.模块不同,处理后的图像也各不相同                            */
		/******************************************************************/


		/*第一步：先定义数据模板*/

		int HWS=3;                                //模板维数:此四个模板均为3维的

		float H1[3][3]={{1.0/10,1.0/10,1.0/10}, //模板一:系数1/10
						{1.0/10,2.0/10,1.0/10},
						{1.0/10,1.0/10,1.0/10}};
		
		float H2[3][3]={{1.0/16,2.0/16,1.0/16}, //模板二:系数1/16
						{2.0/16,4.0/16,2.0/16},
						{1.0/16,2.0/16,1.0/16}};

		float H3[3][3]={{1.0/8,1.0/8,1.0/8},    //模板三:系数1/8,此种情况为把点转为空心矩形
						{1.0/8,0.0/8,1.0/8},
						{1.0/8,1.0/8,1.0/8}};

		float H4[3][3]={{0.0,1.0/8,0.0},        //模板四:系数乘数据后的矩阵
						{1.0/8,1.0/2,1.0/8},
						{0.0,1.0/8,0.0}};


		//打开临时的图片
		FILE *fpo = fopen(BmpName,"rb");
		FILE *fpw = fopen(BmpNameLin,"wb+");
		
		AfxMessageBox("bbbbb!",MB_OK,0);

		//读取文件
		fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
		fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
		
		fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
		fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
		
		fread(m_pImage,m_nImage,1,fpo);
		

		//获取模板对应的序号:(第0个位模板一)
		
		//int Index=dlg.m_txzq_ph.GetCurSel();
		
		/**********************************************************************/
		/* afxwin2.inl 错误 Line:711                                          */
		/* For information on how your program can cause an assertion failure */
		/* see the Visual C++ documentation asserts.                          */
		/**********************************************************************/

		/**********************************************************************/
		/* 详解原因:但不会此种解决方法                                        */
		/* if(aboutDlg.DoModal()==IDOK)                                       */
		/* if(aboutDlg.m_combo.GetCurSel()!=CB_ERR)时就会报错                 */
		/* Dlg.DoModal()函数返回以后,窗口就已经关闭,窗口上的控件就已经释放了  */
		/* 当然无法得到当前选择的项,重载OnOk来得到当前选择的项                */
		/* 最好重载Dlg的OnOk函数,就是IDOK的Command消息,在里面提取选定的内容   */
		/**********************************************************************/

		/**********************************************************/
		/* 重点知识:解决方法                                      */
		/* 1.先Ctrl+W建立Dlg对话框的OnOK()函数                    */
		/* 2.在TestTXZQPHDlg.cpp中OnOK函数前定义全局变量Index     */
		/*		注意：必须是全局变量,否则会出现函数定义类型不一致 */
		/* 3.在该函数中使用extern int Index获取子函数中的值(经典) */
		/**********************************************************/

		//可能它影响了File:afxinl.inl Line:418错误
		extern int Index;

		AfxMessageBox("cccccc!",MB_OK,0);

		CString str;
		str.Format("图像增强(平滑)!选取的模板为:%d",Index+1);
		AfxMessageBox(str);

		
		/*new和delete有效的进行动态内存的分配和释放*/
		unsigned char *ImageSize;      
		ImageSize=new unsigned char[m_nImage];     //使用new时,第一次能成功输出,后面就会崩
		float red,green,blue;
		
		int X,Y;       //一维坐标转换为二维坐标
		int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
		//图像增强:平滑
		for(int i=0; i<m_nImage ; i=i+3 )
		{
			//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
			
			//原图：一维矩阵转换为二维矩阵
			X=(i/3)%m_nWidth;    //图像在X列
			Y=(i/3)/m_nWidth;    //图像在Y行
			
			//赋值为黑色,相当于清零
			red=green=blue=0;

			//对图像进行像素求和并取平均值 HWS维数
			for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
			{
				for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
				{
					if( j>=0 && k>=0 && k<m_nWidth && j<m_nHeight )
					{			
						//模板一
						//进行模板平均,把该点像素分散到四周
						if(Index==0)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H1[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						
						//模板二
						else if(Index==1)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H2[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						//模板三
						else if(Index==2)
						{
							TR=j*m_nWidth*3+k*3;	
							red+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TR]);
							TG=j*m_nWidth*3+k*3+1;
							green+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TG]);
							TB=j*m_nWidth*3+k*3+2;
							blue+=H3[(j-Y+HWS/2)][(k-X+HWS/2)]*(float)(m_pImage[TB]);
						}
						//模板四
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
			
			//对新图像赋值
			ImageSize[i]=(unsigned char)(red);
			ImageSize[i+1]=(unsigned char)(green);
			ImageSize[i+2]=(unsigned char)(blue);
		
		}
		
		fwrite(ImageSize,m_nImage,1,fpw);  
		
		fclose(fpo);
		fclose(fpw);
		

		/******************************************************/
		/* 写成如下情况会报错                                 */
		/* File:afxinl.inl Line:418                           */
		/* 估计是该图片已经编辑一次,已存在,不能在调用显示该图 */
		/* 原来就一个 level=3;                                */
		/******************************************************/

		/****************************************************************/
		/* _AFXWIN_INLINE int CBitmap::GetBitmap(BITMAP* pBitMap)       */
		/* {                                                            */ 
		/* ASSERT(m_hObject != NULL); //在此行出错应该是LoadBitmap失败  */
		/* return ::GetObject(m_hObject, sizeof(BITMAP), pBitMap);      */
		/* }                                                            */
		/****************************************************************/

		numPicture = 2;
		level=400;
		Invalidate();

	}
}




/*****************************************/
/* 图像锐化:我在menu中创建5个子的menu    */
/* 防止出现平滑错误,一次只调用一个下拉单 */
/* ID_RH_Laplacian Laplacian拉普拉斯算子 */
/* ID_RH_Sobel Sobel算子                 */
/* ID_RH_Prewitt Prewitt算子             */
/* ID_RH_Isotropic Isotropic算子         */
/* ID_RH_GTMB 高通模板H2                 */
/*****************************************/


void CBmpDrawView::OnRHLaplacian() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击图像增强(锐化) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(锐化)!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像增强(锐化):采用拉普拉斯(Laplacian)算子!");

	int HWS=3;                                //模板维数:此四个模板均为3维的

	int H[3][3]={{0,-1,0},    //模板为拉普拉斯算子(中心为4的Laplacian)
				{-1,4,-1},
				{0,-1,0}};

	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //一维坐标转换为二维坐标
	int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
	//图像增强:平滑
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
		
		//原图：一维矩阵转换为二维矩阵
		X=(i/3)%m_nWidth;    //图像在X列
		Y=(i/3)/m_nWidth;    //图像在Y行
		
		//赋值为黑色,相当于清零
		red=green=blue=0;
		
		//对图像进行像素求和并取平均值 HWS维数
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
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
		
		//对新图像赋值:为了区别原来的不准确赋值,我把原来的注释掉了如下
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

//Sobel算子采用PPT上的d(x)d(y)模板
void CBmpDrawView::OnRHSobel() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击图像增强(锐化) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(锐化)!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像增强(锐化):采用Sobel算子!");

	int HWS=3;                                //模板维数:此四个模板均为3维的

	//模板为Sobel算子
	int HX[3][3]={{1,0,-1},{2,0,-2},{1,0,-1}};
	int HY[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int redX,greenX,blueX;
	int redY,greenY,blueY;
	
	int X,Y;       //一维坐标转换为二维坐标
	int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
	//图像增强:平滑
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
		
		//原图：一维矩阵转换为二维矩阵
		X=(i/3)%m_nWidth;    //图像在X列
		Y=(i/3)/m_nWidth;    //图像在Y行
		
		//赋值为黑色,相当于清零
		redX=greenX=blueX=0;
		redY=greenY=blueY=0;
		
		//对图像进行像素求和并取平均值 HWS维数
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
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
		
		//对新图像赋值:为了区别原来的不准确赋值,我把原来的注释掉了如下
		//s=(d(x)*d(x)+d(y)*d(y))开根号
		
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

//Isotropic算子采用PPT上的d(x)模板,不是d(y)
void CBmpDrawView::OnRHIsotropic() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击图像增强(锐化) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(锐化)!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像增强(锐化):采用Isotropic算子!");

	int HWS=3;                                //模板维数:此四个模板均为3维的

	//模板为Isotropic算子
	float H[3][3]={{1,0,-1}, 
					{sqrt(2.0),0,-sqrt(2.0)}, 
					{1,0,-1}};

	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	float red,green,blue;
	
	int X,Y;       //一维坐标转换为二维坐标
	int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
	//图像增强:平滑
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
		
		//原图：一维矩阵转换为二维矩阵
		X=(i/3)%m_nWidth;    //图像在X列
		Y=(i/3)/m_nWidth;    //图像在Y行
		
		//赋值为黑色,相当于清零
		red=green=blue=0;
		
		//对图像进行像素求和并取平均值 HWS维数
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
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
		
		//对新图像赋值:为了区别原来的不准确赋值,我把原来的注释掉了如下
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


//Prewitt算子采用PPT上的d(x)模板,不是d(y)
void CBmpDrawView::OnRHPrewitt() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击图像增强(锐化) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(锐化)!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像增强(锐化):采用Prewitt算子!");

	int HWS=3;                                //模板维数:此四个模板均为3维的

	int H[3][3]={{1,0,-1},    //模板为Prewitt算子
				{1,0,-1},
				{1,0,-1}};


	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //一维坐标转换为二维坐标
	int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
	//图像增强:平滑
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
		
		//原图：一维矩阵转换为二维矩阵
		X=(i/3)%m_nWidth;    //图像在X列
		Y=(i/3)/m_nWidth;    //图像在Y行
		
		//赋值为黑色,相当于清零
		red=green=blue=0;
		
		//对图像进行像素求和并取平均值 HWS维数
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
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
		
		//对新图像赋值:为了区别原来的不准确赋值,我把原来的注释掉了如下
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


//高通滤波采用的是模板H2
void CBmpDrawView::OnRhGtmb() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击图像增强(锐化) 
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能图像增强(锐化)!",MB_OK,0);
		return;
	}

	AfxMessageBox("图像增强(锐化):采用Prewitt算子!");

	int HWS=3;                                //模板维数:此四个模板均为3维的

	int H[3][3]={{-1,-1,-1},    //模板为Prewitt算子
				{-1,8,-1},
				{-1,-1,-1}};

	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");
	
	
	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  
	int red,green,blue;
	
	int X,Y;       //一维坐标转换为二维坐标
	int TR,TG,TB;  //记录红绿蓝坐标位置
	
	
	//图像增强:平滑
	for(int i=0; i<m_nImage ; i=i+3 )
	{
		//它要获取源图像周围9个点的矩阵乘以模板9个点的矩阵,故一维图像转二维
		
		//原图：一维矩阵转换为二维矩阵
		X=(i/3)%m_nWidth;    //图像在X列
		Y=(i/3)/m_nWidth;    //图像在Y行
		
		//赋值为黑色,相当于清零
		red=green=blue=0;
		
		//对图像进行像素求和并取平均值 HWS维数
		for(int j=Y-HWS/2 ; j<Y+HWS/2+1 ; j++ )                      //第j行
		{
			for(int k=X-HWS/2 ; k<X+HWS/2+1 ; k++ )                  //第k列
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
		
		//对新图像赋值:为了区别原来的不准确赋值,我把原来的注释掉了如下
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
/* huffman编码 ID_BM_HFM(编码哈弗曼)                                      */
/* 1.计算图像的灰度计数                                                   */
/* 2.计算图像灰度的概率分布                                               */
/* 3.对图像灰度概率进行从小到大的排序                                     */
/* 4.建立编码二叉树                                                       */
/*   (重点)先是对各灰度概率进行排序,排序后的概率最小的两个元素相加        */
/*   作为一个新的元素取代序列中概率最小的两个元素,继续排序找最小的2个操作 */
/* 5.对位图进行编码压缩                                                   */
/**************************************************************************/          

void CBmpDrawView::OnBmHfm() 
{

	//如果没有导入图片直接点击哈弗曼编码 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能进行哈弗曼编码!",MB_OK,0);
		return;
	}
	
	AfxMessageBox("图片编码-Huffman编码压缩图像!",MB_OK,0);
		
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");


	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
//	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
//	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	int Red[256],Green[256],Blue[256];
	int i,j,k;
	for(j=0;j<256;j++)   //定义数组并清零
	{
		Red[j]=0;
		Green[j]=0;
		Blue[j]=0;
	}
	
	//重点:只对24位的灰度图像进行压缩,这里的图像灰度数组就不分为R G B(3个数组)	

	int HD[256];                                  //记录灰度值
	double HDGL[256];                             //灰度概率值记录
	int Relation[256];                            //HDGL[256]和str_HFM[256]的映射关系
	unsigned char red,green,blue;
	int IntRed,IntGreen,IntBlue;                  //强制转换

	//初始化
	memset(HD,0,sizeof(HD));
    memset(HDGL,0,sizeof(HDGL));

	//第一步:计算图像的灰度计数 
	for(i=0; i<m_nImage/3; i++ )
	{
		fread(&red,sizeof(char),1,fpo);
		IntRed=int(red);
		if( IntRed>=0 && IntRed<256 ) HD[IntRed]++;   //原来使用的是Red[IntRed]++;记录RGB 现在统一为灰度图
		
		fread(&green,sizeof(char),1,fpo);
		IntGreen=int(green);
		if( IntGreen>=0 && IntGreen<256 ) HD[IntGreen]++;
		
		fread(&blue,sizeof(char),1,fpo);
		IntBlue=int(blue);
		if( IntBlue>=0 && IntBlue<256 ) HD[IntBlue]++;
	}

	//第二步:计算256灰度值的分布概率
	double sum=0;    //计算概率和
	for(i=0; i<255; i++ )
	{
		HDGL[i]=(HD[i]*1.0)/m_nImage;
		sum+=HDGL[i];
	}
	//为了保证它们的概率和为1,最后一个灰度概率采用1减所有和
	HDGL[255]=1.0-sum;

	//HDGL[256]和str_HFM[256]的映射关系Relation[256]初始化
	for(i=0; i<256; i++ )
	{
		Relation[i]=i;
	}

	//第三步:将图像的灰度等级按概率大小进行从小到大排序 冒泡排序
	double T;                        
	for(j=0; j<256-1; j++)   //因为循环中有i+1,防止越界写成256-1
	{
		for(i=0; i<256-j-1; i++) 
		{
			//交换变量
			if(HDGL[i]>HDGL[i+1])
			{
				T=HDGL[i];
				HDGL[i]=HDGL[i+1];
				HDGL[i+1]=T;
			}

			//更新映射关系
			for(k=0; k<256; k++)
			{
				//判断是否是HDGL[256]的子节点
				if(Relation[k]==i)
				{
					//映射到节点j+1
					Relation[k]=i+1;	
				}
				else if(Relation[k]==i+1)
				{
					//映射到节点i
					Relation[k]=i;
				}
			}

		}
	}

	
	//第四步:计算霍夫曼编码表(二叉树 这里简略为静态的霍夫曼编码采用数组仿造的树型结构)
	for(i=0; i<256-1; i++)
	{
		//寻找第一个不为0的概率灰度级
		if(HDGL[i]>0) break;
	}

	//霍夫曼编码的存储的类似 0 1 的编码
	CString str_HFM[256];                         

	//开始编码
	for(i=i; i<256-1 ; i++)
	{
		//更新str_HFM
		for(k=0; k<256; k++)
		{
			//判断是否是Relation[i]的子节点并编码字符串
			if(Relation[k]==i)
				str_HFM[k]="1"+str_HFM[k];
			else if(Relation[k]==i+1) 
				str_HFM[k]="0"+str_HFM[k];
		}

		//概率最小的两个概率相加,结果保存到HDGL[i+1]
		HDGL[i+1]=HDGL[i+1]+HDGL[i];

		//改变映射关系
		for(k=0; k<256; k++)
		{
			//判断是否是HDGL[i]的子节点
			if(Relation[k]==i)
			{
				//映射到节点i+1
				Relation[k]=i+1;
			}
		}

		//重新排序
		for(j=i+1; j<256-1; j++)
		{
			if(HDGL[j]>HDGL[j+1])
			{
				//互换
				double sign = HDGL[j];
				HDGL[j]=HDGL[j+1];
				HDGL[j+1]=sign;

				//更新映射关系
				for(k=0; k<256; k++)
				{
					//判断是否是HDGL[i]的子节点
					if(Relation[k]==j)
						Relation[k]=j+1;   //映射到节点j+1
					else if(Relation[k]==j+1)
						Relation[k]=j;
				}
			}

			//退出循环
			else break;
		}
	}

	//显示编码压缩的概率分布
	CTestBMDlg dlg;    
	//显示各自的分布
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

	//显示对话框
	if( dlg.DoModal()==IDOK )
	{
	}
	

	//第五步:对图像进行霍夫曼编码压缩

	//位掩码
	unsigned char Array[8]={128,64,32,16,8,4,2,1};
	//8位的霍夫曼编码图像
	CString picture="";
	unsigned char flag=0;
	
	//对图像各像素进行编码
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
		
	numPicture = 1;           //只显示一张图像
	Invalidate();
}



/***************************************************************/
/* 二值图像的细化                                              */
/* 二值图像是数字图像的重要子集，指灰度值只取两种值的图像      */
/* 两个灰度值可取为 0-相应的点构成背景 和 1-相应的点构成景物   */
/* 二值形态学处理算法都是以膨胀,腐蚀这两种最基本的运算为基础的 */
/***************************************************************/

/****************************************************************************/
/* 细化的含义:当进行腐蚀运算是,并不直接消除待剥离像素                       */
/* 而是先通过判断该处理是否改变原图像的连通性,如果不改变,则按以前方法腐蚀掉 */
/* 如果改变,需要对其进行保留                                                */
/* 细化处理实际是一种保持图像原有连通性的腐蚀运算                           */
/* 击中击不中变换   PPT-第13章-15页                                         */
/****************************************************************************/

void CBmpDrawView::OnEztxXh() 
{
	// TODO: Add your command handler code here

	//如果没有导入图片直接点击细化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能细化图片!",MB_OK,0);
		return;
	}

	AfxMessageBox("细化图像!",MB_OK,0);
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);
	
	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);
	
	fread(m_pImage,m_nImage,1,fpo);

	//灰度图像
	int i,j,m,n;
	unsigned char color;
	unsigned char red,green,blue;
	
	//5*5的相邻矩阵,该区域内保留该点,否则去掉
	unsigned char Array[5][5];
	
	unsigned char Count;   //计数器
	unsigned char sign;    //循环跳出标志,true时成立,false跳出循环

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  

	//初始化,初始值为255 白色
	memset(ImageSize,(BYTE)255,m_nImage);
	
	//记录像素在图像中的位置
	int place;          //变换后的位置

	sign=true;
	while(sign)
	{
		sign=false;
		
		//初始化,初始值为255
		memset(ImageSize,(BYTE)255,m_nImage);

		//由于使用5*5的结构元素,为防止越界,不处理外围的2行2列像素
		for(i=2; i<m_nHeight-2; i++)
		{
			for(j=2*3; j<m_nWidth*3-2*3; j+=3 )  //宽*3=每行的像素
			{
				//只想源图像倒数第i行,第j个像素的位置
				place=i*m_nWidth*3+j;                    //获取当前坐标的位置

			//	CString str;
			//	str.Format("%d",place);
			//	AfxMessageBox(str);

				//如果源图像中的点位白色,则跳过
				if(m_pImage[place]>127) continue;        //直接跳出为白色

				//获取当前点相邻的5*5区域内像素值,白色用0表示,黑色用1表示
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

						//图中A点为第一个点,从A点开始找place=A
						//place+(2-m)*m_nWidth*3+(n-2)*3表示A点周围的5*5的矩阵,因为为防止越界,不处理外围的2行2列像素
					
						if(m_pImage[place+(2-m)*m_nWidth*3+(n-2)*3]>127)
							Array[m][n]=0;
						else
							Array[m][n]=1;
					}
				}


//判断条件1是否成立

				/*********/
				/* ..... */
				/* .ooo. */
				/* .o.o. */
				/* .ooo. */
				/* ..... */
				/*********/
				
				Count=0;
				Count=Array[1][1]+Array[1][2]+Array[1][3]+Array[2][1]+Array[2][3]+Array[3][1]+Array[3][2]+Array[3][3];

				if(Count<2 || Count>6)  //改变
				{
					ImageSize[place]=255;
					ImageSize[place+1]=255;
					ImageSize[place+2]=255;
					continue;
				}

//判断条件2是否成立

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

//判断条件3是否成立
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

//判断条件4是否成立

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

				//如果条件都满足则删除该点
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


// 8位图像调用调色板灰度化处理                 
// biBitcount=8时,有256个表项,1个像素占1个字节 

void CBmpDrawView::OnHdBit() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接点击细化 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能灰度化图片!",MB_OK,0);
		return;
	}

	if(m_nBitCount!=8)
	{
		AfxMessageBox("它不是8位bmp图片,请载入8位图片后才能灰度化图片!",MB_OK,0);
		return;
	}

	AfxMessageBox("灰度8bit图像!",MB_OK,0);
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);


	/*****************************************************************/
	/* 重点错误: "0x7c9.."指令引用的"0x00a.."内存,该内存不能为"read" */
	/* 因为:                                                         */
	/*    fread(&m_pPal,sizeof(RGBQUAD),256,fpo);                    */
	/*    fwrite(&m_pPal,sizeof(RGBQUAD),256,fpw);                   */
	/* 你一次读取256个结构体,但不能也写出256个结构体,解决方法见下    */
	/*****************************************************************/
	
	//定义RGB数组记录调色板
	BYTE RED[256];
	BYTE BLUE[256];
	BYTE GREEN[256];

	//读取调色板
	for(int i=0;i<256;i++)
	{
		fread(&m_pPal,sizeof(RGBQUAD),1,fpo);
		RED[i]=m_pPal.rgbRed;
		BLUE[i]=m_pPal.rgbBlue;
		GREEN[i]=m_pPal.rgbGreen;

		//8位的彩色图像灰度,只需改变它的调色板即可.
		RED[i]=BLUE[i]=GREEN[i]=(RED[i]+BLUE[i]+GREEN[i])/3;
		m_pPal.rgbRed=RED[i];
		m_pPal.rgbBlue=BLUE[i];
		m_pPal.rgbGreen=GREEN[i];
		fwrite(&m_pPal,sizeof(RGBQUAD),1,fpw);
	}
	

	//计算8为图片像素部分的大小
	int size_eight;
	size_eight=m_nSize-sizeof(BITMAPFILEHEADER)-sizeof(BITMAPINFOHEADER)-sizeof(RGBQUAD)*256;

	//自定义数组
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


//利用霍夫变换检测直线和圆
//霍夫（Hough）变换方法是利用图像全局特性而直接检测目标轮廓，将图像的边缘像素连接起来的常用方法

void CBmpDrawView::OnHoughZX() 
{
	// TODO: Add your command handler code here
	
	//如果没有导入图片直接检测 提示信息
	if(numPicture==0)
	{
		AfxMessageBox("载入图片后才能检测图片的直线!",MB_OK,0);
		return;
	}

	AfxMessageBox("利用霍夫变换检测直线!",MB_OK,0);
	
	//打开临时的图片
	FILE *fpo = fopen(BmpName,"rb");
	FILE *fpw = fopen(BmpNameLin,"wb+");

	//读取文件
	fread(&bfh,sizeof(BITMAPFILEHEADER),1,fpo);
	fread(&bih,sizeof(BITMAPINFOHEADER),1,fpo);

	fwrite(&bfh,sizeof(BITMAPFILEHEADER),1,fpw);
	fwrite(&bih,sizeof(BITMAPINFOHEADER),1,fpw);

	fread(m_pImage,m_nImage,1,fpo);

	/*new和delete有效的进行动态内存的分配和释放*/
	unsigned char *ImageSize;      
	ImageSize=new unsigned char[m_nImage];  

	//初始化,初始值为255 白色
	memset(ImageSize,(BYTE)255,m_nImage);

	//存储变换域中的两个最大值
	int MaxValue1;
	int MaxValue2;
	int MaxDist1;
	int MaxDist2;
	int MaxAngleNumber1;
	int MaxAngleNumber2;

	//计算变换域的尺寸 最大距离 对角线
	int MaxDist;
	MaxDist = (int) sqrt(m_nWidth*m_nWidth + m_nHeight*m_nHeight);

	//角度从0－180，每格2度
	int MaxAngleNumber;
	MaxAngleNumber = 90;

	//当前位置
	int place;

	//变换域的坐标
	int Dist;
	int AngleNumber;

	//变换域记录值
	int TransArea[100000];

	int i,j;
	for(j=0; j<m_nHeight; j++)
	{
		for(i=0; i<m_nWidth*3; i+=3)
		{
			//获取当前位置
			place=j*m_nWidth*3+i;

			//目标图像中含有0和255外的其它灰度值直接返回
			if(m_pImage[place]!=255 && m_pImage[place]!=0)
			{
				AfxMessageBox("霍夫变换直线检测,只能是二值图像!");
				return;
			}	

			//如果是黑点，则在变换域的对应各点上加1
			if(m_pImage[place]==0)
			{
				//变换域的坐标 注意步长是2度 AngleNumber*2*3.14/180.0中的2
				for(AngleNumber=0; AngleNumber<MaxAngleNumber; AngleNumber++)
				{
					//X*cos(theta) + y*sin(theta) = r 其中角度theta指r与X轴之间的夹角

					Dist = (int) fabs(i*cos(AngleNumber*2*3.14/180.0) + 
						j*sin(AngleNumber*2*3.14/180.0));

					//变换域的对应点上加1
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
	
	
	//找到变换域中的两个最大值点
	MaxValue1=0;
	MaxValue2=0;

	//找到第一个最大值点
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

	//将第一个最大值点附近清零
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

	//找到第二个最大值点
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

	//判断两直线是否平行
	if( fabs(MaxAngleNumber1-MaxAngleNumber2) <= 2 )
	{
		//两直线平行，在缓存图像中重绘这两条直线
		for(j=0; j<m_nHeight; j++)
		{
			for(i=0; i<m_nWidth*3; i+=3)
			{	

				// 指向缓存图像倒数第j行,第i个象素的指针			
				place=m_nWidth*3*j+i;	

				//如果该点在某一条平行直线上，则在将该点赋为黑

				//在第一条直线上
				Dist = (int) fabs(i*cos(MaxAngleNumber1*2*3.14/180.0) + 
							j*sin(MaxAngleNumber1*2*3.14/180.0));
				if (Dist == MaxDist1)
					ImageSize[place]=0;
			
				//在第二条直线上
				Dist = (int) fabs(i*cos(MaxAngleNumber2*2*3.14/180.0) + 
							j*sin(MaxAngleNumber2*2*3.14/180.0));
				if (Dist == MaxDist2)
					ImageSize[place]=0;
			}
		}
	}

	AfxMessageBox("显示!");

	fwrite(ImageSize,m_nImage,1,fpw);

	//少这两句会报错:File:afxinl.inl Line:418
	fclose(fpo);
	fclose(fpw);
	
	numPicture = 2;
	level=3;
	Invalidate();
}
