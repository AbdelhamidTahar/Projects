#include "AddMenuProgram.h"
#include "UI.h"
#include "Input.h"
#include "ElectricityAndGasBillProgram.h"
#include "AddNewClientProgram.h"


void ExecuteAddMenuChoice(const eAddMenuChoice& AddMenuChoice)
{

	switch (AddMenuChoice)
	{
	case eAddMenuChoice::ElectricityAndGasBill:
	{
		if(AddElectricityAndGasBillsProgram())
			Menus::GoBackToAddMenu("", true);
		break;
	}
	case eAddMenuChoice::Client:
	{
		if(AddNewClients())
			Menus::GoBackToAddMenu("", true);
		break;
	}
	default:
	{
		Menus::GoBackTotMainMenu();
		break;
	}
	}

	return;
}


void AddMenuProgram(const string &Message)
{
	Menus::PrintAddMenu(Message);
	eAddMenuChoice AddMenuChoice;

	AddMenuChoice = (eAddMenuChoice)Reads::ReadChose(1, 3);
	ExecuteAddMenuChoice(AddMenuChoice);
}
