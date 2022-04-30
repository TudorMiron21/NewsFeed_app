#pragma once




#include "IdButton.h"
#include "CLog_In.h"
#include "CSign_In.h"
#include"Client_Connect.h"

class CMainWindow: public wxFrame
{
public:

	CMainWindow();

	~CMainWindow(){}

private:
	void on_click_sign_in(wxCommandEvent&);
	void on_click_log_in(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};



