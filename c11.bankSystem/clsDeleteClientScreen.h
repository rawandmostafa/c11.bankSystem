#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "ClsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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
public:
	static void ShowDeleteClientScreen() {
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		_DrawScreenHeader("\tDelete client screen");
		string AccountNumber = "";
		cout << "enter account number ?";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "account not found, choose another one\n";
			cout << "enter account number ?";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		_PrintClient(Client);
		cout << "are you sure you want to delete this client?\n";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y') {
			if (Client.Delete()) {
				cout << "client delete succefuly\n";
				_PrintClient(Client);
			}
			else {
				cout << "error client was not delete\n";
			}
		}
	}
};

