#include"Core.h";
using namespace std;

class clsPerson {
	
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public :
	clsPerson() {

	}

	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	// get, set proberties.
	// FirstName
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	_declspec(property (get=GetFirstName, put = SetFirstName))string FirstName;
	// LastName
	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	_declspec(property(get = GetLastName, put = SetLastName))string LastName;
	// _Email
	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	_declspec(property(get = GetEmail, put = SetEmail))string Email;
	//phone
	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	_declspec(property(get = GetPhone, put = SetPhone))string Phone;

	//functions

	string GetFullName() {
		return _FirstName + " " + _LastName;
	}

};