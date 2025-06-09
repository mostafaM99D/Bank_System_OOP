#pragma once
#include"Core.h"
#include"clsBankClient.h"
using namespace std;

class clsShowAllScreen : protected clsHeader {

private:

	static void _PrintClientCard(clsBankClient Client) {
		cout << "\n\n\t\t\t\t\tThe following are the client details : " << endl;
		cout << "\t\t\t\t\t===========================" << endl;
		cout << "\t\t\t\t\tAccount number : " << Client.GetAccountNumber() << endl;
		cout << "\t\t\t\t\tPin code : " << Client.PinCode << endl;
		cout << "\t\t\t\t\tName : " << Client.GetFullName() << endl;
		cout << "\t\t\t\t\tPhone number : " << Client.Phone << endl;
		cout << "\t\t\t\t\tAccount balance : " << Client.Balance << endl;
		cout << "\t\t\t\t\t===========================" << endl;
	}
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.Balance;
	}
	static void _PrintInBalaneceMode(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.Balance;
	}
	static void _PrintAllInBalanceMode(vector<clsBankClient> clients) {
		cout << "\n\t\t\t\t\tClient List (" << clients.size() << ")Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (clsBankClient Client : clients) {
			_PrintInBalaneceMode(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

public:

	static void PrintAllClients(vector<clsBankClient> clients) {
		cout << "\n\t\t\t\t\tClient List (" << clients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (clsBankClient Client : clients) {
			_PrintClientRecord(Client);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};