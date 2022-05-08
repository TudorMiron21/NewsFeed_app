#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Client_Connect.h"
#include"IdButton.h"
#include"CNewsList.h"
#include"CNewsList_admin.h"
#include"CAdmin.h"
#include"CClient.h"
#include"CStire.h"
class CNewsWindow:public wxFrame
{
public:
	CNewsWindow();

private:
	wxPanel* panel;
	std::vector<CStire> split_server_message(CStire::type_stire type);
	void on_click_sport(wxCommandEvent&);
	void on_click_economie(wxCommandEvent&);
	void on_click_educatie(wxCommandEvent&);
	void on_click_medicina(wxCommandEvent&);
	void on_click_relatii_internationale(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();

};

