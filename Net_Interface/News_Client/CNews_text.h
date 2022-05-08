#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"IdButton.h"
#include"CTable_list.h"

class CNews_text:public wxFrame
{
public:

	CNews_text(std::string Title,std::vector<std::string> news);

private:
	wxPanel* panel;
	wxListBox * news;
	void on_click_back(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

