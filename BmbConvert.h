// BmbConvert.h : main header file for the BMBCONVERT application
//

#if !defined(AFX_BMBCONVERT_H__AB19D832_D4C9_4622_9746_9D62A62E7440__INCLUDED_)
#define AFX_BMBCONVERT_H__AB19D832_D4C9_4622_9746_9D62A62E7440__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmbConvertApp:
// See BmbConvert.cpp for the implementation of this class
//

class CBmbConvertApp : public CWinApp
{
public:
	CBmbConvertApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmbConvertApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmbConvertApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMBCONVERT_H__AB19D832_D4C9_4622_9746_9D62A62E7440__INCLUDED_)
