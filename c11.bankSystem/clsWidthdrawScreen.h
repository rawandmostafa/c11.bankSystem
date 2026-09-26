#pragma once
#include<iostream>
#include "clsScreen.h"
#include "ClsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsWidthdrawScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\n Client Card ";
		cout << "\n----------------------------";
		cout << "\n first name :" << Client.FirstName;
		cout << "\n last name :" << Client.LastName;
		cout << "\n full Name :" << Client.FullName();
		cout << "\n Email :" << Client.Email;
		cout << "\n phone :" << Client.Phone;
		cout << "\n AccountNumber :" << Client.AccountNumber();
		cout << "\n pinCode :" << Client.PinCode;
		cout << "\n AccountBalance :" << Client.AccountBalance;
		cout << "\n----------------------------\n";
	}
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowWidthdrawScreen() {
		_DrawScreenHeader("\t Widthdraw Screen \n");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client With " << AccountNumber << "does not exist \n";
			string AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		_PrintClient(Client);
		double amount = 0;
		cout << "enter Widthdraw amount?\n";
		amount = clsInputValidate::ReadDblNumber();
		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y') {
			if (Client.Withdraw(amount)) {
				cout << "\nAmount widthdraw Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;

			}
			else {
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;

			}
			}

		else
		{
			cout << "\nOperation was cancelled.\n";
		}

		
	}
};

