// SerialPortTestDlg.cpp : implementation file
//
#include "stdafx.h"
#include "SerialPortTest.h"
#include "SerialPortTestDlg.h"
#include "WatchAttriDlg.h"

#define WIN_BASE_TEXT	"魔杖串口工具 -- o07sai."

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE(a)	(sizeof(a)/sizeof(a[0]))
#endif
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str=_T(
		"2018年07月19日\n"
		"1. 程序默认字符显示模式显示汉字。\n"
		"2. 如果配置文件中，CONFIG字段有DISHANZI=0,则不显示汉字，所有字节大于127的，都换成0x07。\n"
		"3. V1.5.0\n"
		"\n"
		"2018年07月04日\n"
		"1. 删除扩展预置发送内容\n"
		"2. 添加一个WATCH，窗口加高，添加一个历史列表\n"
		"3. 历史列表奇偶行不同背景色\n"
		"4. 限制历史记录最多400条，每条文本字节数最多1000个\n"
		"\n"
		"2018年01月22日\n"
		"1. 扩展预置发送内容\n"
		"\n"
		"2017年11月28日\n"
		"1. 改变RTS和DTR的使用方法。选择RTS流控，可以用它来控制RS485的方向，实现半双工。\n"
		"2. v1.4.0\n"
		"\n"
		"2017年9月26日\n"
		"1. 修改了串口类的读策略，提高了接收数据的实时性（针对某些USB转串口芯片）。\n"
		"2. 改变了帧间隔判断方法。\n"
		"3. 隐式添加MODBUS帧间隔最小时间，默认按MODBUS标准来计算。最小值4ms，可以指定4-2000ms。\n"
		"4. 修改了每次都保存配置文件的BUG。\n"
		"5. 修改了主发送缓冲区换行的问题。\n"
		"6. v1.3.2\n"
		"\n"
		"2017年9月21日\n"
		"1. 修复接收字符显示时首个字母丢失问题，这个与汉字显示相关。\n"
		"2. 改变版本更新记录顺序。\n"
		"3. 添加自定义尾缀。\n"
		"4. v1.3.0\n"
		"\n"
		"2017年7月24日\n"
		"1.增加自动回复功能。\n"
		"2.语法为：每行为一条语句。\n"
		"例：_T(hello)=_T(world),收到hello字符串，自动回复world.\n"
		"_T()表示使用字符串模式，_H()表示用十六进制模式。\n"
		"$1=$2,表示收到内容与右侧发送缓冲区1的内容相同，自动回复2号缓冲区内容。\n"
		"左侧模式按显示”HEX显示“有没有勾选来定，右侧按右侧的缓冲区“HEX发送”有没有勾选定。\n"
		"\n"
		"2016年3月21日\n"
		"1.修复在串口号大于9时,打不开的问题.\n"
		"\n"
		"2016年3月14日\n"
		"1.修改观察窗口显示的部分BUG,选择32位数据类型是,按16进制显示时,大小端不正确.v1.2.3\n"
		"2.修复在没有串口时保存数据格式问题,导致下次启动时丢失部分数据.\n"
		"\n"
		"2014年8月20日\n"
		"1.新增添加回车换行尾缀.\n"
		"2.优化接收数据的数据处理速度,一次读取多个字节.\n"
		"3.修复发送内容含有\"=\",\",\"这些特殊字符时保存数据后再读取时的错误.\n"
		"4.修复发送内容缓冲字符的个数限制,原先限制了128个字节.\n"
		"5.主发送区禁止输入回车换行.\n"
		"6.默认按钮改到手动发送,退出按钮改成普通按钮.\n"
		"7.v1.2.1\n"
		"8.汉字显示问题修复.v1.2.2\n"
		"\n"
		"2013年10月31日\n"
		"1.添加<隐藏发送内容>选项.\n"
		"2.在关于对话框里添加版本更新记录.\n"
		"\n"
		"2013年5月29日\n"
		"1.新增WATCH窗口字节顺，支持BIG ENDIAN,LITTLE ENDIAN和MODBUS\n"
		"\n"
		"2013年5月23日\n"
		"1.修改了配置文件里记录的串口号，当前不存在时，误当错误格式处理的BUG。\n"
		"2.隐式增加校验和算法。在配置文件里添加字段CHECKSUM_USEADD,默认是减法运算，当添加为1时，使用加法运算。\n"
		"\n"
		);
 	//str.LoadString(IDS_UPDATE_STR);
	str.Replace("\n", "\r\n");
	SetDlgItemText(IDC_UPDATE_CONTENT, str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////////////////////
// CSerialPortTestDlg dialog

CSerialPortTestDlg::CSerialPortTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSerialPortTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSerialPortTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bStopDis = FALSE;
	m_dwRecvCnt = 0;
	m_dwSendCnt = 0;
	m_bModifiedParam = FALSE;
	m_lasttick = 0;
	m_bSerialPortOpened = FALSE;
	m_autotime = 1000;
	m_cycletime = 1000;
	m_cyclesendindex = 0;
	m_hzi = 0;
	m_bSumAdd = FALSE;
	m_bHasTimeOut = TRUE;
	m_spacetime = 20;

	m_bDisHZ = TRUE;
}

void CSerialPortTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSerialPortTestDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_HIST, m_multibox);
}

BEGIN_MESSAGE_MAP(CSerialPortTestDlg, CDialog)
	//{{AFX_MSG_MAP(CSerialPortTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_OPEN_SERIALPORT, OnOpenSerialPortTest)
	ON_BN_CLICKED(IDC_MANUAL_SEND, OnManualSend)
	ON_BN_CLICKED(IDC_EMPTY_RECVBUF, OnEmptyRecvbuf)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_EMPTY_SENDBUF, OnEmptySendbuf)
	ON_BN_CLICKED(IDC_STOP_DIS, OnStopDis)
	ON_MESSAGE(WM_COMM_RXCHAR, OnReceiveData)
	ON_MESSAGE(WM_COMM_RW_ERROR, OnCommRWError)
	ON_MESSAGE(WM_COMM_TXEMPTY_DETECTED, OnCommTXEmptyDtd)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_REFRESH_COMM, OnRefreshComm)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
	ON_STN_DBLCLK(IDC_LOGO, &CSerialPortTestDlg::OnStnDbClickedLogo)
	ON_MESSAGE(WM_COMM_TIMEOUT, &CSerialPortTestDlg::OnCommTimeout)
	ON_WM_MEASUREITEM()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerialPortTestDlg message handlers

CString join(CStringArray& strArr, CString separator)
{
	int size = strArr.GetSize();
	if(size == 0) return "";
	if(size == 1) return strArr[0];

	CString str;
	int i;
	for(i=0; i < (size-1); i++)
	{
		str += strArr[i];
		str += separator;
	}
	str += strArr[i];
	return str;
}

void split(CString& str, CStringArray& strArr, CString separator)
{
	str.TrimLeft();
	str.TrimRight();
	int len = str.GetLength();
	LPTSTR p = str.GetBuffer(len);
	strArr.RemoveAll();

	int nStart=0;
	BOOL b = FALSE;
	int i;
	for(i=0; i<len; i++)
	{
		if(separator.Find(p[i]) >= 0){//是分隔字符.
			if(b){
				strArr.Add(str.Mid(nStart, i - nStart));
				b = FALSE;//忽略连续的分隔字符
			}
		/*	else if((p[i] != ' ') && (p[i] != '\t'))
			{
				strArr.Add(str.Mid(0, 0));
			}*/
		}else{//不是分隔字符
			if(FALSE == b){//判断是否是第一次遇到非分隔字符.
				b = TRUE;
				nStart = i;//保存开始位置
			}
		}
	}
	//最后一个字串,结尾不是分隔符的话.b为真.
	if(b)
	{
		strArr.Add(str.Mid(nStart, i-nStart));
	}
	else if((p[i] != ' ') && (p[i] != '\t'))
	{
		strArr.Add(str.Mid(0, 0));
	}

	str.ReleaseBuffer();
}

void EnumCOMMNum(CStringArray& strArr)
{
	HKEY hKey;
	strArr.RemoveAll();
	if(ERROR_SUCCESS ==
		RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\SERIALCOMM", NULL, KEY_READ, &hKey))
	{
		CString sValueName, sValue;
		DWORD dwValueNameLen;
		DWORD dwValueLen;
		DWORD dwValueNum;
		DWORD dsz = 256;
		RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL, &dwValueNum, NULL, NULL, NULL, NULL);
		for(DWORD i=0; i < dwValueNum; i++)
		{
			DWORD type = REG_SZ;
			dwValueNameLen = 256;
			dwValueLen = 256;
			DWORD retCode = RegEnumValue(hKey, i,
				sValueName.GetBuffer(dwValueNameLen), &dwValueNameLen, NULL, &type,
				(BYTE*)sValue.GetBuffer(dwValueLen), &dwValueLen);
			sValueName.ReleaseBuffer();
			sValue.ReleaseBuffer();
			if(retCode == ERROR_SUCCESS)
			{
				strArr.Add(sValue);
			}
			sValue.Empty();
			sValueName.Empty();
		}
	}
}

