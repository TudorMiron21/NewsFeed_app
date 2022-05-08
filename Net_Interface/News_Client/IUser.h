#pragma once
#define _CRT_SECURE_NO_WARNINGS
class IUser
{
public:

	enum class type_user{Admin,Client};

	virtual type_user get_identity() = 0;
	virtual void set_identity(type_user) = 0;
	
};

