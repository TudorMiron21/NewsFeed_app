
#include "CAdmin.h"
CAdmin* CAdmin::instance = nullptr;

CAdmin::CAdmin(type_user type)
	:CUser(type)
{

}

CAdmin* CAdmin::get_instance()
{
	if (instance == nullptr)
		instance = new CAdmin(IUser::type_user::Admin);
	return instance;
}

bool CAdmin::is_logged()
{
	if (instance == nullptr)
		return false;
	return true;
}
