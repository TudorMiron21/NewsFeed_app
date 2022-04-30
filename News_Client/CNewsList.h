#pragma once
#include"wx/listctrl.h"
#include"Client_Connect.h"
#include"IdButton.h"

class CNewsList:public wxFrame
{
public:

	CNewsList(const wxString & title);
protected:
	wxListView * basicList;
	void on_click_back(wxCommandEvent&);

	wxDECLARE_EVENT_TABLE();
	
	//int list_item_index;
};

