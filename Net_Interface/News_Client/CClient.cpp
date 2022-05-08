#include "CClient.h"
CClient* CClient::instance = nullptr;

CClient::CClient(type_user type)
	:CUser(type)
{

}
CClient* CClient::get_instance()
{
	if (instance == nullptr)
		instance = new CClient(IUser::type_user::Client);
	return instance;
}

bool CClient::is_logged()
{
	if (instance == nullptr)
		return false;
	return true;
}


