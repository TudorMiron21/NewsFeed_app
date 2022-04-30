#pragma once
#include<iostream>
#include <mysql.h>
class DataBase
{

private:
	static DataBase* instance;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int state;
	DataBase();

public:

	static DataBase* get_instance();
	bool Autentificare(std::string nume ,std::string parola);
	bool Inregistrare(std::string nume ,std::string prola);
};