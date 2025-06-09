#pragma once
#include"Core.h"
#include"clsBankUser.h"
using namespace std;

class clsFindUser {
private:
	static void _FindClient(string username) {

		if (!clsBankUser::IsUserExistByUsername(username))
			cout << "Client with [" << username << "] is not exist." << endl;

		clsBankUser User = clsBankUser::Find(username);
		User.Print();
	}
public:


	static void FindUserScreen(string username) {
		_FindClient(username);

	}
};