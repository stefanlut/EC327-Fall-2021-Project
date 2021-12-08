#pragma once
#include "wx/wx.h"
#include "cMain.h"
#include "Vaccine.h"
class cApp : public wxApp
{
public:
	cApp();
	~cApp();

	virtual bool OnInit();
private:
	cMain* m_frame1 = nullptr;
	cMain* m_frame2 = nullptr;
	cMain* m_frame3 = nullptr;
	cMain* m_frame4 = nullptr;
	cMain* m_frame5 = nullptr;
	cMain* m_frame6 = nullptr;
	cMain* m_frame7 = nullptr;
};



