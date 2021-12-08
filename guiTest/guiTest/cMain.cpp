#include "cMain.h"
#include <fstream>
#include <iostream>
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_MENU(10006, cMain::OnMenu1)
EVT_MENU(10007, cMain::OnMenu2)
EVT_MENU(10008, cMain::OnMenu3)
EVT_MENU(10009, cMain::OnMenu4)
EVT_MENU(10011, cMain::OnMenu5)
EVT_BUTTON(10001, OnYesButtonClicked)
EVT_BUTTON(10002, OnNoButtonClicked)
EVT_BUTTON(10003, OnSaveButtonClicked)
EVT_BUTTON(10004, OnEnterButtonClicked)
EVT_BUTTON(10005, OnScheduleButtonClicked)
EVT_BUTTON(10010, OnEClicked)
EVT_BUTTON(10012, OnExit)
EVT_BUTTON(10013, OnExit2)
wxEND_EVENT_TABLE()
bool cond;
int global = 1;
wxString dateArray[7] = { wxString("Monday"),wxString("Tuesday"),wxString("Wednesday"),wxString("Thursday"),wxString("Friday"),wxString("Saturday"),wxString("Sunday") };
wxString locArray[2] = { wxString("808 Commonwealth Ave."),wxString("BU Medical Center") };
wxString Services[35] = { wxString("Tooth - Color Fillings"), wxString("Major Restorative"), wxString("Dentures, Partials, Bridges"), wxString("Bleaching"), wxString("Bonding"), wxString("Porcelain Veneers"), wxString("Implants"), wxString("Periodontics"), wxString("Oral Surgery"), wxString("Covid Test"), wxString("Covid Booster Shot"), wxString("Covid Vaccine"), wxString("Covid Isolation"), wxString("Covid Guidelines"), wxString("Covid Health Service"), wxString("Child Covid Care"),wxString("Vision Care"), wxString("Eye Exam"), wxString("Vision Tests"), wxString("Prescribe Glasses"), wxString("Contact Lenses"), wxString("Monitor Eye Condition"), wxString("Dry Eyes"), wxString("Glaucoma"), wxString("Vision Theraphy"), wxString("Provide Low Vision Aid"), wxString("New Family Consulation"), wxString("Newborn Care"), wxString("Immunizations"), wxString("Pediatric Nutrition"), wxString("Physical Exam"), wxString("Toddler Care"), wxString("FAN Club"), wxString("Obesity"), wxString("Fevers, Cold, Flu")};

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "TestGUI - EC327", wxPoint(30, 30), wxSize(800, 750))
{
	if (global == 1) {
		m_btn1 = new wxButton(this, 10001, "Yes", wxPoint(180, 300), wxSize(50, 20));
		m_btn1->SetBackgroundColour(wxColor(115, 147, 179));
		m_btn2 = new wxButton(this, 10002, "No", wxPoint(400, 300), wxSize(50, 20));
		m_btn2->SetBackgroundColour(wxColor(115, 147, 179));
		m_btn3 = new wxButton(this, 10003, "Save Response", wxPoint(250, 400), wxSize(150, 20));
		m_text = new wxStaticText(this, wxID_ANY, "Have you experienced a new onset of any of the following symptoms in the past 14 days?\nFever of 100\xB0 F or feeling unusually hot with shivering / chills, sore throat, new cough not related to a chronic condition, difficulty breathing / shortness of breath, severe fatigue, severe muscle aches, new loss of sense of taste or smell ? ", wxPoint(200, 100), wxSize(250, 150));
		m_text->SetBackgroundColour(wxColor(115, 147, 179));
		m_msg = new wxMessageDialog(this, "Results Saved!", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_txt2 = new wxTextCtrl(this, wxID_ANY, "Enter symtoms:", wxPoint(100, 475), wxSize(100, 30));
		m_txt2->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(200, 475), wxSize(150, 50));
		m_btn4 = new wxButton(this, 10004, "Enter", wxPoint(375, 475), wxSize(150, 50));
		m_btn4->SetBackgroundColour(wxColor(115, 147, 179));
		m_text1 = new wxStaticText(this, wxID_ANY, "Please schdule a Covid vaccine booster shot if you haven't.", wxPoint(25, 10), wxSize(400, 15));
		m_btn5 = new wxButton(this, 10005, "Schedule Now", wxPoint(450, 10), wxSize(100, 25));
		m_btn5->SetBackgroundColour(wxColor(115, 147, 179));
		m_text1->SetBackgroundColour(wxColor(255, 00, 00));
		m_msg5 = new wxMessageDialog(this, "Symptom(s) have been saved! \nYou may close the tab now.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_MenuBar = new wxMenuBar();
		this->SetMenuBar(m_MenuBar);

		wxMenu* menuFile = new wxMenu();
		menuFile->Append(10006, "Service Avaliable");
		menuFile->Append(10007, "Schedule Apointment");
		menuFile->Append(10008, "Doctors Info");
		menuFile->Append(10009, "Quit");
		menuFile->Append(10011, "About");

		m_MenuBar->Append(menuFile, "Menu");
	}
	if (global == 2) {
		m_text1 = new wxStaticText(this, wxID_ANY, "Covid Vaccine Booster shot Appointment Registration", wxPoint(25, 10), wxSize(400, 50));
		m_text1->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt3 = new wxTextCtrl(this, wxID_ANY, "Enter A Date (S,M,T,W,Th,F,Sat): ", wxPoint(50, 100), wxSize(200, 50));
		m_txt3->SetBackgroundColour(wxColor(115, 147, 179));
		chc_date = new wxChoice(this, wxID_ANY, wxPoint(300, 100), wxDefaultSize,7,dateArray,0,wxDefaultValidator,"Weekday");
		m_txt5 = new wxTextCtrl(this, wxID_ANY, "Enter A Location:\n(808 OR BUMC):", wxPoint(50, 200), wxSize(200, 50));
		m_txt5->SetBackgroundColour(wxColor(115, 147, 179));
		chc_loc = new wxChoice(this, wxID_ANY, wxPoint(300, 200), wxDefaultSize, 2, locArray, 0, wxDefaultValidator, "Location");
		m_txt7 = new wxTextCtrl(this, wxID_ANY, "Enter your name & ID:", wxPoint(50, 300), wxSize(200, 50));
		m_txt7->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt8 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 300), wxSize(150, 50));
		m_txt9 = new wxTextCtrl(this, wxID_ANY, "Enter your Email:", wxPoint(50, 400), wxSize(200, 50));
		m_txt9->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt10 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 400), wxSize(150, 50));
		m_txt11 = new wxTextCtrl(this, wxID_ANY, "Enter your Phone Number:", wxPoint(50, 500), wxSize(200, 50));
		m_txt11->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt12 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 500), wxSize(150, 50));
		m_btn8 = new wxButton(this, 10010, "Enter", wxPoint(500, 500), wxSize(50, 50));
		m_btn8->SetBackgroundColour(wxColor(115, 147, 179));
		m_msg3 = new wxMessageDialog(this, "Saved! You May close the tab now.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_msg4 = new wxMessageDialog(this, "Please fill all forms.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_msg6 = new wxMessageDialog(this, "Please fill all forms with appropriate entries.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
	}
	if (global == 3) 
	{
		m_msg5 = new wxMessageDialog(this, "Symptom(s) have been saved! \nYou may close the tab now.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
	}
	if (global == 4)
	{
		m_text3 = new wxStaticText(this, wxID_ANY, "Dr. Tian:\nOphthalmologist - 20 years of experience\n1(646)919-6767\nExpert and Mastermind\n\nEduction:\nBS - Harvard; MS - John Hopkin; PHD - Community College;\nSpecial Talent: Can perform Magic\nFun Fact: Have 12 fingers to optimize patient's need.", wxPoint(150, 100), wxSize(200, 190));
		m_text3->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt13 = new wxTextCtrl(this, wxID_ANY, "Picture Will Update Soon", wxPoint(400, 100), wxSize(200, 190));
		m_text4 = new wxStaticText(this, wxID_ANY, "Dr. Stefan:\nCardiologist - 50 years of experience\n1(646)988-8888\nCritcal Thinker & Experienced\n\nEduction:\nBS - BU; MS - BU; PHD - BU;\nSpecial Talent: Can Solve 10x10 Cubic Cubes\nFun Fact: Smart.", wxPoint(150, 300), wxSize(200, 190));
		m_text4->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt14 = new wxTextCtrl(this, wxID_ANY, "Picture Will Update Soon", wxPoint(400, 300), wxSize(200, 190));
	}
	if (global == 5) 
	{
		st0 = new wxStaticText(this, wxID_ANY, "Dental Service:", wxPoint(0, 10), wxSize(200, 100));
		st0->SetBackgroundColour(wxColor(247, 191, 190));
		st1 = new wxStaticText(this, wxID_ANY, "Covid Service:", wxPoint(200, 10), wxSize(200, 100));
		st1->SetBackgroundColour(wxColor(234, 221, 202));
		st2 = new wxStaticText(this, wxID_ANY, "Ophthalmologists Service:", wxPoint(400, 10), wxSize(200, 100));
		st2->SetBackgroundColour(wxColor(115, 147, 179));
		st3 = new wxStaticText(this, wxID_ANY, "Child Health Service:", wxPoint(600, 10), wxSize(200, 100));
		st3->SetBackgroundColour(wxColor(144, 238, 144));
		st4 = new wxStaticText(this, wxID_ANY,
			"*Tooth-Color Fillings\n\n*Major Restorative\n\n*Dentures, Partials, Bridges\n\n*Bleaching\n\n*Bonding\n\n*Porcelain Veneers\n\n*Implants\n\n*Periodontics\n\n*Oral Surgery", wxPoint(0, 150), wxSize(200, 300));
		st4->SetBackgroundColour(wxColor(247, 191, 190));
		st5 = new wxStaticText(this, wxID_ANY, "*Covid Test\n\n*Covid Booster Shot\n\n*Covid Vaccine\n\n*Covid Isolation\n\n*Covid Guidelines\n\n*Covid Health Service\n\n*Child Covid Care", wxPoint(200, 150), wxSize(200, 300));
		st5->SetBackgroundColour(wxColor(234, 221, 202));
		st6 = new wxStaticText(this, wxID_ANY, "*Vision Care\n\n*Eye Exam\n\n*Vision Tests\n\n*Prescribe Glasses\n\n*Contact Lenses\n\n*Monitor Eye Condition\n\n*Dry Eyes\n\n*Glaucoma\n\n*Vision Theraphy\n\n*Provide Low Vision Aid", wxPoint(400, 150), wxSize(200, 300));
		st6->SetBackgroundColour(wxColor(115, 147, 179));
		st7 = new wxStaticText(this, wxID_ANY, "*New Family Consulation\n\n*Newborn Care\n\n*Immunizations\n\n*Pediatric Nutrition\n\n*Physical Exam\n\n*Toddler Care\n\n*FAN Club\n\n*Obesity\n\n*Fevers, Cold, Flu", wxPoint(600, 150), wxSize(200, 300));
		st7->SetBackgroundColour(wxColor(144, 238, 144));
		b0 = new wxButton(this, 10012, "Make An Appointment Now", wxPoint(600, 500), wxSize(210, 20));
		st8 = new wxStaticText(this, wxID_ANY, "We provide much more service than above \nQuestion/Concerns\nEmail Us at: GloriousHospital@GH.com\n Call us at:1(858)965-8888", wxPoint(0, 500), wxSize(400, 100));
		st8->SetBackgroundColour(wxColor(139, 116, 189));
	}
	if (global == 6) 
	{
		st13 = new wxStaticText(this, wxID_ANY, "Appointment Form", wxPoint(25, 10), wxSize(400, 50));
		st13->SetBackgroundColour(wxColor(115, 147, 179));
		st14 = new wxStaticText(this, wxID_ANY, "Enter a date (S,M,T,W,Th,F,Sat): ", wxPoint(50, 100), wxSize(200, 50));
		st14->SetBackgroundColour(wxColor(115, 147, 179));
		chc_date = new wxChoice(this, wxID_ANY, wxPoint(300, 100), wxDefaultSize, 7, dateArray, 0, wxDefaultValidator, "Weekday");
		st15 = new wxStaticText(this, wxID_ANY, "Enter a Location:\n(808 OR BUMC)", wxPoint(50, 200), wxSize(200, 50));
		st15->SetBackgroundColour(wxColor(115, 147, 179));
		chc_loc = new wxChoice(this, wxID_ANY, wxPoint(300, 200), wxDefaultSize, 2, locArray, 0, wxDefaultValidator, "Location");
		st16 = new wxStaticText(this, wxID_ANY, "Enter your name & ID:", wxPoint(50, 300), wxSize(200, 50));
		st16->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt17 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 300), wxSize(150, 50));
		st17 = new wxStaticText(this, wxID_ANY, "Enter your Email:", wxPoint(50, 400), wxSize(200, 50));
		st17->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt18 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 400), wxSize(150, 50));
		st18 = new wxStaticText(this, wxID_ANY, "Enter your Phone Number:", wxPoint(50, 500), wxSize(200, 50));
		st18->SetBackgroundColour(wxColor(115, 147, 179));
		m_txt19 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 500), wxSize(150, 50));
		st19 = new wxStaticText(this, wxID_ANY, "Enter your Service needed:", wxPoint(50, 600), wxSize(200, 50));
		st19->SetBackgroundColour(wxColor(115, 147, 179));
		chc_serv = new wxChoice(this, wxID_ANY, wxPoint(300, 600), wxDefaultSize, 35, Services, 0, wxDefaultValidator, "Service");
		m_btn9 = new wxButton(this, 10013, "Enter", wxPoint(500, 600), wxSize(50, 50));
		m_btn9->SetBackgroundColour(wxColor(115, 147, 179));
		m_msg3 = new wxMessageDialog(this, "Saved! We will email you the confirmation!", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_msg4 = new wxMessageDialog(this, "Please fill all forms.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
		m_msg6 = new wxMessageDialog(this, "Please fill all forms with appropriate entries.", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
	}
	if (global == 7) 
	{
		st9 = new wxStaticText(this, wxID_ANY, "Our Mission\n\nTo provide patient-centered healthcare with excellence in quality, service, and access.", wxPoint(0, 0), wxSize(800, 200));
		st9->SetBackgroundColour(wxColor(250, 191, 190));
		st10 = new wxStaticText(this, wxID_ANY,
			"\n\nVision:\n\nTo provide patient-centered healthcare with excellence in quality, service, and access.\n\nA community in which all people achieve their full potential for healthand well - being across the lifespan.\n\nWe work to be trusted by patients, a valued partner in the community, and creators of positive change.\n"
			, wxPoint(0, 100), wxSize(800, 200));
		st10->SetBackgroundColour(wxColor(115, 191, 190));
		st11 = new wxStaticText(this, wxID_ANY,
			"\nGoals:\n\nThe patient always comes first. We are dedicated to patient care.\n\nWe treat each person with respect and dignity.\n\nWe are compassionate listeners.We hear the issues of our patients, respect them, and do everything in our power to help."
			, wxPoint(0, 300), wxSize(800, 200));
		st11->SetBackgroundColour(wxColor(115, 147, 179));
		st12 = new wxStaticText(this, wxID_ANY, "\n\nSincerely, \n\n- GloriousHospital Team", wxPoint(0, 500), wxSize(800, 200));
		st12->SetBackgroundColour(wxColor(144, 238, 144));
	}
}

void cMain::OnMenu1(wxCommandEvent& evt)
{
	global = 5;
	cMain* m_frame5 = nullptr;
	m_frame5 = new cMain;
	m_frame5->Show();
	evt.Skip();
}

void cMain::OnMenu2(wxCommandEvent& evt)
{
	global = 6;
	cMain* m_frame6 = nullptr;
	m_frame6 = new cMain;
	m_frame6->Show();
	evt.Skip();
}

void cMain::OnMenu3(wxCommandEvent& evt)
{
	global = 4;
	cMain* m_frame4 = nullptr;
	m_frame4 = new cMain;
	m_frame4->Show();
	evt.Skip();
}

void cMain::OnMenu4(wxCommandEvent& evt)
{
	Close();
	evt.Skip();
}

void cMain::OnMenu5(wxCommandEvent& evt)
{
	global = 7;
	cMain* m_frame7 = nullptr;
	m_frame7 = new cMain;
	m_frame7->Show();
	evt.Skip();
}
cMain::~cMain()
{
	delete m_btn1;	delete m_btn2;	delete m_btn3;	delete m_text;	delete m_msg; delete m_btn3; delete m_btn4;	delete m_btn5;	delete m_btn6 ; delete m_btn7; delete m_btn8; delete m_btn9; delete m_text; delete m_text1; delete m_text2; delete m_text3; delete m_text4; delete m_msg1; delete m_msg2; delete m_msg3; delete m_msg4; delete m_msg5; delete m_msg6; delete m_txt1; delete m_txt2; delete m_txt3; delete m_txt4; delete m_txt5; delete m_txt6; delete m_txt7; delete m_txt8; delete m_txt9; delete m_txt10; delete
		m_txt11; delete m_txt12; delete m_txt13; delete m_txt14; delete m_txt15; delete	m_txt16; delete m_txt17; delete m_txt18; delete m_txt19; delete m_txt20; delete b0; delete st0; delete st1; delete st2; delete st3; delete	st4; delete st5; delete st6; delete st7; delete st8; delete	st9; delete st10; delete st11; delete st12; delete st13; delete st14; delete st15; delete st16; delete st17; delete st18; delete st19; delete t0; delete chc_date; delete chc_loc;
}

void cMain::OnScheduleButtonClicked(wxCommandEvent& evt)
{
	global = 2;
	cMain* m_frame2 = nullptr;
	m_frame2 = new cMain;
	m_frame2->Show();
	evt.Skip();
}
void cMain::OnYesButtonClicked(wxCommandEvent& evt)
{
	has_COVID = true;
	button_Pressed = true;
	evt.Skip();
}

void cMain::OnNoButtonClicked(wxCommandEvent& evt)
{
	has_COVID = false;
	button_Pressed = true;
	evt.Skip();
}

void cMain::OnSaveButtonClicked(wxCommandEvent& evt)
{
	if (button_Pressed && has_COVID)
	{
		std::ofstream resultsFile("Output_File.txt"); 
		resultsFile << "Date of Test: " << CurrentDate() << std::endl;
		resultsFile << "Has COVID-19: " << "Yes" << std::endl;
		resultsFile.close();
		m_msg->ShowModal();
	}
	else if (button_Pressed && !has_COVID)
	{
		std::ofstream resultsFile("Output_File.txt"); 
		resultsFile << "Date of Test: " << CurrentDate() << std::endl;
		resultsFile << "Has COVID-19: " << "No" << std::endl;
		resultsFile.close();
		m_msg->ShowModal();
	}
	evt.Skip();
}

void cMain::OnEClicked(wxCommandEvent& evt)
{
	std::ofstream resultsFile("Output_File.txt");
	if (chc_date->GetSelection() == wxNOT_FOUND || chc_loc->GetSelection() == wxNOT_FOUND || m_txt8->GetValue().empty() == true || m_txt10->GetValue().empty() == true || m_txt12->GetValue().empty() == true)
		m_msg4->ShowModal();
	else
	{
		resultsFile << "Appointment Date: " << chc_date->GetString(chc_date->GetSelection()) << std::endl;
		resultsFile << "Location: " << chc_loc->GetString(chc_loc->GetSelection()) << std::endl;
		resultsFile << "Name & ID: " << m_txt8->GetValue() << std::endl;
		resultsFile << "Email: " << m_txt10->GetValue() << std::endl;
		resultsFile << "Phone Number: " << m_txt12->GetValue() << std::endl;
		resultsFile.close();
		m_msg3->ShowModal();
		evt.Skip();
	}
	
}
void cMain::OnExit2(wxCommandEvent& evt)
{
	std::ofstream resultsFile("Output_File.txt");
	if (chc_date->GetSelection() == wxNOT_FOUND || chc_loc->GetSelection() == wxNOT_FOUND || m_txt17->GetValue().empty() == true || m_txt18->GetValue().empty() == true || m_txt19->GetValue().empty() == true || chc_serv->GetSelection() == wxNOT_FOUND)
	{
		m_msg4->ShowModal();
	}
	else
	{
		resultsFile << "Appointment Date: " << chc_date->GetString(chc_date->GetSelection()) << std::endl;
		resultsFile << "Location: " << chc_loc->GetString(chc_loc->GetSelection()) << std::endl;
		resultsFile << "Name & ID: " << m_txt17->GetValue() << std::endl;
		resultsFile << "Email: " << m_txt18->GetValue() << std::endl;
		resultsFile << "Phone Number: " << m_txt19->GetValue() << std::endl;
		resultsFile << "Service Requested: " << chc_serv->GetString(chc_serv->GetSelection()) << std::endl;
		resultsFile.close();
		m_msg3->ShowModal();
		evt.Skip();
	}
}
void cMain::OnEnterButtonClicked(wxCommandEvent& evt)
{
	std::ofstream resultsFile("Output_File.txt");
	if (m_txt1->GetValue().empty() == true)
	{
		resultsFile << "SYMPTOMS PROVIDED: none" << std::endl;
		resultsFile.close();
		global = 3;
		m_msg5->ShowModal();
	}
	else
	{
		resultsFile << "SYMPTOMS PROVIDED: " << m_txt1->GetValue() << std::endl;
		resultsFile.close();
		global = 3;
		m_msg5->ShowModal();
	}
	evt.Skip();
}

void cMain::OnExit(wxCommandEvent& evt)
{
	global = 6;
	cMain* m_frame6 = nullptr;
	m_frame6 = new cMain;
	m_frame6->Show();
	evt.Skip();
}
std::string cMain::CurrentDate()
{
	time_t timetoday;
   	time (&timetoday);
   	struct tm* timeinfo = localtime(&timetoday);
   	char buffer [20];

   	strftime(buffer, 20, "%D",timeinfo);
   	std::string date = std::string(buffer);

   	return date;
}