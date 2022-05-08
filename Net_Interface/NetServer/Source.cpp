#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <olc_net.h>
#include"DataBase.h"
#include <mysql.h>
#include"CCustomServer.h"

int main()
{
	CCustomServer server(60000);
	server.Start();
	DataBase::get_instance();
	
	while (1)
	{
		server.Update(-1, true);
	}

	return 0;
}