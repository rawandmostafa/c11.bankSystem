#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "ClsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen 
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
	static void ShowUpdateClientScreen() {
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
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
		cout << "are you sure you want to update this client?\n";
		char answer = 'n';
		cin >> answer;
		if (answer = 'y') {
			cout << "update client info\n";
			cout << "-------------------------\n";
			_ReadClientInfo(Client);
			clsBankClient::enSaveResult SaveResult;
			SaveResult = Client.save();
			switch (SaveResult) {
				case clsBankClient::enSaveResult::svSucceeded:
					cout << "account updated succesfuly\n";
					_PrintClient(Client);
					break;

				case clsBankClient::enSaveResult::svFailedEmptyObject:
					cout << "\nError account was not saved because it's Empty";
						
					break;
			}

		}
		

	}


};

