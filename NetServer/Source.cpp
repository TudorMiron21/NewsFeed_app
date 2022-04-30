#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <olc_net.h>
#include"DataBase.h"
#include <mysql.h>
using namespace std;
enum class CustomMsgTypes : uint32_t
{
	ServerAccept_log=1,
	ServerDeny_log,
	ServerAccept,
	ServerDeny,
	ServerPing,
	MessageAll,
	ServerMessage,
	Autentificare,
	Inregistrare,
	Inregistrare_Admin
};



class CustomServer : public olc::net::server_interface<CustomMsgTypes>
{
public:
	CustomServer(uint16_t nPort) : olc::net::server_interface<CustomMsgTypes>(nPort)
	{

	}

protected:
	virtual bool OnClientConnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client)
	{
		olc::net::message<CustomMsgTypes> msg;
		msg.header.id = CustomMsgTypes::ServerAccept;
		client->Send(msg);
		return true;
	}

	// Called when a client appears to have disconnected
	virtual void OnClientDisconnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client)
	{
		std::cout << "Removing client [" << client->GetID() << "]\n";
	}

	// Called when a message arrives
	virtual void OnMessage(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client, olc::net::message<CustomMsgTypes>& msg)
	{
		switch (msg.header.id)
		{
		//case CustomMsgTypes::ServerPing:
		//{
		//	std::cout << "[" << client->GetID() << "]: Server Ping\n";

		//	// Simply bounce message back to client
		//	client->Send(msg);
		//}
		//break;

		//case CustomMsgTypes::MessageAll:
		//{
		//	std::cout << "[" << client->GetID() << "]: Message\n";

		//	// Construct a new message and send it to all clients
		//	olc::net::message<CustomMsgTypes> msg;
		//	msg.header.id = CustomMsgTypes::ServerMessage;
		//	char vec[50] = "Hello";
		//	vec[5] = '\0';
		//	msg << vec;
		//	client->Send(msg);
		//}
		//break;

		case CustomMsgTypes::Autentificare:
		{
			std::cout << "[" << client->GetID() << "]: Autentificare\n cu urmatoarele credentiale";
			char Credentiale[60];
			msg >> Credentiale;
			printf(" %s\n", Credentiale);

			std::vector<std::string> nume_parola_vec;
			char* word = strtok(Credentiale, "|");

			while (word)
			{
				std::string cuv(word);
				nume_parola_vec.push_back(word);
				word = strtok(NULL, "|");
			}
			olc::net::message<CustomMsgTypes> mesaj;

			if (nume_parola_vec[0] == "admin" && nume_parola_vec[1] == "administrator")
			{
				std::cout << "Administratorul a fost autentificat\n";
				mesaj.header.id = CustomMsgTypes::Inregistrare_Admin;
			}
			else
			if (DataBase::get_instance()->Autentificare(nume_parola_vec[0],nume_parola_vec[1])==true)
			{
				std::cout << "userul cu credentialele:"<< nume_parola_vec[0] <<" si "<< nume_parola_vec[1]<<" a fost autentificat\n";
				mesaj.header.id = CustomMsgTypes::ServerAccept_log; 
			}
			else
			{
				std::cout << "userul cu credentialele:" << nume_parola_vec[0] << " si " << nume_parola_vec[1] << " NU a fost autentificat\n";
				mesaj.header.id = CustomMsgTypes::ServerDeny_log;
			}
			client->Send(mesaj);
		}
			break;



		case CustomMsgTypes::Inregistrare:
		{
			std::cout << "[" << client->GetID() << "]: Inregistrare\n cu urmatoarele credentiale\n";
			char Credentiale[60];
			msg >> Credentiale;
			printf(" %s\n", Credentiale);
			std::vector<std::string> nume_parola_vec;
			char* word = strtok(Credentiale, "|");

			while (word)
			{
				std::string cuv(word);
				nume_parola_vec.push_back(word);
				word = strtok(NULL, "|");
			}
			olc::net::message<CustomMsgTypes> mesaj;


			if (DataBase::get_instance()->Inregistrare(nume_parola_vec[0], nume_parola_vec[1]) == true)
			{
				std::cout << "userul cu credentialele:" << nume_parola_vec[0] << " si " << nume_parola_vec[1] << " a fost inregistrat\n";
				mesaj.header.id = CustomMsgTypes::ServerAccept_log;
			}
			else
			{
				std::cout << "userul cu credentialele:" << nume_parola_vec[0] << " si " << nume_parola_vec[1] << " NU a fost inregistrat\n";
				mesaj.header.id = CustomMsgTypes::ServerDeny_log;
			}
			client->Send(mesaj);

		}
		break;


		}
	}
};

int main()
{
	CustomServer server(60000);
	server.Start();
	DataBase::get_instance();
	
	while (1)
	{
		server.Update(-1, true);
	}

	return 0;
}