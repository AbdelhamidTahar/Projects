#pragma once
#include <iostream>
using namespace std;

namespace Menus
{
	void PrintHeadarMainMenu();
	void PrintBodyMainMenu();
	void PrintFootarMainMenu();
	void PrintMainMenu(const string& Message="");
	void GoBackTotMainMenu(const bool MessageReturn = false);
	

	void PrintHeadarAddMenu();
	void PrintBodyAddMenu();
	void PrintFootarAddMenu();
	void PrintAddMenu(const string& ErrorMessage = "");
	void GoBackToAddMenu(const string& ErrorMessage = "", const bool MessageReturn = false);


	void PrintHeadarSerchMenu();
	void PrintBodySerchMenu();
	void PrintFootarSerchMenu();
	void PrintSerchMenu(const string& ErrorMessage = "");
	void GoBackToSerchMenu(const string& ErrorMessage = "", const bool MessageReturn = false);

}