#include "SarchMenuProgram.h"
#include "UI.h"
#include "Input.h"
#include "SearchForElectricityAndGasBillWithIDProgram.h"
#include "SerchForElectricity&GasBillWithClientIDProgram.h"
#include "ShowAllElectricity&GasBillsProgram.h"
#include "SerchForClientWithIDProgram.h"
#include "SerchForClientWithFullNameProgram.h"
#include "ShowAllClientsProgram.h"

void ExecuteSarchMenuChoice(const eSarchMenuChoice& SarchMenuChoice)
{

	switch (SarchMenuChoice)
	{
	case eSarchMenuChoice::eElectricityAndGasBillWithID:
	{
		SearchForElectricityAndGasBillWithIDProgram();
		break;
	}
	case eSarchMenuChoice::eElectricityAndGasBillWithClientID:
	{
		SerchForElectricityAndGasBillWithClientIDProgram();
		break;
	}
	case eSarchMenuChoice::eShowAllElectricityAndGasBills:
	{
		ShowAllElectricityAndGasBillsProgram();
		break;
	}
	case eSarchMenuChoice::eSerchForClientWithID:
	{
		SerchForClientWithIDProgram();
		break;
	}
	case eSarchMenuChoice::eSerchForClientWithFullName:
	{
		SerchForClientWithFullNameProgram();
		break;
	}
	case eSarchMenuChoice::eSowAllClients:
	{
		ShowAllClientsProgram();
		break;
	}
	default:
	{
		MainMenuProgram();
		break;
	}
	}

	return;
}


void SarchMenuProgram(const string Message)
{
	Menus::PrintSerchMenu(Message);
	eSarchMenuChoice SarchMenuChoice;

	SarchMenuChoice = (eSarchMenuChoice)Reads::ReadChose(1, 7);
	ExecuteSarchMenuChoice(SarchMenuChoice);
}