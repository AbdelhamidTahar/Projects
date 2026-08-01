#include "SerchForElectricity&GasBillWithClientIDProgram.h"
#include "ClientProgram.h"
#include "SarchMenuProgram.h"
#include "UI.h"
#include "Print.h"

bool SerchForElectricityAndGasBillWithClientIDProgram()
{
	sClient Client;

	if (!ClientProgram(Client))
	{
		Menus::GoBackToSerchMenu("Error: Client with this ID does not exist!\n");
		return false;
	}

	vector <sElectricityAndGasBill> vElectricityAndGasBill; 

	vElectricityAndGasBill = ElectricityAndGasBillDataOperations::
		LoadAllElectricityAndGasBills();

	vElectricityAndGasBill = ElectricityAndGasBillDataOperations::
		FindElectricityAndGasBillWithClientID
	(
		vElectricityAndGasBill,
		Client.ID
	);

	if (vElectricityAndGasBill.empty())
	{
		Menus::GoBackToSerchMenu("Sorry, there are currently no bills for this client!\n");
		return false;
	}

	system("cls");
	int CountBill = 1;
	for (const sElectricityAndGasBill& sElectricityAndGasBill : vElectricityAndGasBill)
	{
		cout << endl;
		cout << "Bill Number: " << "\033[33m" << CountBill << "\033[0m" << endl;
		PrintElectricityAndGasBill(sElectricityAndGasBill);
		CountBill++;
	}

	Menus::GoBackToSerchMenu("", true);

	return true;
}