BOOL CSerialPortTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SendDlgItemMessage(IDC_SPIN2, UDM_SETRANGE, 0, MAKELPARAM(100, 0));

	OnRefreshComm();

	m_bModifiedParam = FALSE;

	SendDlgItemMessage(IDC_ENDIAN, CB_SETCURSEL, 0, 0);
	if(FALSE == ReadParamFile("a.ini"))
		DefaultParam();
	OpenSerialPort();
	SetDlgItemInt(IDC_RECV_COUNT, 0, 0);
	SetDlgItemInt(IDC_SEND_COUNT, 0, 0);
	SetTimer(IDC_SYS_TIME, 1000, NULL);
	OnTimer(IDC_SYS_TIME);

	SendDlgItemMessage(IDC_RECV_BUF, EM_LIMITTEXT, (WPARAM)-1, 0);

	((CComboBox*)GetDlgItem(IDC_HIST))->LimitText(1000);
	((CComboBox*)GetDlgItem(IDC_HIST))->SetItemHeight(-1, 18);
//	((CComboBox*)GetDlgItem(IDC_HIST))->SetHorizontalExtent(2000);
// 	m_multibox.SubclassDlgItem(IDC_HIST, this);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSerialPortTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSerialPortTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSerialPortTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString& Trim(CString& str)
{
	str.TrimLeft();
	str.TrimRight();
	return str;
}

int CSerialPortTestDlg::ReadParamFile(LPCSTR sFileName)
{
	BYTE n = 0x1f;
	int iRet = TRUE;
	CStdioFile file;
	BOOL bLastCOMExist = TRUE;
	if(FALSE == file.Open(sFileName, CFile::modeRead|CFile::typeText))
		return FALSE;

	CString sLine, stemp;
	CStringArray strArr;
	while(file.ReadString(sLine))
	{
		Trim(sLine);
		if((0 == sLine.CompareNoCase("[COM]")) && (n&0x01))
		{
			while(file.ReadString(sLine))
			{
				Trim(sLine);
				if(0 == sLine.CompareNoCase("[/COM]"))
				{
					n &=~ 0x01;
					break;
				}
				split(sLine, strArr, "=");
				stemp = strArr.GetAt(0);
				if(0 == stemp.CompareNoCase("COM"))
				{
					CString str(strArr.GetAt(1));
					split(str, strArr, ",");
					if(5 == strArr.GetSize())
					{
						if(CB_ERR == SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_SELECTSTRING,
							(WPARAM)(-1), (LPARAM)((LPCSTR)strArr.GetAt(0))))
						{//上次打开的串口现在不在了，打开第一个
							SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_SETCURSEL, 0, 0);
							//m_bModifiedParam = TRUE;
							bLastCOMExist  = FALSE;
						}
						if(CB_ERR == SendDlgItemMessage(IDC_BAUD_RATE, CB_SELECTSTRING,
							(WPARAM)(-1), (LPARAM)((LPCSTR)strArr.GetAt(1))))
							iRet = FALSE;
						if(CB_ERR == SendDlgItemMessage(IDC_DATA_BIT, CB_SELECTSTRING,
							(WPARAM)(-1), (LPARAM)((LPCSTR)strArr.GetAt(2))))
							iRet = FALSE;
						if(CB_ERR == SendDlgItemMessage(IDC_STOP_BIT, CB_SELECTSTRING,
							(WPARAM)(-1), (LPARAM)((LPCSTR)strArr.GetAt(3))))
							iRet = FALSE;
						if(CB_ERR == SendDlgItemMessage(IDC_CHECK_BIT, CB_SELECTSTRING,
							(WPARAM)(-1), (LPARAM)((LPCSTR)strArr.GetAt(4))))
							iRet = FALSE;
					}
					else
						iRet = FALSE;
				}
/*
				else if(0 == stemp.CompareNoCase("DTR"))
				{
					WPARAM i = atoi(strArr.GetAt(1));
					i = i ? BST_CHECKED: BST_UNCHECKED;
					SendDlgItemMessage(IDC_DTR, BM_SETCHECK, i, 0);
				}
*/
				else if(0 == stemp.CompareNoCase("RTS"))
				{
					WPARAM i = atoi(strArr.GetAt(1));
					//i = i ? BST_CHECKED: BST_UNCHECKED;
					//SendDlgItemMessage(IDC_RTS, BM_SETCHECK, i, 0);
					SendDlgItemMessage(IDC_RTS_FLOW, CB_SETCURSEL, i, 0);
				}
			}
		}
		else if((0 == sLine.CompareNoCase("[WATCH]")) && (n&0x02))
		{
			while(file.ReadString(sLine))
			{
				Trim(sLine);
				if(0 == sLine.CompareNoCase("[/WATCH]"))
				{
					n &=~ 0x02;
					break;
				}
				split(sLine, strArr, "=");
				if(0 == strArr[0].CompareNoCase("ENDIAN"))
				{
					if(0 == strArr[1].CompareNoCase("LITTLE ENDIDAN"))
						SendDlgItemMessage(IDC_ENDIAN, CB_SETCURSEL, 0, 0);
					else if(0 == strArr[1].CompareNoCase("BIG ENDIDAN"))
						SendDlgItemMessage(IDC_ENDIAN, CB_SETCURSEL, 1, 0);
					else if(0 == strArr[1].CompareNoCase("MODBUS"))
						SendDlgItemMessage(IDC_ENDIAN, CB_SETCURSEL, 2, 0);
					else
						SendDlgItemMessage(IDC_ENDIAN, CB_SETCURSEL, 0, 0);
				}
				else
				{
					int i;
					sscanf_s((LPCSTR)strArr[0], "[%d]", &i);
					if((i <= 7) && (i >= 0))
					{
						CString str(strArr[1]);
						split(str, strArr, ",");
						if(strArr.GetSize() == 3)
						{
							m_watch[i].offset = atoi(strArr[0]);
							str = strArr[1];
							Trim(str);
							m_watch[i].sType = str;
							m_watch[i].bHex = atoi(strArr[2]);
						}
						else
							iRet = FALSE;
					}
				}
			}
		}
		else if((0 == sLine.CompareNoCase("[SENDBUFF]")) && (n&0x04))
		{
			CComboBox* pbox = (CComboBox*)GetDlgItem(IDC_HIST);
			while(file.ReadString(sLine))
			{
				Trim(sLine);
				if(0 == sLine.CompareNoCase("[/SENDBUFF]"))
				{
					n &=~ 0x04;
					break;
				}
				split(sLine, strArr, "=");
				int i;
				sscanf_s((LPCSTR)strArr[0], "[%d]", &i);
				if(i < 15)
				{
					strArr.RemoveAt(0);
					CString str = join(strArr, "=");
					split(str, strArr, ",");
					if(strArr.GetSize() >= 2)
					{
						CString s1 = strArr[0];
						strArr.RemoveAt(0);
						str = join(strArr, ",");
						if(0 == i)
							str.Replace("\14", "\r\n");
						if(i >= 0)
							SetSendBuffContent(i, atoi((LPCSTR)s1), str);
						else if(400 > pbox->GetCount())//最多读400条
							pbox->AddString(str);
					}
// 					else
// 						iRet = FALSE;
				}
			}
		}
		else if((0 == sLine.CompareNoCase("[PARSER]")) && (n&0x10))
		{
			stemp.Empty();
			while(file.ReadString(sLine))
			{
				Trim(sLine);
				if(0 == sLine.CompareNoCase("[/PARSER]"))
				{
					n &=~ 0x10;
					Trim(stemp);
					SetDlgItemText(IDC_ERAUTO_EDIT, stemp);
					break;
				}
				stemp += sLine+"\r\n";
			}
		}
		else if((0 == sLine.CompareNoCase("[CONFIG]")) && (n&0x08))
		{
			while(file.ReadString(sLine))
			{
				Trim(sLine);
				if(0 == sLine.CompareNoCase("[/CONFIG]"))
				{
					n &=~ 0x08;
					break;
				}
				split(sLine, strArr, "=");
				WPARAM check = atoi(strArr[1]);
				check = check ? BST_CHECKED : BST_UNCHECKED;
				if(0 == strArr[0].CompareNoCase("HEXSEND"))
					SendDlgItemMessage(IDC_HEX_SEND, BM_SETCHECK, check, 0);
				else if(0 == strArr[0].CompareNoCase("HEXDIS"))
					SendDlgItemMessage(IDC_HEX_DIS, BM_SETCHECK, check, 0);
				else if(0 == strArr[0].CompareNoCase("USEWATCHES"))
					SendDlgItemMessage(IDC_USE_WATCHES, BM_SETCHECK, check, 0);
				else if(0 == strArr[0].CompareNoCase("VERIFY"))
				{
					WPARAM sum = BST_UNCHECKED;
					WPARAM xor = BST_UNCHECKED;
					WPARAM crc16ibm = BST_UNCHECKED;
					WPARAM crc16ccitt = BST_UNCHECKED;
					WPARAM crc32 = BST_UNCHECKED;
					WPARAM newline = BST_UNCHECKED;
					if(0 == strArr[1].CompareNoCase("SUM"))
						sum = BST_CHECKED;
					else if(0 == strArr[1].CompareNoCase("XOR"))
						xor = BST_CHECKED;
					else if(0 == strArr[1].CompareNoCase("CRC16IBM"))
						crc16ibm = BST_CHECKED;
					else if(0 == strArr[1].CompareNoCase("CRC16CCITT"))
						crc16ccitt = BST_CHECKED;
					else if(0 == strArr[1].CompareNoCase("CRC32"))
						crc32 = BST_CHECKED;
					else if(0 == strArr[1].CompareNoCase("NEWLINE"))
						newline = BST_CHECKED;
					SendDlgItemMessage(IDC_CHECK_SUM, BM_SETCHECK, sum, 0);
					SendDlgItemMessage(IDC_CHECK_XOR, BM_SETCHECK, xor, 0);
					SendDlgItemMessage(IDC_CHECK_CRC16_IBM, BM_SETCHECK, crc16ibm, 0);
					SendDlgItemMessage(IDC_CHECK_CRC16_CCITT, BM_SETCHECK, crc16ccitt, 0);
					SendDlgItemMessage(IDC_CHECK_CRC32, BM_SETCHECK, crc32, 0);
					SendDlgItemMessage(IDC_NEW_LINE_END, BM_SETCHECK, newline, 0);
					if(newline == BST_CHECKED)
					{
						SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_SETCHECK, BST_UNCHECKED, 0);
					}
				}
				else if(0 == strArr[0].CompareNoCase("INDEX"))
				{
					SetDlgItemText(IDC_CHECK_INDEX, strArr[1]);
				}
				else if(0 == strArr[0].CompareNoCase("HEXSENDCYCLE"))
					SendDlgItemMessage(IDC_GHEX_SEND, BM_SETCHECK, check, 0);
				else if(0 == strArr[0].CompareNoCase("CYCLETIME"))
					SetDlgItemText(IDC_CYCLE_TIME, strArr[1]);
				else if(0 == strArr[0].CompareNoCase("AUTOSENDTIME"))
					SetDlgItemText(IDC_AUTOSEND_TIME, strArr[1]);
				else if(0 == strArr[0].CompareNoCase("CHECKSUM_USEADD"))
				{
					if(0 == strArr[1].CompareNoCase("1"))
						m_bSumAdd = TRUE;
					else
						m_bSumAdd = FALSE;
				}
				else if(0 == strArr[0].CompareNoCase("MODBUS_SPACETIME"))
				{
					m_spacetime = atoi(strArr[1]);
					if(m_spacetime < 4) m_spacetime = 4;
					else if(m_spacetime > 2000) m_spacetime = 2000;
				}
				else if(0 == strArr[0].CompareNoCase("HIDESEND"))
					SendDlgItemMessage(IDC_HIDE_SEND, BM_SETCHECK, check, 0);
				else if(0 == strArr[0].CompareNoCase("SUFFIX"))
				{
					if(strArr.GetSize() >= 2)
					{
						strArr.RemoveAt(0);
						CString str = join(strArr, "=");
						SetDlgItemText(IDC_SUFFIX, (LPCTSTR)str);
					}
				}
				else if(0 == strArr[0].CompareNoCase("CHECKSUFFIX"))
				{
					SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_SETCHECK, check, 0);
					if(check == BST_CHECKED)
					{//些尾缀不能与换行尾缀同时存在
						SendDlgItemMessage(IDC_NEW_LINE_END, BM_SETCHECK, BST_UNCHECKED, 0);
					}
				}
				else if( 0 == strArr[0].CompareNoCase("DISHANZI"))
				{
					m_bDisHZ = !!check;
				}
			}
		}
		if(!n) break;
	}
	if(n)
		iRet = FALSE;
	ModifySelectAll();
	//上次打开的串口仍然存在，那么在这里就没有修改。
	//避免了在写发送缓冲区时，把m_bModifiedParam置成TRUE。导致每次都写配置文件。
	if(bLastCOMExist) m_bModifiedParam = FALSE;
	return iRet;
}

