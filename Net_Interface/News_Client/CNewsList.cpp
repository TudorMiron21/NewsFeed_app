#define _CRT_SECURE_NO_WARNINGS

#include "CNewsList.h"
#include"CNewsWindow.h"
#include"CNews_text.h"
wxBEGIN_EVENT_TABLE(CNewsList, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Back_button_event,  CTable_list::on_click_back)
//EVT_BUTTON(101, CNewsList::on_click_view)
wxEND_EVENT_TABLE()

CNewsList::CNewsList(const wxString& title, CTable_list::type_stire type, std::vector<CStire> vec):
	CTable_list(title,type)
{
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(470, 600));
	auto button_back = new wxButton(panel, (wxWindowID)type_button_event::Back_button_event, "Back", wxPoint(350, 530), wxSize(100, 25));
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


	for(const auto &it:this->button_vector)
	it->get_button()->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CTable_list::on_click_view, this, it->get_id());

	this->InsertNews(vec);
}

void CNewsList::on_click_view(wxCommandEvent& evt)
{
	//std::vector<std::string> news_line;
	//for (const auto& it : this->button_vector)
	//{
	//	if (it->get_id() == it->get_button()->GetId());
	//	{

	//		CustomClient::get_instance()->Get_News(it->get_file_name());
	//		//wait for server response;
	//		Sleep(10);

	//		char nr_lines;
	//		if (!CustomClient::get_instance()->Incoming().empty())
	//		{
	//			auto msg = CustomClient::get_instance()->Incoming().pop_back().msg;

	//			msg >> nr_lines;

	//			//nr_lines++;


	//			//while (nr_lines--)
	//			//{
	//				//char line[100];
	//				//auto msg = CustomClient::get_instance()->Incoming().back().msg;
	//				//CustomClient::get_instance()->Incoming().pop_back();
	//				//msg >> line;
	//				
	//				std::string curr_line("aceasta este o stire");

	//				news_line.push_back(curr_line);

	//			//}


	//		}
	//		auto win = new CNews_text(it->get_titlu(),news_line);

	//		win->Show();
	//		
	//		break;
	//	}
	//}
	//
	//
	//this->Close();
	//evt.Skip();
}
