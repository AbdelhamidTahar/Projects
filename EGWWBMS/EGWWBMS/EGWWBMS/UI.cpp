#pragma once
#include <iostream>
#include "UI.h"
#include "Input.h"
using namespace std;



void Menus::PrintHeadarMainMenu()
{
	cout << "--------------------------------------\n";
	cout << "-                                    -\n";
	cout << "-           Main Menu                -\n";
	cout << "-                                    -\n";
	cout << "--------------------------------------\n";
}
void Menus::PrintBodyMainMenu()
{
	cout << "[1] Add (Electricity & Gas Bill | Client)\n";
	cout << "[2] Search (Electricity & Gas Bill | Client)\n";
	cout << "[3] Exit\n";

}
void Menus::PrintFootarMainMenu()
{
	cout << "--------------------------------------\n";
}
void Menus::PrintMainMenu(const string& ErrorMessage )
{
	PrintHeadarMainMenu();
	PrintBodyMainMenu();
	PrintFootarMainMenu();
	Messages::PrintErrorMessage(ErrorMessage);
}
void Menus::GoBackTotMainMenu(const string& ErrorMessage )
{
	system("cls");
	PrintMainMenu(ErrorMessage);
}



void  Menus::PrintHeadarAddMenu()
{
	cout << "--------------------------------------\n";
	cout << "-                                    -\n";
	cout << "-           Add Menu                 -\n";
	cout << "-                                    -\n";
	cout << "--------------------------------------\n";
}
void  Menus::PrintBodyAddMenu()
{
	cout << "[1] Add New Electricity & Gas Bill.\n";
	cout << "[2] Add New Client.\n";
	cout << "[3] Exit.\n";
}
void  Menus::PrintFootarAddMenu()
{
	cout << "--------------------------------------\n";
}
void  Menus::PrintAddMenu(const string& ErrorMessage)
{
	PrintHeadarAddMenu();
	PrintBodyAddMenu();
	PrintFootarAddMenu();
	Messages::PrintErrorMessage(ErrorMessage);
}
void  Menus::GoBackToAddMenu(const string& ErrorMessage)
{
	system("cls");
	PrintAddMenu(ErrorMessage);
}




void Menus::PrintHeadarSerchMenu()
{
	cout << "--------------------------------------\n";
	cout << "-                                    -\n";
	cout << "-           Serch Menu               -\n";
	cout << "-                                    -\n";
	cout << "--------------------------------------\n";
}
void Menus::PrintBodySerchMenu()
{
	cout << "[1] Serch For Electricity & Gas Bill With ID\n";
	cout << "[2] Serch For Electricity & Gas Bill With Client ID\n";
	cout << "[3] Show All Electricity & Gas Bills";
	cout << "[4] Serch For Client With ID\n";
	cout << "[5] Serch For Client With Full Name\n";
	cout << "[6] Show All Clients\n";
	cout << "[7] Exit\n";
}
void Menus::PrintFootarSerchMenu()
{
	cout << "--------------------------------------\n";
}
void Menus::PrintSerchMenu(const string& ErrorMessage )
{
	PrintHeadarSerchMenu();
	PrintBodySerchMenu();
	PrintFootarSerchMenu();
	Messages::PrintErrorMessage(ErrorMessage);
}
void Menus::GoBackToSerchMenu(const string& ErrorMessage)
{
	system("cls");
	PrintSerchMenu(ErrorMessage);
}
