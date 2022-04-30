#include "CNewsWindow.h"

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

void CNewsWindow::on_click_sport(wxCommandEvent&evt)
{
	auto win = new CNewsList("Stiri despre Sport");
	win->Show();
	this->Close();
	evt.Skip();

}

void CNewsWindow::on_click_economie(wxCommandEvent&evt)
{
	auto win = new CNewsList("Stiri despre Economie");
	win->Show();
	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_educatie(wxCommandEvent&evt)
{
	auto win = new CNewsList("Stiri despre Educatie");
	win->Show();
	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_medicina(wxCommandEvent&evt)
{
	auto win = new CNewsList("Stiri despre Medicina");
	win->Show();
	this->Close();
	evt.Skip();
}

void CNewsWindow::on_click_relatii_internationale(wxCommandEvent&evt)
{
	auto win = new CNewsList("Stiri despre Relatii Internationale");
	win->Show();
	this->Close();
	evt.Skip();
}
