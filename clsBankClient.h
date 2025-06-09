#pragma once
#include"Core.h";
#include"clsPerson.h";
#include"clsString.h";
using namespace std;

class clsBankClient : public clsPerson {

private:
	string _AccountNumber = "";
	string _PinCode = "";
	double _AccountBalance = 0;
	bool MarkForDelete = 0;
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNew = 3 };
	enMode _Mode;

	static clsBankClient _ConvertLineToObject(string Line, string Separator = "#//#") {
		vector<string> clinet;
		clinet = clsString::Split(Line, Separator);
		return clsBankClient(UpdateMode, clinet[0], clinet[1], clinet[2], clinet[3], clinet[4], clinet[5], stod(clinet[6]));
	}

	static clsBankClient _EmptyData() {
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadAllClientsFromFile() {

		fstream file;
		file.open("Clients.txt", ios::in);
		vector<clsBankClient> clients;
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsBankClient client = _ConvertLineToObject(line, "#//#");
				clients.push_back(client);
			}

			file.close();
		}
		return clients;
	}

	string _ConvertObjectToLine(clsBankClient Client, string Separator = "#//#") {
		string res = "";
		res += Client.FirstName + Separator;
		res += Client.LastName + Separator;
		res += Client.Email + Separator;
		res += Client.Phone + Separator;
		res += Client.GetAccountNumber() + Separator;
		res += Client.PinCode + Separator;
		res += to_string(Client._AccountBalance);
		return res;
	}

	void _SaveDataToFile(vector<clsBankClient>clients) {
		fstream file;
		file.open("Clients.txt", ios::out);
		if (file.is_open()) {

			for (clsBankClient c : clients) {
				if (!c.MarkForDelete)
				{
					string Line = _ConvertObjectToLine(c);
					file << Line << endl;
				}
			}
			file.close();
		}
	}

	void _Update() {
		vector<clsBankClient>clients = _LoadAllClientsFromFile();
		for (clsBankClient& c : clients) {
			if (GetAccountNumber() == c.GetAccountNumber()) {
				c = *this;
				break;
			}
		}
		_SaveDataToFile(clients);
	}

	void _AddNew() {
		_AddToFile(_ConvertObjectToLine(*this));
	}

	void _AddToFile(string s) {
		fstream file;
		file.open("Clients.txt", ios::app | ios::out);
		if (file.is_open()) {
			file << s << endl;
			file.close();
		}
	}

	static void _PrintInBalaneceMode(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.Balance;
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccNumber, string PIN, double Balance)
		:clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccNumber;
		_PinCode = PIN;
		_AccountBalance = Balance;
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}
	string GetPinCode() {
		return _PinCode;
	}
	void SetPinCode(string pin) {
		_PinCode = pin;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	double GetBalance() {
		return _AccountBalance;
	}
	void SetBalance(double Balance) {
		_AccountBalance = Balance;
	}
	_declspec(property(get = GetBalance, put = SetBalance))double Balance;
	void Print() {
		cout << "\nClient Card :" << endl;
		cout << "=====================" << endl;
		cout << "First Name : " << GetFirstName() << endl;
		cout << "Last Name : " << GetLastName() << endl;
		cout << "Full Name : " << GetFullName() << endl;
		cout << "Email : " << GetEmail() << endl;
		cout << "Phone : " << GetPhone() << endl;
		cout << "Account Number : " << GetAccountNumber() << endl;
		cout << "PIN Code : " << GetPinCode() << endl;
		cout << "Account Balance : " << GetBalance() << endl;
		cout << "=====================\n" << endl;
	}
	bool IsEmpty() {
		return (_Mode != EmptyMode);
	}
	// functions

	static clsBankClient Find(string AccountNumber) {
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {

			string line;
			while (getline(file, line)) {

				clsBankClient Client = _ConvertLineToObject(line, "#//#");
				if (Client.GetAccountNumber() == AccountNumber) {
					file.close();
					return Client;
				}

			}
			file.close();
		}

		return _EmptyData();
	}

	static clsBankClient Find(string AccountNumber, string Pin) {
		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open()) {

			string Line;
			while (getline(file, Line)) {
				clsBankClient cl = _ConvertLineToObject(Line, "#//#");
				if (cl.GetAccountNumber() == AccountNumber && cl.GetPinCode() == Pin) {

					file.close();
					return cl;
				}
			}

			file.close();
		}
		return _EmptyData();
	}

	static bool IsClientExistByAccountNumber(string AccountNumber) {
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {

			string line;
			while (getline(file, line)) {

				clsBankClient Client = _ConvertLineToObject(line, "#//#");
				if (Client.GetAccountNumber() == AccountNumber) {
					file.close();
					return true;
				}

			}
			file.close();
		}

		return false;
	}

	enum enSaveStatus { FaildSave = 0, SuccessSave = 1 };

	enSaveStatus Save() {

		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveStatus::FaildSave;
			break;
		case clsBankClient::UpdateMode:
			_Update();
			return enSaveStatus::SuccessSave;
			break;
		case clsBankClient::AddNew:
			if (this->IsClientExistByAccountNumber(this->GetAccountNumber()))
				return FaildSave;
			_AddNew();
			return enSaveStatus::SuccessSave;
			break;
		default:
			break;
		}
	}

	static clsBankClient GetAddNewObject(string AccountNumber) {
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList() {
		return _LoadAllClientsFromFile();
	}

	bool Delete() {
		vector<clsBankClient>cls = _LoadAllClientsFromFile();
		for (clsBankClient& cl : cls) {
			if (cl.GetAccountNumber() == _AccountNumber) {
				cl.MarkForDelete = 1;
				break;
			}
		}
		_SaveDataToFile(cls);
		*this = _EmptyData();
		return true;
	}

	static double GetTotalBalances() {

		vector<clsBankClient>Clients = _LoadAllClientsFromFile();
		double TotalBalances = 0;
		for (clsBankClient cl : Clients) 
			TotalBalances += cl.Balance;
		return TotalBalances;
	}

	static void PrintAllInBalanceMode() {
		vector<clsBankClient> clients = _LoadAllClientsFromFile();
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

};