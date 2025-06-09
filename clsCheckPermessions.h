#pragma once
#include"Core.h"
#include"clsBankUser.h"
#include"clsSession.h"

class clsCheckPermessions {

private:
	static bool CheckAccessPermission(int Permission)
	{
		if (clsSession::CurrentUser.Permissions == clsBankUser::enPermessions::all)
			return true;
		return ((Permission & clsSession::CurrentUser.Permissions) == Permission);
	}


public :

	static bool IsChecked(clsBankUser::enPermessions ScreenChoice) {
		if (CheckAccessPermission((int)ScreenChoice))
			return true;
		else
			return false;
	}
	static void ShowAccessDeniedMessage()
	{
		cout << "\n\t\t\t\t\t------------------------------------\n";
		cout << "\t\t\t\t\tAccess Denied, \n\t\t\t\t\tYou dont Have Permission To Do this, \n\t\t\t\t\tPlease Conact Your Admin.";
		cout << "\n\t\t\t\t\t------------------------------------\n";
	}

};