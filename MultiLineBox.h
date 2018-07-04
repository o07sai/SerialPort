#pragma once


// CMultiLineBox

class CMultiLineBox : public CComboBox
{
	DECLARE_DYNAMIC(CMultiLineBox)

public:
	CMultiLineBox();
	virtual ~CMultiLineBox();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
};


