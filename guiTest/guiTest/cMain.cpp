#include "cMain.h"
cMain::cMain() : wxFrame(nullptr,wxID_ANY,"TestGUI - EC327",wxPoint(30,30),wxSize(800,600))
{
	m_btn1 = new wxButton(this, 10001, "Yes", wxPoint(200, 300), wxSize(50, 20));
	m_btn2 = new wxButton(this, 10002, "No", wxPoint(400, 300), wxSize(50, 20));
	m_text = new wxStaticText(this, wxID_ANY, "Have you experienced a new onset of any of the following symptoms in the past 14 days?\nFever of 100°F or feeling unusually hot with shivering / chills, sore throat, new cough not related to a chronic condition, difficulty breathing / shortness of breath, severe fatigue, severe muscle aches, new loss of sense of taste or smell ? ", wxPoint(250, 100), wxSize(200, 200));
}
cMain::~cMain()
{

}