int CSerialPortTestDlg::SaveParamFile(LPCSTR sFileName)
{
	int iRet = TRUE;
	int i;
	CStdioFile file(sFileName, CFile::modeWrite|CFile::modeCreate|CFile::typeText);
	CString sLine, stemp;
	CStringArray strArr;
	file.WriteString("[Magic Serial port test program.]\n[author] = o07sai.\n\n[COM]\n");
	CString sComNum,sBaud,sDataBit,sStopBit,sCheck;
	int dtr=0,rts=0;
	GetDlgItemText(IDC_SERIALPORT_NUM, sComNum);
	Trim(sComNum);
	if(sComNum.IsEmpty())
		sComNum = "COM1";
	GetDlgItemText(IDC_BAUD_RATE, sBaud);
	GetDlgItemText(IDC_DATA_BIT, sDataBit);
	GetDlgItemText(IDC_STOP_BIT, sStopBit);
	GetDlgItemText(IDC_CHECK_BIT, sCheck);
// 	dtr = SendDlgItemMessage(IDC_DTR, BM_GETCHECK, 0, 0);
// 	rts = SendDlgItemMessage(IDC_RTS, BM_GETCHECK, 0, 0);
	rts = SendDlgItemMessage(IDC_RTS_FLOW, CB_GETCURSEL, 0, 0);
	sLine.Format("COM=%s,%s,%s,%s,%s\n",
		(LPCSTR)sComNum,
		(LPCSTR)sBaud,
		(LPCSTR)sDataBit,
		(LPCSTR)sStopBit,
		(LPCSTR)sCheck
		);
	file.WriteString(sLine);
	//sLine.Format("DTR=%d\nRTS=%d\n[/COM]\n", dtr, rts);
	sLine.Format("RTS=%d\n[/COM]\n", rts);
	file.WriteString(sLine);

	file.WriteString("[WATCH]\nENDIAN=");
	char* s[]={"LITTLE ENDIAN\n", "BIG ENDIAN\n", "MODBUS\n"};
	file.WriteString(s[SendDlgItemMessage(IDC_ENDIAN, CB_GETCURSEL, 0, 0)]);
	for(i=0; i<ARRAYSIZE(m_watch); i++)
	{
		sLine.Format("[%d]=%d,%s,%d\n", i, m_watch[i].offset, (LPCSTR)(m_watch[i].sType), m_watch[i].bHex);
		file.WriteString(sLine);
	}
	file.WriteString("[/WATCH]\n[SENDBUFF]\n");
	for(i=0; i<15; i++)
	{
		sLine.Format("[%d]=%d,%s\n", i, GetWeatherSelByIndex(i), GetSendBuffContent(i, stemp));
		if(0 == i)
		{
			sLine.Replace("\r\n", "\14");
		}
		file.WriteString(sLine);
	}
	CComboBox* pbox = (CComboBox*)GetDlgItem(IDC_HIST);
	int cnt = pbox->GetCount();
	for(i=0; i<cnt; i++)
	{
		pbox->GetLBText(i, stemp);
		sLine.Format("[-1]=0,%s\n", stemp);
		file.WriteString(sLine);
	}
	file.WriteString("[/SENDBUFF]\n[PARSER]\n");
	UINT32 len = SendDlgItemMessage(IDC_ERAUTO_EDIT, WM_GETTEXTLENGTH);
	len += 8;
	GetDlgItemText(IDC_ERAUTO_EDIT, stemp.GetBuffer(len), len);
	stemp.ReleaseBuffer();
	stemp.Replace("\r\n", "\n");
	Trim(stemp);
	stemp += "\n";
	file.WriteString(stemp);
	file.WriteString("[/PARSER]\n[CONFIG]\n");
	sLine.Format("HEXSEND=%d\n", SendDlgItemMessage(IDC_HEX_SEND, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);
	sLine.Format("HEXDIS=%d\n", SendDlgItemMessage(IDC_HEX_DIS, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);
	stemp = "NULL";
	if(SendDlgItemMessage(IDC_CHECK_SUM, BM_GETCHECK, 0, 0))
		stemp = "SUM";
	if(SendDlgItemMessage(IDC_CHECK_XOR, BM_GETCHECK, 0, 0))
		stemp = "XOR";
	if(SendDlgItemMessage(IDC_CHECK_CRC16_IBM, BM_GETCHECK, 0, 0))
		stemp = "CRC16IBM";
	if(SendDlgItemMessage(IDC_CHECK_CRC16_CCITT, BM_GETCHECK, 0, 0))
		stemp = "CRC16CCITT";
	if(SendDlgItemMessage(IDC_CHECK_CRC32, BM_GETCHECK, 0, 0))
		stemp = "CRC32";
	if(SendDlgItemMessage(IDC_NEW_LINE_END, BM_GETCHECK, 0, 0))
		stemp = "NEWLINE";
	sLine.Format("VERIFY=%s\n", (LPCSTR)stemp);
	file.WriteString(sLine);

	GetDlgItemText(IDC_CHECK_INDEX, stemp);
	sLine.Format("INDEX=%s\n", stemp);
	file.WriteString(sLine);

	sLine.Format("HEXSENDCYCLE=%d\n", SendDlgItemMessage(IDC_GHEX_SEND, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);
	sLine.Format("CYCLETIME=%d\n", GetDlgItemInt(IDC_CYCLE_TIME));
	file.WriteString(sLine);
	sLine.Format("AUTOSENDTIME=%d\n", GetDlgItemInt(IDC_AUTOSEND_TIME));
	file.WriteString(sLine);

	sLine.Format("USEWATCHES=%d\n", SendDlgItemMessage(IDC_USE_WATCHES, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);

	if(m_bSumAdd)
		sLine = "CHECKSUM_USEADD=1\n";
	else
		sLine = "CHECKSUM_USEADD=0\n";
	file.WriteString(sLine);

	sLine.Format("MODBUS_SPACETIME=%d\n", m_spacetime);
	file.WriteString(sLine);

	sLine.Format("HIDESEND=%d\n", SendDlgItemMessage(IDC_HIDE_SEND, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);

	sLine.Format("CHECKSUFFIX=%d\n", SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_GETCHECK, 0, 0));
	file.WriteString(sLine);

	GetDlgItemText(IDC_SUFFIX, stemp);
	sLine.Format("SUFFIX=%s\n", (LPCSTR)stemp);
	file.WriteString(sLine);

	sLine.Format("DISHANZI=%d\n", m_bDisHZ);
	file.WriteString(sLine);

	file.WriteString("[/CONFIG]\n");
	return iRet;
}

int CSerialPortTestDlg::SetSendBuffContent(int index, int bSelected, CString &str)
{
	if(0 == index)
		SetDlgItemText(IDC_SEND_BUF, str);
	else
	{
		int id = IDC_MEM_1 + index - 1;
		SetDlgItemText(id, str);
		id = IDC_CHECK_MEM1 + index - 1;
		SendDlgItemMessage(id, BM_SETCHECK, bSelected ? BST_CHECKED : BST_UNCHECKED, 0);
	}
	return 0;
}


CString& CSerialPortTestDlg::GetSendBuffContent(int index, CString& str)
{
	int id;
	if(0 == index)
	{
		id = IDC_SEND_BUF;
	}
	else
	{
		id = IDC_MEM_1 + index - 1;
	}
	UINT32 len = SendDlgItemMessage(id, WM_GETTEXTLENGTH);
	len += 8;
	GetDlgItemText(id, str.GetBuffer(len), len);
	str.ReleaseBuffer();
	return str;
}

int CSerialPortTestDlg::GetWeatherSelByIndex(int index)
{
	if(index)
	{
		return SendDlgItemMessage(IDC_CHECK_MEM1 + index - 1, BM_GETCHECK, 0, 0);
	}
	return BST_UNCHECKED;
}


void CSerialPortTestDlg::OnDestroy()
{
	KillTimer(IDC_SYS_TIME);
	KillTimer(IDC_AUTO_SEND);
	KillTimer(IDC_G_CYCLE_SEND);
	if(m_bModifiedParam)
		SaveParamFile("a.ini");
	CDialog::OnDestroy();

	// TODO: Add your message handler code here

}

void CSerialPortTestDlg::OnOpenSerialPortTest()
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_OPEN_SERIALPORT, str);
	if(0 == str.CompareNoCase("关闭串口"))
	{
		m_serialPort.ClosePort();
		SetPromptWhenOpenOrClose(FALSE);
	}
	else
	{
		OpenSerialPort();
	}
}

void CSerialPortTestDlg::OnManualSend()
{
	// TODO: Add your control notification handler code here
	SendBuffContent(0);
}

void CSerialPortTestDlg::OnEmptyRecvbuf()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_RECV_BUF, NULL);
	::SetFocus(GetDlgItem(IDC_RECV_BUF)->GetSafeHwnd());
}

