#define _CRT_SECURE_NO_WARNINGS

#include "CTable_list.h"
#include"CNewsWindow.h"

CTable_list::CTable_list(const wxString& title,type_stire type):
	wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 30), wxSize(470, 600)),
	type(type)
{
	
}

void CTable_list::InsertNews(std::vector<CStire> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_type_stire() == CStire::type_stire::Economie)
			basicList->InsertItem(i, "Economie");
		else
			if (vec[i].get_type_stire() == CStire::type_stire::Educatie)
				basicList->InsertItem(i, "Educatie");
			else
				if (vec[i].get_type_stire() == CStire::type_stire::Medicina)
					basicList->InsertItem(i, "Medicina");

				else
					if (vec[i].get_type_stire() == CStire::type_stire::Relatii_internationale)
						basicList->InsertItem(i, "Relatii Internationale");

					else
						if (vec[i].get_type_stire() == CStire::type_stire::Sport)
							basicList->InsertItem(i, "Sport");

		basicList->SetItem(i, 1, vec[i].get_titlu());
		//basicList->SetItem(i, 2, "button");
	}
}

void CTable_list::on_click_back(wxCommandEvent& evt)
{
	auto win = new CNewsWindow();
	win->Show();
	this->Close();
	evt.Skip();
}

void CTable_list::on_click_view(wxCommandEvent& evt)
{
	std::vector<std::string> news_line;
	for (const auto& it : this->button_vector)
	{
		if (it->get_id() == it->get_button()->GetId());
		{

			CustomClient::get_instance()->Get_News(it->get_file_name());
			//wait for server response;
			Sleep(10);

			char nr_lines;
			if (!CustomClient::get_instance()->Incoming().empty())
			{
				auto msg = CustomClient::get_instance()->Incoming().pop_back().msg;

				msg >> nr_lines;

				//nr_lines++;


				//while (nr_lines--)
				//{
					//char line[100];
					//auto msg = CustomClient::get_instance()->Incoming().back().msg;
					//CustomClient::get_instance()->Incoming().pop_back();
					//msg >> line;

				std::string curr_line("aceasta este o stire");

				news_line.push_back(curr_line);

				//}


			}
			auto win = new CNews_text(it->get_titlu(), news_line);

			win->Show();

			break;
		}
	}


	this->Close();
	evt.Skip();
}
