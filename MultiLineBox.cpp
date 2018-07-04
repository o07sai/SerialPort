// MultiLineBox.cpp : 实现文件
//

#include "stdafx.h"
#include "SerialPortTest.h"
#include "MultiLineBox.h"


// CMultiLineBox

IMPLEMENT_DYNAMIC(CMultiLineBox, CComboBox)

CMultiLineBox::CMultiLineBox()
{
	m_pfont = NULL;
}

CMultiLineBox::~CMultiLineBox()
{
}


BEGIN_MESSAGE_MAP(CMultiLineBox, CComboBox)
END_MESSAGE_MAP()



// CMultiLineBox 消息处理程序




void CMultiLineBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  添加您的代码以绘制指定项
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
			if(lpDrawItemStruct->itemID & 0x01)
				br.CreateSolidBrush(RGB(255,255,255));
			else
				br.CreateSolidBrush(RGB(196,232,253));

			dc.SetTextColor(RGB(0,0,0));  
		}  
		dc.FillRect(&rcClient,&br);  
		dc.SetBkMode(TRANSPARENT);  
		
		if(lpDrawItemStruct->itemState & ODS_COMBOBOXEDIT)
		{
			if(lpDrawItemStruct->itemID!=(UINT)-1)
			{
				UINT id = lpDrawItemStruct->itemID;  
				CString strText;  
				GetLBText(id,strText);
				dc.DrawText(strText, -1,&rcClient, DT_LEFT); 
			}
		}
		else if(lpDrawItemStruct->itemID!=(UINT)-1)  
		{  
			UINT id = lpDrawItemStruct->itemID;  
			CString strText,str;  
			GetLBText(id,strText);

			str.Format("drawitem rect:%d,%d,%d,%d\n",
				rcClient.left, rcClient.top, rcClient.right, rcClient.bottom);
			::OutputDebugStringA(str);

 			rcClient.DeflateRect(2,1);

			CRect rc=rcClient;
			dc.DrawText(strText, -1, rc, DT_WORDBREAK| DT_EDITCONTROL | DT_CALCRECT);
			SetItemHeight(id, rc.Height()+4);

			rcClient.top += 1;
			dc.DrawText(strText, -1,&rcClient, DT_WORDBREAK| DT_EDITCONTROL);  
		}  
		dc.Detach();  
	}
}


void CMultiLineBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO:  添加您的代码以确定指定项的大小
// 	::OutputDebugStringA("MeasureItem\n");
	if( (lpMeasureItemStruct->CtlType==ODT_COMBOBOX)&&  
		(lpMeasureItemStruct->itemID!=(UINT)-1))  
	{  
		CString strText,str;  
		GetLBText(lpMeasureItemStruct->itemID,strText);
		CRect rcClient;
		GetClientRect(rcClient);

		str.Format("MeasureItem rect:%d,%d,%d,%d\n",
			rcClient.left, rcClient.top, rcClient.right, rcClient.bottom);
		::OutputDebugStringA(str);

		rcClient.right += 20;
		
		CDC* pDC = GetDC();//这个dc和上面函数里的dc不同，计算高度有误差。
 		rcClient.DeflateRect(2,1);  
		lpMeasureItemStruct->itemHeight = pDC->DrawText(strText, -1, rcClient, DT_WORDBREAK| DT_EDITCONTROL | DT_CALCRECT);   
		
		ReleaseDC(pDC);  
	}
}