void CSerialPortTestDlg::OnAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CSerialPortTestDlg::OnEmptySendbuf()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_SEND_BUF, NULL);
	::SetFocus(GetDlgItem(IDC_SEND_BUF)->GetSafeHwnd());
}

void CSerialPortTestDlg::OnStopDis()
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_STOP_DIS, str.GetBuffer(30), 30);
	str.ReleaseBuffer();
	if(0 == str.CompareNoCase("停止显示"))
	{
		SetDlgItemText(IDC_STOP_DIS, "继续显示");
		m_bStopDis = TRUE;
	}
	else
	{
		SetDlgItemText(IDC_STOP_DIS, "停止显示");
		m_bStopDis = FALSE;
	}
}


BOOL CSerialPortTestDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class
	WORD id = LOWORD(wParam);
	switch(HIWORD(wParam))
	{
	case BN_CLICKED:
		if(id >= IDC_WATCH_BTN1 && id <= IDC_WATCH_BTN8)
		{
			RECT rc;
			GetDlgItem(id)->GetWindowRect(&rc);
			CWatchAttriDlg watch;
			watch.m_xpos = rc.right;
			watch.m_ypos = rc.bottom;
			watch.m_pWatch = &m_watch[id - IDC_WATCH_BTN1];
			watch.DoModal();
			m_bModifiedParam = watch.m_bModified;
			break;
		}
		else if(id >= IDC_SEND_MEM1 && id <= IDC_SEND_MEM14)
		{
			SendBuffContent(id - IDC_SEND_MEM1 + 1);
		}
		else if(id >= IDC_CHECK_MEM1 && id <= IDC_CHECK_MEM14)
		{
			ModifySelectAll();
			m_bModifiedParam = TRUE;
		}
		else
		{
			switch(id)
			{
			case IDC_GHEX_SEND:
			case IDC_HEX_DIS:
			case IDC_HEX_SEND:
			case IDC_USE_WATCHES:
				m_bModifiedParam = TRUE;
				break;
			case IDC_SELECT_ALL:
				SetSelectAll();
				break;
/*
			case IDC_DTR:
			case IDC_RTS:
				SendDlgItemMessage(IDC_AUTO_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
				SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
				KillTimer(IDC_AUTO_SEND);
				KillTimer(IDC_G_CYCLE_SEND);
				OpenSerialPort();
				m_bModifiedParam = TRUE;
				break;
*/
			case IDC_CHECK_SUM:
			case IDC_CHECK_XOR:
			case IDC_CHECK_CRC16_IBM:
			case IDC_CHECK_CRC16_CCITT:
			case IDC_CHECK_CRC32:
			case IDC_NEW_LINE_END:
				if(SendDlgItemMessage(id, BM_GETCHECK, 0, 0))
				{
					WORD ids[] = {IDC_CHECK_SUM, IDC_CHECK_XOR,
						IDC_CHECK_CRC16_IBM, IDC_CHECK_CRC16_CCITT, IDC_CHECK_CRC32,IDC_NEW_LINE_END};
					int i;
					for(i=0; i<ARRAYSIZE(ids); i++)
					{
						if(id != ids[i])//选择其中一个后，其它都需要取消，不能同时存在。
							SendDlgItemMessage(ids[i], BM_SETCHECK, BST_UNCHECKED, 0);
					}
				}
				m_bModifiedParam = TRUE;
				if(SendDlgItemMessage(IDC_NEW_LINE_END, BM_GETCHECK, 0, 0))
				{//选择了换行尾缀，就取消通用的帧尾缀
					SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_SETCHECK, BST_UNCHECKED, 0);
				}
				break;
			case IDC_CHECK_SUFFIX:
				if(SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_GETCHECK, 0, 0))
				{//选择了换行尾缀，就取消通用的帧尾缀
					SendDlgItemMessage(IDC_NEW_LINE_END, BM_SETCHECK, BST_UNCHECKED, 0);
				}
				break;
			case IDC_AUTO_SEND:
				if(SendDlgItemMessage(IDC_AUTO_SEND, BM_GETCHECK, 0, 0))
				{
					int t = GetDlgItemInt(IDC_AUTOSEND_TIME);
					if(t < 10) t = 10;
					SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
					SetTimer(IDC_AUTO_SEND, t, NULL);
					OnTimer(IDC_AUTO_SEND);
					KillTimer(IDC_G_CYCLE_SEND);
				}
				else
				{
					KillTimer(IDC_AUTO_SEND);
				}
				break;
			case IDC_G_CYCLE_SEND:
				if(SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_GETCHECK, 0, 0))
				{
					if(BST_UNCHECKED == SendDlgItemMessage(IDC_SELECT_ALL, BM_GETCHECK, 0, 0))
					{
						SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
						break;//一个都没选择,就不自动发送了.
					}
					int t = GetDlgItemInt(IDC_CYCLE_TIME);
					if(t < 10) t = 10;
					SendDlgItemMessage(IDC_AUTO_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
					SetTimer(IDC_G_CYCLE_SEND, t, NULL);
					OnTimer(IDC_G_CYCLE_SEND);
					KillTimer(IDC_AUTO_SEND);
				}
				else
				{
					m_cyclesendindex = 0;
					KillTimer(IDC_G_CYCLE_SEND);
				}
				break;
			case IDC_RAUTO_EN:
				if(!SendDlgItemMessage(IDC_RAUTO_EN, BM_GETCHECK, 0, 0))
				{
					GetDlgItem(IDC_LOGO)->ShowWindow(TRUE);
					GetDlgItem(IDC_RAUTO_EN)->ShowWindow(FALSE);
					GetDlgItem(IDC_SAUTOBOX)->ShowWindow(FALSE);
					GetDlgItem(IDC_ERAUTO_EDIT)->ShowWindow(FALSE);
				}
				break;
			default:
				break;
			}
		}
		break;
	case CBN_SELCHANGE:
		switch(id)
		{
		case IDC_SERIALPORT_NUM:
		case IDC_BAUD_RATE:
		case IDC_DATA_BIT:
		case IDC_STOP_BIT:
		case IDC_CHECK_BIT:
		case IDC_RTS_FLOW:
			SendDlgItemMessage(IDC_AUTO_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
			SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
			KillTimer(IDC_AUTO_SEND);
			KillTimer(IDC_G_CYCLE_SEND);
			OpenSerialPort();
			m_bModifiedParam = TRUE;
			break;
		case IDC_HIST://选择了历史发送数据
			SendBuffContent(IDC_HIST);
			break;
		default:
			break;
		}
		break;
	case EN_CHANGE:
		if(((id >= IDC_MEM_1) && (id <= IDC_MEM_14)) ||
			(id == IDC_SEND_BUF) || (id == IDC_ERAUTO_EDIT))
			m_bModifiedParam = TRUE;
		break;
	default:
		break;
	}
	return CDialog::OnCommand(wParam, lParam);
}

