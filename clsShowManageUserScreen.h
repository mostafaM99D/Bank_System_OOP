#pragma once
#include"Core.h"
#include"clsShowUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsShowUpdateScreen.h"
#include"clsShowDeleteUserScreen.h"
#include"clsShowFindUserScreen.h"
using namespace std;
class clsManageUserScreen :protected clsHeader {
private:
	enum enUsersChoice { ShowAllUsers = 1, AddNewUsers = 2, DeleteUsers = 3, UpdateUsers = 4, FindUsers = 5 };
	static void WhatHappenAfterUsersChoic(enUsersChoice choice) {

		switch (choice)
		{
		case ShowAllUsers:
			system("cls");
			DrawHeader("Show Users");
			clsShowAllUsersScreen::ShowAllUsers();
			cout << "\t\t\t\t\tPress any key to return to manage users menu ..." << endl;
			system("Pause>nul");
			_ShowManageUsersScreen();
			break;
		case AddNewUsers:
			system("cls");
			DrawHeader("Add Users");
			clsAddNewUser::ShowAddNewUserScreen();
			cout << "\n\t\t\t\t\tPress any key to return to  manage users menu ..." << endl;
			system("Pause>nul");
			_ShowManageUsersScreen();
			break;
		case DeleteUsers:
			system("cls");
			DrawHeader("Delete Users");
			clsDeleteUsers::ShowDeleteScreen();
			cout << "\n\t\t\t\t\tPress any key to return to  manage users menu ..." << endl;
			system("Pause>nul");
			_ShowManageUsersScreen();
			break;
		case UpdateUsers:
			system("cls");
			DrawHeader("Update Users");
			clsUpdateUserScreen::ShowUpdateScreen();
			cout << "\n\t\t\t\t\tPress any key to return to  manage users menu ..." << endl;
			system("Pause>nul");
			_ShowManageUsersScreen();
			break;
		case FindUsers:
			system("cls");
			DrawHeader("Find Users");
			clsFindUser::FindUserScreen(clsInputValidate::ReadString("Enter the username : "));
			cout << "\n\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			_ShowManageUsersScreen();
			break;
		default:
			break;
		}
	}

	static void _ShowManageUsersScreen() {
		system("cls");
		DrawHeader("Manage Users");
	
		cout << "\t\t\t\t\t[1] List users." << endl;
		cout << "\t\t\t\t\t[2] Add new user." << endl;
		cout << "\t\t\t\t\t[3] Delete user." << endl;
		cout << "\t\t\t\t\t[4] Update user." << endl;
		cout << "\t\t\t\t\t[5] Find user." << endl;
		cout << "\t\t\t\t\t[6] Main menu." << endl;
		cout << "\t\t\t\t\t============================" << endl;

		cout << "\t\t\t\t\tChoose what do you want (1 to 6) : ";
		WhatHappenAfterUsersChoic((enUsersChoice)clsInputValidate::ReadIntNumberBetween(1,6));
	}


public:
	static void ShowManageUserScreen() {
		_ShowManageUsersScreen();
	}



};