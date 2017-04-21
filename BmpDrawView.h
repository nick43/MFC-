// BmpDrawView.h : interface of the CBmpDrawView class
//
/////////////////////////////////////////////////////////////////////////////
#include "ImageStruct.h"

#if !defined(AFX_BMPDRAWVIEW_H__7F2D52DC_E3C1_44A4_8238_1D48AA39FC12__INCLUDED_)
#define AFX_BMPDRAWVIEW_H__7F2D52DC_E3C1_44A4_8238_1D48AA39FC12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpDrawView : public CView
{
protected: // create from serialization only
	CBmpDrawView();
	DECLARE_DYNCREATE(CBmpDrawView)

// Attributes
public:
	CBmpDrawDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ShowWindowInfo();
	//显示状态栏信息

	bool SaveBmp(LPCSTR lpFileName);
	//用来保存bmp格式图片

	bool ReadBmp();
	//用来读取bmp个手机图片

	bool ShowJpgGif(CDC* pDC,CString strPath, int x, int y);
	//用来显示指定位图jpg、gif的函数

	void ShowBitmap(CDC* pDC,CString BmpName);
	//用来显示指定位图bmp的函数

	CBitmap m_bitmap;   //创建位图对象
	CBitmap m_bitmaplin;//创建临时位图对象进行处理
	CString EntName;    //保存图像文件扩展名
	CString BmpName;    //保存图像文件文件名

	CString BmpNameLin; //保存图像的副本文件 原工程中
	
	int	m_nWidth;		//图像实际宽度
	int	m_nHeight;		//图像实际高度
	int	m_nDrawWidth;	//图像显示宽度
	int	m_nDrawHeight;	//图像显示高度
	DWORD m_nImage;		//图像数据的字节数 只含位图
	DWORD m_nSize;      //图像文件大小
	int m_nLineByte;    //图像一行所占字节数
	int	m_nBitCount;    //图像每个像素所占位数
	int	m_nPalette;     //位图实际使用的颜色表中的颜色数
	
	BYTE *m_pImage;         //读入图片数据后的指针
	BITMAPFILEHEADER bfh;           //全局变量文件头
	BITMAPINFOHEADER bih;           //全局变量信息头
	RGBQUAD m_pPal;                //颜色表指针

	//在第14章8bit彩色图像灰度时会调用到调色板RGBQUAD *m_pPal

	virtual ~CBmpDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpDrawView)
	afx_msg void OnUpdateFileNew(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileMruFile1(CCmdUI* pCmdUI);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShowTwo();
	afx_msg void OnLh2();
	afx_msg void OnLh4();
	afx_msg void OnLh8();
	afx_msg void OnLh16();
	afx_msg void OnLh32();
	afx_msg void OnLh64();
	afx_msg void OnShowHd();
	afx_msg void OnCy();
	afx_msg void OnXxhdJx();
	afx_msg void OnXxhdQb();
	afx_msg void OnXxhdYd();
	afx_msg void OnXxhdZq();
	afx_msg void OnZftYt();
	afx_msg void OnFxxhdPf();
	afx_msg void OnFxxhdHs();
	afx_msg void OnFxxhdLs();
	afx_msg void OnZftBh();
	afx_msg void OnFxxhdJhh();
	afx_msg void OnJhysSxxcz();
	afx_msg void OnJhysZjlcz();
	afx_msg void OnJhbhPy();
	afx_msg void OnJhbhFz();
	afx_msg void OnJhbhXz();
	afx_msg void OnTxzqPh();
	afx_msg void OnRHLaplacian();
	afx_msg void OnRHSobel();
	afx_msg void OnRHIsotropic();
	afx_msg void OnRHPrewitt();
	afx_msg void OnRhGtmb();
	afx_msg void OnBmHfm();
	afx_msg void OnEztxXh();
	afx_msg void OnHdBit();
	afx_msg void OnHoughZX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BmpDrawView.cpp
inline CBmpDrawDoc* CBmpDrawView::GetDocument()
   { return (CBmpDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPDRAWVIEW_H__7F2D52DC_E3C1_44A4_8238_1D48AA39FC12__INCLUDED_)
