#pragma once
#include "wx/wx.h"
#include "wx/stattext.h"
#include "wx/msgdlg.h"
class cMain : public wxFrame
{
private:
	bool has_COVID;
	bool button_Pressed;
public:
	cMain();
	~cMain();
public:
	wxButton* m_btn1 = nullptr, * m_btn2 = nullptr, * m_btn3 = nullptr;
	wxStaticText* m_text = nullptr;
	wxMessageDialog* m_msg = nullptr;
	void OnYesButtonClicked(wxCommandEvent& evt);
	void OnNoButtonClicked(wxCommandEvent& evt);
	void OnSaveButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