#define NUM2CHAR(n)		((char)((n<10) ? ('0'+n) : ('A'+n-10)))

WORD _crc16_IBM(const void* data, DWORD len, WORD crc);
WORD _crc16_CCITT(const void* data, DWORD len, WORD crc);
DWORD _crc32_IEEE(const void* data, DWORD len, DWORD crc);

void CSerialPortTestDlg::SendBuffContent(int index)
{
	if(FALSE == m_bSerialPortOpened) return;
	CString str;
	int id;
	BOOL bHex;
	if((index >= 0) && (index <= 14))
	{
		if(index){
			id = IDC_MEM_1 + index - 1;
			bHex = SendDlgItemMessage(IDC_GHEX_SEND, BM_GETCHECK, 0, 0);
		}else{
			id = IDC_SEND_BUF;
			bHex = SendDlgItemMessage(IDC_HEX_SEND, BM_GETCHECK, 0, 0);
		}
		GetDlgItem(id)->GetWindowText(str);
		CComboBox* pbox = (CComboBox*)GetDlgItem(IDC_HIST);
		int sel = pbox->FindStringExact(-1, str);
		if(sel >= 0){//找到
			if(sel){//不在第一个。
				pbox->DeleteString(sel);
				pbox->InsertString(0, str);//插入到第一个。
				m_bModifiedParam = TRUE;
			}
		}else{//没找到
			int cnt  = pbox->GetCount();
			if(cnt >= 400)//最多缓存400个
				pbox->DeleteString(cnt - 1);
			pbox->InsertString(0, str);//插入到第一个。
			m_bModifiedParam = TRUE;
		}
	}
	else if(index == IDC_HIST)
	{
		bHex = SendDlgItemMessage(IDC_GHEX_SEND, BM_GETCHECK, 0, 0);
		CComboBox* pbox = (CComboBox*)GetDlgItem(IDC_HIST);
		int sel = pbox->GetCurSel();
		if(sel >= 0)
			pbox->GetLBText(sel, str);
		else return;
		if(sel > 0)
		{
			pbox->DeleteString(sel);
			pbox->InsertString(0, str);//插入到第一个。
			pbox->SetCurSel(0);
			m_bModifiedParam = TRUE;
		}
	}
	else
		return;
	BYTE pBuff[4096];// = NULL;// = (BYTE*)malloc(2048);

	int len = TransBuff(bHex, str, pBuff, 2048);
	if(len <= 0) return;
	int offset = GetDlgItemInt(IDC_CHECK_INDEX, NULL, FALSE);
	if(SendDlgItemMessage(IDC_CHECK_SUM, BM_GETCHECK, 0, 0))
	{//求和校验
		BYTE sum = 0;
		int i;
		if(m_bSumAdd)
		{
			for(i=offset; i<len; i++)
			{
				sum += pBuff[i];
			}
		}
		else
		{
			for(i=offset; i<len; i++)
			{
				sum -= pBuff[i];
			}
		}
		pBuff[len] = sum;
		len += 1;
	}
	else if(SendDlgItemMessage(IDC_CHECK_XOR, BM_GETCHECK, 0, 0))
	{//异或校验
		int i;
		BYTE sum = pBuff[offset];
		for(i=offset+1; i<len; i++)
		{
			sum ^= pBuff[i];
		}
		pBuff[len] = sum;
		len += 1;
	}
	else if(SendDlgItemMessage(IDC_CHECK_CRC16_IBM, BM_GETCHECK, 0, 0))
	{//CRC16IBM
		WORD crc16 = _crc16_IBM(pBuff+offset, len - offset, (WORD)-1);
		pBuff[len] = LOBYTE(crc16);
		pBuff[len+1] = HIBYTE(crc16);
		len += 2;
	}
	else if(SendDlgItemMessage(IDC_CHECK_CRC16_CCITT, BM_GETCHECK, 0, 0))
	{//CRC16CCITT
		WORD crc16 = _crc16_CCITT(pBuff+offset, len - offset, (WORD)-1);
		pBuff[len] = LOBYTE(crc16);
		pBuff[len+1] = HIBYTE(crc16);
		len += 2;
	}
	else if(SendDlgItemMessage(IDC_CHECK_CRC32, BM_GETCHECK, 0, 0))
	{//CRC32
		DWORD crc32 = _crc32_IEEE(pBuff+offset, len - offset, (DWORD)-1);
		pBuff[len] = LOBYTE(LOWORD(crc32));
		pBuff[len+1] = HIBYTE(LOWORD(crc32));
		pBuff[len+2] = LOBYTE(HIWORD(crc32));
		pBuff[len+3] = HIBYTE(HIWORD(crc32));
		len += 4;
	}
	else if(SendDlgItemMessage(IDC_NEW_LINE_END, BM_GETCHECK, 0, 0))
	{
		pBuff[len] = 0x0D;
		pBuff[len+1] = 0x0A;
		len += 2;
	}
	if(SendDlgItemMessage(IDC_CHECK_SUFFIX, BM_GETCHECK, 0, 0))
	{
		CString str;
		GetDlgItemText(IDC_SUFFIX, str);
		int n = TransBuff(bHex, str, pBuff+len, 20);//添加尾缀功能，在校验之后
		len += n;
	}
	pBuff[len] = 0;
	SendBuff((LPCSTR)pBuff, len);
	if(BST_UNCHECKED == SendDlgItemMessage(IDC_HIDE_SEND, BM_GETCHECK, 0, 0))
	{
		CString stemp;
		if(SendDlgItemMessage(IDC_HEX_DIS, BM_GETCHECK, 0, 0))
		{//HEX 显示
			int i;
			for(i=0; i<len; i++)
			{
				stemp = stemp + NUM2CHAR((pBuff[i]>>4));
				stemp += NUM2CHAR((pBuff[i]&0x0F));
				stemp += ' ';
			}
		}
		else
		{//字符显示
			int i=0;
			for(i=0; i<len; i++)
			{
				if(!(pBuff[i]))
					pBuff[i] = 1;//0不能显示,却又是字串结束标识,替换成1,让后面的能显示出来.
			}
			stemp = pBuff;
		}
		stemp = "\r\n<<- " + stemp;
		AppendString2Dis(stemp);
	}
//	Sleep(1);
//	free(pBuff);
}

void CSerialPortTestDlg::SetSelectAll()
{
	int id = IDC_CHECK_MEM1;
	int sel = SendDlgItemMessage(IDC_SELECT_ALL, BM_GETCHECK, 0, 0);
	if(BST_INDETERMINATE == sel)
	{
		sel = BST_UNCHECKED;
		SendDlgItemMessage(IDC_SELECT_ALL, BM_SETCHECK, sel, 0);
	}
	while(id <= IDC_CHECK_MEM14) 
	{
		SendDlgItemMessage(id++, BM_SETCHECK, sel, 0);
	}
	m_bModifiedParam = TRUE;
}

void CSerialPortTestDlg::ModifySelectAll()
{
	int id = IDC_CHECK_MEM1;
	int i = 0;
	while(id <= IDC_CHECK_MEM14)
	{
		i += SendDlgItemMessage(id++, BM_GETCHECK, 0, 0);
	}
	if(0 == i)
		SendDlgItemMessage(IDC_SELECT_ALL, BM_SETCHECK, BST_UNCHECKED, 0);
	else if(14 == i)
		SendDlgItemMessage(IDC_SELECT_ALL, BM_SETCHECK, BST_CHECKED, 0);
	else
		SendDlgItemMessage(IDC_SELECT_ALL, BM_SETCHECK, BST_INDETERMINATE, 0);
}

