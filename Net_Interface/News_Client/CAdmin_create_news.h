#pragma once
#include"Client_Connect.h"
#include"CStire.h"



class CAdmin_create_news: 
	public wxFrame
{
public:
	CAdmin_create_news();

private:

	void on_click_back(wxCommandEvent&);
	void on_click_commit(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};

