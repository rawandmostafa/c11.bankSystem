#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "ClsInputValidate.h"
using namespace std;

class clsFindClientScreen:protected clsScreen
{
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
	static void ShowFindClientScreen() {
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}
		_DrawScreenHeader("\tfind client screen \n");
		string AccountNumber = "";
		cout << "enter account number ?";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "account not found, choose another one\n";
			cout << "enter account number ?";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		if (!Client.isEmpty()) {
			cout << "Client found \n";
		}
		else {
			cout << "client not found\n";

		}
		_PrintClient(Client);

	}
};

