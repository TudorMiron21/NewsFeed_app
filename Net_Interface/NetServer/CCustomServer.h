#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <olc_net.h>
#include"DataBase.h"
#include <mysql.h>

enum class CustomMsgTypes : uint32_t
{
	ServerAccept_log = 1,
	ServerDeny_log,
	ServerAccept,
	ServerDeny,
	ServerPing,
	MessageAll,
	ServerMessage,
	Autentificare,
	Inregistrare,
	Inregistrare_Admin,
	Sport,
	Medicina,
	Educatie,
	Economie,
	Relatii_Internationale,
	Request_News,
};

class CCustomServer :public olc::net::server_interface<CustomMsgTypes>
{
public:
	CCustomServer(uint16_t nPort) : olc::net::server_interface<CustomMsgTypes>(nPort)
	{

	}

protected:
	

	virtual bool OnClientConnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client);

	virtual void OnClientDisconnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client);
	
	virtual void OnMessage(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client, olc::net::message<CustomMsgTypes>& msg);

};

