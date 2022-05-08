#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"Client_Connect.h"
#include"IdButton.h"
#include "CMainWindow.h"

class CApp :public wxApp
{
public:

	virtual bool OnInit()override;
	
private:

	CMainWindow * m_frame1 = nullptr;

public:
};



