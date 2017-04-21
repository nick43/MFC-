// BmpDrawDoc.h : interface of the CBmpDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMPDRAWDOC_H__3C9B3B93_BF70_4E9A_9971_787E1426C431__INCLUDED_)
#define AFX_BMPDRAWDOC_H__3C9B3B93_BF70_4E9A_9971_787E1426C431__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBmpDrawDoc : public CDocument
{
protected: // create from serialization only
	CBmpDrawDoc();
	DECLARE_DYNCREATE(CBmpDrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPDRAWDOC_H__3C9B3B93_BF70_4E9A_9971_787E1426C431__INCLUDED_)
