#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"IdButton.h"
#include"CTable_list.h"
class CNewsList:public CTable_list 
{
public:

	CNewsList(const wxString & title, INewsList::type_stire type, std::vector<CStire> vec);
private:

	void on_click_view(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
	
};

