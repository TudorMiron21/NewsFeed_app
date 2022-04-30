#include "CSign_In.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include"CNewsWindow.h"

wxBEGIN_EVENT_TABLE(CSign_In, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event, CSign_In::on_click_back)
EVT_BUTTON((wxWindowID)type_button_event::Inregistrare_button_event, CSign_In::on_click_inregistrare)
wxEND_EVENT_TABLE()

CSign_In::CSign_In() :
	wxFrame(nullptr, wxID_ANY, "Sign In",wxPoint(30, 30), wxSize(300, 400))
{
	this->panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(185, 335), wxSize(100, 25));
	auto button_autentificare = new wxButton(panel, (wxWindowID)type_button_event::Inregistrare_button_event, "Inregistrare", wxPoint(75, 335), wxSize(100, 25));

	this->name_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(125, 110), wxSize(150, 30));
	this->password_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(125, 160), wxSize(150, 30));
	this->password_slot_again = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(125, 210), wxSize(150, 30));

	auto name_txt = new wxStaticText(panel, wxID_ANY, "Introduceti Nume:", wxPoint(10, 110));
	auto password_txt = new wxStaticText(panel, wxID_ANY, "Introduceti Parola:", wxPoint(10, 160));
	auto password_txt_again = new wxStaticText(panel, wxID_ANY, "Introduceti Parola\na doua oara:", wxPoint(10, 210));
}

void CSign_In::on_click_back(wxCommandEvent& evt)
{
	auto win = new CMainWindow();
	win->Show();
	this->Close();
	evt.Skip();
}

void CSign_In::on_click_inregistrare(wxCommandEvent& evt)
{
	if (password_slot->GetValue() == password_slot_again->GetValue())
	{
		CustomClient::get_instance()->Inregistrare((std::string)name_slot->GetValue(), (std::string)password_slot->GetValue());
		//Sleep(20);

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

				case CustomMsgTypes::ServerDeny_log:
				{
					wxMessageBox("Numele sau/si parola exista deja in baza de date a programului");

				}
				break;

				}
			}
		
	}
	else
	{
		wxMessageBox("Parolele introduse difera!");
	}
	
}
