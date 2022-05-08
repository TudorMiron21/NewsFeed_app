#pragma once
#include<iostream>
class CStire
{
public:
	enum class type_stire { Sport, Medicina, Relatii_internationale, Educatie, Economie };
private:

	std::string Titlu;
	std::string File_stire;
	type_stire type;
	std::string ID;
public:
	
	CStire(std::string Titlu, std::string File_stire, type_stire type, std::string ID);
	std::string get_titlu()const { return this->Titlu; }
	std::string get_file_stire()const { return this->File_stire; }
	type_stire get_type_stire()const { return this->type; }
	std::string get_ID()const { return this->ID; }
};

