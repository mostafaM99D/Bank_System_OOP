#pragma once
#include"Core.h"
#include"clsBankUser.h"
using namespace std;

class clsUpdateUserScreen {

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

	static void _ReadData(clsBankUser& User) {
		cout << "\nEnter the first name : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter the last name : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter the email : ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter the phone number : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter the username : ";
		User.Username = clsInputValidate::ReadString();
		cout << "\nEnter the password : ";
		User.Password = clsInputValidate::ReadString();

		_ReadPermissions(User);
	}
	static void _UpdateUser() {

		cout << "Enter the username : ";
		string username = clsInputValidate::ReadString();
		while (true) {
			if (!clsBankUser::IsUserExistByUsername(username)) {
				cout << "Client with [" << username << "] is not exist." << endl;
				username = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankUser user = clsBankUser::Find(username);
		user.Print();
		char c;
		cout << "\n\nAre you sure for updating this client (y/n) ?";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			_ReadData(user);
			switch (user.Save())
			{
			case clsBankClient::enSaveStatus::SuccessSave:
				cout << "user with [" << username << "] updated successfully." << endl;
				break;
			case clsBankClient::enSaveStatus::FaildSave:
				cout << "Error occured during update user." << endl;
				break;
			}
		}
	}


public:
	static void ShowUpdateScreen() {
		_UpdateUser();
	}

};