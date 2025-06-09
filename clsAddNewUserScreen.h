#pragma once
#include"Core.h"
#include"clsBankUser.h"
using namespace std;
class clsAddNewUser {


private:
	static int _ReadPermissions(clsBankUser& User) {
		char c = ' ';
		cout << "\nDo you want to give this user all permissions ?(y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions = clsBankUser::enPermessions::all;
			return User.Permissions;
		}
		User.Permissions = 0;
		cout << "Do you want give this user permission to show all clients ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::showall;
		}
		cout << "Do you want give this user permission to add new clients ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::New;
		}
		cout << "Do you want give this user permission to show delete clients ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::delet;
		}
		cout << "Do you want give this user permission to update clients? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::update;
		}
		cout << "Do you want give this user permission to find clients ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::find;
		}
		cout << "Do you want give this user permission to transaction ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::transaction;
		}
		cout << "Do you want give this user permission to manage users ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::manageusers;
		}
		cout << "Do you want give this user permission to logs screen ? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y') {
			User.Permissions += clsBankUser::enPermessions::logs;
		}

		return User.Permissions;
	}

	static void ReadData(clsBankUser& User) {
		User.FirstName = clsInputValidate::ReadString("Enter the first name : ");
		User.LastName = clsInputValidate::ReadString("Enter the last name : ");
		User.Email = clsInputValidate::ReadString("Enter the email : ");
		User.Phone = clsInputValidate::ReadString("Enter the phone : ");
		User.Password = clsInputValidate::ReadString("Enter the password : ");
		User.Permissions = _ReadPermissions(User);
	}
	static void _ShowAddNewUserScreen() {
		cout << "Enter the username : ";
		string username = clsInputValidate::ReadString();
		while (true) {
			if (clsBankUser::IsUserExistByUsername(username)) {
				cout << "The user with [" << username << "] is already exist, please enter another username : ";
				username = clsInputValidate::ReadString();
			}
			else
				break;
		}

		clsBankUser NewClient = clsBankUser::GetAddNewObject(username);
		ReadData(NewClient);
		switch (NewClient.Save())
		{
		case clsBankUser::SuccessfullSave:
			cout << "User with ["<<username<<"] added successfully." << endl;
			break;
		case clsBankUser::FailedSave:
			cout << "Error occured when add new user" << endl;
		default:
			break;
		}



	}

public:

	static void ShowAddNewUserScreen() {
		_ShowAddNewUserScreen();
	}

};