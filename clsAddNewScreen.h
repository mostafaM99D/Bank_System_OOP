#pragma once
#include"Core.h"

class clsAddNew :protected clsHeader {

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

	static void AddNewClient() {
		cout << "\t\t\t\t\tEnter account number" << endl;
		string accNumber = clsInputValidate::ReadString();
		while (true)
		{
			if (clsBankClient::IsClientExistByAccountNumber(accNumber)) {
				cout << "Client with [" << accNumber << "] is already exist, enter another account Number :";
				accNumber = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankClient newClient = clsBankClient::GetAddNewObject(accNumber);
		_ReadData(newClient);
		switch (newClient.Save())
		{
		case clsBankClient::enSaveStatus::SuccessSave:
			cout << "Client with [" << accNumber << "] added successfully." << endl;
			break;
		case clsBankClient::enSaveStatus::FaildSave:
			cout << "Error occured during add new client." << endl;
			break;
		}
	}

};