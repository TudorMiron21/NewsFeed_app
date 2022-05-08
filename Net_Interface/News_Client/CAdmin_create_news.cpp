#include "CAdmin_create_news.h"
#include"IdButton.h"
wxBEGIN_EVENT_TABLE(CAdmin_create_news, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event, CAdmin_create_news::on_click_back)
EVT_BUTTON((wxWindowID)type_button_event::Autentificare_button_event, CAdmin_create_news::on_click_commit)
wxEND_EVENT_TABLE()

CAdmin_create_news::CAdmin_create_news():
	wxFrame(nullptr,wxID_ANY,"Admin Customise Window",wxPoint(30,30),wxSize(800,700))
{
	auto panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 700));
	panel->SetBackgroundColour(wxColour(100, 100, 200));

	//auto category_choose = new wxStaticText(panel, wxID_ANY, "Alegeti categoria articolului dumneavoastra:", wxPoint(20,80));
	//auto sport_button = new wxButton(panel, (wxWindowID)type_button_event::Sport_button_event, "Sport", wxPoint(20,100), wxSize(130, 40));
	//auto educatie_button = new wxButton(panel, (wxWindowID)type_button_event::Economie_button_event, "Economie", wxPoint(164,100), wxSize(130, 40));
	//auto economie_button = new wxButton(panel, (wxWindowID)type_button_event::Educatie_button_event, "Educatie", wxPoint(308,100), wxSize(130, 40));
	//auto medicina_button = new wxButton(panel, (wxWindowID)type_button_event::Medicina_button_event, "Medicina", wxPoint(452,100), wxSize(130, 40));
	//auto relatii_internationale_button = new wxButton(panel, (wxWindowID)type_button_event::Relatii_internationale_button_event, "Relatii Internationale", wxPoint(598, 100), wxSize(130, 40));

	auto title_text = new wxStaticText(panel, wxID_ANY, "Introduceti titlul articolului:", wxPoint(300, 30));
	auto title_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 50), wxSize(250, 30));

	auto file_text = new wxStaticText(panel, wxID_ANY, "Introduceti numele fisierului de stocare:", wxPoint(20, 30));
	auto file_slot = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 50), wxSize(250, 30));

	auto news_text = new wxStaticText(panel, wxID_ANY, "Introduceti textul stirii:", wxPoint(20, 300));
	auto news_slot = new wxTextCtrl(panel, wxID_ANY,"", wxPoint(20, 120), wxSize(740, 500));

	auto commit_button = new wxButton(panel, (wxWindowID)type_button_event::Commit_button_event,"Commit", wxPoint(570, 630), wxSize(100, 25));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(680, 630), wxSize(100, 25));
}

void CAdmin_create_news::on_click_back(wxCommandEvent&)
{
}

void CAdmin_create_news::on_click_commit(wxCommandEvent&)
{
}
