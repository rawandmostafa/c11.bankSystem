#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "ClsInputValidate.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
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
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "enter first name ?\n";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "enter last name ?\n";
		Client.LastName = clsInputValidate::ReadString();

		cout << "enter Email ?\n";
		Client.Email = clsInputValidate::ReadString();

		cout << "enter phone ?\n";
		Client.Phone = clsInputValidate::ReadString();

		cout << "enter pinCode ?\n";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "enter AccountBalance ?\n";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}
public:
	static void ShowAddNewClientScreen() {
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("\tAdd New Client Screen ");
		cout << "enter Account number \n";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount numbe is already used \n";
			cout << "enter Account number \n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient newClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(newClient);
		clsBankClient::enSaveResult saveResult;
		saveResult = newClient.save();
		switch (saveResult) {
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "\nAccount Added Succesfuly \n";
			_PrintClient(newClient);
			break;
		case clsBankClient::enSaveResult::svFailedEmptyObject:
			cout << "\nerror acount was not saved because its empty \n";
			break;
		case clsBankClient::enSaveResult::svFailedAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
	}
};

