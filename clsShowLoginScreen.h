#pragma once
#include"Core.h";
#include"clsBankUser.h"
#include"clsSession.h"
#include"clsMainMenuScreen.h"
using namespace std;
class clsMainMenuScreen;
class clsLoginScreen :protected clsHeader{

private:
	static bool _ShowLoginScreen() {
		 clsSession::Username = clsInputValidate::ReadString("\t\t\t\t\tEnter the username : ");
		 clsSession::Password = clsInputValidate::ReadString("\t\t\t\t\tEnter the password : ");
		 short t=3;
		while (true) {
			if (!clsBankUser::IsUserExistByUsernameAndPassword(clsSession::Username, clsSession::Password)) {
				t--;
				if (!t) {
					system("cls");
					cout << "\t\t\t\t\t=====================" << endl;
					cout << "\t\t\t\t\tThe system is locked." << endl;
					cout << "\t\t\t\t\t=====================" << endl;
					return false;
				}
				system("cls");
				DrawHeader("Login Screen");
				cout << "\t\t\t\t\tInvalid Username / Password ." << endl;
				cout << "\t\t\t\t\tYou have (" << t << ") trail(s) before locked system." << endl;
				clsSession::Username = clsInputValidate::ReadString("\t\t\t\t\tEnter the username : ");
				clsSession::Password = clsInputValidate::ReadString("\t\t\t\t\tEnter the password : ");

			}
			else
				break;

		}
		clsSession::CurrentUser = clsBankUser::Find(clsSession::Username, clsSession::Password);
		clsSession::CurrentUser.LogFile();
		//clsReturnToMainMenu::ReturnToMainMenu();
		clsMainMenuScreen::ShowMainMenuScreen();
		clsSession::CurrentUser = clsBankUser::Find("","");
		return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		 DrawHeader("Login Screen");
		return _ShowLoginScreen();		
	}
};