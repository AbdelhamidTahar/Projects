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
		SarchMenuProgram("Sorry, there are currently no bills for this client!\n");
		return false;
	}

	int CountBill = 1;
	for (const sElectricityAndGasBill& sElectricityAndGasBill : vElectricityAndGasBill)
	{
		cout << endl;
		cout << "Bill Number: " << CountBill << endl;
		PrintElectricityAndGasBill(sElectricityAndGasBill);
		CountBill++;
	}



	return true;
}