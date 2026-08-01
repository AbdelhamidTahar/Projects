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
void Menus::PrintMainMenu( const string& Message)
{
	system("cls");
	PrintHeadarMainMenu();
	PrintBodyMainMenu();
	PrintFootarMainMenu();
	cout << Message << endl;
}
void Menus::GoBackTotMainMenu( const bool MessageReturn)
{
	if (MessageReturn)
	{
		cout << "Press Any Key To Go Back To Main Menu . . .\n";
		system("pause>0");
	}

	system("cls");
	MainMenuProgram();
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
	system("cls");
	PrintHeadarAddMenu();
	PrintBodyAddMenu();
	PrintFootarAddMenu();
	Messages::PrintErrorMessage(ErrorMessage);
}
void  Menus::GoBackToAddMenu(const string& ErrorMessage, const bool MessageReturn )
{

	if (MessageReturn)
	{
		cout << "\n\nPress any key to go back to Add Menue...";
		system("pause>0");
	}

	system("cls");
	AddMenuProgram(ErrorMessage);
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
	cout << "[3] Show All Electricity & Gas Bills\n";
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
	system("cls");
	PrintHeadarSerchMenu();
	PrintBodySerchMenu();
	PrintFootarSerchMenu();
	Messages::PrintErrorMessage(ErrorMessage);
}
void Menus::GoBackToSerchMenu(const string& ErrorMessage ,const bool MessageReturn)
{
	if (MessageReturn)
	{
		cout << "Press Any Key To Go Back To Serch Menu . . .\n";
		system("pause>0");
	}

	system("cls");
	SarchMenuProgram(ErrorMessage);

}


