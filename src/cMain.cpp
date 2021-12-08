#include "cMain.h"
#include <fstream>
#include <iostream>
wxBEGIN_EVENT_TABLE(cMain,wxFrame)

	EVT_BUTTON(10001, OnYesButtonClicked)
	EVT_BUTTON(10002, OnNoButtonClicked)
	EVT_BUTTON(10003, OnSaveButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr,wxID_ANY,"TestGUI - EC327",wxPoint(30,30),wxSize(800,600))
{
	m_btn1 = new wxButton(this, 10001, "Yes", wxPoint(200, 300), wxSize(50, 20));
	m_btn2 = new wxButton(this, 10002, "No", wxPoint(400, 300), wxSize(50, 20));
	m_btn3 = new wxButton(this, 10003, "Save Response to .txt file", wxPoint(250, 400), wxSize(150, 20));
	m_text = new wxStaticText(this, wxID_ANY, "Have you experienced a new onset of any of the following symptoms in the past 14 days?\nFever of 100°F or feeling unusually hot with shivering / chills, sore throat, new cough not related to a chronic condition, difficulty breathing / shortness of breath, severe fatigue, severe muscle aches, new loss of sense of taste or smell ? ", wxPoint(250, 100), wxSize(200, 200));
	m_msg = new wxMessageDialog(this, "Results Saved!", "Results Confirmation", wxOK | wxCENTRE, wxDefaultPosition);
}
cMain::~cMain()
{

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
		std::ofstream resultsFile("example.txt"); // This filename should probably be something like Day_Month_Year_Results.txt
		resultsFile << "Has COVID-19: " << "Yes" << std::endl;
		resultsFile.close();
		m_msg->ShowModal();
	}
	else if (button_Pressed && !has_COVID)
	{
		std::ofstream resultsFile("example.txt"); // This filename should probably be something like Day_Month_Year_Results.txt
		resultsFile << "Has COVID-19: " << "No" << std::endl;
		resultsFile.close();
		m_msg->ShowModal();
	}
	evt.Skip();
}