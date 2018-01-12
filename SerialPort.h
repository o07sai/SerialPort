
#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#define WM_COMM_BREAK_DETECTED		WM_USER+1	// A break was detected on input.
#define WM_COMM_CTS_DETECTED		WM_USER+2	// The CTS (clear-to-send) signal changed state. 
#define WM_COMM_DSR_DETECTED		WM_USER+3	// The DSR (data-set-ready) signal changed state. 
#define WM_COMM_ERR_DETECTED		WM_USER+4	// A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. 
#define WM_COMM_RING_DETECTED		WM_USER+5	// A ring indicator was detected. 
#define WM_COMM_RLSD_DETECTED		WM_USER+6	// The RLSD (receive-line-signal-detect) signal changed state. 
#define WM_COMM_RXCHAR				WM_USER+7	// A character was received and placed in the input buffer. 
#define WM_COMM_RXFLAG_DETECTED		WM_USER+8	// The event character was received and placed in the input buffer.  
#define WM_COMM_TXEMPTY_DETECTED	WM_USER+9	// The last character in the output buffer was sent.  
#define WM_COMM_VERIFY_SN			WM_USER+10
#define WM_COMM_RW_ERROR			WM_USER+11	// When ReadFile or WriteFile error occurs,send this message.
#define WM_COMM_TIMEOUT				WM_USER+12	// When ReadFile or WriteFile error occurs,send this message.

class CSerialPort
{														 
public:
	DWORD m_nWriteSize;
	void ClosePort();
	// construction and destruction
	CSerialPort();
	virtual		~CSerialPort();

	void SetTimeOut(DWORD timeout_ms){m_dwTimerOut = timeout_ms;};
	// port initialization											
	BOOL InitPort(
			CWnd* pPortOwner,
			UINT portnr = 1,
			UINT baud = 1200,
			char parity = 'N',
			UINT databits = 8,
			UINT stopbits = 1,
			UINT DTRCtrl = 0,
			UINT RTSCtrl = 1,
			DWORD dwCommEvents = EV_RXCHAR,
			UINT writebuffersize = 1024
	);
	HANDLE				m_hComm;

	// start/stop comm watching
	BOOL		StartMonitoring();
	BOOL		RestartMonitoring();
	BOOL		StopMonitoring();

	DWORD		GetWriteBufferSize();
	DWORD		GetCommEvents();
	DCB			GetDCB();

	void		WriteToPort(char* string);
	void		WriteToPort(char* string,int n);
	void		WriteToPort(LPCTSTR string);
	void		WriteToPort(LPCTSTR string,int n);

protected:
	// protected member functions
	void		ProcessErrorMessage(char* ErrorText);
	static UINT	CommThread(LPVOID pParam);
	static void	ReceiveChar(CSerialPort* port);
	static void	WriteChar(CSerialPort* port);

	// thread
	CWinThread*			m_Thread;

	// synchronization objects
	CRITICAL_SECTION	m_csCommunicationSync;
	BOOL				m_bThreadAlive;

	// handles
	HANDLE				m_hWriteEvent;
	HANDLE				m_hShutdownEvent;

	// Event array. 
	// One element is used for each event. There are two event handles for each port.
	// A Write event and a receive character event which is located in the overlapped structure (m_ov.hEvent).
	// There is a general shutdown when the port is closed. 
	HANDLE				m_hEventArray[3];

	// structures
	OVERLAPPED			m_ov;
	COMMTIMEOUTS		m_CommTimeouts;
	DCB					m_dcb;

	// owner window
	CWnd*				m_pOwner;

	// misc
	UINT				m_nPortNr;
	char*				m_szWriteBuffer;
	DWORD				m_dwCommEvents;
	DWORD				m_nWriteBufferSize;

	DWORD	m_dwTimerOut;//用于在MODBUS通信时，帧间隔判断，主动发送帧结束消息（超时消息）
	DWORD	m_dwLastTime;//最后一次接收数据的时间
	BOOL	m_bHasRecieved;//表示之前有接收到过数据。
};

#endif __SERIALPORT_H__


