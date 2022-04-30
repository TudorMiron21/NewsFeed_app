#pragma once
#include<iostream>
class CStire
{
	enum class type_stire { Sport, Medicina, Relatii_internationale, Educatie, Economie };
private:

	std::string Titlu;
	std::string File_stire;
	type_stire type;
public:

	CStire(std::string Titlu, std::string File_stire, type_stire type);
};

