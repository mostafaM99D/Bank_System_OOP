#pragma once
#include"Core.h";
#include"clsBankUser.h"
using namespace std;

class clsDeleteUsers :protected clsHeader {


private:
	static void _DeleteClient() {
		string user = clsInputValidate::ReadString("Enter the username : ");
		while (true) {
			if (!clsBankUser::IsUserExistByUsername(user)) {
				cout << "The user with [" << user << "] is not exist.Please enter another account number" << endl;
				user = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankUser User = clsBankUser::Find(user);
		User.Print();
		char c;
		cout << "\n\nDo you sure for deleting this user (y/n) ?";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			if (User.Delete()) {
				cout << "User with [" << user << "] is deleted successfully." << endl;
			}
			else
				cout << "Error occured during delete this client" << endl;
		}
	}

public:


	

	static void ShowDeleteScreen() {
		_DeleteClient();
	}

};