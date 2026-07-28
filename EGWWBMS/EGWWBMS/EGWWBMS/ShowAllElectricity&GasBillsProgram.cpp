#include "ShowAllElectricity&GasBillsProgram.h"
#include "ElectricityAndGasBillDataFile.h"


bool ShowAllElectricityAndGasBillsProgram()
{
	vector<sElectricityAndGasBill>vElectricityAndGasBill =
		ElectricityAndGasBillDataOperations::LoadAllElectricityAndGasBills();

	if (vElectricityAndGasBill.empty())
	{
		Menus::GoBackToSerchMenu("Sorry, there are no electricity and gas bills to display!\n");
		return false;
	}

	int CountBill = 1;
	for (const sElectricityAndGasBill& ElectricityAndGasBill : vElectricityAndGasBill)
	{
		cout << endl;
		cout << "Bill Number: " << CountBill << endl;
		PrintElectricityAndGasBill(ElectricityAndGasBill);
		CountBill++;
	}


	return true;
}