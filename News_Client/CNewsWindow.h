#pragma once
#include"Client_Connect.h"
#include"IdButton.h"
#include"CNewsList.h"

class CNewsWindow:public wxFrame
{
public:
	CNewsWindow();

private:
	wxPanel* panel;
	void on_click_sport(wxCommandEvent&);
	void on_click_economie(wxCommandEvent&);
	void on_click_educatie(wxCommandEvent&);
	void on_click_medicina(wxCommandEvent&);
	void on_click_relatii_internationale(wxCommandEvent&);
	void on_click_back(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();

};

