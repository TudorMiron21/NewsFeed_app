#pragma once

#include "IException.h"
class CException :
    public IException
{

    std::string mesaj_err;

public:

    CException(std::string mesaj_err);

};

