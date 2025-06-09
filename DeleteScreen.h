#pragma once
#include"Core.h";
using namespace std;

class clsDelete :protected clsHeader {


private:


public:


	static void DeleteClient() {
		string accNumber = clsInputValidate::ReadString("Enter the account number : ");
		while (true) {
			if (!clsBankClient::IsClientExistByAccountNumber(accNumber)) {
				cout << "The client with [" << accNumber << "] is not exist.Please enter another account number" << endl;
				accNumber = clsInputValidate::ReadString();
			}
			else
				break;
		}
		clsBankClient client = clsBankClient::Find(accNumber);
		client.Print();
		char c;
		cout << "\n\nDo you sure for deleting this client (y/n) ?";
		cin >> c;
		if(c=='Y'||c=='y')
		{
			if (client.Delete()) {
				cout << "Client with [" << accNumber << "] is deleted successfully." << endl;
			}
			else
				cout << "Error occured during delete this client" << endl;
		}
	}



};