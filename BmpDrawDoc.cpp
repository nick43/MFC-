// BmpDrawDoc.cpp : implementation of the CBmpDrawDoc class
//

#include "stdafx.h"
#include "BmpDraw.h"

#include "BmpDrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawDoc

IMPLEMENT_DYNCREATE(CBmpDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CBmpDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawDoc construction/destruction

CBmpDrawDoc::CBmpDrawDoc()
{
	// TODO: add one-time construction code here

}

CBmpDrawDoc::~CBmpDrawDoc()
{
}

BOOL CBmpDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBmpDrawDoc serialization

void CBmpDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawDoc diagnostics

#ifdef _DEBUG
void CBmpDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpDrawDoc commands
