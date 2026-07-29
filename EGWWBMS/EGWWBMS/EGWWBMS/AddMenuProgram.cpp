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
		AddElectricityAndGasBillsProgram();
		break;
	}
	case eAddMenuChoice::Client:
	{
		AddNewClients();
		break;
	}
	}

	return;
}


void AddMenuProgram(const string Message)
{
	Menus::PrintAddMenu();
	eAddMenuChoice AddMenuChoice;

	AddMenuChoice = Reads::ReadAddMenuchose();
	ExecuteAddMenuChoice(AddMenuChoice);
}