void CSerialPortTestDlg::OpenSerialPort()
{
	CString str;
	int iret = FALSE;
	int portnum = 1;
	int baudrate = 9600;
	int databit = 8;
	int stopbit = 0;
// 	int dtr = 1;
	int rts = 1;
	char parity = 'N';

	GetDlgItemText(IDC_SERIALPORT_NUM, str.GetBuffer(10), 10);
	str.ReleaseBuffer();
	if(4 > str.GetLength())
		goto __end;
	portnum = atoi(((LPCTSTR)str) + 3);

	databit = GetDlgItemInt(IDC_DATA_BIT);

	stopbit = SendDlgItemMessage(IDC_STOP_BIT, CB_GETCURSEL, 0, 0);

	GetDlgItemText(IDC_CHECK_BIT, str.GetBuffer(10), 10);
	str.ReleaseBuffer();
	str.MakeUpper();
	parity = str[0];

	baudrate = GetDlgItemInt(IDC_BAUD_RATE);
/*
	dtr = SendDlgItemMessage(IDC_DTR, BM_GETCHECK, 0, 0);
	rts = SendDlgItemMessage(IDC_RTS, BM_GETCHECK, 0, 0);
*/
	rts = SendDlgItemMessage(IDC_RTS_FLOW, CB_GETCURSEL, 0, 0);

	iret = m_serialPort.InitPort(this, portnum, baudrate, parity, databit, stopbit,
		0, rts, EV_RXCHAR|EV_TXEMPTY, 1024);
	if(iret)
	{
		iret = m_serialPort.StartMonitoring();
	}
__end:
	if(iret)
	{
		CString s;
		switch(stopbit)
		{
		default:
		case 0:
			s = "1";
			break;
		case 1:
			s = "1.5";
			break;
		case 2:
			s = "2";
			break;
		}
		str.Format(" -- COM%d,%d,%d,%c,%s",
			portnum, baudrate, databit, parity, (LPCSTR)s);
/*
		if(dtr)
			str += ",DTR";
		if(rts)
			str += ",RTS";
*/
		int spacetime = (int)((35000000)/baudrate+500)/1000;
		if(spacetime < m_spacetime)
			spacetime = m_spacetime;
		m_serialPort.SetTimeOut(spacetime);
		SetDlgItemText(IDC_SERIALPORT_STATE, "串口已打开" + str);
		SetWindowText(WIN_BASE_TEXT + str);
		SetPromptWhenOpenOrClose(TRUE);
	}
	else
	{
		SetPromptWhenOpenOrClose(FALSE);
	}
	return;
}

void CSerialPortTestDlg::DefaultParam()
{
	SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_SETCURSEL, 0, 0);
	SendDlgItemMessage(IDC_BAUD_RATE, CB_SETCURSEL, 3, 0);
	SendDlgItemMessage(IDC_DATA_BIT, CB_SETCURSEL, 3, 0);
	SendDlgItemMessage(IDC_STOP_BIT, CB_SETCURSEL, 0, 0);
	SendDlgItemMessage(IDC_CHECK_BIT, CB_SETCURSEL, 0, 0);
	SendDlgItemMessage(IDC_RTS_FLOW, CB_SETCURSEL, 1, 0);
/*
	SendDlgItemMessage(IDC_DTR, BM_SETCHECK, 1, 0);
	SendDlgItemMessage(IDC_RTS, BM_SETCHECK, 1, 0);
*/
	SendDlgItemMessage(IDC_HEX_SEND, BM_SETCHECK, BST_CHECKED, 0);
	SendDlgItemMessage(IDC_HEX_DIS, BM_SETCHECK, BST_CHECKED, 0);
	SendDlgItemMessage(IDC_CHECK_SUM, BM_SETCHECK, BST_CHECKED, 0);
	SetDlgItemInt(IDC_CHECK_INDEX, 0, 0);
	SendDlgItemMessage(IDC_GHEX_SEND, BM_SETCHECK, BST_CHECKED, 0);

	SetDlgItemInt(IDC_CYCLE_TIME, 1000, FALSE);
	SetDlgItemInt(IDC_AUTOSEND_TIME, 1000, FALSE);

	for(int i=0; i<ARRAYSIZE(m_watch); i++)
	{
		m_watch[i].offset = i;
		m_watch[i].sType = "UINT8";
		m_watch[i].bHex = TRUE;
	}
	m_bModifiedParam = TRUE;
	m_bDisHZ = TRUE;
}

LRESULT CSerialPortTestDlg::OnCommTXEmptyDtd(WPARAM wParam, LPARAM lParam)
{
	//在发送文件时，需要这个消息来触发发送文件剩下内容。

	return 1;
}

LRESULT CSerialPortTestDlg::OnCommRWError(WPARAM wParam, LPARAM lParam)
{
	m_serialPort.ClosePort();
	SetPromptWhenOpenOrClose(FALSE);
	return 1;
}


afx_msg LRESULT CSerialPortTestDlg::OnCommTimeout(WPARAM wParam, LPARAM lParam)
{
	if(!m_bStopDis)
	{
		CString str;
		if(m_hzi)
		{
			CString s((char)m_hzi);
			str = s;
			m_hzi = 0;
		}
		AppendString2Dis(str);
	}
	if(SendDlgItemMessage(IDC_USE_WATCHES, BM_GETCHECK, 0, 0))
		UpdateWatches(m_recvBag);
	if(SendDlgItemMessage(IDC_RAUTO_EN, BM_GETCHECK, 0, 0))
		AutoResp(m_recvBag);
	m_recvBag.RemoveAll();
	m_bHasTimeOut = TRUE;
	return 0;
}

LRESULT CSerialPortTestDlg::OnReceiveData(WPARAM wParam, LPARAM lParam)
{
	BYTE* cRecv = (BYTE*)wParam;
	WORD len = LOWORD(lParam);
//  	int systick = GetTickCount();
	m_dwRecvCnt+=len;
	SetDlgItemInt(IDC_RECV_COUNT, m_dwRecvCnt, FALSE);

// 	if(systick > (m_lasttick + m_spacetime))
// 	{
// 		if(!m_bStopDis)
// 		{
// 			CString str;
// 			if(m_hzi)
// 			{
// 				CString s((char)m_hzi);
// 				str = s;
// 				m_hzi = 0;
// 			}
// 			str += "\r\n->> ";
// 			AppendString2Dis(str);
// 		}
// 		if(SendDlgItemMessage(IDC_USE_WATCHES, BM_GETCHECK, 0, 0))
// 			UpdateWatches(m_recvBag);
// 		if(SendDlgItemMessage(IDC_RAUTO_EN, BM_GETCHECK, 0, 0))
// 			AutoResp(m_recvBag);
// 		m_recvBag.RemoveAll();
// 	}
	if((m_bHasTimeOut)&&(!m_bStopDis))
	{
		AppendString2Dis("\r\n->> ");
		m_bHasTimeOut = FALSE;
	}
	int i;
	if(!m_bStopDis)
	{
		if(SendDlgItemMessage(IDC_HEX_DIS, BM_GETCHECK, 0, 0))
		{
			CString str, s;
			s.Empty();
			for(i=0; i<len; i++)
			{
				str.Format("%02X ", cRecv[i]);
				s += str;
			}
			AppendString2Dis(s);
		}
		else
		{
			WORD n = len;
			BYTE* ps = (BYTE*)cRecv;
			if(m_hzi)
			{
				AppendChar2Dis(cRecv[0]);
				n--;
				ps++;
			}
/*
			if(n == 1)
			{
				//AppendChar2Dis(cRecv[1]);//这应该是0，字符显示时，第一个字符经常丢失。汉字时没有测试。
				AppendChar2Dis(cRecv[0]);//
			}
			else if(n > 1)
*/
			if(n > 0)
			{
				if(cRecv[len-1] < 0x80)
				{
					CString s((LPCSTR)ps, n);
					AppendString2Dis(s);
				}
				else
				{
					BYTE w=0;
					for(i=0; i<n; i++)
					{
						if(w)
							w = 0;
						else if(ps[i] >= 0x80)
							w = 1;
						else
							w = 0;
					}
					if(w) n--;
					if(n > 0)
					{
						CString s((LPCSTR)ps, n);
						AppendString2Dis(s);
					}
					if(w)
						AppendChar2Dis(cRecv[len-1]);
				}
			}
		}
	}
	for(i=0; i<len; i++)
		m_recvBag.Add(cRecv[i]);
// 	m_lasttick = systick;
	return 1;
}

void CSerialPortTestDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetDlgItem(IDC_RECV_COUNT)->GetWindowRect(rc);
	ClientToScreen(&point);
	if(rc.PtInRect(point))
	{
		m_dwRecvCnt = 0;
		SetDlgItemInt(IDC_RECV_COUNT, 0, 0);
	}
	else
	{
		GetDlgItem(IDC_SEND_COUNT)->GetWindowRect(rc);
		if(rc.PtInRect(point))
		{
			m_dwSendCnt = 0;
			SetDlgItemInt(IDC_SEND_COUNT, 0, 0);
		}
	}
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CSerialPortTestDlg::SendBuff(LPCSTR pBuff, int len)
{
	m_dwSendCnt += len;
	SetDlgItemInt(IDC_SEND_COUNT, m_dwSendCnt, FALSE);
	m_serialPort.WriteToPort((char*)pBuff, len);
}

