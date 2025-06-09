#pragma once
#include "clsHeader.h"
#include "clsInputValidate.h"
#include "Core.h"
#include"clsShowDepositeScreen.h"
#include"clsShowWithDrawScreen.h"
#include"clsShowTotalBalanceScreen.h"

using namespace std;

class clsTransactionScreen {


private:
	enum enChoice { Deposite = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4 };
	static void _WhatHappenAfterChoic(enChoice choice) {
		switch (choice)
		{
		case Deposite:
			system("cls");
			clsDepositeScreen::ShowDepositeScreen();
			cout << "\t\t\t\t\tPress any key to return to transaction menu ..." << endl;
			system("Pause>nul");
			ShowTransactionScreen();

			break;
		case Withdraw:

			system("cls");
			clsHeader::DrawHeader("Withdraw Screen");
			clsWithDrawScreen::ShowDepositeScreen();
			cout << "\t\t\t\t\tPress any key to return to transaction menu ..." << endl;
			system("Pause>nul");
			ShowTransactionScreen();
			break;
		case TotalBalances:
			system("cls");
			clsHeader::DrawHeader("Total Balances");
			clsTotalBalanceScreen::ShowTotalBalanceScreen();
			cout << "\n\t\t\t\t\tPress any key to return to transaction menu ..." << endl;
			system("Pause>nul");
			ShowTransactionScreen();
			break;
		default:
			system("cls");
			break;
		}
	}

public :
	

	static void ShowTransactionScreen() {
		system("cls");
		clsHeader::DrawHeader("Transactions");
		cout << "\t\t\t\t\t[1] Deposite." << endl;
		cout << "\t\t\t\t\t[2] Withdraw." << endl;
		cout << "\t\t\t\t\t[3] Total balances." << endl;
		cout << "\t\t\t\t\t[4] Main menu." << endl;
		cout << "\t\t\t\t\t=================================" << endl;
		cout << "\t\t\t\t\tChoose do you want (1 to 4) : ";
		_WhatHappenAfterChoic((enChoice)clsInputValidate::ReadIntNumberBetween(1, 4));
	}

};