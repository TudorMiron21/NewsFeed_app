#include "CCustomServer.h"
#include<fstream>
#include<string>
bool CCustomServer::OnClientConnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client)
{
		olc::net::message<CustomMsgTypes> msg;
		msg.header.id = CustomMsgTypes::ServerAccept;
		client->Send(msg);
		return true;
}

void CCustomServer::OnClientDisconnect(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client)
{
	std::cout << "Removing client [" << client->GetID() << "]\n";
}

void CCustomServer::OnMessage(std::shared_ptr<olc::net::connection<CustomMsgTypes>> client, olc::net::message<CustomMsgTypes>& msg)
{
	switch (msg.header.id)
	{
	
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
			if (DataBase::get_instance()->Autentificare(nume_parola_vec[0], nume_parola_vec[1]) == true)
			{
				std::cout << "userul cu credentialele:" << nume_parola_vec[0] << " si " << nume_parola_vec[1] << " a fost autentificat\n";
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

	case CustomMsgTypes::Sport:
	{
		std::cout << "[" << client->GetID() << "]: request Sport news\n";
		std::vector<CStire> send_vec=DataBase::get_instance()->request_news(CStire::type_stire::Sport);

		int size = send_vec.size();
		int size_copy = size;

		while (size--)
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Sport;
			char News[100];
			CStire current = send_vec.back();
			send_vec.pop_back();
			int i = 0;
			for (int ch=0; ch < current.get_titlu().size(); i++)
				News[i] = current.get_titlu()[ch++];
			News[i++] = '|';

			for (int ch=0; ch < current.get_file_stire().size(); i++)
				News[i] = current.get_file_stire()[ch++];
			News[i++] = '|';

			for (int ch=0; ch < current.get_ID().size(); i++)
				News[i] = current.get_ID()[ch++];

			News[i++] = '\0';

			mesaj << News;

			client->Send(mesaj);
		}

		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id= CustomMsgTypes::Sport;
		mesaj << size_copy;
		client->Send(mesaj);
	}
	break;

	case CustomMsgTypes::Economie:
	{
		std::cout << "[" << client->GetID() << "]: request Economie news\n";
		std::vector<CStire> send_vec = DataBase::get_instance()->request_news(CStire::type_stire::Economie);

		int size = send_vec.size();
		int size_copy = size;

		while (size--)
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Economie;
			char News[100];
			CStire current = send_vec.back();
			send_vec.pop_back();
			int i = 0;
			for (int ch = 0; ch < current.get_titlu().size(); i++)
				News[i] = current.get_titlu()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_file_stire().size(); i++)
				News[i] = current.get_file_stire()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_ID().size(); i++)
				News[i] = current.get_ID()[ch++];

			News[i++] = '\0';

			mesaj << News;

			client->Send(mesaj);
		}

		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id = CustomMsgTypes::Economie;
		mesaj << size_copy;
		client->Send(mesaj);
	}
	break;

	case CustomMsgTypes::Educatie:
	{
		std::cout << "[" << client->GetID() << "]: request Educatie news\n";
		std::vector<CStire> send_vec = DataBase::get_instance()->request_news(CStire::type_stire::Educatie);

		int size = send_vec.size();
		int size_copy = size;

		while (size--)
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Educatie;
			char News[100];
			CStire current = send_vec.back();
			send_vec.pop_back();
			int i = 0;
			for (int ch = 0; ch < current.get_titlu().size(); i++)
				News[i] = current.get_titlu()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_file_stire().size(); i++)
				News[i] = current.get_file_stire()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_ID().size(); i++)
				News[i] = current.get_ID()[ch++];

			News[i++] = '\0';

			mesaj << News;

			client->Send(mesaj);
		}

		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id = CustomMsgTypes::Educatie;
		mesaj << size_copy;
		client->Send(mesaj);
	}
	break;

	case CustomMsgTypes::Medicina:
	{
		std::cout << "[" << client->GetID() << "]: request Medicina news\n";
		std::vector<CStire> send_vec = DataBase::get_instance()->request_news(CStire::type_stire::Medicina);

		int size = send_vec.size();
		int size_copy = size;

		while (size--)
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Medicina;
			char News[100];
			CStire current = send_vec.back();
			send_vec.pop_back();
			int i = 0;
			for (int ch = 0; ch < current.get_titlu().size(); i++)
				News[i] = current.get_titlu()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_file_stire().size(); i++)
				News[i] = current.get_file_stire()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_ID().size(); i++)
				News[i] = current.get_ID()[ch++];

			News[i++] = '\0';

			mesaj << News;

			client->Send(mesaj);
		}

		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id = CustomMsgTypes::Medicina;
		mesaj << size_copy;
		client->Send(mesaj);
	}
	break;

	case CustomMsgTypes::Relatii_Internationale:
	{
		std::cout << "[" << client->GetID() << "]: request Relatii Internationale news\n";
		std::vector<CStire> send_vec = DataBase::get_instance()->request_news(CStire::type_stire::Relatii_internationale);

		int size = send_vec.size();
		int size_copy = size;

		while (size--)
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Relatii_Internationale;
			char News[100];
			CStire current = send_vec.back();
			send_vec.pop_back();
			int i = 0;
			for (int ch = 0; ch < current.get_titlu().size(); i++)
				News[i] = current.get_titlu()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_file_stire().size(); i++)
				News[i] = current.get_file_stire()[ch++];
			News[i++] = '|';

			for (int ch = 0; ch < current.get_ID().size(); i++)
				News[i] = current.get_ID()[ch++];

			News[i++] = '\0';

			mesaj << News;

			client->Send(mesaj);
		}

		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id = CustomMsgTypes::Relatii_Internationale;
		mesaj << size_copy;
		client->Send(mesaj);
	}
	break;

	case CustomMsgTypes::Request_News:
	{
		std::cout << "[" << client->GetID() << "]: request  news text \n";
		std::ifstream f;
		char file_name[30];
		msg >> file_name;
		f.open(file_name, std::ios::in);
	  std::string line;
		char count = 0;
		while (std::getline(f, line))
		{
			olc::net::message<CustomMsgTypes> mesaj;
			mesaj.header.id = CustomMsgTypes::Request_News;
			char line_vec[100];
			
			f >> line;
			int i = 0;
			for (; i < line.size(); i++)
				line_vec[i] = line[i];
			
			line_vec[--i] = '\0';

			mesaj << line_vec;

			client->Send(mesaj);
			count++;
		}

	
		olc::net::message<CustomMsgTypes> mesaj;
		mesaj.header.id = CustomMsgTypes::Request_News;
		char copy = count;
		mesaj << copy;
		client->Send(mesaj);


	}
	break;
	}
}

