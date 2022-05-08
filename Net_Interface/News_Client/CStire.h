#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Client_Connect.h"
#include<iostream>

class CStire
{
public:
	enum class type_stire { Sport, Medicina, Relatii_internationale, Educatie, Economie };
private:

	std::string Titlu;
	std::string File_stire;
	type_stire type;
	int ID;

public:

	CStire(std::string Titlu, std::string File_stire, type_stire type, int  ID);
	CStire(){}
	std::string& get_titlu() { return this->Titlu; }
	std::string& get_file_stire() { return this->File_stire; }
	type_stire& get_type_stire() { return this->type; }
	int & get_ID() { return this->ID; }

};

