#pragma once
#include<iostream>
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string subTitle = "") {
		cout << "\t\t\t\t\t-------------------------------------------";
		cout << "\n\n\t\t\t\t\t" << Title;
		if (subTitle != "") {
			cout << "\n\t\t\t\t\t" << subTitle;
		}
		cout << "\n\t\t\t\t\t-------------------------------------------\n\n";
	}
	static bool CheckAccessRights(clsUser::enPermissions Permission) {

		if (!CurrentUser.CheckAccessPermissions(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}
};

