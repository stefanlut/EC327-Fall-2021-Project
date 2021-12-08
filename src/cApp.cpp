#include "cApp.h"
wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
	if (global == 1) {
		m_frame1 = new cMain();
		m_frame1->Show();
	}
	if (global == 2) {
		m_frame2 = new cMain();
		m_frame2->Show();
		m_frame2->SetBackgroundColour(wxColor(115, 147, 179));
	}
	if (global == 3) {
		m_frame3 = new cMain();
		m_frame3->Show();
		m_frame3->SetBackgroundColour(wxColor(115, 147, 179));
	}
	if (global == 4) {
		m_frame4 = new cMain;
		m_frame4->Show();
		m_frame4->SetBackgroundColour(wxColor(115, 147, 179));
	}
	if (global == 5) {
		m_frame5 = new cMain;
		m_frame5->Show();
		m_frame5->SetBackgroundColour(wxColor(115, 147, 179));
	}
	if (global == 6) {
		m_frame6 = new cMain;
		m_frame6->Show();
		m_frame6->SetBackgroundColour(wxColor(115, 147, 179));
	}
	if (global == 7) {
		m_frame7 = new cMain;
		m_frame7->Show();
		m_frame7->SetBackgroundColour(wxColor(115, 147, 179));
	}
	return true;
}