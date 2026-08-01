#include "MainMenuProgram.h"
#include "UI.h"
#include "Input.h"

void ExecuteMainMenuChoice(const eMainMenuChoice& MainMenuChoice)
{

	switch(MainMenuChoice)
	{
	case eMainMenuChoice::Add:
	{
		AddMenuProgram();
		break;
	}
	case eMainMenuChoice::Sarch:
	{
		SarchMenuProgram();
		break;
	}
	default:
	{
		cout << "\n\nEndProgram;)\n\n";
		break;
	}
	}

	return;
}

void MainMenuProgram()
{

	eMainMenuChoice MainMenuChoice;

	Menus::PrintMainMenu();
	MainMenuChoice = (eMainMenuChoice) Reads::ReadChose(1,3);
	ExecuteMainMenuChoice(MainMenuChoice);

	return;
}