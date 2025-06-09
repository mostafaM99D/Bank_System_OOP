#pragma once
#include"Core.h"
using namespace std;


class clsUpdate {

private:
	static void _ReadData(clsBankClient& client) {
		cout << "\nEnter the first name : ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter the last name : ";
		client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter the email : ";
		client.Email = clsInputValidate::ReadString();
		cout << "\nEnter the phone number : ";
		client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter the PIN code : ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter the account balance : ";
		client.Balance = clsInputValidate::ReadDblNumber();
	}


public:

	static void UpdateClient() {

		cout << "Enter the account number : ";
		string accNumber = clsInputValidate::ReadString();
		while (true) {
			if (!clsBankClient::IsClientExistByAccountNumber(accNumber)) {
				cout << "Client with [" << accNumber << "] is not exist." << endl;
				accNumber = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankClient client = clsBankClient::Find(accNumber);
		client.Print();
		char c;
		cout << "\n\nAre you sure for updating this client (y/n) ?";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			_ReadData(client);
			switch (client.Save())
			{
			case clsBankClient::enSaveStatus::SuccessSave:
				cout << "Client with [" << accNumber << "] updated successfully." << endl;
				break;
			case clsBankClient::enSaveStatus::FaildSave:
				cout << "Error occured during update client." << endl;
				break;
			}
		}
	}
};