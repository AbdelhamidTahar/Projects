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
		PrintElectricityAndGasBill(ElectricityAndGasBill);
		return true;
	}

		Menus::GoBackToSerchMenu("Error: No Electricity and Gas Bill found with this ID!");
		return false;



	return true;
}