void CSerialPortTestDlg::AppendString2Dis(LPCSTR str)
{
	if(m_bStopDis) return;
	int len = SendDlgItemMessage(IDC_RECV_BUF, WM_GETTEXTLENGTH, 0, 0);
	SendDlgItemMessage(IDC_RECV_BUF, EM_SETSEL, len, len);

	if(m_bDisHZ)//显示汉字(GBK编码)
		SendDlgItemMessage(IDC_RECV_BUF, EM_REPLACESEL, 0, (LPARAM)str);
	else
	{
		int n = strlen(str);
		char *buff = (char*)malloc(n+8);
		if(buff)
		{
			int i;
			for(i=0; i<n; i++)
			{
				if(str[i] < 0) buff[i] = 0x07;
				else buff[i] = str[i];
			}
			buff[i] = 0;
			SendDlgItemMessage(IDC_RECV_BUF, EM_REPLACESEL, 0, (LPARAM)buff);
			free(buff);
		}
	}
}

void CSerialPortTestDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case IDC_SYS_TIME:
	{
// 		static DWORD lastcnt=0;
// 		if(lastcnt == m_dwRecvCnt)
// 		{
// 			m_lasttick = 0;//一个帧结束.
// 			if(!m_bStopDis)
// 			{
// 				if(m_hzi)
// 				{
// 					CString s((char)m_hzi);
// 					m_hzi = 0;
// 					AppendString2Dis(s);
// 				}
// 			}
// 			m_hzi = 0;
// 			if(SendDlgItemMessage(IDC_USE_WATCHES, BM_GETCHECK, 0, 0))
// 				UpdateWatches(m_recvBag);
// 			if(SendDlgItemMessage(IDC_RAUTO_EN, BM_GETCHECK, 0, 0))
// 				AutoResp(m_recvBag);
// 			m_recvBag.RemoveAll();
// 		}
// 		lastcnt = m_dwRecvCnt;
		SYSTEMTIME t;
		GetLocalTime(&t);
		CString str;
		str.Format("%d-%02d-%02d %02d:%02d:%02d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
		GetDlgItem(IDC_SYS_TIME)->SetWindowText(str);
	}
	break;
	case IDC_AUTO_SEND:
		SendBuffContent(0);
		break;
	case IDC_G_CYCLE_SEND:
		{
			WORD checkid = IDC_CHECK_MEM1;
			if(BST_UNCHECKED == SendDlgItemMessage(IDC_SELECT_ALL, BM_GETCHECK, 0, 0))
			{
				KillTimer(IDC_G_CYCLE_SEND);
				m_cyclesendindex = 0;
				break;
			}
			while(BST_UNCHECKED == SendDlgItemMessage(checkid + m_cyclesendindex, BM_GETCHECK, 0, 0))
			{
				m_cyclesendindex++;
				if(m_cyclesendindex >= 14)
					m_cyclesendindex = 0;
			}
			SendBuffContent(m_cyclesendindex + 1);
			m_cyclesendindex++;
			if(m_cyclesendindex >= 14)
				m_cyclesendindex = 0;
		}
		break;
	default:
		break;
	}
//	CDialog::OnTimer(nIDEvent);
}

