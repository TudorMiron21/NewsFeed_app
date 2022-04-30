#include "CNewsList.h"
#include"CNewsWindow.h"
wxBEGIN_EVENT_TABLE(CNewsList, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event, CNewsList::on_click_back)
wxEND_EVENT_TABLE()

CNewsList::CNewsList(const wxString& title):
	wxFrame(nullptr,wxID_ANY,title,wxPoint(30,30),wxSize(470,600))
{
	wxPanel *panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(470, 600));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(350,530), wxSize(100, 25));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	basicList = new wxListView(panel);
	basicList->AppendColumn("Categorie");
	basicList->AppendColumn("Titlu");
	basicList->AppendColumn("Buton");

	basicList->SetColumnWidth(0, 150);
	basicList->SetColumnWidth(1, 180);
	basicList->SetColumnWidth(2, 120);
	
	auto sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(basicList, 1, wxALL | wxEXPAND, 0);
	panel->SetSizerAndFit(sizer);
}

void CNewsList::on_click_back(wxCommandEvent&evt)
{
	auto win = new CNewsWindow();
	win->Show();
	this->Close();
	evt.Skip();
}
