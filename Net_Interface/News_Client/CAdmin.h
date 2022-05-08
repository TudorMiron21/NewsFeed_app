#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"CUser.h"
class CAdmin:public CUser
{
private:
    static CAdmin* instance;
    CAdmin(type_user type);

public:

    static CAdmin* get_instance();
    static bool is_logged();
};

