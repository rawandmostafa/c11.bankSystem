#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static void _Login() {
		bool LoginFailed = false;
		string Username, password;
		do {
			if(LoginFailed){
				cout << "\n invalid username/password\n\n";
			}
			cout << "enter username\n";
			cin >> Username;
			cout << "enter password\n";
			cin >> password;
			CurrentUser = clsUser::Find(Username, password);
			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed);
		clsMainScreen::ShowMainMenue();
	}
public:
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login screen ");
		_Login();
	}
};

