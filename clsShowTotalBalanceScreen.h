#pragma once
#include"Core.h"

class clsTotalBalanceScreen {

private:



public :



	static void ShowTotalBalanceScreen() {

		clsBankClient::PrintAllInBalanceMode();
		cout << "\n\t\t\t\t\t\tTotal Balances : " << clsBankClient::GetTotalBalances() << endl;

	}


};