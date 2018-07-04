// MultiLineBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SerialPortTest.h"
#include "MultiLineBox.h"


// CMultiLineBox

IMPLEMENT_DYNAMIC(CMultiLineBox, CComboBox)

CMultiLineBox::CMultiLineBox()
{

}

CMultiLineBox::~CMultiLineBox()
{
}


BEGIN_MESSAGE_MAP(CMultiLineBox, CComboBox)
END_MESSAGE_MAP()



// CMultiLineBox ��Ϣ�������




void CMultiLineBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  ������Ĵ����Ի���ָ����
	if(lpDrawItemStruct->CtlType==ODT_COMBOBOX)  
	{  
		CDC dc;  
		dc.Attach(lpDrawItemStruct->hDC);  
		CRect rcClient = lpDrawItemStruct->rcItem;  
		UINT state = lpDrawItemStruct->itemState;  
		CBrush br;  
		if(state&ODS_SELECTED)  
		{  
			br.CreateSolidBrush(RGB(51,153,255));  
			dc.SetTextColor(RGB(255,255,255));  
		}  
		else  
		{  
// 			br.CreateSolidBrush(RGB(255,255,128));
			br.CreateSolidBrush(RGB(255,255,255));
			dc.SetTextColor(RGB(0,0,0));  
		}  
		dc.FillRect(&rcClient,&br);  
		dc.SetBkMode(TRANSPARENT);  
		//������ǿ���  
		if(lpDrawItemStruct->itemID!=(UINT)-1)  
		{  
			UINT id = lpDrawItemStruct->itemID;  
			CString strText;  
			GetLBText(id,strText);  

// 			::OutputDebugStringA("id str:" + strText + "\n");

			rcClient.DeflateRect(2,1); 

			dc.DrawText(strText, strText.GetLength(),&rcClient, DT_WORDBREAK| DT_EDITCONTROL);  
		}  
		dc.Detach();  
	}
}


void CMultiLineBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO:  ������Ĵ�����ȷ��ָ����Ĵ�С
// 	::OutputDebugStringA("MeasureItem\n");
	if( (lpMeasureItemStruct->CtlType==ODT_COMBOBOX)&&  
		(lpMeasureItemStruct->itemID!=(UINT)-1))  
	{  
		CString strText;  
		GetLBText(lpMeasureItemStruct->itemID,strText);
		CRect rcClient;
		GetClientRect(rcClient);
		
// 		CString str;
// 		str.Format("rect:%d,%d\n", rcClient.Width(), rcClient.Height());
// 		::OutputDebugStringA(str);
		
		CDC* pDC = GetDC();   
		rcClient.DeflateRect(2,1);  
		lpMeasureItemStruct->itemHeight = -16 + pDC->DrawText(strText, -1, rcClient, DT_WORDBREAK| DT_EDITCONTROL | DT_CALCRECT);   
		
// 		str.Format("height:%d\n", lpMeasureItemStruct->itemHeight);
// 		::OutputDebugStringA(str);
// 		str.Format("rect2:%d,%d\n", rcClient.Width(), rcClient.Height());
// 		::OutputDebugStringA(str);
		
		ReleaseDC(pDC);  
	} 
}
