#include "CUser.h"

CUser::CUser(type_user type)
	:type(type)
{
}

IUser::type_user CUser::get_identity()
{
	return type;
}

void CUser::set_identity(type_user type)
{
	this->type = type;
}
