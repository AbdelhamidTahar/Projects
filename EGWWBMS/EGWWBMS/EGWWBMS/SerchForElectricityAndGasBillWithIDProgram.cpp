#include "SearchForElectricityAndGasBillWithIDProgram.h"
#include "Input.h"
#include "Print.h"
#include "UI.h"


bool SearchForElectricityAndGasBillWithIDProgram()
{
	sElectricityAndGasBill ElectricityAndGasBill;
	string BillID = "";

	BillID = Reads::ReadID("Enter Electricity and Gas Bill ID: ");

	if (
		ElectricityAndGasBillDataOperations::GetForElectricityAndGasBillWithID
		(BillID, ElectricityAndGasBill)
		)
	{
		system("cls");
		PrintElectricityAndGasBill(ElectricityAndGasBill);
		Menus::GoBackToSerchMenu("", true);
		return true;
	}
	Menus::GoBackToSerchMenu("\n\033[1;31mError: No Electricity and Gas Bill found with this ID\033[0m\n");


	return false;

}