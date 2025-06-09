#pragma once
#include"Core.h";


class clsWithDrawScreen :protected clsHeader
{
private:

	static void _Deposite(clsBankClient& Client,double amount) {

		char c;
		cout << "\n\nAre you sure for do this operation (y/n) ?";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			Client.Balance += amount;
			switch (Client.Save())
			{
			case clsBankClient::enSaveStatus::SuccessSave:
				cout << "amout in account with [" << Client.GetAccountNumber() << "] updated successfully." << endl;
				break;
			case clsBankClient::enSaveStatus::FaildSave:
				cout << "Error occured during update client." << endl;
				break;
			}
		}

	}


public:

	static void ShowDepositeScreen() {

		DrawHeader("Deposite Screen");
		cout << "Enter account number : ";
		string accNum = clsInputValidate::ReadString();
		while (true) {
			if (!clsBankClient::IsClientExistByAccountNumber(accNum)) {
				cout << "The client with [" << accNum << "] is not founded, Please enter another account number : ";
				accNum = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankClient Client = clsBankClient::Find(accNum);
		Client.Print();
		double ammount;
		cout << "\nEnter the amount you want to withdraw : ";
		ammount = (clsInputValidate::ReadDblNumber());
		while (true) {
			if (ammount > Client.Balance || ammount < 0) {
				cout << "You can only withdraw form 0 to " << Client.Balance << " , Enter another amount : ";
				ammount = clsInputValidate::ReadDblNumber();
			}
			else
				break;
		}

		_Deposite(Client,-ammount);

	}


};