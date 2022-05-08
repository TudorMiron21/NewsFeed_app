#include "CNewsWindow.h"
#define _CRT_SECURE_NO_WARNINGS
wxBEGIN_EVENT_TABLE(CNewsWindow, wxFrame)
EVT_BUTTON((wxWindowID)type_button_event::Sport_button_event, CNewsWindow::on_click_sport)
EVT_BUTTON((wxWindowID)type_button_event::Economie_button_event, CNewsWindow::on_click_economie)
EVT_BUTTON((wxWindowID)type_button_event::Educatie_button_event, CNewsWindow::on_click_educatie)
EVT_BUTTON((wxWindowID)type_button_event::Medicina_button_event, CNewsWindow::on_click_medicina)
EVT_BUTTON((wxWindowID)type_button_event::Relatii_internationale_button_event, CNewsWindow::on_click_relatii_internationale)
wxEND_EVENT_TABLE()

CNewsWindow::CNewsWindow():
	wxFrame(nullptr,wxID_ANY,"News Categories",wxPoint(30,30),wxSize(500,500))
{

	this->panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300, 400));
	panel->SetBackgroundColour(wxColour(100, 100, 200));
	auto button_sport = new wxButton(panel, (wxWindowID)type_button_event::Sport_button_event, "Sport", wxPoint(10, 10), wxSize(150, 50));
	auto button_economie = new wxButton(panel, (wxWindowID)type_button_event::Economie_button_event, "Economie", wxPoint(170, 10), wxSize(150,50));
	auto button_educatie= new wxButton(panel, (wxWindowID)type_button_event::Educatie_button_event, "Educatie", wxPoint(330, 10), wxSize(150, 50));
	auto button_medicna = new wxButton(panel, (wxWindowID)type_button_event::Medicina_button_event, "Medicina", wxPoint(10, 70), wxSize(150, 50));
	auto button_relatii_internationale = new wxButton(panel, (wxWindowID)type_button_event::Relatii_internationale_button_event, "Relatii Internationale", wxPoint(170, 70), wxSize(150, 50));

}

std::vector<CStire> CNewsWindow::split_server_message(CStire::type_stire type)
{
	if (type == CStire::type_stire::Sport)

		CustomClient::get_instance()->Get_Sport();
	else
		if (type == CStire::type_stire::Economie)
			CustomClient::get_instance()->Get_Economie();
		else
			if (type == CStire::type_stire::Educatie)
				CustomClient::get_instance()->Get_Educatie();
			else
				if (type == CStire::type_stire::Medicina)
					CustomClient::get_instance()->Get_Medicina();
				else
					if (type == CStire::type_stire::Relatii_internationale)
						CustomClient::get_instance()->Get_Relatii();

	//wait for server response
	Sleep(1);

	std::vector<CStire> vec_news;
	if (!CustomClient::get_instance()->Incoming().empty())
	{

		auto msg = CustomClient::get_instance()->Incoming().pop_back().msg;
		int size_vec;
		msg >> size_vec;

		while (size_vec--)
		{
			CStire current;
			
			current.get_type_stire() = type;
			
			auto msg = CustomClient::get_instance()->Incoming().pop_back().msg;
			char News[100];
			msg >> News;
			char* word = strtok(News, "|");
			int count = 0;
			while (word)
			{
				count++;
				if (count == 1)

					current.get_titlu() = word;
				else
					if (count == 2)
						current.get_file_stire() = word;
					else
						if (count == 3)
							current.get_ID() = atoi(word);
				word = strtok(NULL, "|");
			}
			vec_news.push_back(current);

		}

	}
	return vec_news;
}

void CNewsWindow::on_click_sport(wxCommandEvent&evt)
{

	std::vector<CStire> vec_news(this->split_server_message(CStire::type_stire::Sport));

	if (CClient::is_logged())
	{
		auto win = new CNewsList("Stiri despre Sport",CTable_list::type_stire::Sport,vec_news);
		win->Show();

	}
	else if(CAdmin::is_logged()) {
		auto win = new CNewsList_admin("Stiri despre Sport", CTable_list::type_stire::Sport,vec_news);
		win->Show();
	}

	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_economie(wxCommandEvent&evt)
{
	std::vector<CStire> vec_news(this->split_server_message(CStire::type_stire::Economie));


	if (CClient::is_logged())
	{
		auto win = new CNewsList("Stiri despre Economie", CTable_list::type_stire::Economie,vec_news);
		win->Show();

	}
	else if (CAdmin::is_logged()) {
		auto win = new CNewsList_admin("Stiri despre Economie", CTable_list::type_stire::Economie,vec_news);
		win->Show();
	}

	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_educatie(wxCommandEvent&evt)
{
	std::vector<CStire> vec_news(this->split_server_message(CStire::type_stire::Educatie));

	if (CClient::is_logged())
	{
		auto win = new CNewsList("Stiri despre Educatie", CTable_list::type_stire::Educatie, vec_news);
		win->Show();

	}
	else if (CAdmin::is_logged()) {
		auto win = new CNewsList_admin("Stiri despre Educatie", CTable_list::type_stire::Educatie, vec_news);
		win->Show();
	}

	this->Close();
	evt.Skip();
	
}

void CNewsWindow::on_click_medicina(wxCommandEvent&evt)
{
	std::vector<CStire> vec_news(this->split_server_message(CStire::type_stire::Medicina));


	if (CClient::is_logged())
	{
		auto win = new CNewsList("Stiri despre Medicina", CTable_list::type_stire::Medicina, vec_news);
		win->Show();

	}
	else if (CAdmin::is_logged()) {
		auto win = new CNewsList_admin("Stiri despre Medicina", CTable_list::type_stire::Medicina, vec_news);
		win->Show();
	}

	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_relatii_internationale(wxCommandEvent&evt)
{
	std::vector<CStire> vec_news(this->split_server_message(CStire::type_stire::Relatii_internationale));


	if (CClient::is_logged())
	{
		auto win = new CNewsList("Stiri despre Relatii Internationale", CTable_list::type_stire::Relatii_internationale, vec_news);
		win->Show();

	}
	else if (CAdmin::is_logged()) {
		auto win = new CNewsList_admin("Stiri despre Relatii Internationale", CTable_list::type_stire::Relatii_internationale, vec_news);
		win->Show();
	}

	this->Close();
	evt.Skip();
}
