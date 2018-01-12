// CWatchAttriDlg.cpp : implementation file
//

#include "stdafx.h"
#include "serialporttest.h"
#include "WatchAttriDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWatchAttriDlg dialog


CWatchAttriDlg::CWatchAttriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWatchAttriDlg::IDD, pParent)
{
	m_pWatch = NULL;
	//{{AFX_DATA_INIT(CWatchAttriDlg)
	//}}AFX_DATA_INIT
}


void CWatchAttriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWatchAttriDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWatchAttriDlg, CDialog)
	//{{AFX_MSG_MAP(CWatchAttriDlg)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWatchAttri message handlers

BOOL CWatchAttriDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int rst = 0;
	// TODO: Add extra initialization here
	if(m_pWatch)
	{
		SetDlgItemInt(IDC_OFFSET, m_pWatch->offset, FALSE);
		rst = SendDlgItemMessage(IDC_DATA_TYPE, CB_SELECTSTRING,
			(WPARAM)(-1), (LPARAM)(LPCSTR(m_pWatch->sType)));
		rst |= SendDlgItemMessage(IDC_B_HEX, CB_SETCURSEL, m_pWatch->bHex, 0);
		CRect rc;
		GetWindowRect(rc);
		int cx = rc.Width();
		int cy = rc.Height();
		SetWindowPos(NULL, m_xpos, m_ypos, cx, cy, TRUE);
	}
	if((CB_ERR == rst) || (NULL == m_pWatch))
	{
		SetDlgItemInt(IDC_OFFSET, 0, FALSE);
		SendDlgItemMessage(IDC_DATA_TYPE, CB_SETCURSEL, 0, 0);
		SendDlgItemMessage(IDC_B_HEX, CB_SETCURSEL, 1, 0);
	}

	SendDlgItemMessage(IDC_SPIN1, UDM_SETRANGE, 0, MAKELPARAM(100, 0));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWatchAttriDlg::OnDestroy() 
{
	if(m_bModified)
	{
		m_pWatch->offset = GetDlgItemInt(IDC_OFFSET);
		m_pWatch->bHex = GetDlgItemInt(IDC_B_HEX);
		CString str;
		GetDlgItemText(IDC_DATA_TYPE, str.GetBuffer(10), 9);
		str.ReleaseBuffer();
		m_pWatch->sType = str;
	}

	CDialog::OnDestroy();
}

BOOL CWatchAttriDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	WORD id = LOWORD(wParam);
	switch(HIWORD(wParam))
	{
	case EN_CHANGE:
		if(IDC_OFFSET == id)
		{
			m_bModified = TRUE;
		}
		break;
	case CBN_SELCHANGE:
		switch(id)
		{
		case IDC_B_HEX:
		case IDC_DATA_TYPE:
			m_bModified = TRUE;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return CDialog::OnCommand(wParam, lParam);
}

LRESULT CWatchAttriDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((message == WM_NCACTIVATE) && (wParam == FALSE))
	{
		PostMessage(WM_COMMAND, MAKELPARAM(IDOK, BN_CLICKED), 0);
		return 1;
	}
	return CDialog::WindowProc(message, wParam, lParam);
}
