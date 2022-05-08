#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "INewsList.h"
#include"IdButton.h"
#include<vector>
#include"CStire.h"
#include"CButton.h"
#include"CNews_text.h"
#include"wx/listctrl.h"


class CTable_list : public INewsList,public wxFrame
{
public:
    CTable_list(const wxString& title,type_stire type);
    void on_click_view(wxCommandEvent& evt);

protected:

    type_stire type;
    wxListView* basicList;
    wxPanel* panel;
    std::vector<CButton*> button_vector;

    void on_click_back(wxCommandEvent& evt);


    virtual void InsertNews(std::vector<CStire> vec)override;

    
};

