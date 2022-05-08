#define _CRT_SECURE_NO_WARNINGS

#include "CNewsList_admin.h"
#include"CNewsWindow.h"
#include"CAdmin_create_news.h"
wxBEGIN_EVENT_TABLE(CNewsList_admin, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Add_button_event,CNewsList_admin::on_click_add)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event,CTable_list::on_click_back)
wxEND_EVENT_TABLE()

CNewsList_admin::CNewsList_admin(const wxString& title, CTable_list::type_stire type, std::vector<CStire> vec):
	CTable_list(title,type)
{
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(470, 600));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(350, 530), wxSize(100, 25));
	add_button = new wxButton(panel, (wxWindowID)type_button_event::Add_button_event, "Add", wxPoint(240, 530), wxSize(100, 25));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	int x = 350, y = 25, inc = 21, count = 0;
	for (auto& it : vec)
	{
		auto button = new wxButton(panel, (wxWindowID)it.get_ID(), "view", wxPoint(x, y + (inc * count++)), wxSize(100, 20));

		auto button_elem = new CButton((wxWindowID)it.get_ID(), button, it.get_file_stire(), it.get_titlu());

		this->button_vector.push_back(button_elem);

	}
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

	for (const auto& it : this->button_vector)
		it->get_button()->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CTable_list::on_click_view, this, it->get_id());

	this->InsertNews(vec);

}

void CNewsList_admin::on_click_add(wxCommandEvent& evt)
{
	auto win = new CAdmin_create_news();
	win->Show();
	this->Close();
	evt.Skip();
}




