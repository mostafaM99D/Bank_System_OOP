#pragma once
#include"Core.h";
#include"clsSession.h"
using namespace std;
class clsLogs {



private:

    static void PrintLoginRegisterRecordLine(clsBankUser::stLoginLogs Logs)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << Logs.DateTime;
        cout << "| " << setw(20) << left << Logs.UserName;
        cout << "| " << setw(20) << left << Logs.Password;
        cout << "| " << setw(10) << left << Logs.Permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    {

        vector <clsBankUser::stLoginLogs> vLogs = clsBankUser::GetLoginLogsList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLogs.size()) + ") Record(s).";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogs.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankUser::stLoginLogs r : vLogs)
            {
                PrintLoginRegisterRecordLine(r);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};