#pragma once
#include"Core.h"
#include"clsHeader.h"
#include"clsInputValidate.h"
#include"clsShowAllScreen.h"
#include"clsAddNewScreen.h"
#include"DeleteScreen.h";
#include"clsUpdateScreen.h"
#include"clsFindScreen.h"
#include"ShowTransactionScreen.h"
#include"clsShowManageUserScreen.h"
#include"clsCheckPermessions.h"
#include"clsShowLoginScreen.h"
#include"LogsScreen.h"

using namespace std;

class clsMainMenuScreen :protected clsHeader {

private:
	enum _enClientChoice { ShowAll = 1, AddNew = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, ManageUsers = 7,Logs=8 };
	static void _WhatHappenAfterChoic(_enClientChoice choice) {
		switch (choice)
		{
		case ShowAll:
			system("cls");
			clsHeader::DrawHeader("Show Client List");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::showall))
				clsShowAllScreen::PrintAllClients(clsBankClient::GetClientsList());
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();
			break;
		case AddNew:
			system("cls");
			clsHeader::DrawHeader("Add New Clients");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::New))
				clsAddNew::AddNewClient();
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\n\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();
			break;
		case Delete:
			system("cls");
			clsHeader::DrawHeader("Delete Clients");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::delet))

				clsDelete::DeleteClient();
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\n\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();

			break;
		case Update:
			system("cls");
			clsHeader::DrawHeader("Update Clients");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::update))
				clsUpdate::UpdateClient();
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\n\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();

			break;
		case Find:
			system("cls");
			clsHeader::DrawHeader("Find Clients");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::find))
				clsFindClient::FindClient(clsInputValidate::ReadString("Enter the account number : "));
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\n\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();
			break;
		case Transaction:
			system("cls");
			clsHeader::DrawHeader("Transactions");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::transaction))
				clsTransactionScreen::ShowTransactionScreen();
			else
			{
				clsCheckPermessions::ShowAccessDeniedMessage();
				cout << "\t\t\t\t\tPress any key to return to main menu ..." << endl;
				system("Pause>nul");

			}
			ShowMainMenuScreen();

			break;
		case ManageUsers:
			system("cls");
			clsHeader::DrawHeader("Manage Users");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::manageusers))
			clsManageUserScreen::ShowManageUserScreen();
			else
			{
				clsCheckPermessions::ShowAccessDeniedMessage();
				cout << "\t\t\t\t\tPress any key to return to main menu ..." << endl;
				system("Pause>nul");

			}
			ShowMainMenuScreen();

			break;
		case Logs:
			system("cls");
			clsHeader::DrawHeader("Logs Screen");
			if (clsCheckPermessions::IsChecked(clsBankUser::enPermessions::logs))
				clsLogs::ShowLoginRegisterScreen();
			else
				clsCheckPermessions::ShowAccessDeniedMessage();
			cout << "\t\t\t\t\tPress any key to return to main menu ..." << endl;
			system("Pause>nul");
			ShowMainMenuScreen();
			break;
		default:
			system("cls");
			clsHeader::DrawHeader("Logout");
			break;
		}
	}


public:


	static void ShowMainMenuScreen() {
		system("cls");
		clsHeader::DrawHeader("Main Menu");
		cout << "\t\t\t\t\t[1] Show client list." << endl;
		cout << "\t\t\t\t\t[2] Add new client." << endl;
		cout << "\t\t\t\t\t[3] Delete Client." << endl;
		cout << "\t\t\t\t\t[4] Update client data." << endl;
		cout << "\t\t\t\t\t[5] Find client." << endl;
		cout << "\t\t\t\t\t[6] Transactions." << endl;
		cout << "\t\t\t\t\t[7] Manage users." << endl;
		cout << "\t\t\t\t\t[8] Login Logs." << endl;
		cout << "\t\t\t\t\t[9] Logout." << endl;
		cout << "\t\t\t\t\t==================================" << endl;
		cout << "\t\t\t\t\tChoose what do you want (1 to 9) : ";

		_WhatHappenAfterChoic((_enClientChoice)clsInputValidate::ReadIntNumberBetween(1, 9));

	}


};