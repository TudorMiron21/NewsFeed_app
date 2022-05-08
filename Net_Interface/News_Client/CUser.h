#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "IUser.h"
class CUser :
    public IUser
{
protected:
    type_user type;

public:
    CUser(type_user type);
    virtual IUser::type_user get_identity()override;
    virtual void set_identity(type_user type)override;
};


