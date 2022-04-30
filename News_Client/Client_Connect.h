#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <olc_net.h>

#include"wx/wx.h"

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
	Inregistrare_admin
};



class CustomClient : public olc::net::client_interface<CustomMsgTypes>
{
public:
	//void PingServer()
	//{
	//	olc::net::message<CustomMsgTypes> msg;
	//	msg.header.id = CustomMsgTypes::ServerPing;

	//	// Caution with this...
	//	std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

	//	msg << timeNow;
	//	Send(msg);
	//}


	//void MessageAll()
	//{
	//	olc::net::message<CustomMsgTypes> msg;
	//	msg.header.id = CustomMsgTypes::MessageAll;
	//	Send(msg);
	//}

	void Autentification(std::string nume, std::string parola);

	void Inregistrare(std::string nume, std::string parola);

	CustomClient(const CustomClient&) = delete;
	static CustomClient* get_instance();
private:

	static CustomClient* instance;
	CustomClient(){}

};


