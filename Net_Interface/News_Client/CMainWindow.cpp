#include "CMainWindow.h"

wxBEGIN_EVENT_TABLE(CMainWindow, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::LogIn_button_event, CMainWindow::on_click_log_in)
EVT_BUTTON((wxWindowID)type_button_event::SignIn_button_event, CMainWindow::on_click_sign_in)
wxEND_EVENT_TABLE()

CMainWindow::CMainWindow()
	:wxFrame(nullptr,wxID_ANY,"Daily News!", wxPoint(30, 30), wxSize(500, 500))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	panel->SetBackgroundColour(wxColour(100,100,200));

	auto title = new wxStaticText(panel,wxID_ANY,"GET YOUT DAILY NEWS!",wxPoint(50,20),wxSize(400,80));
	auto button1 = new wxButton(panel,(wxWindowID)type_button_event::SignIn_button_event , "Sign In",wxPoint(50,250),wxSize(150,50));
	auto button2 = new wxButton(panel, (wxWindowID)type_button_event::LogIn_button_event, "Log In", wxPoint(300, 250), wxSize(150, 50));
	//auto sizer = new wxBoxSizer(wxHORIZONTAL);
	//sizer->Add(button1, 0, wxCENTER | wxALL, 100);
	//sizer->Add(button2, 0, wxCENTER | wxALL, 100);
	//SetSizerAndFit(sizer);
}

void CMainWindow::on_click_sign_in(wxCommandEvent& evt)
{
	auto win = new CSign_In();
	
	win->Show();
	this->Close();
	evt.Skip();
}

void CMainWindow::on_click_log_in(wxCommandEvent& evt)
{
	auto win = new CLog_In();
	win->Show();
	this->Close();
	evt.Skip();
}
