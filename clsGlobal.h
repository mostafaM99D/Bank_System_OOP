#pragma once
#include"clsBankUser.h"
struct Data
{
	static string Username;
	static string Password;
	static clsBankUser CurrentUser(string username,string password) {
		Username = username;
		Password = password;
		return clsBankUser::Find(username, password);
	}
};