void CSerialPortTestDlg::UpdateWatches(CByteArray& recvbag)
{
	int len = recvbag.GetSize();
	BYTE* pbuff = recvbag.GetData();
	int i;
	
	if(NULL == pbuff) return;
	ENDIAN end = (ENDIAN)SendDlgItemMessage(IDC_ENDIAN, CB_GETCURSEL, 0, 0);

	for(i=0; i<ARRAYSIZE(m_watch); i++)
	{
		if(m_watch[i].bHex)
		{
			CString str;
			if(0 == m_watch[i].sType.CompareNoCase("UINT8") ||
				0 == m_watch[i].sType.CompareNoCase("SINT8")||
				0 == m_watch[i].sType.CompareNoCase("CHAR"))
			{
				if(m_watch[i].offset >= len) continue;
				str.Format("%02X", pbuff[m_watch[i].offset]);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("UINT16") ||
				0 == m_watch[i].sType.CompareNoCase("SINT16"))
			{
				if(m_watch[i].offset >= (len - 1)) continue;
				WORD wv; 
				ConvEndian(pbuff+m_watch[i].offset, &wv, end);
				//str.Format("%02X", wv);
				str.Format("%04X", wv);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("UINT32") ||
				0 == m_watch[i].sType.CompareNoCase("SINT32") ||
				0 == m_watch[i].sType.CompareNoCase("FLOAT"))
			{
				if(m_watch[i].offset >= (len - 3)) continue;
				DWORD dwv;
				ConvEndian(pbuff+m_watch[i].offset, &dwv, end);
				//str.Format("%02X", *(DWORD*)(pbuff+m_watch[i].offset));
				str.Format("%08X", dwv);
			}
			SetDlgItemText(IDC_WATCH1+i, str);
		}
		else
		{
			if(0 == m_watch[i].sType.CompareNoCase("UINT8"))
			{
				if(m_watch[i].offset >= len) continue;
				SetDlgItemInt(IDC_WATCH1+i, pbuff[m_watch[i].offset], FALSE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("UINT16"))
			{
				if(m_watch[i].offset >= (len - 1)) continue;
				WORD wv; 
				ConvEndian(pbuff+m_watch[i].offset, &wv, end);
				SetDlgItemInt(IDC_WATCH1+i, wv, FALSE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("UINT32"))
			{
				if(m_watch[i].offset >= (len - 3)) continue;
				DWORD dwv; 
				ConvEndian(pbuff+m_watch[i].offset, &dwv, end);
				SetDlgItemInt(IDC_WATCH1+i, dwv, FALSE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("SINT8"))
			{
				if(m_watch[i].offset >= (len)) continue;
				SetDlgItemInt(IDC_WATCH1+i, (DWORD)(int)*((char*)(pbuff+m_watch[i].offset)), TRUE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("SINT16"))
			{
				if(m_watch[i].offset >= (len - 1)) continue;
				WORD wv; 
				ConvEndian(pbuff+m_watch[i].offset, &wv, end);
				SetDlgItemInt(IDC_WATCH1+i, (int)((short)wv), TRUE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("SINT32"))
			{
				if(m_watch[i].offset >= (len - 3)) continue;
				DWORD dwv; 
				ConvEndian(pbuff+m_watch[i].offset, &dwv, end);
				SetDlgItemInt(IDC_WATCH1+i, dwv, TRUE);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("FLOAT"))
			{
				if(m_watch[i].offset >= (len - 3)) continue;
				float f;
				ConvEndian(pbuff+m_watch[i].offset, (DWORD*)&f, end);
				CString str;
				str.Format("%f", f);
				SetDlgItemText(IDC_WATCH1+i, str);
			}
			else if(0 == m_watch[i].sType.CompareNoCase("CHAR"))
			{
				if(m_watch[i].offset >= (len)) continue;
				CString str;
				str = (char)(pbuff[m_watch[i].offset]);
				SetDlgItemText(IDC_WATCH1+i, str);
			}
		}
	}
}


void CSerialPortTestDlg::SetPromptWhenOpenOrClose(BOOL bopenclose)
{
	m_bSerialPortOpened = bopenclose;
	if(bopenclose)//opened
	{
		SetDlgItemText(IDC_OPEN_SERIALPORT, "关闭串口");
		SendDlgItemMessage(IDC_B_CONNECTED, STM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(AfxFindResourceHandle(MAKEINTRESOURCE(IDB_FACE_HAPPY), RT_BITMAP),
			MAKEINTRESOURCE(IDB_FACE_HAPPY))
			);
	}
	else
	{
		SetDlgItemText(IDC_OPEN_SERIALPORT, "打开串口");
		SetWindowText(WIN_BASE_TEXT);
		SetDlgItemText(IDC_SERIALPORT_STATE, "串口已关闭");
		SendDlgItemMessage(IDC_B_CONNECTED, STM_SETIMAGE, IMAGE_BITMAP,
			(LPARAM)LoadBitmap(AfxFindResourceHandle(MAKEINTRESOURCE(IDB_FACE_SAD), RT_BITMAP),
			MAKEINTRESOURCE(IDB_FACE_SAD))
			);
		SendDlgItemMessage(IDC_AUTO_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
		SendDlgItemMessage(IDC_G_CYCLE_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
		KillTimer(IDC_AUTO_SEND);
		KillTimer(IDC_G_CYCLE_SEND);
	}
}

void CSerialPortTestDlg::AppendChar2Dis(BYTE c)
{
	if(m_bStopDis) return;
	BYTE s[3] = {0, 0, 0};
	if(m_hzi)
	{
		s[0] = m_hzi;
		s[1] = c?c:1;
		m_hzi = 0;
	}
	else
	{
		if(c >= 0x80)
		{
			m_hzi = c;
			return;
		}
		s[0] = c;
	}
	int len = SendDlgItemMessage(IDC_RECV_BUF, WM_GETTEXTLENGTH, 0, 0);
	SendDlgItemMessage(IDC_RECV_BUF, EM_SETSEL, len, len);
	SendDlgItemMessage(IDC_RECV_BUF, EM_REPLACESEL, 0, (LPARAM)s);
}

void CSerialPortTestDlg::OnRefreshComm() 
{
	// TODO: Add your control notification handler code here
	CStringArray strArr;
	if(FALSE == m_bSerialPortOpened)//这个注册表的键值,影响到串口报占用的问题.
		RegDeleteKey(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\COM Name Arbiter");
	EnumCOMMNum(strArr);
	SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_RESETCONTENT, 0, 0);
	for(int i=0; i < strArr.GetSize(); i++)
	{
		SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_ADDSTRING, 0, (DWORD)(LPCSTR(strArr.GetAt(i))));
	}
	if(strArr.GetSize())
		SendDlgItemMessage(IDC_SERIALPORT_NUM, CB_SETCURSEL, 0, 0);
}

void CSerialPortTestDlg::ConvEndian(BYTE *src, WORD *desc, ENDIAN end)
{
	switch(end)
	{
	case E_MODBUS:
	case E_BIGENDIAN:
		*desc = MAKEWORD(src[1], src[0]);
		break;
	case E_LITTLEENDIAN:
		*desc = MAKEWORD(src[0], src[1]);
	default:
		break;
	}
}

void CSerialPortTestDlg::ConvEndian(BYTE *src, DWORD *desc, ENDIAN end)
{
	switch(end)
	{
	case E_BIGENDIAN:
		*desc = MAKELONG(MAKEWORD(src[3], src[2]), MAKEWORD(src[1], src[0]));
		break;
	case E_LITTLEENDIAN:
		*desc = MAKELONG(MAKEWORD(src[0], src[1]), MAKEWORD(src[2], src[3]));
		break;
	case E_MODBUS:
		*desc = MAKELONG(MAKEWORD(src[1], src[0]), MAKEWORD(src[3], src[2]));
		break;
	default:
		break;
	}
}

void CSerialPortTestDlg::OnOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void CSerialPortTestDlg::OnStnDbClickedLogo()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LOGO)->ShowWindow(FALSE);
	GetDlgItem(IDC_RAUTO_EN)->ShowWindow(TRUE);
	GetDlgItem(IDC_SAUTOBOX)->ShowWindow(TRUE);
	GetDlgItem(IDC_ERAUTO_EDIT)->ShowWindow(TRUE);
}


int GetTokenString(const char ** ps, char* stoken);
int CSerialPortTestDlg::SendRightContent(CStringArray& sa)
{
	if(1 > sa.GetSize()) return 0;
	if(0 == sa[0].Compare("_H"))
	{
		if(sa.GetSize() != 4) return 0;
		SendDlgItemMessage(IDC_HEX_SEND, BM_SETCHECK, BST_CHECKED, 0);
		SetDlgItemText(IDC_SEND_BUF, sa[2]);
		SendBuffContent(0);
	}
	else if(0 == sa[0].Compare("_T"))
	{
		if(sa.GetSize() != 4) return 0;
		SendDlgItemMessage(IDC_HEX_SEND, BM_SETCHECK, BST_UNCHECKED, 0);
		SetDlgItemText(IDC_SEND_BUF, sa[2]);
		SendBuffContent(0);
	}
	else if(sa[0][0] == '$')
	{
		if(sa.GetSize() != 1) return 0;
		sa[0].Replace("$", "");
		int v;
		sscanf_s(sa[0].GetString(), "%d", &v);
		SendBuffContent(v);
	}
	return 1;
}

int CSerialPortTestDlg::AutoResp(CByteArray& sRecv)
{
	int len = sRecv.GetSize();
	if(0 == len) return 0;
	BYTE pbuff[4096];
	memcpy(pbuff, sRecv.GetData(), len);
	pbuff[len] = 0;
	int i;
	CString sLine, stemp;
	CStringArray strArr;

	GetDlgItem(IDC_ERAUTO_EDIT)->GetWindowText(stemp);
	Trim(stemp);
	split(stemp, strArr, "\r\n");

	char token[256];
	char pstr[4096];
	for(i=0; i<strArr.GetSize(); i++)
	{
		int l;
		BOOL bIndex = FALSE;
		sLine = strArr[i];
		l = sLine.GetLength();
		if(l >= 4096) break;
		memcpy(pstr, (LPCSTR)sLine, l);
		pstr[l]=0;
		const char* ps = pstr;
		CStringArray leftarr,rightarr;
		leftarr.RemoveAll();
		rightarr.RemoveAll();
		while(l = GetTokenString(&ps, token))
		{
			if(token[0] == '=') break;
			leftarr.Add(token);
		}
		while(l = GetTokenString(&ps, token))
		{
			rightarr.Add(token);
		}
		if(leftarr[0][0] == '$')
		{
			if(1 != leftarr.GetSize()) break;
			leftarr[0].Replace("$", "");
			int v;
			sscanf_s(leftarr[0].GetString(), "%d", &v);
			BYTE compbuff[4096];
			GetBuffContent(v, compbuff);
			if(0 == memcmp(compbuff, pbuff, len))
			{
				SendRightContent(rightarr);
			}
		}
		else if(0 == leftarr[0].Compare("_T"))
		{
			if(4 != leftarr.GetSize()) break;
			CString s1 = leftarr[2];
			CString s2(pbuff);
			Trim(s1);
			Trim(s2);
			if(s1 == s2)
			{
				SendRightContent(rightarr);
			}
		}
		else if(0 == leftarr[0].Compare("_H"))
		{
			if(4 != leftarr.GetSize()) break;
			CStringArray shex;
			split(leftarr[2], shex, " ,\t");
			BYTE hex[4096];
			int j;
			for(j=0; j<shex.GetSize(); j++)
			{
				int v;
				sscanf_s(LPCSTR(shex[i]), "%X", &v);
				hex[j] = (BYTE)v;
			}
			if(0 == memcmp(hex, pbuff, len))
			{
				SendRightContent(rightarr);
			}
		}
	}
	return 0;
}


void CSerialPortTestDlg::GetBuffContent(int index, BYTE* pbuff)
{
	if(FALSE == m_bSerialPortOpened) return;
	int id;
	BOOL bHex;
	if((index > 0) && (index <= 14))
	{
		id = IDC_MEM_1 + index - 1;
		bHex = SendDlgItemMessage(IDC_HEX_DIS, BM_GETCHECK, 0, 0);
	}
	else return;
	CString str;
	GetDlgItem(id)->GetWindowText(str);

	int len;
	if(bHex)
	{
		str.Replace("\n", "");
		str.Replace("\r", "");
		str.TrimLeft();
		str.TrimRight();
		if(0 == str.GetLength())
		{
			return;
		}
		CStringArray strarr;
		split(str, strarr, " ,\t");
		len = strarr.GetSize();
		if(len > 2048)
		{
			MessageBox("最多发送2048字节!");
			return;
		}
		for(int i=0; i<len; i++)
		{
			int v;
			sscanf_s(LPCSTR(strarr[i]), "%X", &v);
			pbuff[i] = (BYTE)v;
		}
	}
	else
	{//字符
		len = str.GetLength();
		if(0 == len)
		{
			return;
		}
		else if(len >2048)
		{
			MessageBox("最多发送2048字节!");
			return;
		}
		memcpy(pbuff, (LPCSTR)str, len);
	}
}

int CSerialPortTestDlg::TransBuff(BOOL bHex, CString &str, BYTE* pBuff, int size)
{
	int len;
	if(bHex)
	{//十六进制发送
		str.Replace("\n", "");
		str.Replace("\r", "");
		str.TrimLeft();
		str.TrimRight();
		if(0 == str.GetLength())
		{
			return 0;
		}
		CStringArray strarr;
		split(str, strarr, " ,\t");
		len = strarr.GetSize();
		if(len > size)
		{
			CString s;
			s.Format("最多发送%d字节!", size);
			MessageBox(s);
			return 0;
		}
		for(int i=0; i<len; i++)
		{
			int v;
			sscanf_s(LPCSTR(strarr[i]), "%X", &v);
			pBuff[i] = (BYTE)v;
		}
	}
	else
	{//字符发送
		len = str.GetLength();
		if(0 == len)
		{
			return 0;
		}
		else if(len >size)
		{
			CString s;
			s.Format("最多发送%d字节!", size);
			MessageBox(s);
			return 0;
		}
		memcpy(pBuff, (LPCSTR)str, len);
	}
	return len;
}

//end of file.



void CSerialPortTestDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
// 	if(nIDCtl == IDC_HIST)
// 	{
// 		m_multibox.MeasureItem(lpMeasureItemStruct);
// 		return;
// 	}
	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CSerialPortTestDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

//	CDialog::OnCancel();
}


void CSerialPortTestDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialog::OnOK();
}

