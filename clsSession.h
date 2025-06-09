#pragma once

#include <string>
#include "clsBankUser.h"

class clsSession {
public:
    static std::string Username;
    static std::string Password;
    static clsBankUser CurrentUser;
};
