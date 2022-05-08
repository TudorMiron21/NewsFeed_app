#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "CUser.h"
class CClient :
    public CUser
{
private:
    static CClient* instance;
    CClient(type_user type);

public:

    static CClient* get_instance();
    static bool is_logged();
};

