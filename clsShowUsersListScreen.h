#pragma once
#include"Core.h"
#include"clsBankUser.h"
using namespace std;
class clsShowAllUsersScreen {



private:
	static void _PrintAllUsers() {
		clsBankUser::PrintAllUsers();
	}

public:


	static void ShowAllUsers() {

		_PrintAllUsers();

	}

};