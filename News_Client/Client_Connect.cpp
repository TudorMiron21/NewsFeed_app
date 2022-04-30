#include "Client_Connect.h"
CustomClient* CustomClient::instance = nullptr;
void CustomClient::Autentification(std::string nume, std::string parola)
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Autentificare;
	char NumeParola[60];
	for (int i=0;i<nume.size(); i++)
	{
		NumeParola[i] = nume[i];
	}
	NumeParola[nume.size()] = '|';
	int add = nume.size() +1;
	for (int i = 0; i < parola.size(); i++)
	{
		NumeParola[i+add] = parola[i];
	}
	NumeParola[parola.size()+ nume.size()+1] = '\0';

	msg << NumeParola;
	Send(msg);
}

void CustomClient::Inregistrare(std::string nume, std::string parola)
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Inregistrare;
	char NumeParola[60];
	for (int i = 0; i < nume.size(); i++)
	{
		NumeParola[i] = nume[i];
	}
	NumeParola[nume.size()] = '|';
	int add = nume.size() + 1;
	for (int i = 0; i < parola.size(); i++)
	{
		NumeParola[i + add] = parola[i];
	}
	NumeParola[parola.size() + nume.size() + 1] = '\0';

	msg << NumeParola;
	Send(msg);
}

CustomClient* CustomClient::get_instance()
{
	if (instance == nullptr)
		instance = new CustomClient();
	return instance;
}
