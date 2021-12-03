#pragma once
#include "wx/wx.h"
#include "wx/stattext.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	wxButton* m_btn1 = nullptr, * m_btn2 = nullptr;
	wxStaticText* m_text = nullptr;
};

