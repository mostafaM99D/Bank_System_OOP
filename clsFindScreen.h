#pragma once
#include"Core.h"
using namespace std;

class clsFindClient {

public:

	static void FindClient(string AccounNumber) {

		if (!clsBankClient::IsClientExistByAccountNumber(AccounNumber))
			cout << "Client with [" << AccounNumber << "] is not exist." << endl;

		clsBankClient Client = clsBankClient::Find(AccounNumber);
		Client.Print();
	}
};