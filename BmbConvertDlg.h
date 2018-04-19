// BmbConvertDlg.h : header file
//

#if !defined(AFX_BMBCONVERTDLG_H__90667F8E_4236_4ACA_ABDF_0EA7F6ECC499__INCLUDED_)
#define AFX_BMBCONVERTDLG_H__90667F8E_4236_4ACA_ABDF_0EA7F6ECC499__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmbConvertDlg dialog

class CBmbConvertDlg : public CDialog
{
// Construction
public:
	CBmbConvertDlg(CWnd* pParent = NULL);	// standard constructor
	CString CBmbConvertDlg::ConvertBmbFile( CString strFilePath );

// Dialog Data
	//{{AFX_DATA(CBmbConvertDlg)
	enum { IDD = IDD_BMBCONVERT_DIALOG };
	CString	m_strPath;
	CString	m_strResult;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmbConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmbConvertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMBCONVERTDLG_H__90667F8E_4236_4ACA_ABDF_0EA7F6ECC499__INCLUDED_)
