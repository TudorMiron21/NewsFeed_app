#pragma once

#include"Client_Connect.h"
#include"CMainWindow.h"
class CSign_In :public wxFrame
{
public:
	CSign_In();

private:
	wxPanel* panel;
	wxTextCtrl* name_slot;
	wxTextCtrl* password_slot;
	wxTextCtrl* password_slot_again;
	void on_click_back(wxCommandEvent&);
	void on_click_inregistrare(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};
