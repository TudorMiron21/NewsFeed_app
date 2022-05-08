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

void CustomClient::Get_Sport()
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Sport;
	Send(msg);
}

void CustomClient::Get_Educatie()
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Educatie;
	Send(msg);
}

void CustomClient::Get_Economie()
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Economie;
	Send(msg);
}

void CustomClient::Get_Medicina()
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Medicina;
	Send(msg);
}

void CustomClient::Get_News(std::string file_name)
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Request_News;
	char filename[30];
	int i = 0;
	for (; i < file_name.size(); i++)
	{
		filename[i] = file_name[i];
	}
	filename[i++] = '\0';

	msg << filename;
	Send(msg);
}

void CustomClient::Get_Relatii()
{
	olc::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::Relatii_Internationale;
	Send(msg);
}


