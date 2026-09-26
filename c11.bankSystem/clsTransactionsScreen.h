#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "ClsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWidthdrawScreen.h"
#include"clsTotalBalancesScreen.h"
using namespace std;

class clsTransactionsScreen:protected clsScreen
{
private: 
	enum enTransactionsMenueOptions{eDeposit=1,ewithdraw=2,eShowTotalBalance=3,eShowMainMenue=4
	};
	static short ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 4, "enter number between 1 to 4?");
		return choice;
	}
	static void ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void ShowWithdrawtScreen() {
		clsWidthdrawScreen::ShowWidthdrawScreen();
	}
	static void ShowTotalBalanceScreen() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _GoBackToTransactionsMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _performTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
		switch (TransactionsMenueOption) {
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::ewithdraw:
			system("cls");
			ShowWithdrawtScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowMainMenue:
		{

		}
		}
	}


public:
	static void ShowTransactionsMenue() {

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\ttransactions screen\n");
		cout << setw(37) << left << "" << "=============================================================\n";
		cout << setw(37) << left << "" << "\t\t transaction Menue \n";
		cout << setw(37) << left << "" << "\t[1]Deposit\n";
		cout << setw(37) << left << "" << "\t[2]Withdraw\n";
		cout << setw(37) << left << "" << "\t[3]TotalBalance\n";
		cout << setw(37) << left << "" << "\t[4]Main Menue\n";
		cout << setw(37) << left << "" << "============================================================\n";
		_performTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}
	
};

