#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include"Client_Connect.h"
#include"CMainWindow.h"
class CLog_In:public wxFrame
{


public:
	CLog_In();
	
private:

	wxTextCtrl* name_slot;
	wxTextCtrl* password_slot;

	void on_click_back(wxCommandEvent&);
	void on_click_autentificare(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();

};

