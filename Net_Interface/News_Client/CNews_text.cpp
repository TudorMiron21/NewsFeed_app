#include "CNews_text.h"
#include"CNewsWindow.h"
wxBEGIN_EVENT_TABLE(CNews_text, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event, CNews_text::on_click_back)

wxEND_EVENT_TABLE()

CNews_text::CNews_text(std::string Title,std::vector<std::string> news):
	wxFrame(nullptr, wxID_ANY, Title, wxPoint(30, 30), wxSize(800, 700))
{
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 700));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(680, 630), wxSize(100, 25));
	this->news = new wxListBox(panel, wxID_ANY, wxPoint(20,20), wxSize(740,600));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	for (const auto& it : news)
	{
		this->news->AppendString(it);
	}
}

void CNews_text::on_click_back(wxCommandEvent& evt)
{
	auto win = new CNewsWindow();
	win->Show();
	this->Close();
	evt.Skip();
}
