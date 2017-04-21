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
	//��ʾ״̬����Ϣ

	bool SaveBmp(LPCSTR lpFileName);
	//��������bmp��ʽͼƬ

	bool ReadBmp();
	//������ȡbmp���ֻ�ͼƬ

	bool ShowJpgGif(CDC* pDC,CString strPath, int x, int y);
	//������ʾָ��λͼjpg��gif�ĺ���

	void ShowBitmap(CDC* pDC,CString BmpName);
	//������ʾָ��λͼbmp�ĺ���

	CBitmap m_bitmap;   //����λͼ����
	CBitmap m_bitmaplin;//������ʱλͼ������д���
	CString EntName;    //����ͼ���ļ���չ��
	CString BmpName;    //����ͼ���ļ��ļ���

	CString BmpNameLin; //����ͼ��ĸ����ļ� ԭ������
	
	int	m_nWidth;		//ͼ��ʵ�ʿ��
	int	m_nHeight;		//ͼ��ʵ�ʸ߶�
	int	m_nDrawWidth;	//ͼ����ʾ���
	int	m_nDrawHeight;	//ͼ����ʾ�߶�
	DWORD m_nImage;		//ͼ�����ݵ��ֽ��� ֻ��λͼ
	DWORD m_nSize;      //ͼ���ļ���С
	int m_nLineByte;    //ͼ��һ����ռ�ֽ���
	int	m_nBitCount;    //ͼ��ÿ��������ռλ��
	int	m_nPalette;     //λͼʵ��ʹ�õ���ɫ���е���ɫ��
	
	BYTE *m_pImage;         //����ͼƬ���ݺ��ָ��
	BITMAPFILEHEADER bfh;           //ȫ�ֱ����ļ�ͷ
	BITMAPINFOHEADER bih;           //ȫ�ֱ�����Ϣͷ
	RGBQUAD m_pPal;                //��ɫ��ָ��

	//�ڵ�14��8bit��ɫͼ��Ҷ�ʱ����õ���ɫ��RGBQUAD *m_pPal

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
