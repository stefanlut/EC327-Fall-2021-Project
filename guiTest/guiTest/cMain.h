#pragma once
#include "wx/wx.h"
#include "wx/stattext.h"
#include "wx/msgdlg.h"
//#include "cEditorFrame.h"
extern int global;
class cMain : public wxFrame
{
private:
	bool has_COVID;
	bool button_Pressed = false;
	wxToolBar* m_ToolBar = nullptr;
	wxMenuBar* m_MenuBar = nullptr;
	std::string CurrentDate();

	void OnMenu1(wxCommandEvent& evt);
	void OnMenu2(wxCommandEvent& evt);
	void OnMenu3(wxCommandEvent& evt);
	void OnMenu4(wxCommandEvent& evt);
	void OnMenu5(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
public:
	cMain();
	~cMain();
public:
	wxButton* m_btn1 = nullptr, * m_btn2 = nullptr, * m_btn3 = nullptr, * m_btn4 = nullptr, * m_btn5 = nullptr, * m_btn6 = nullptr, * m_btn7 = nullptr,
		* m_btn8 = nullptr, * m_btn9 = nullptr;
	wxStaticText* m_text = nullptr, * m_text1 = nullptr, * m_text2 = nullptr, * m_text3 = nullptr, * m_text4 = nullptr;
	wxMessageDialog* m_msg = nullptr, * m_msg1 = nullptr, * m_msg2 = nullptr, * m_msg3 = nullptr, * m_msg4 = nullptr, * m_msg5 = nullptr, * m_msg6 = nullptr;
	wxTextCtrl* m_txt1 = nullptr, * m_txt2 = nullptr, * m_txt3 = nullptr, * m_txt4 = nullptr, * m_txt5 = nullptr,
		* m_txt6 = nullptr, * m_txt7 = nullptr, * m_txt8 = nullptr, * m_txt9 = nullptr, * m_txt10 = nullptr,
		* m_txt11 = nullptr, * m_txt12 = nullptr, * m_txt13 = nullptr, * m_txt14 = nullptr, * m_txt15 = nullptr,
		* m_txt16 = nullptr, * m_txt17 = nullptr, * m_txt18 = nullptr, * m_txt19 = nullptr, * m_txt20 = nullptr;
	wxButton* b0 = nullptr;
	wxStaticText* st0 = nullptr, * st1 = nullptr, * st2 = nullptr, * st3 = nullptr,
		* st4 = nullptr, * st5 = nullptr, * st6 = nullptr, * st7 = nullptr, * st8 = nullptr,
		* st9 = nullptr, * st10 = nullptr, * st11 = nullptr, * st12 = nullptr, * st13 = nullptr,
		* st14 = nullptr, * st15 = nullptr, * st16 = nullptr, * st17 = nullptr, * st18 = nullptr,
		* st19 = nullptr;
	wxTextCtrl* t0 = nullptr;
	wxChoice* chc_date = nullptr, * chc_loc = nullptr, * chc_serv = nullptr;
	void OnYesButtonClicked(wxCommandEvent& evt);
	void OnNoButtonClicked(wxCommandEvent& evt);
	void OnSaveButtonClicked(wxCommandEvent& evt);
	void OnEnterButtonClicked(wxCommandEvent& evt);
	void OnScheduleButtonClicked(wxCommandEvent& evt);
	void OnEClicked(wxCommandEvent& evt);
	void OnExit(wxCommandEvent& evt);
	void OnExit2(wxCommandEvent& evt);
};



