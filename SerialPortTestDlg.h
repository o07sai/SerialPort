// SerialPortTestDlg.h : header file
//

#if !defined(AFX_SerialPortTestDLG_H__D9C3646C_FAD1_459F_8FFD_9863EB2231E5__INCLUDED_)
#define AFX_SerialPortTestDLG_H__D9C3646C_FAD1_459F_8FFD_9863EB2231E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SerialPort.h"
#include "afxwin.h"
#include "MultiLineBox.h"

enum ENDIAN{
	E_BIGENDIAN=0,
	E_LITTLEENDIAN,
	E_MODBUS
};

typedef struct _tagWatch{
	int offset;
	CString sType;
	int bHex;
}Watch;
/////////////////////////////////////////////////////////////////////////////
// CSerialPortTestDlg dialog

class CSerialPortTestDlg : public CDialog
{
// Construction
public:
	void ConvEndian(BYTE* src, WORD* desc, ENDIAN end);
	void ConvEndian(BYTE* src, DWORD* desc, ENDIAN end);
	void SetPromptWhenOpenOrClose(BOOL bopenclose);
	CSerialPortTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSerialPortTestDlg)
	enum { IDD = IDD_SERIALPORT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialPortTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

private:
	BOOL m_bSumAdd;
	BOOL m_bModifiedParam;
	BOOL m_bStopDis;
	BOOL m_bSerialPortOpened;
	Watch m_watch[8];
	CSerialPort m_serialPort;
	int m_spacetime;
	int m_lasttick;
	BOOL m_bHasTimeOut;

	int m_autotime;
	int m_cycletime;
	int m_cyclesendindex;

	DWORD m_dwRecvCnt;
	DWORD m_dwSendCnt;

	CByteArray m_recvBag;
	BYTE m_hzi;

private:
	void AppendChar2Dis(BYTE c);
	void UpdateWatches(CByteArray& recvbag);
	void SendBuff(LPCSTR pBuff, int len);
	void DefaultParam(void);
	void OpenSerialPort(void);
	void ModifySelectAll(void);
	void SetSelectAll(void);
	void SendBuffContent(int index);

	int TransBuff(BOOL bHex, CString &str, BYTE* pBuff, int size);

	int GetWeatherSelByIndex(int index);
	CString& GetSendBuffContent(int index, CString& str);
	int SaveParamFile(LPCSTR sFileName);
	int SetSendBuffContent(int index, int bSelected, CString& str);
	int ReadParamFile(LPCSTR sFileName);
	
	void AppendString2Dis(LPCSTR str);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSerialPortTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnOpenSerialPortTest();
	afx_msg void OnManualSend();
	afx_msg void OnEmptyRecvbuf();
	afx_msg void OnAbout();
	afx_msg void OnEmptySendbuf();
	afx_msg void OnStopDis();
	afx_msg LRESULT OnReceiveData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCommRWError(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCommTXEmptyDtd(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRefreshComm();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnDbClickedLogo();
	int AutoResp(CByteArray& sRecv);
	int SendRightContent(CStringArray& sa);
	void GetBuffContent(int index, BYTE* pbuff);
protected:
	afx_msg LRESULT OnCommTimeout(WPARAM wParam, LPARAM lParam);
public:
	CMultiLineBox m_multibox;
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void OnCancel();
	afx_msg void OnClose();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SerialPortTestDLG_H__D9C3646C_FAD1_459F_8FFD_9863EB2231E5__INCLUDED_)
