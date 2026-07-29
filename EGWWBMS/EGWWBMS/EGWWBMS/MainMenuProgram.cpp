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
	}

	return;
}

void MainMenuProgram()
{

	eMainMenuChoice MainMenuChoice;

	Menus::PrintMainMenu();
	MainMenuChoice = Reads::ReadMainMenuchose();
	ExecuteMainMenuChoice(MainMenuChoice);

	return;
}