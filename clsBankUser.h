#pragma once
#include"Core.h"
using namespace std;


 class clsBankUser :public clsPerson {

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	string _Username = "";
	bool _MarkForDelete = 0;
	string _Password = "";
	enMode _Mode;
	int _Permessions = 0;


	static clsBankUser _ConvertLineToObject(string Line, string Sep = "#//#") {
		vector<string>User = clsString::Split(Line, Sep);
		return clsBankUser(UpdateMode, User[0], User[1], User[2], User[3], User[4], User[5], stoi(User[6]));
	}

	static clsBankUser _GetEmptyObject() {
		return clsBankUser(EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankUser> _LoadDataFromFile() {
		vector<clsBankUser>Users;
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsBankUser User = _ConvertLineToObject(line);
				Users.push_back(User);
			}
			file.close();
		}
		return Users;
	}

	string _ConvertObjectToLine(clsBankUser user, string sep = "#//#") {
		string res = "";
		res += user.FirstName + sep;
		res += user.LastName + sep;
		res += user.Email + sep;
		res += user.Phone + sep;
		res += user.Username + sep;
		res += user.GetPassword() + sep;
		res += to_string(user.Permissions);
		return res;
	}

	void _SaveDataToFile(vector<clsBankUser>Users) {
		fstream file;
		file.open("Users.txt", ios::out);
		if (file.is_open()) {

			for (clsBankUser& u : Users) {
				if (!u._MarkForDelete) {
					string line = _ConvertObjectToLine(u);
					file << line << endl;
				}
			}
		}
	}

	void _Update() {
		vector<clsBankUser> users = _LoadDataFromFile();
		for (clsBankUser& user : users) {
			if (user.Username == Username) {
				user = *this;
				break;
			}
		}
		_SaveDataToFile(users);
	}

	void _AddDataToFile(string s) {
		fstream file;
		file.open("Users.txt", ios::in | ios::app);
		if (file.is_open()) {
			file << s << endl;
			file.close();
		}
	}

	void _AddNew() {
		_AddDataToFile(_ConvertObjectToLine(*this));
	}

	static void _PrintUserRecord(clsBankUser User)
	{
		cout << "| " << setw(20) << left << User.GetFullName();
		cout << "| " << setw(15) << left << User.Email;
		cout << "| " << setw(15) << left << User.Phone;
		cout << "| " << setw(15) << left << User.Username;
		cout << "| " << setw(10) << left << User.GetPassword();
		cout << "| " << setw(10) << left << User.GetPermission();
	}

	static string _getCurrentDate() {
		auto now = chrono::system_clock::now();
		time_t now_c = chrono::system_clock::to_time_t(now);
		tm tm_struct;
		localtime_s(&tm_struct, &now_c);
		ostringstream oss;
		oss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S");
		return oss.str();
	}

	struct stLoginLogs;
	static stLoginLogs _ConvertLoginLogsToRecord(string Line, string Seperator = "#//#")
	{
		stLoginLogs res;


		vector <string> logs = clsString::Split(Line, Seperator);
		res.DateTime = logs[0];
		res.UserName = logs[1];
		res.Password = logs[2];
		res.Permissions = stoi(logs[3]);

		return res;

	}

	string _PrepareLoginsLogToFile(clsBankUser User,string Sep="#//#") {
		string res;
		res += _getCurrentDate() + Sep;
		res += User.Username + Sep;
		res += User.Password + Sep;
		res += to_string(User.Permissions);
		return res;
	}

public:
	static enum enPermessions { all = -1, showall = 1, New = 2, delet = 4, update = 8, find = 16, transaction = 32, manageusers = 64,logs=128 };

	clsBankUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permessions) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Username = Username;
		_Password = Password;
		_Mode = Mode;
		_Permessions = Permessions;
	}

	clsBankUser() {

	}

	struct stLoginLogs {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	static clsBankUser GetEmptyObject() {
		return _GetEmptyObject();
	}

	int GetPermission() {
		return _Permessions;
	}

	void SetPermeission(int Permession) {
		_Permessions = Permession;
	}

	__declspec(property(get = GetPermission, put = SetPermeission))int Permissions;

	string GetUsername() {
		return _Username;
	}

	void SetUsername(string Username) {
		_Username = Username;
	}

	__declspec(property(get = GetUsername, put = SetUsername))string Username;

	string GetPassword() {
		return _Password;
	}

	void SetPassword(string Password) {
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;


	static clsBankUser Find(string Username) {
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string Line;
			while (getline(file, Line)) {
				clsBankUser client = _ConvertLineToObject(Line);
				if (Username == client.Username) {
					file.close();
					return client;
				}
			}
			file.close();
		}

		return _GetEmptyObject();
	}

	static clsBankUser Find(string Username, string Password) {
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string Line;
			while (getline(file, Line)) {
				clsBankUser client = _ConvertLineToObject(Line);
				if (Username == client.Username && Password == client.Password) {
					file.close();
					return client;
				}
			}
			file.close();
		}

		return _GetEmptyObject();
	}

	static bool IsUserExistByUsername(string Username) {
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string Line;
			while (getline(file, Line)) {
				clsBankUser client = _ConvertLineToObject(Line);
				if (Username == client.Username) {
					file.close();
					return true;
				}
			}
			file.close();
		}
		return false;
	}

	static bool IsUserExistByUsernameAndPassword(string Username, string Password) {
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string Line;
			while (getline(file, Line)) {
				clsBankUser client = _ConvertLineToObject(Line);
				if (Username == client.Username && Password == client.Password) {
					file.close();
					return true;
				}
			}
			file.close();
		}
		return false;
	}

	static enum enSaveStatus { SuccessfullSave = 1, FailedSave = 2 };

	enSaveStatus Save() {

		switch (_Mode)
		{
		case clsBankUser::EmptyMode:
			return enSaveStatus::FailedSave;
			break;
		case clsBankUser::UpdateMode:
			_Update();
			return enSaveStatus::SuccessfullSave;
			break;
		case clsBankUser::AddNewMode:
			_AddNew();
			return enSaveStatus::SuccessfullSave;
			break;
		default:
			break;
		}
		return FailedSave;
	}

	static clsBankUser GetAddNewObject(string UserName) {
		return clsBankUser(AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsBankUser> GetUsersList() {
		return _LoadDataFromFile();
	}

	void LogFile() {

		string Line = _PrepareLoginsLogToFile(*this);
		fstream file;
		file.open("LoginLogs.txt",ios::out|ios::app);
		if (file.is_open()) {
			file << Line << endl;
			file.close();
		}

	}

	static  vector <stLoginLogs> GetLoginLogsList()
	{
		vector <stLoginLogs> res;

		fstream MyFile;
		MyFile.open("LoginLogs.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				stLoginLogs data = _ConvertLoginLogsToRecord(Line);

				res.push_back(data);

			}

			MyFile.close();

		}

		return res;

	}

	bool Delete() {
		vector<clsBankUser>users = _LoadDataFromFile();
		for (clsBankUser& u : users) {
			if (u.Username == _Username) {
				u._MarkForDelete = 1;
				break;
			}
		}
		_SaveDataToFile(users);
		*this = _GetEmptyObject();
		return true;
	}

	void Print() {
		cout << "\nClient Card :" << endl;
		cout << "=====================" << endl;
		cout << "First Name : " << GetFirstName() << endl;
		cout << "Last Name : " << GetLastName() << endl;
		cout << "Full Name : " << GetFullName() << endl;
		cout << "Email : " << GetEmail() << endl;
		cout << "Phone : " << GetPhone() << endl;
		cout << "Username : " << GetUsername() << endl;
		cout << "Password : " << GetPassword() << endl;
		cout << "Permission : " << GetPermission() << endl;
		cout << "=====================\n" << endl;
	}

	static void PrintAllUsers() {
		vector<clsBankUser> Users = _LoadDataFromFile();
		cout << "\n\t\t\t\tUser List (" << Users.size() << ") Users(s).";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(10) << "Permessions";
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		for (clsBankUser User : Users) {
			_PrintUserRecord(User);
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "______________________________________________________________\n" << endl;
	}

};