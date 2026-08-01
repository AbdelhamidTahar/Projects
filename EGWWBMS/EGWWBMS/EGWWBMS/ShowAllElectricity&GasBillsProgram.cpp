#include "ShowAllElectricity&GasBillsProgram.h"
#include "ElectricityAndGasBillDataFile.h"
#include "SarchMenuProgram.h"


bool ShowAllElectricityAndGasBillsProgram()
{
	vector<sElectricityAndGasBill>vElectricityAndGasBill =
		ElectricityAndGasBillDataOperations::LoadAllElectricityAndGasBills();

	if (vElectricityAndGasBill.empty())
	{
		Menus::GoBackToSerchMenu("Sorry, there are no electricity and gas bills to display!\n");
		return false;
	}


	system("cls");
	int CountBill = 1;
	for (const sElectricityAndGasBill& ElectricityAndGasBill : vElectricityAndGasBill)
	{
		cout << endl;
		cout << "Bill Number: " << "\033[33m" << CountBill << "\033[0m" << endl;
		PrintElectricityAndGasBill(ElectricityAndGasBill);
		CountBill++;
	}

	Menus::GoBackToSerchMenu("", true);

	return true;
}