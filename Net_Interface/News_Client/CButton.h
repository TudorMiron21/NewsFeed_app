#pragma once
#include"Client_Connect.h"

class CButton
{
private:

	wxWindowID ID;
	wxButton* button;
	std::string file_name;
	std::string Titlu;


public:

	CButton(wxWindowID ID, wxButton* button, std::string file_name, std::string Titlu);

	wxWindowID get_id()const { return ID; }
	wxButton* get_button() { return button; }
	std::string get_file_name()const { return file_name; }
	std::string get_titlu()const { return Titlu; }

};

