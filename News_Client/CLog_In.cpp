#include "CLog_In.h"
#include"CNewsWindow.h"
wxBEGIN_EVENT_TABLE(CLog_In, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event, CLog_In::on_click_back)
EVT_BUTTON((wxWindowID)type_button_event::Autentificare_button_event, CLog_In::on_click_autentificare)
wxEND_EVENT_TABLE()

CLog_In::CLog_In():
	wxFrame(nullptr,wxID_ANY,"Log In",wxPoint(30,30),wxSize(300,400))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(185, 335), wxSize(100, 25));
	auto button_autentificare = new wxButton(panel, (wxWindowID)type_button_event::Autentificare_button_event, "Autentificare", wxPoint(75, 335), wxSize(100, 25));
	this->name_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(125, 110), wxSize(150, 30));
	this->password_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(125, 160), wxSize(150, 30));

	auto name_text = new wxStaticText(panel, wxID_ANY, "Introduceti Nume:", wxPoint(10, 110));
	auto password_text = new wxStaticText(panel, wxID_ANY, "Introduceti Parola:", wxPoint(10, 160));

	//auto sizer = new wxBoxSizer(wxVERTICAL);
	//sizer->Add(button_back, 1, wxALL | wxEXPAND, 0);
	//sizer->Add(button_autentificare, 1, wxALL | wxEXPAND, 0);
	//sizer->Add(name_slot, 1, wxALL | wxEXPAND, 0);
	//sizer->Add(password_slot, 1, wxALL | wxEXPAND, 0);
	//sizer->Add(name_text, 1, wxALL | wxEXPAND, 0);
	//sizer->Add(password_text, 1, wxALL | wxEXPAND, 0);
	//panel->SetSizerAndFit(sizer);
}

void CLog_In::on_click_back(wxCommandEvent& evt)
{
	auto win = new CMainWindow();
	win->Show();
	this->Close();
	evt.Skip();
}


void CLog_In::on_click_autentificare(wxCommandEvent& evt)
{
	
	CustomClient::get_instance()->Autentification((std::string)name_slot->GetValue(), (std::string)password_slot->GetValue());
	Sleep(2);
	
	if (!CustomClient::get_instance()->Incoming().empty())
	{


		auto msg = CustomClient::get_instance()->Incoming().pop_back().msg;

		switch (msg.header.id)
		{
		case CustomMsgTypes::ServerAccept_log:
		{
			auto win = new CNewsWindow();
			win->Show();
			this->Close();
			evt.Skip();
		}
		break;
		case CustomMsgTypes::Inregistrare_admin:
		{
			wxMessageBox("Sunteti logat cu drepturi de administrator");
			auto win = new CNewsWindow();
			win->Show();
			this->Close();
			evt.Skip();
		}
		break;

		case CustomMsgTypes::ServerDeny_log:
		{
			wxMessageBox("Numele sau/si parola nu exista in baza de date a programului");

		}
		break;

		}
	}
}
