#pragma once
#include <iostream>
using namespace std;

namespace Menus
{
	void PrintHeadarMainMenu();
	void PrintBodyMainMenu();
	void PrintFootarMainMenu();
	void PrintMainMenu(const string& ErrorMessage = "");
	void GoBackTotMainMenu(const string& ErrorMessage = "");


	void PrintHeadarAddMenu();
	void PrintBodyAddMenu();
	void PrintFootarAddMenu();
	void PrintAddMenu(const string& ErrorMessage = "");
	void GoBackToAddMenu(const string& ErrorMessage = "");


	void PrintHeadarSerchMenu();
	void PrintBodySerchMenu();
	void PrintFootarSerchMenu();
	void PrintSerchMenu(const string& ErrorMessage = "");
	void GoBackToSerchMenu(const string& ErrorMessage = "");

}