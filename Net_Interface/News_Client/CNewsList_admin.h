#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"CTable_list.h"

class CNewsList_admin :public CTable_list
{
public:
    CNewsList_admin(const wxString& title,INewsList::type_stire type, std::vector<CStire> vec);

private:

    wxButton* add_button;
    void on_click_add(wxCommandEvent& evt);
    wxDECLARE_EVENT_TABLE();
};

