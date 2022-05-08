#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"CStire.h"
#include"Client_Connect.h"

class INewsList
{
public:

	enum class type_window{Client_win,Admin_win};

	enum class type_stire { Sport, Medicina, Relatii_internationale, Educatie, Economie };

	//class News_list_Factory {

	//public:
	//	static INewsList* Create_news_window(type_window type,const wxString& title,type_stire type_st);
	//};


	virtual void InsertNews(std::vector<CStire> vec)=0;
};

