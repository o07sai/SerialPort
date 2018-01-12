#if !defined(AFX_WATCHATTRI_H__A6A766BD_0B55_49F9_9A13_8DF76726ADAA__INCLUDED_)
#define AFX_WATCHATTRI_H__A6A766BD_0B55_49F9_9A13_8DF76726ADAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CWatchAttriDlg.h : header file
//
#include "SerialPortTestDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CWatchAttriDlg dialog

class CWatchAttriDlg : public CDialog
{
// Construction
public:
	CWatchAttriDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWatchAttriDlg)
	enum { IDD = IDD_WATCH_ATTRI };
	//}}AFX_DATA

	BOOL m_bModified;
	Watch* m_pWatch;
	int m_xpos;
	int m_ypos;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWatchAttriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWatchAttriDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATCHATTRI_H__A6A766BD_0B55_49F9_9A13_8DF76726ADAA__INCLUDED_)
